//
// Created by nevo on 27/12/16.
//

#include "../server/sockets/Udp.h"
#include "../server/managment/ProperInput.h"
#include "../server/tripOperations/Driver.h"
#include "../server/enum/MartialStatuesFactory.h"
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[]) {
    // create a socket for transferring data between the server and the client
    Socket *sock = new Udp(0, atoi(argv[2]));
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

    // create a driver with the user input
    Driver *driver = new Driver(id, age, MartialStatuesFactory::getMartialStatus(status),
                                experience, vehicleId);

    // serialize the driver
    std::string serial_str;
    {
        boost::iostreams::back_insert_device<std::string> inserter(serial_str);
        boost::iostreams::stream<boost::iostreams::back_insert_device<std::string> > s(inserter);
        boost::archive::binary_oarchive oa(s);
        oa << driver;
        s.flush();
    }

    // send the driver using the socket
    char buffer[1024];
    sock->sendData(serial_str);
    cout << "sent driver" << endl;
    sock->reciveData(buffer, sizeof(buffer));   // wait to receive a cab from the server
    cout << "received taxi" << endl;

    // deserialize the taxi from the server
    Taxi *cab;
    {
        boost::iostreams::basic_array_source<char> device(buffer, 1024);
        boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
        boost::archive::binary_iarchive ia(s2);
        ia >> cab;
    }
    driver->setCab(cab);                           // set the cab to the driver

    TripInfo *ti = NULL;
    // do while the server still sends orders different frmo the exit order "7"
    do {
        if (ti == NULL) {
            sock->sendData("waiting_for_trip");    // tell the server that the client is waiting
            cout << "sent waiting for trips" << endl;

            // wait to receive the trip info from the server
            sock->reciveData(buffer, sizeof(buffer));
            cout << "received trip" << endl;

            if (buffer == "9") {    // no trip info to move with
                continue;
            }
            // deserialize the trip info from the server
            {
                boost::iostreams::basic_array_source<char> device(buffer, 1024);
                boost::iostreams::stream<boost::iostreams::basic_array_source<char> > s2(device);
                boost::archive::binary_iarchive ia(s2);
                ia >> ti;
            }
            driver->setTi(ti);                     // set the driver with the trip info
        }
        sock->sendData("waiting_for_orders");      // tell the server that the client is waiting
        sock->reciveData(buffer, sizeof(buffer));  // wait to receive the orders from the server

        // if the client received the advance order
        if (buffer == "9") {
            driver->moveOneStep();                 // move the driver one step
            if (driver->getTi()->checkEnd(cab->getLocation()->getP())) { // if reached the end
                delete ti;
                driver->setTi(NULL);
                ti = NULL;
            }
        }
    } while (buffer != "exit");

    // delete all objects in the client
    if (ti != NULL) {
        delete ti;
    }
    delete cab;
    delete driver;
    return 0;
}