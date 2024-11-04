#ifndef GUN_H
#define GUN_H

#include <iostream>
#include "Magazine.h"

class Gun {
private:
    Magazine _magazine;
    bool _gunReloadedFirstTime = false;

public:
    Gun(Patron** patrons) {
        _magazine = Magazine();
        Reload(patrons);
        _gunReloadedFirstTime = true;
    }

    void Shoot();

    void Reload(Patron** arr);
};

#endif // GUN_H