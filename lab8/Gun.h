#ifndef GUN_H
#define GUN_H

#include <iostream>
#include "Magazine.h"

class Gun {
private:
    Magazine _magazine;

    bool _gunReloadedFirstTime = true;

    int _numberOfPatronsFired = 0;

    int _numberOfMagazinesReloaded = 0;

    double _spentLoadingCartridgesIntoMagazine = 0;

    double _spentShooting = 0;

    int _subsonicNumber = 0;

    int _supersonicNumber = 0;

    int _tracingNumber = 0;

    void Shoot();

    void Reload();

public:
    Gun() {
        _magazine = Magazine();
        Reload();
        _gunReloadedFirstTime = false;
    }

    void SimulatingShootingProcess();

    void GetStats();
};

#endif // GUN_H