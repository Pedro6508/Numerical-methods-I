
#ifndef METODOS_NUMERICOS_OUTPUT_H
#define METODOS_NUMERICOS_OUTPUT_H
#include <vector>
#include <fmt/core.h>
#include <map>
#include <ranges>

namespace result {

    template<typename T>
    size_t MaxKeyLength(const std::map<std::string, T> &m);

    void run();
}
#endif //METODOS_NUMERICOS_OUTPUT_H
