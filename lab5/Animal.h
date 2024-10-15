#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <utility>
#include <iostream>
#include "Constants.h"
#include "AnimalState.h"
#include "Utils.h"

/**
 * Животное
 */
class Animal {

private:

    std::string _name;

    int _age;

    int _satiety = MAX_SATIETY;

    int _fatigue = MIN_FATIGUE;

    AnimalState _state;

    int _time = 0;

public:

    /**
     * @param name имя животного
     * @param age возраст животного
     */
    Animal(std::string name, int age);

protected:

    /**
     * @return расход сытости в текущем состоянии
     */
    virtual int satietyConsumption() = 0;

    /**
     * @return расход усталости в текущем состоянии
     */
    virtual int fatigueConsumption() = 0;

    /**
     * @return время сна
     */
    virtual int getSleepingTime() = 0;

    /**
     * @return время приёма пищи
     */
    virtual int getEatingTime() = 0;

public:

    Animal(Animal &obj);

    virtual ~Animal();

    /**
     * @return имя животного
     */
    std::string getName();

    /**
     * @return возраст животного
     */
    int getAge() const;

    /**
     * @return текущий уровень сытости
     */
    int getSatiety() const;

    /**
     * @return текущий уровень усталости
     */
    int getFatigue() const;

    /**
     * @return текущее состояние
     */
    AnimalState getState();

    /**
     * Установить новое состояние
     * @param state новое состояние
     * @param time продолжительность состояния
     */
    void setState(AnimalState state, int time);

    /**
     * Установить новое состояние. Только сон или еда.
     * @param state сон или еда
     */
    void setState(AnimalState state);

    /**
     * @return true, если сытость <= THRESHOLD_SATIETY, иначе false
     */
    bool isNeedEat() const;

    /**
     * @return true, если усталость >= THRESHOLD_FATIGUE, иначе false
     */
    bool isNeedSleep() const;

    /**
     * Вывести информацию о животном в консоль
     */
    void printToConsole();

    /**
     * Шаг симуляции на 1 минуту
     */
    void simulate();

    /**
     * Сброс всех переменных к значениям по умолчанию
     */
    void reset();

protected:

    /**
     * Увеличить усталость
     */
    void addToFatigue(int added);

    /**
     * Увеличить сытость
     */
    void addToSatiety(int added);

    /**
     * Задать сытость
     */
    void setSatiety(int satiety);

    /**
     * Задать усталость
     */
    void setFatigue(int fatigue);

};


#endif // ANIMAL_H
