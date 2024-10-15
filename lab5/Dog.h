#ifndef DOG_H
#define DOG_H


#include "Animal.h"

/**
 * Собака
 */
class Dog : public Animal {

public:

    using Animal::Animal;

    Dog(Dog &obj);

    ~Dog() override;

private:

    int satietyConsumption() override;

    int fatigueConsumption() override;

    int getSleepingTime() override;

    int getEatingTime() override;

};


#endif // DOG_H
