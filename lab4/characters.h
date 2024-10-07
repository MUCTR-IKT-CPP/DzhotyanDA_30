#ifndef CHARACTERS_H
#define CHARACTERS_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Swordsman
{
    public:
        int power = 60 + rand() % 81;
        int durability = 90 + rand() % 111;
        int distance = 3 + rand() % 6;
        int cost = 30;
        string type = "Swordsman";

        int getPower() { return power; }
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
        int durability = 80;
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
