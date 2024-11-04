#include <iostream>
#include "Patron.h"

Patron::Patron(const Patron& other) = default;

Patron::~Patron() = default;

void Patron::Sound() {
    std::cout << "Звук патрона\n";
}