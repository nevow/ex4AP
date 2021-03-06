// Socket class.
// creating socket, close socket and method prints the errors occurs while
// creating sockets, in all the different methods involved

#include "Socket.h"
#include <unistd.h>


#define NONE 0

/**
 * creating new Socket object, with the computer ip,
 * and no port number and socket descriptor, 0 backlogs.
 */
Socket::Socket() {
    this->ip_address = IP;
    this->backLog = NONE;
    this->socketDescriptor = NONE;
    this->isServer = true;
    this->port_number = NONE;
}

/**
 * default destructor
 */
Socket::~Socket() {
    close(this->socketDescriptor);
}