//
// MainFlow.
//

#include "MainFlow.h"

#include "../taxi/Cab.h"
#include "../enum/ColorFactory.h"
#include "../enum/CarManufactureFactory.h"
#include "../taxi/LuxuryCab.h"
#include "ProperInput.h"
#include "../sockets/Udp.h"


using namespace std;

/**
 * constructor.
 * initialize the environment, get map, obstacles and create a SystemOperations.
 */
MainFlow::MainFlow() {

    int rows, columns, obstacleNum;

    // get the map's size and create it
    cin >> columns >> rows;
    Map *map = new Map(columns, rows);
    cin.ignore();

    obstacleNum = ProperInput::validInt();
    cin.ignore();

    so = new SystemOperations(map);

    // make the obstacles List from the input
    for (; obstacleNum > 0; obstacleNum--) {
        Point obs = ProperInput::validPoint(columns, rows);
        cin.ignore();
        so->addObstacle(obs);
    }
}

/**
 * get inputs from user and follow the commands.
 */
void MainFlow::input(int ip) {
    int choice;
    int id, drivers_num, taxi_type, num_passengers, trip_time;
    double tariff;
    char trash, manufacturer, color;

    Udp udp(1, ip);
    udp.initialize();

    do {
        choice = ProperInput::validInt();
        cin.ignore();
        switch (choice) {
            // create drivers, gets from the client
            case 1: {
                drivers_num = ProperInput::validInt();
                cin.ignore();

                for (int i = drivers_num; i > 0; --i) {

                    char buffer[1024];
                    // receive the driver from the client
                    udp.reciveData(buffer, sizeof(buffer));
                    Driver *driver;
                    boost::iostreams::basic_array_source<char> device(buffer, 1024);
                    boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(
                            device);
                    boost::archive::binary_iarchive ia(s2);
                    ia >> driver;

                    // assign the Driver with the taxi, serialize the taxi, send it to the client
                    Taxi *taxi = so->assignDriver(driver);
                    std::string serial_str;
                    boost::iostreams::back_insert_device<std::string> inserter(serial_str);
                    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(
                            inserter);
                    boost::archive::binary_oarchive oa(s);
                    oa << taxi;
                    s.flush();
                    udp.sendData(serial_str);
                }
                break;
            }
                // create new TripInfo
            case 2: {

                id = ProperInput::validInt();
                cin >> trash;
                Point p1 = ProperInput::validPoint(so->getX(), so->getY());
                Point *start = new Point(p1.getX(), p1.getY());
                cin >> trash;
                Point p2 = ProperInput::validPoint(so->getX(), so->getY());
                Point *end = new Point(p2.getX(), p2.getY());
                cin >> trash;
                num_passengers = ProperInput::validInt();
                cin >> trash;
                tariff = ProperInput::validDouble();
                cin >> trash;
                trip_time = ProperInput::validInt();
                cin.ignore();
                TripInfo *tripInfo = new TripInfo(id, start, end, num_passengers, tariff,
                                                  trip_time);
                so->addTI(tripInfo);

                char buf[1024];
                // receive the client's status
                udp.reciveData(buf, sizeof(buf));
                if (buf == "waiting_for_trip") {

                    std::string serial_str;
                    boost::iostreams::back_insert_device<std::string> inserter(serial_str);
                    boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(
                            inserter);
                    boost::archive::binary_oarchive oa(s);
                    oa << tripInfo;
                    s.flush();
                    udp.sendData(serial_str);
                } else {
                    delete (tripInfo);
                }
                break;

            }
                // create new Taxi
            case 3: {
                id = ProperInput::validInt();
                cin >> trash;
                taxi_type = ProperInput::validInt();
                cin >> trash >> manufacturer >> trash >> color;
                cin.ignore();

                Taxi *taxi;
                if (taxi_type == 1)                      // create regular cab
                {
                    taxi = new Cab(ColorFactory::charToColor(color),
                                   CarManufactureFactory::charToFirm(manufacturer), id);

                } else if (taxi_type == 2)               // create LuxuryCab cab
                {
                    taxi = new LuxuryCab(ColorFactory::charToColor(color),
                                         CarManufactureFactory::charToFirm(
                                                 manufacturer), id);
                } else {
                    break;
                }
                so->addTaxi(taxi);
                break;
            }
                // request for a driver location by his id
            case 4: {
                id = ProperInput::validInt();
                cin.ignore();

                Point *location = so->getDriverLocation(id);
                if (location) {
                    cout << *location;
                }
                break;
            }

                // clock time - move one step
            case 9: {
                char buf[1024];
                // receive the client's status
                udp.reciveData(buf, sizeof(buf));
                if (buf == "waiting_for_orders") {
                    udp.sendData("9");
                    ++clock;
                    so->moveAll();
                }
                break;
            }

                // every other case - don't do anything.
            default: {
                break;
            }
        }
        // exit condition
    } while (choice != 7);

    // send message to the client to shut down
    udp.sendData("exit");
}
