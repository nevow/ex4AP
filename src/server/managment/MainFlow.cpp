//
// MainFlow.
//

#include "MainFlow.h"
#include "DataSender.h"
#include "DataSender.cpp"

using namespace std;

/**
 * constructor.
 * initialize the environment, get map, obstacles and create a SystemOperations.
 */
MainFlow::MainFlow(int ip) {

    sock = new Udp(1, ip);
    sock->initialize();

    int rows, columns, obstacleNum;

    // get the map's size and create it
    cin >> columns >> rows;
    Map *map = new Map(columns, rows);
    cin.ignore();

    obstacleNum = ProperInput::validInt();
    cin.ignore();

    so = new SystemOperations(map, sock);

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
void MainFlow::input() {
    int choice;
    int id, drivers_num, taxi_type, num_passengers, trip_time;
    double tariff;
    char trash, manufacturer, color;


    char buf[100];

    do {
        choice = ProperInput::validInt();
        cin.ignore();
        switch (choice) {
            // create drivers, gets from the client
            case 1: {
                drivers_num = ProperInput::validInt();
                cin.ignore();

                for (int i = drivers_num; i > 0; --i) {

                    cout << "waiting for driver" << endl;                 //***********************
                    // receive the driver from the client
                    Driver *driver = DataSender<Driver>::receiveData(sock);
                    cout << "received driver" << endl;                    //***********************

                    // assign the Driver with the taxi, serialize the taxi, send it to the client
                    Taxi *taxi = so->assignDriver(driver);
                    DataSender<Taxi>::sendData(sock, taxi);

                    cout << "sent taxi" << endl;                          //***********************
                    cout << "waiting for client reply" << endl;           //***********************

                    // receive the client's status
                    sock->receiveData(buf, sizeof(buf));
                    if (!strcmp(buf, "waiting_for_trip")) {
                        TripInfo *ti = driver->getTi();
                        DataSender<TripInfo>::sendData(sock, ti);
                        cout << "sent trip info" << endl;
                    }
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
                sock->sendData("9");
                cout << "sent 9" << endl;
                ++clock;
                so->moveAll(clock);

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
    sock->sendData("exit");
}
