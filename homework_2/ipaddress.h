//
// Created by sinigr on 13.01.2023.
//

#ifndef HOMEWORK_2_IPADDRESS_H
#define HOMEWORK_2_IPADDRESS_H

#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::ostream;

namespace homework_2 {

    class IPAddress {

    public:

        explicit IPAddress(string address);

        const vector<int>& getBytes() const;

        bool operator<(const IPAddress &rhs) const;

        bool operator>(const IPAddress &rhs) const {
            return rhs < *this;
        }

        bool operator<=(const IPAddress &rhs) const {
            return !(rhs < *this);
        }

        bool operator>=(const IPAddress &rhs) const {
            return !(*this < rhs);
        }

        bool operator==(const IPAddress &rhs) const;

        bool operator!=(const IPAddress &rhs) const {
            return !(rhs == *this);
        }

        friend std::ostream &operator<<(std::ostream &os, const IPAddress &address);

    private:
        string addressString;
        vector<int> bytes;

        static vector<int> unpackBytes(const string &addressString, char delimiter);
    };



} // homework_2

#endif //HOMEWORK_2_IPADDRESS_H
