#include "Rat.h"

#include <utility>

Rat::Rat(Rat &obj) = default;

Rat::~Rat() = default;

int Rat::satietyConsumption() {
    switch (getState()) {
        case AnimalState::sleeping: return RAT_SATIETY_SLEEPING;
        case AnimalState::interact_with_people: return RAT_SATIETY_INTERACT_WITH_PEOPLE;
        case AnimalState::interact_with_animals: return RAT_SATIETY_INTERACT_WITH_ANIMALS;
        case AnimalState::free: return RAT_SATIETY_PASSIVE;
        default: return 0;
    }
}

int Rat::fatigueConsumption() {
    switch (getState()) {
        case AnimalState::eating: return RAT_FATIGUE_EATING;
        case AnimalState::interact_with_people: return RAT_FATIGUE_INTERACT_WITH_PEOPLE;
        case AnimalState::interact_with_animals: return RAT_FATIGUE_INTERACT_WITH_ANIMALS;
        case AnimalState::free: return RAT_FATIGUE_PASSIVE;
        default: return 0;
    }
}

int Rat::getEatingTime() {
    return RAT_EATING_TIME;
}

int Rat::getSleepingTime() {
    return RAT_SLEEPING_TIME;
}
