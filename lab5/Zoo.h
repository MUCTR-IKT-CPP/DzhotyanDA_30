#ifndef ZOO_H
#define ZOO_H

#include <vector>
#include "Animal.h"
#include "Cat.h"

class Zoo {

private:

    std::vector<Animal *> animals;

    float intensity = 0.5f;

    bool owner = true;

public:

    /**
    * @param animals животные в этом зоопарке
    */
    Zoo(std::vector<Animal *> animals);

    Zoo(Zoo &obj);

    ~Zoo();

    /**
     * @param newIntensity новая интенсивность
     */
    void setIntensity(float newIntensity);

    /**
     * Если животное свободно и ему нужно спать или есть, то оно начинает спать или есть
     */
    void inspect();

    /**
     * Если животное свободно, то установить новое случайное состояние с случайным временем
     * Симулировать жизнь животного
     */
    void simulate();

    /**
     * Сбросить всех животных
     */
    void newDay();

    /**
     * Вывести всех животных в консоль
     */
    void printToConsole();

private:

    /**
     * @param currentAnimal животное
     * @return true, если есть свободные животные, иначе false
     */
    bool isHasOtherAnimals(Animal *currentAnimal);

};


#endif // ZOO_H
