#include <iostream>
#include "TracingPatron.h"

TracingPatron::TracingPatron() = default;

TracingPatron::~TracingPatron() = default;

void TracingPatron::Sound() {
    std::cout << "*звук трассирующего патрона*\n";
}