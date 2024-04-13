#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

#include "ipaddress.h"
#include "IPAddressReader.h"

int main(int, char **) {
    try {
        // чтение из файла
        auto readAddresses = homework_2::IPAddressReader::readIPAddresses("ip_filter.tsv", '\n');

        // обратная лексикографическая сортировка
        std::sort(readAddresses.rbegin(), readAddresses.rend());

        // вывод в cout отсортированного списка адресов
        std::copy(readAddresses.begin(),
                  readAddresses.end(),
                  std::ostream_iterator<homework_2::IPAddress>(std::cout, "\n"));

        // вывод списка адресов в которых первый байт равен 1
        std::for_each(readAddresses.begin(), readAddresses.end(), [](const auto &ipAddress) {
            const auto& bytes = ipAddress.getBytes();
            if (!bytes.empty() && bytes[0] == 1)
            {
                std::cout << ipAddress << "\n";
            }
        });

        // вывод списка адресов в которых первый байт равен 46, а второй 70
        std::for_each(readAddresses.begin(), readAddresses.end(), [](const auto &ipAddress) {
            const auto& bytes = ipAddress.getBytes();
            if (bytes.size() > 1 && bytes[0] == 46 && bytes[1] == 70)
            {
                std::cout << ipAddress << "\n";
            }
        });

        // вывод списка адресов в которых есть байт равный 46
        std::for_each(readAddresses.begin(), readAddresses.end(), [](const auto &ipAddress) {
            const std::vector<int>& bytes = ipAddress.getBytes();
            if (!bytes.empty() && std::find(bytes.begin(), bytes.end(), 46) != bytes.end())
            {
                std::cout << ipAddress << "\n";
            }
        });
    } catch (std::runtime_error& error)
    {
        std::cout << error.what() << std::endl;
    }

    return 0;
}
