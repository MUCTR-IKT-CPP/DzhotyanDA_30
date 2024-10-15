#ifndef WOMBAT_H
#define WOMBAT_H


#include "Animal.h"

/**
 * Вомбат
 */
class Wombat : public Animal {

public:

    using Animal::Animal;

    Wombat(Wombat &obj);

    ~Wombat() override;

private:

    int fatigueConsumption() override;

    int satietyConsumption() override;

    int getEatingTime() override;

    int getSleepingTime() override;

};


#endif // WOMBAT_H
