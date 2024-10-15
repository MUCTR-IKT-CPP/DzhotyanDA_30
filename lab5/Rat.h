#ifndef RAT_H
#define RAT_H


#include "Animal.h"

/**
 * Крыса
 */
class Rat : public Animal {

public:
    using Animal::Animal;

    Rat(Rat &obj);

    ~Rat() override;

private:

    int satietyConsumption() override;

    int fatigueConsumption() override;

    int getSleepingTime() override;

    int getEatingTime() override;
};


#endif // RAT_H
