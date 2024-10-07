#ifndef GUILD_H
#define GUILD_H

#include <iostream>
#include <vector>
#include "characters.h"

class Guild
{
    public:
        vector<Mercenary> mercenaries;

        void generatePerfectGroup(int maxCost);
        void fillRandomGroup(int N);
        void viewMercenaries();
        void addToGroup(vector<Mercenary>& group);
};

#endif // GUILD_H