#include "Wombat.h"

#include <utility>

Wombat::Wombat(Wombat &obj) = default;

Wombat::~Wombat() = default;

int Wombat::fatigueConsumption() {
    switch (getState()) {
        case AnimalState::eating: return WOMBAT_FATIGUE_EATING;
        case AnimalState::interact_with_people: return WOMBAT_FATIGUE_INTERACT_WITH_PEOPLE;
        case AnimalState::interact_with_animals: return WOMBAT_FATIGUE_INTERACT_WITH_ANIMALS;
        case AnimalState::free: return WOMBAT_FATIGUE_PASSIVE;
        default: return 0;
    }
}

int Wombat::satietyConsumption() {
    switch (getState()) {
        case AnimalState::sleeping: return WOMBAT_SATIETY_SLEEPING;
        case AnimalState::interact_with_people: return WOMBAT_SATIETY_INTERACT_WITH_PEOPLE;
        case AnimalState::interact_with_animals: return WOMBAT_SATIETY_INTERACT_WITH_ANIMALS;
        case AnimalState::free: return WOMBAT_SATIETY_PASSIVE;
        default: return 0;
    }
}

int Wombat::getEatingTime() {
    return WOMBAT_EATING_TIME;
}

int Wombat::getSleepingTime() {
    return WOMBAT_SLEEPING_TIME;
}
