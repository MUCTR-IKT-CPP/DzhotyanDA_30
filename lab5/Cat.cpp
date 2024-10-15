#include "Cat.h"

#include <utility>

int Cat::fatigueConsumption() {
    switch (getState()) {
        case AnimalState::eating: return CAT_FATIGUE_EATING;
        case AnimalState::interact_with_people: return CAT_FATIGUE_INTERACT_WITH_PEOPLE;
        case AnimalState::interact_with_animals: return CAT_FATIGUE_INTERACT_WITH_ANIMALS;
        case AnimalState::free: return CAT_FATIGUE_PASSIVE;
        default: return 0;
    }
}

int Cat::satietyConsumption() {
    switch (getState()) {
        case AnimalState::sleeping: return CAT_SATIETY_SLEEPING;
        case AnimalState::interact_with_people: return CAT_SATIETY_INTERACT_WITH_PEOPLE;
        case AnimalState::interact_with_animals: return CAT_SATIETY_INTERACT_WITH_ANIMALS;
        case AnimalState::free: return CAT_SATIETY_PASSIVE;
        default: return 0;
    }
}

int Cat::getEatingTime() {
    return CAT_EATING_TIME;
}

int Cat::getSleepingTime() {
    return CAT_SLEEPING_TIME;
}

Cat::Cat(Cat &cat) = default;

Cat::~Cat() = default;;
