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
size_t MaxRowLength(const std::map<std::string, T> &m) {
    auto res = std::ranges::max_element(std::views::values(m),
        [](const auto &a, const auto &b) {
            return a.size() < b.size();
        });
    return (*res).size();
}

typedef std::vector<std::tuple<double, double>> MethodData;

void printRowName(std::string name, const std::string& padding, int size) {
    using namespace fmt;
    std::cout << format("{:{}}", name, size);
    std::cout << padding;
}

void printRowLabel(const std::string& padding, int size) {
    using namespace fmt;

    std::cout << format("{:{}}","Result\tError", size);
    std::cout << padding;
}

void printRow(double result, double error, int relativePos, const std::string& padding, int size) {
    using namespace fmt;
    if (relativePos > 0) {
        std::cout << format("{:.2f}\t{:.2f}", result, error, size);
    } else {
        std::cout << format("{:{}}", "End", size);
    }
    std::cout << padding;
}

void result::run() {
    using namespace std;

    constexpr size_t Rows = 5;
    const MethodData bisectionMethod = {{1, 1}, {2, 2}, {4, 4}, {8, 8}};
    const MethodData newtonRaphsonMethod = {{1, 1}, {5, 5}, {25, 25}};
    const MethodData falsePositionMethod = {{1, 1}, {3, 3}, {9, 9}, {27,27}, {81, 81}, {243, 243}};

    const map<string, MethodData> table{
            {"Bisection", bisectionMethod},
            {"False-Position", falsePositionMethod},
            {"Newton-Raphson", newtonRaphsonMethod},
    };

    size_t Columns = 3;
    int colSize = int(MaxKeyLength(table));
    int rowSize = int(MaxRowLength(table));
    const string padding = "\t\t";
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
            printRow(get<0>(row[i]), get<1>(row[i]), int(row.size()) - int(i), padding, colSize);
        }
        cout << "\n";
    }
}
