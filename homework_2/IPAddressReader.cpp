//
// Created by sinigr on 13.01.2023.
//

#include "IPAddressReader.h"

#include <fstream>

namespace homework_2 {

    vector<IPAddress> IPAddressReader::readIPAddresses(const string &fileName, char delimiter = '\n') {
        vector<IPAddress> addresses;

        std::ifstream readStream(fileName);
        if (readStream.is_open()) {
            std::string line;
            while (std::getline(readStream, line, delimiter)) {
                std::string ipAddress = line.substr(0, line.find_first_of('\t'));

                if (ipAddress.empty()) {
                    throw std::runtime_error("Bad file lines format. Must be {ip address} \\t{number} \\t{number}");
                }

                addresses.emplace_back(std::move(ipAddress));
            }
        }

        readStream.close();

        return addresses;
    }
} // homework_2