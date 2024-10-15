#include "Dog.h"

#include <utility>

int Dog::satietyConsumption() {
    switch (getState()) {
        case AnimalState::sleeping: return DOG_SATIETY_SLEEPING;
        case AnimalState::interact_with_people: return DOG_SATIETY_INTERACT_WITH_PEOPLE;
        case AnimalState::interact_with_animals: return DOG_SATIETY_INTERACT_WITH_ANIMALS;
        case AnimalState::free: return DOG_SATIETY_PASSIVE;
        default: return 0;
    }
}

int Dog::fatigueConsumption() {
    switch (getState()) {
        case AnimalState::eating: return DOG_FATIGUE_EATING;
        case AnimalState::interact_with_people: return DOG_FATIGUE_INTERACT_WITH_PEOPLE;
        case AnimalState::interact_with_animals: return DOG_FATIGUE_INTERACT_WITH_ANIMALS;
        case AnimalState::free: return DOG_FATIGUE_PASSIVE;
        default: return 0;
    }
}

int Dog::getEatingTime() {
    return DOG_EATING_TIME;
}

int Dog::getSleepingTime() {
    return DOG_SLEEPING_TIME;
}


Dog::Dog(Dog &obj) = default;

Dog::~Dog() = default;


