#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "characters.h"
#include "guild.h"

using namespace std;

/**
 * Генерация идеальной группы наемников
 * 
 * @param maxCost предельная стоимость группы
 */
void Guild::generatePerfectGroup(int maxCost)
{
    
}

/**
 * Генерация наемников
 * 
 * @param N требуемое количество наемников
 */
void Guild::fillRandomGroup(int N)
{
    mercenaries.clear();

    srand(time(0));

    mercenaries.push_back(Mercenary(new Swordsman())); // Мечник обычный
    
    Swordsman* tank = new Swordsman(); // Мечник танк
    tank->durability = 150;
    mercenaries.push_back(Mercenary(tank));

    Swordsman* highPowerSwordsman = new Swordsman(); // Мечник, наносящий значительный урон
    highPowerSwordsman->power = 120;
    mercenaries.push_back(highPowerSwordsman);

    // Гарантированно добавляем одного мага
    Wizard* wizard = new Wizard();
    int distanceChoice = rand() % 2;
    if (distanceChoice == 1)
    {
        wizard->distance = 30;
    }
    mercenaries.push_back(wizard);

    while ((int)mercenaries.size() < N)
    {
        int randomChoice = rand() % 2;

        if (randomChoice == 0)
        {
            Wizard* wizard = new Wizard();
            int distanceChoice = rand() % 2;
            
            if (distanceChoice == 1)
            {
                wizard->distance = 30;
            }
            
            mercenaries.push_back(wizard);
        }
        else
        {
            Bowman* bowman = new Bowman();
            int distanceChoice = rand() % 2;
            
            if (distanceChoice == 1)
            {
                bowman->distance = 30;
            }

            mercenaries.push_back(bowman);
        }
    }
}

/**
 * Вывод списка наемников в гильдии
*/
void Guild::viewMercenaries()
{
    cout << "===================== Список наемников в гильдии =====================" << endl;
    for (size_t i = 0; i < mercenaries.size(); i++)
    {
        cout << i + 1 << ". ";
        mercenaries[i].display();
    }
}

/**
 * Добавление наемников в группу пользователя
 * 
 * @param group группа пользователя для наполнения
 */
void Guild::addToGroup(vector<Mercenary>& group)
{
    for (size_t i = 0; i < mercenaries.size(); i++)
    {
        group.push_back(mercenaries[i]);
    }
}