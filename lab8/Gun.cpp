#include "Gun.h"

void Gun::Shoot() {
    Patron* patron = _magazine.GetPatron();
    if (patron) {
        patron->Sound();
        std::cout << "Выстрел" << std::endl << "Патрон в магазине: " << _magazine.GetMagazine().size() << std::endl;
    } else {
        std::cout << "В магазине нет патронов" << std::endl;
    }
}

void Gun::Reload(Patron** arr) {
    for (int i = 0; i < _magazine.GetCapacity(); i++) {
        _magazine.AddPatron(arr[i]);
    }
        
    if (!_gunReloadedFirstTime) {
        std::cout << "Оружие перезаряжено" << std::endl;
    }
}