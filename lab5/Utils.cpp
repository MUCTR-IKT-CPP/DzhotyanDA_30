#include "Utils.h"
#include "Cat.h"
#include "Animal.h"
#include "Dog.h"
#include "Rat.h"
#include "Wombat.h"

std::string to_string(AnimalState state) {
    switch (state) {
        case AnimalState::sleeping:
            return "Sleeping";
        case AnimalState::interact_with_people:
            return "Interact with people";
        case AnimalState::interact_with_animals:
            return "Interact with animals";
        case AnimalState::eating:
            return "Eating";
        case AnimalState::free:
            return "Free";
    }

    return "Unknown";
}



int animalType(Animal *animal) {
    if (dynamic_cast<Cat *>(animal)) {
        return 0;
    } else if (dynamic_cast<Dog *>(animal)) {
        return 1;
    } else if (dynamic_cast<Rat *>(animal)) {
        return 2;
    } else if (dynamic_cast<Wombat *>(animal)) {
        return 3;
    }
    return -1;
}

int randInt(int left, int right) {
    return left + rand() % (right - left);
}

AnimalState randomAnimalState(float intensity) {
    int n = randInt(0, 100);
    int peopleThreshold = static_cast<int>(70 * intensity);
    int animalThreshold = static_cast<int>((100 - peopleThreshold) * 0.3);

    if (n < peopleThreshold) {
        return AnimalState::interact_with_people;
    } else if (n - peopleThreshold < animalThreshold) {
        return AnimalState::interact_with_animals;
    } else {
        return AnimalState::free;
    }
}

float randIntensity() {
    return static_cast<float>(rand()) / RAND_MAX;
}
