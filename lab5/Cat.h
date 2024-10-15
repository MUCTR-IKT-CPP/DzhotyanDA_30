#ifndef CAT_H
#define CAT_H

#include "Animal.h"

/**
 * Собака
 */
class Cat : public Animal {

public:

    using Animal::Animal;

    Cat(Cat &cat);

    ~Cat() override;

private:
    int fatigueConsumption() override;

    int satietyConsumption() override;

    int getEatingTime() override;

    int getSleepingTime() override;
};


#endif // CAT_H