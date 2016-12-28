//
// MainFlow.
//

#include "MainFlow.h"

#include "../enum/MartialStatuesFactory.h"
#include "../taxi/Cab.h"
#include "../enum/ColorFactory.h"
#include "../enum/CarManufactureFactory.h"
#include "../taxi/LuxuryCab.h"
#include "ProperInput.h"

using namespace std;

/**
 * constructor.
 * initialize the environment, get map, obstacles and create a SystemOperations.
 */
MainFlow::MainFlow() {

    int rows, columns, obstacleNum;
    std::list<Node *> *obstacles = new list<Node *>;

    // get the map's size and create it
    cin >> columns >> rows;
    Map *map = new Map(columns, rows);
    cin.ignore();

    obstacleNum = ProperInput::validInt();
    cin.ignore();

    // make the obstacles List from the input
    for (; obstacleNum > 0; obstacleNum--) {
        Point obs = ProperInput::validPoint(columns, rows);
        cin.ignore();
        Node *n = new Node(&obs);
        obstacles->push_front(n);
    }

    so = new SystemOperations(map, obstacles);
}

/**
 * get inputs from user and follow the commands.
 */
void MainFlow::input() {
    int choice;
    int id, age, experience, vehicleId, taxi_type, num_passengers;
    double tariff;
    char trash, status, manufacturer, color;

    do {
        choice = ProperInput::validInt();
        cin.ignore();
        switch (choice) {
            // create new drive
            case 1: {
                id = ProperInput::validInt();
                cin >> trash;
                age = ProperInput::validInt();
                cin >> trash >> status >> trash;
                experience = ProperInput::validInt();
                cin >> trash;
                vehicleId = ProperInput::validInt();
                cin.ignore();

                Driver *driver = new Driver(id, age,
                                            MartialStatuesFactory::getMartialStatus(status),
                                            experience, vehicleId);
                so->addDriver(driver);
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
                cin.ignore();

                TripInfo *tripInfo = new TripInfo(id, start, end, num_passengers, tariff);
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
                // start driving - getting all drivers to their end point
            case 6: {
                so->moveAll();
                break;
            }
                // every other case - don't do anything.
            default: {
                break;
            }
        }

    } while (choice != 7);         // exit condition
}
