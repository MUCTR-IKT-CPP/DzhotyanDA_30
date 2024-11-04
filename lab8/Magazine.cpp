#include <iostream>
#include <unistd.h>
#include "Magazine.h"
#include "Patron.h"
#include "Constants.h"

const std::string Magazine::_avalaibleTypesPatrons[AVALAIBLE_PATRONS_COUNT] = {"Subsonic", "Supersonic", "Tracing"};

std::queue<Patron*> Magazine::GetMagazine() {
    return _patrons;
}

Patron* Magazine::GetPatron() {
    sleep(1);
    if (!_patrons.empty()) {
        Patron* p = _patrons.front();
        _patrons.pop();
        return p;
    }
    return nullptr; 
}

void Magazine::AddPatron(Patron* p) {
    sleep(2);
    _patrons.push(p);
}

int Magazine::GetCapacity() {
    return _capacity;
}