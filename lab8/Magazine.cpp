#include <iostream>
#include <unistd.h>
#include "Magazine.h"
#include "Patron.h"
#include "Constants.h"

const std::string Magazine::_avalaibleTypesPatrons[AVALAIBLE_PATRONS_COUNT] = {"Subsonic", "Supersonic", "Tracing"};

/**
 * Получение патрона из магазина
 */
Patron* Magazine::GetPatron() {
    sleep(TIME_GET_PATRON);
    if (!_patrons.empty()) {
        Patron* p = _patrons.front();
        _patrons.pop();
        return p;
    }
    return nullptr;
}

/**
 * Добавление патрона в магазин
 * 
 * @param  Patron*  ссылка на объект патрона
 */
void Magazine::AddPatron(Patron* p) {
    sleep(TIME_ADD_PATRON);
    _patrons.push(p);
}

/**
 * Пустой ли магазин
 * 
 * @return  bool  булевое значение, является ли магазин пустым
 */
bool Magazine::IsEmpty() {
    return _patrons.size() == 0;
}

/**
 * Получение емкости магазина
 * 
 * @return  int  емкость
 */
int Magazine::GetCapacity() {
    return _capacity;
}

/**
 * Получение количества патрон в магазине
 * 
 * @return  int  количество патрон
 */
int Magazine::GetSize() {
    return _patrons.size();
}