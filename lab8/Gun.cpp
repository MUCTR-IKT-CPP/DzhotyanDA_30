#include <unistd.h>
#include "Gun.h"
#include "PatronBox.h"
#include "Constants.h"

using std::cout;
using std::endl;

/**
 * Выстрел
 */
void Gun::Shoot()
{
    Patron* patron = _magazine.GetPatron();
    if (patron) 
    {
        sleep(TIME_SHOOT);
        patron->Sound();
        _numberOfPatronsFired++;
        _spentShooting += TIME_SHOOT;
    
        if (dynamic_cast<SubsonicPatron*>(patron))
        {
            _subsonicNumber++;
        }
        else if (dynamic_cast<SupersonicPatron*>(patron))
        {
            _supersonicNumber++;
        }
        else if (dynamic_cast<TracingPatron*>(patron))
        {
            _tracingNumber++;
        }
    } 
    else 
    {
        cout << "В магазине нет патронов" << endl;
    }
}

/**
 * Перезарядка
 */
void Gun::Reload()
{
    while (_magazine.GetSize() < _magazine.GetCapacity())
    {
        Patron* patron = Magazine().GeneratePatron();
        _magazine.AddPatron(patron);
        _spentLoadingCartridgesIntoMagazine += TIME_ADD_PATRON;
    }

    _numberOfMagazinesReloaded++;

    cout << "Оружие перезаряжено" << endl;
}

/**
 * Симмуляция процесса стрельбы
 */
void Gun::SimulatingShootingProcess()
{
    PatronBox patronBox = PatronBox();

    cout << "В ящике " << patronBox.patronsCount << " патрон" << endl;

    while (patronBox.patronsCount > 0 || !_magazine.IsEmpty())
    {
        if (_magazine.IsEmpty())
        {
            if (patronBox.patronsCount > 0)
            {
                Reload();
                
                if (patronBox.patronsCount < _magazine.GetCapacity())
                {
                } 
            }
            else
            {
                break;
            }
        }
        else
        {
            Shoot();
        }
    }

    if (!_magazine.IsEmpty())
    {
        while (_magazine.GetSize() > 0)
        {
            Shoot();
        }
    }
}

/**
 * Получение статистики по стрельбе
 */
void Gun::GetStats()
{
    cout << "######## Статистика ########" << endl;
    cout << "Суммарное количество отстрелянных патронов: " << _numberOfPatronsFired << endl;
    cout << "Суммарное количество перезаряженных магазинов: " << _numberOfMagazinesReloaded << endl;
    cout << "Суммарное время потраченное на зарядку патронов в магазин: " << _spentLoadingCartridgesIntoMagazine << endl;
    cout << "Суммарное время стрельбы: " << _spentShooting << endl;

    cout << "Количество каждого типа патронов:";
    cout << " Сверхзвуковых = " << _supersonicNumber << ",";
    cout << " Дозвуковых = " << _subsonicNumber << ",";
    cout << " Трассирующих = " << _tracingNumber << endl;
}