//
// Created by sinigr on 13.01.2023.
//

#ifndef HOMEWORK_2_IPADDRESSREADER_H
#define HOMEWORK_2_IPADDRESSREADER_H

#include "ipaddress.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

namespace homework_2 {

    class IPAddressReader {
    public:

        static vector<IPAddress> readIPAddresses(const string& fileName, char delimiter);
    };

} // homework_2

#endif //HOMEWORK_2_IPADDRESSREADER_H
