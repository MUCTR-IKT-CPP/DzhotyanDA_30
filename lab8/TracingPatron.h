#ifndef TRACINGPATRON_H
#define TRACINGPATRON_H

#include <iostream>
#include "Patron.h"

class TracingPatron : public Patron {
public:
    using Patron::Patron;

    TracingPatron();
    
    ~TracingPatron() override;

    void Sound() override;
};

#endif // TRACINGPATRON_H