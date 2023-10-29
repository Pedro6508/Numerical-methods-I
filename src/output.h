
#ifndef METODOS_NUMERICOS_OUTPUT_H
#define METODOS_NUMERICOS_OUTPUT_H
#include <vector>
#include <fmt/core.h>
#include <map>
#include <ranges>

namespace result {
    typedef std::vector<std::tuple<double, double>> MethodData;

    template<typename T>
    size_t MaxKeyLength(const std::map<std::string, T> &m);

    template<typename T>
    size_t MaxRowLength(const std::map<std::string, T> &m);

    void printRowName(std::string name, const std::string& padding, int size);

    void printRowLabel(const std::string& padding, int size);

    void printRow(double result, double error, int iter, int v_size, const std::string& padding, int size);

    void run(std::map<std::string, result::MethodData> table);
}
#endif //METODOS_NUMERICOS_OUTPUT_H
