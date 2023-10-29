#define FMT_HEADER_ONLY
#include <iostream>
#include <vector>
#include <fmt/core.h>
#include <map>
#include <ranges>
#include "output.h"

template<typename T>
size_t result::MaxKeyLength(const std::map<std::string, T> &m) {
    auto res = std::ranges::max_element(std::views::keys(m),
        [](const auto &a, const auto &b) {
            return a.length() < b.length();
        });
    return (*res).length();
}

template<typename T>
size_t result::MaxRowLength(const std::map<std::string, T> &m) {
    auto res = std::ranges::max_element(std::views::values(m),
        [](const auto &a, const auto &b) {
            return a.size() < b.size();
        });
    return (*res).size();
}



void result::printRowName(std::string name, const std::string& padding, int size) {
    using namespace fmt;
    std::cout << format("{}{}{}", padding, name, padding, size);

}

void result::printRowLabel(const std::string& padding, int size) {
    using namespace fmt;
    std::cout << padding;
    std::cout << format("{:}","Iter\tResult\tError", size);
}
//Iter	Result	Error
void result::printRow(double result, double error, int iter, int v_size, const std::string& padding, int size) {
    using namespace fmt;
    std::cout << padding;
    if (v_size - iter > 0) {
        std::cout << format("[{:02d}]\t{:.2f}\t{:.2f}", iter, result, error, size);
    } else {
        std::cout << format("[{:}]\t{:}\t{:}", "--", "----", "----",size);
    }
}

void result::run(std::map<std::string, result::MethodData> table) {
    using namespace std;

    size_t Columns = 3;
    int colSize = 35;
    int rowSize = int(MaxRowLength(table));
    const string padding = "\t\t";
    std::cout << padding;
    for (const auto& name: views::keys(table)) {
        printRowName(name, padding, colSize);
    }
    cout << "\n";

    for (size_t i = 0; i < Columns; i++) {
        printRowLabel(padding, colSize);
    }
    cout << "\n";

    for (size_t i = 0; i < rowSize; i++) {
        for (const auto &row: views::values(table)) {
            printRow(get<0>(row[i]), get<1>(row[i]), int(i), int(row.size()), padding, colSize);
        }
        cout << "\n";
    }
}
