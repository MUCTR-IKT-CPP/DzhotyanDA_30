#ifndef PATRONBOX_H
#define PATRONBOX_H

#include <stdlib.h>
#include "Constants.h"

class PatronBox {
private:
    int _minPatronCountInBox = MIN_PATRON_COUNT_IN_BOX;
    int _maxPatronCountInBox = MAX_PATRON_COUNT_IN_BOX;

public:
    int patronsCount;

    PatronBox() {
        patronsCount = MIN_PATRON_COUNT_IN_BOX + (rand() % MAX_PATRON_COUNT_IN_BOX);
    }
};

#endif // PATRONBOX_H