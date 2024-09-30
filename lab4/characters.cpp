#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "characters.h"

using namespace std;

Mercenary::Mercenary(Swordsman* s)
{
    character = s;
    type = s->type;
}

Mercenary::Mercenary(Wizard* w)
{
    character = w;
    type = w->type;
}

Mercenary::Mercenary(Bowman* b)
{
    character = b;
    type = b->type;
}

/**
 * Отображение информации о наемнике
 */
void Mercenary::display()
{
    if (type == "Swordsman")
    {
        Swordsman* s = static_cast<Swordsman*>(character);
        printf("Тип: Мечник, Сила: %d, Стойкость: %d, Дистанция: %d, Стоимость: %d\n", s->power, s->durability, s->distance, s->cost);
    }
    if (type == "Wizard")
    {
        Wizard* w = static_cast<Wizard*>(character);
        printf("Тип: Маг, Сила: %d, Стойкость: %d, Дистанция: %d, Стоимость: %d\n", w->power, w->durability, w->distance, w->cost);
    }
    if (type == "Bowman")
    {
        Bowman* b = static_cast<Bowman*>(character);
        printf("Тип: Стрелок, Сила: %d, Стойкость: %d, Дистанция: %d, Стоимость: %d\n", b->power, b->durability, b->distance, b->cost);
    }
}