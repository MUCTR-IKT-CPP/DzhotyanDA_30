#include <iostream>
#include "Cat.h"
#include "Zoo.h"
#include "Dog.h"
#include "Wombat.h"
#include "Rat.h"

Zoo *makeZoo() {
    std::vector<Animal *> animals;

    for (int i = 0; i < NUM_OF_CATS; i++) {
        animals.push_back(new Cat(NAMES[randInt(0, NUM_OF_NAMES)], randInt(MIN_CAT_YEAR_OLD, MAX_CAT_YEAR_OLD)));
    }

    for (int i = 0; i < NUM_OF_DOGS; i++) {
        animals.push_back(new Dog(NAMES[randInt(0, NUM_OF_NAMES)], randInt(MIN_DOR_YEAR_OLD, MAX_DOR_YEAR_OLD)));
    }

    for (int i = 0; i < NUM_OF_WOMBATS; i++) {
        animals.push_back(new Wombat(NAMES[randInt(0, NUM_OF_NAMES)], randInt(MIN_WOMBAT_YEAR_OLD, MAX_WOMBAT_YEAR_OLD)));
    }

    for (int i = 0; i < NUM_OF_RATS; i++) {
        animals.push_back(new Rat(NAMES[randInt(0, NUM_OF_NAMES)], randInt(MIN_RAT_YEAR_OLD, MAX_RAT_YEAR_OLD)));
    }

    return new Zoo(animals);
}

int main() {

    srand(time(nullptr));

    auto *zoo = makeZoo();

    for (int day = 0; day < 1; day++) {
        zoo->newDay();
        std::cout << std::endl << std::endl << "Day " << day + 1 << std::endl << std::endl;
        for (int hours = 0; hours < 16; hours++) {
            float intensity = randIntensity();
            zoo->setIntensity(intensity);
            std::cout << hours << " hours. Intensity " << intensity << std::endl;
            for (int minutes = 0; minutes < 60; minutes++) {
                zoo->simulate();
            }
            zoo->printToConsole();
        }
    }

    delete zoo;
}
