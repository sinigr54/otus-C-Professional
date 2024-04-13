//
// Created by sinigr on 13.01.2023.
//

#include "ipaddress.h"

#include <string>
#include <vector>
#include <utility>
#include <sstream>

namespace homework_2 {

    IPAddress::IPAddress(string address) : addressString(std::move(address)), bytes(unpackBytes(addressString, '.')) {

    }

    bool IPAddress::operator<(const IPAddress &rhs) const {
        return std::lexicographical_compare(bytes.begin(), bytes.end(), rhs.bytes.begin(), rhs.bytes.end());
    }

    bool IPAddress::operator==(const IPAddress &rhs) const {
        return bytes == rhs.bytes;
    }

    vector<int> IPAddress::unpackBytes(const string &addressString, char delimiter) {
        vector<int> bytes;
        if (addressString.empty()) {
            return bytes;
        }

        std::istringstream addressStream(addressString);
        string token;

        while (std::getline(addressStream, token, delimiter)) {
            std::stringstream converter;
            int byte;

            converter << token;
            converter >> byte;

            bytes.push_back(byte);
        }

        return bytes;
    }

    std::ostream &operator<<(std::ostream &os, const IPAddress &address) {
        os << address.addressString;
        return os;;
    }

    const vector<int> &IPAddress::getBytes() const {
        return bytes;
    }

}

