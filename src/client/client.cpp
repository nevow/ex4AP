//
// client.
//

#include "../server/sockets/Udp.h"
#include "../server/managment/ProperInput.h"
#include "../server/tripOperations/Driver.h"
#include "../server/enum/MartialStatuesFactory.h"
#include "../server/managment/DataSender.h"
#include "../server/managment/DataSender.cpp"

using namespace std;

int main(int argc, char *argv[]) {
    int portNumber = atoi(argv[2]);
    // create a socket for transferring data between the server and the client
    Socket *sock = new Udp(0, portNumber);
    sock->initialize();

    // get a driver with user input
    int id, age, experience, vehicleId;
    char trash, status;
    id = ProperInput::validInt();
    cin >> trash;
    age = ProperInput::validInt();
    cin >> trash >> status >> trash;
    experience = ProperInput::validInt();
    cin >> trash;
    vehicleId = ProperInput::validInt();
    cin.ignore();
    char buffer[50];

    // create a driver with the user input
    Driver *driver = new Driver(id, age, MartialStatuesFactory::getMartialStatus(status),
                                experience, vehicleId, portNumber);
    // serialize and send the driver
    DataSender<Driver>::sendData(sock, driver);

    // deserialize the taxi from the server
    Taxi *cab = DataSender<Taxi>::receiveData(sock); // wait to receive a cab from the server

    driver->setCab(cab);                             // set the cab to the driver

    TripInfo *ti = NULL;
    // do while the server still sends orders different from the exit order "exit"
    do {
        if (ti == NULL) {
            // no trip info to move with
            if (!strcmp(buffer, "9")) {
                sock->receiveData(buffer, sizeof(buffer));
                continue;
            }
            if (!strcmp(buffer, "2")) {
                sock->sendData("waiting_for_trip");
                ti = DataSender<TripInfo>::receiveData(sock);
                cout << "received trip" << endl;
                driver->setTi(ti);                     // set the driver with the trip info
            }
            /*sock->sendData("waiting_for_trip");      // tell the server that the client is waiting
            cout << "sent waiting for trips" << endl;
            // deserialize the trip info from the server
            ti = DataSender<TripInfo>::receiveData(sock);
            cout << "received trip" << endl;
            driver->setTi(ti);                     // set the driver with the trip info*/
        }
        //sock->sendData("waiting_for_orders");      // tell the server that the client is waiting
        cout << "sent waiting for orders" << endl;
        sock->receiveData(buffer, sizeof(buffer));  // wait to receive the orders from the server

        // if the client received the advance order
        if (!strcmp(buffer, "9")) {
            driver->moveOneStep();                 // move the driver one step
            cout << *(driver->getCab()->getLocation()->getP());

            if (driver->getTi()->checkEnd(cab->getLocation()->getP())) { // if reached the end
                delete ti;
                driver->setTi(NULL);
                ti = NULL;
            }
        }
    } while (strcmp(buffer, "exit"));

    // delete all objects in the client
    delete cab;
    delete driver;
    return 0;
}