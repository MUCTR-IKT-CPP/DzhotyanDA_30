#ifndef SUPERSONICPATRON_H
#define SUPERSONICPATRON_H

#include <iostream>
#include "Patron.h"

class SupersonicPatron : public Patron {
public:
    using Patron::Patron;
    
    SupersonicPatron();
    
    ~SupersonicPatron() override;

    void Sound() override;
};

#endif // SUPERSONICPATRON_H