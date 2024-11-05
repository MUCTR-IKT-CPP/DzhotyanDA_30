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
void Gun::Reload(int numberOfPatrons)
{
    while (_magazine.GetSize() < numberOfPatrons)
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

    while (patronBox.patronsCount > 0) // продолжаем, пока есть патроны в ящике
    {
        if (_magazine.IsEmpty())
        {
            int availableSpace = _magazine.GetCapacity() - _magazine.GetSize(); // вычисляем свободное место в магазине
            int reloadCount = std::min(patronBox.patronsCount, availableSpace); // выбираем минимальное из свободного места и патронов в ящике

            if (reloadCount > 0)
            {
                Reload(reloadCount);
                patronBox.patronsCount -= reloadCount;
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