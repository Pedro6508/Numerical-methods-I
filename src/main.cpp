#include <iostream>
#include "./method_example.cpp"

int main() {
    using namespace method::example;
    LinearFunc func = LinearFunc(2.f, 1.f);

    float res = func.calc(2);

    std::cout << "Result: " << res << std::endl;
    return 0;
}
