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

    void Reload(int numberOfPatrons);

public:
    Gun() {
        _magazine = Magazine();
        Reload(_magazine.GetCapacity());
        _gunReloadedFirstTime = false;
    }

    void SimulatingShootingProcess();

    void GetStats();

    /**
     * Перегрузка оператора вывода в поток через дружественную функцию
     */
    friend std::ostream& operator<<(std::ostream &os, const Gun& gun)
    {
        os << "Gun statistics:\n";
        os << "Number of patrons fired: " << gun._numberOfPatronsFired << "\n";
        os << "Number of magazines reloaded: " << gun._numberOfMagazinesReloaded << "\n";
        os << "Time spent loading cartridges into magazine: " << gun._spentLoadingCartridgesIntoMagazine << " seconds\n";
        os << "Time spent shooting: " << gun._spentShooting << " seconds\n";
        os << "Subsonic patrons fired: " << gun._subsonicNumber << "\n";
        os << "Supersonic patrons fired: " << gun._supersonicNumber << "\n";
        os << "Tracing patrons fired: " << gun._tracingNumber << "\n";
        return os;
    }
};

#endif // GUN_H