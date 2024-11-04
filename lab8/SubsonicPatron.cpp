#include <iostream>
#include "SubsonicPatron.h"

SubsonicPatron::SubsonicPatron() = default;

SubsonicPatron::~SubsonicPatron() = default;

void SubsonicPatron::Sound() {
    std::cout << "*звук дозвукового патрона*\n";
}