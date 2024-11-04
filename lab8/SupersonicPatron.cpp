#include <iostream>
#include "SupersonicPatron.h"

SupersonicPatron::SupersonicPatron() = default;

SupersonicPatron::~SupersonicPatron() = default;

void SupersonicPatron::Sound() {
        std::cout << "*звук сверхзвукового патрона*\n";
    }