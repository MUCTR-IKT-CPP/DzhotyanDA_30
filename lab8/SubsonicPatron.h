#ifndef SUBSONICPATRON_H
#define SUBSONICPATRON_H

#include <iostream>
#include "Patron.h"

class SubsonicPatron : public Patron {
public:
    using Patron::Patron;

    SubsonicPatron();
    
    ~SubsonicPatron() override;

    void Sound() override;
};

#endif // SUBSONICPATRON_H