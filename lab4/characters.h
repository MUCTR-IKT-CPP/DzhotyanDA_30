#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Swordsman
{
    public:
        int power = 80;
        int durability = 100;
        int distance = 5;
        int cost = 30;
        string type = "Swordsman";
};

class Wizard
{
    public:
        int power = 120;
        int durability = 60;
        int distance = 20;
        int cost = 50;
        string type = "Wizard";
};

class Bowman
{
    public:
        int power = 100;
        int durability = 120;
        int distance = 20;
        int cost = 40;
        string type = "Bowman";
};

class Mercenary
{
    public:
        void* character;
        string type;

        Mercenary(Swordsman* s);
        Mercenary(Wizard* w);
        Mercenary(Bowman* b);
        void display();
};

#endif // CHARACTERS_H
