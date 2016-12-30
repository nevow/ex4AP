//
// DataSender.
//

#include "DataSender.h"

template<class T>
void DataSender<T>::sendData(Socket *sock, T *item) {
    std::string serial_str;
    {
        boost::iostreams::back_insert_device<std::string> inserter(serial_str);
        boost::iostreams::stream<boost::iostreams::
        back_insert_device<std::string>> s(inserter);
        boost::archive::binary_oarchive oa(s);
        oa << item;
        s.flush();
    }
    sock->sendData(serial_str);
}

template<class T>
T *DataSender<T>::receiveData(Socket *sock) {
    char buffer[1024];
    sock->reciveData(buffer, sizeof(buffer));
    T *item;
    {
        boost::iostreams::basic_array_source<char> dev(buffer, 1024);
        boost::iostreams::stream<boost::iostreams::basic_array_source<char>> s2(
                dev);
        boost::archive::binary_iarchive ia(s2);
        ia >> item;
    }
    return item;
}