#include "Gun.h"
#include "PatronBox.h"
#include "Constants.h"

using std::cout;
using std::endl;

void Gun::Shoot() {
    Patron* patron = _magazine.GetPatron();
    if (patron) {
        patron->Sound();
    } else {
        std::cout << "В магазине нет патронов" << std::endl;
    }
}

/*void Gun::Reload(Patron** arr) {
    for (int i = 0; i < _magazine.GetCapacity(); i++) {
        _magazine.AddPatron(arr[i]);
    }
        
    if (!_gunReloadedFirstTime) {
        std::cout << "Оружие перезаряжено" << std::endl;
    }
}*/

void Gun::Reload()
{
    while (_magazine.GetSize() < _magazine.GetCapacity())
    {
        Patron* patron = Magazine().GeneratePatron();
        _magazine.AddPatron(patron);
    }

    cout << "Оружие перезаряжено" << endl;
}

void Gun::SimulatingShootingProcess()
{
    PatronBox patronBox = PatronBox();

    cout << "В ящике " << patronBox.patronsCount << " патрон" << endl;

    while (patronBox.patronsCount > 0)
    {
        if (_magazine.IsEmpty())
        {
            //Patron** patrons = Magazine().GeneratePatrons();
            
            //Reload(patrons);

            Reload();

            patronBox.patronsCount -= _magazine.GetCapacity();
        }
        else
        {
            Shoot();
        }
    }
}