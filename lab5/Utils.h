#ifndef UTILS_H
#define UTILS_H

#include <string>
#include "AnimalState.h"

class Animal;

/**
 * Преобразовать AnimalState в std::string
 * @param state состояние
 * @return строка
 */
std::string to_string(AnimalState state);

/**
 * Вернуть тип животного в виде целого числа
 * @param animal животное
 * @return тип
 */
int animalType(Animal *animal);

/**
 * Случайное целое число
 * @param left левая граница
 * @param right правая граница
 * @return случайное целое число
 */
int randInt(int left, int right);

/**
 * Случайная интенсивность от 0 до 1
 * @return
 */
float randIntensity();

/**
 * Случайное состояние: взаимодействие с людьми, взаимодействие с животными или свободно
 * Случайное состояние зависит от интенсивности
 * @param intensity интенсивность
 * @return взаимодействие с людьми, взаимодействие с животными или свободно
 */
AnimalState randomAnimalState(float intensity);

#endif // UTILS_H
