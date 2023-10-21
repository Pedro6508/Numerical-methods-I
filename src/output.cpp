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

void result::run() {
    constexpr size_t Rows = 5;
    const std::map<std::string, std::array<double, Rows>> productToOrders{
            {"LABEL A",   {100, 200, 50.5, 30,   10}},
            {"LABEL B",  {80,  10,  100,  120,  70}},
            {"LABEL C",  {130, 75,  25,   64.5, 128}},
            {"LABEL D", {70,  100, 170,  80,   90}},
            {"LABEL E",   {100, 200, 50.5, 30,   10}},
            {"LABEL F",  {80,  10,  100,  120,  70}},
            {"LABEL G",  {130, 75,  25,   64.5, 128}},
            {"LABEL H", {70,  100, 170,  80,   90}},
    };

    int colLength = MaxKeyLength(productToOrders) + 2;
    int mapRows = productToOrders.size();
    for (const auto& name : std::views::keys(productToOrders))
        std::cout << fmt::format("{:>{}}", name, colLength);
    std::cout << '\n';
    for (size_t i = 0; i < mapRows; ++i) {
        for (const auto& values : std::views::values(productToOrders)) {
            std::cout << fmt::format("{:>{}.2f}", values[i], colLength);
        }
        std::cout << '\n';
    }
}
