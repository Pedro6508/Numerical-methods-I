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
} //        Bisection

void result::printRowName(std::string name, const std::string& padding, int size) {
    using namespace fmt;
    std::string data = format("\t{:}{:}\t", name, padding, size);

    std::cout << format("|{:*^{}}|", data, size);
}

void result::printRowLabel(const std::string& padding, int size) {
    using namespace fmt;
    std::string data = format("{:^5}\t{:<8}\t{:<8}","Iter", "Result", "Err", size);
    std::cout << format("|{:^{}}|", data, size);
}
//Iter	Result	Error
void result::printRow(double result, double error, int iter, int v_size, const std::string& padding, int size) {
    using namespace fmt;
    std::string data;
    if (v_size - iter > 0) {
        data = format("[{:03d}]\t{:.6f}\t{:.6f}", iter, result, error, size);
    } else {
        data = format("[{:}]\t{:}\t{:}", "---", "--------", "--------",size);
    }

    std::cout << format("|{:^{}}|", data, size);
}

void result::run(std::map<std::string, result::MethodData> table) {
    using namespace std;

    size_t Columns = 3;
    int colSize = 28;
    int rowSize = int(MaxRowLength(table));
    const string paddingName = "  ";
    for (const auto& name: views::keys(table)) {
        printRowName(name, paddingName, colSize);
    }
    cout << "\n";

    const string paddingLabel = "";
    for (size_t i = 0; i < Columns; i++) {
        printRowLabel(paddingLabel, colSize);
    }
    cout << "\n";

    const string paddingRow = "";
    for (size_t i = 0; i < rowSize; i++) {
        for (const auto &row: views::values(table)) {
            printRow(get<0>(row[i]), get<1>(row[i]), int(i), int(row.size()), paddingRow, colSize);
        }
        cout << "\n";
    }
}
