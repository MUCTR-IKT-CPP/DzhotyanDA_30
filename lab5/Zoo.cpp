#include "Zoo.h"

#include <utility>

Zoo::Zoo(std::vector<Animal *> animals) {
    this->animals = std::move(animals);
}

Zoo::Zoo(Zoo& other) {
    this->animals = other.animals;
    this->owner = false;
}

Zoo::~Zoo() {
    if (!owner) return;

    for (auto a: animals) {
        delete a;
    }
}

void Zoo::inspect() {
    for (auto a: animals) {
        if (a->getState() != AnimalState::free) continue;

        if (a->isNeedEat()) {
            a->setState(AnimalState::eating);
        } else if (a->isNeedSleep()) {
            a->setState(AnimalState::sleeping);
        }
    }
}

void Zoo::simulate() {
    inspect();

    for (auto a: animals) {
        if (a->getState() == AnimalState::free) {

            auto newState = randomAnimalState(intensity);
            auto time = randInt(MIN_INTERACT_TIME, MAX_INTERACT_TIME);

            if (newState == AnimalState::interact_with_animals && !isHasOtherAnimals(a)) {
                newState = AnimalState::free;
            }

            a->setState(newState, time);
        }
        a->simulate();
    }
}

bool Zoo::isHasOtherAnimals(Animal *currentAnimal) {
    auto origType = animalType(currentAnimal);

    for (auto a: animals) {
        if (a != currentAnimal && origType == animalType(a)) {
            if (a->getState() == AnimalState::free || a->getState() == AnimalState::interact_with_animals)
                return true;
        }
    }
    return false;
}

void Zoo::printToConsole() {
    for (auto a: animals) {
        a->printToConsole();
    }
}

void Zoo::setIntensity(float newIntensity) {
    this->intensity = newIntensity;
}

void Zoo::newDay() {
    for (auto a : animals) {
        a->reset();
    }
}
