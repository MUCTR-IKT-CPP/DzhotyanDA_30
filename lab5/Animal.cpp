#include "Animal.h"

Animal::Animal(std::string name, int age) {
    this->_name = std::move(name);
    this->_age = age;
    this->_state = AnimalState::free;
}

Animal::Animal(Animal &obj) {
    this->_name = std::move(obj._name);
    this->_age = obj._age;
    this->_state = obj._state;
    this->_satiety = obj._satiety;
    this->_fatigue = obj._fatigue;
}

std::string Animal::getName() {
    return _name;
}

int Animal::getAge() const {
    return _age;
}

int Animal::getSatiety() const {
    return _satiety;
}

int Animal::getFatigue() const {
    return _fatigue;
}

bool Animal::isNeedEat() const {
    return _satiety < THRESHOLD_SATIETY;
}

bool Animal::isNeedSleep() const {
    return _fatigue > THRESHOLD_FATIGUE;
}

void Animal::setSatiety(int satiety) {
    _satiety = satiety > MAX_SATIETY ? MAX_SATIETY : (satiety < MIN_SATIETY ? MIN_SATIETY : satiety);
}

void Animal::setFatigue(int fatigue) {
    _fatigue = fatigue > MAX_FATIGUE ? MAX_FATIGUE : (fatigue < MIN_FATIGUE ? MIN_FATIGUE : fatigue);
}

AnimalState Animal::getState() {
    return _state;
}

void Animal::addToFatigue(int added) {
    setFatigue(_fatigue + added);
}

void Animal::addToSatiety(int added) {
    setSatiety(_satiety += added);
}

void Animal::printToConsole() {
    std::cout << "Name: " << _name << ", " << _age << " year old." << std::endl
              << "satiety: " << _satiety << ", fatigue: " << _fatigue << std::endl
              << "state: " << to_string(_state) << std::endl
              << "--------------------------------" << std::endl;
}

void Animal::simulate() {

    addToFatigue(fatigueConsumption());
    addToSatiety(satietyConsumption());

    _time -= 1;
    if (_time <= 0) {

        if (_state == AnimalState::sleeping) {
            _fatigue = MIN_FATIGUE;
        } else if (_state == AnimalState::eating) {
            _satiety = MAX_SATIETY;
        }

        _state = AnimalState::free;
    }
}

void Animal::setState(AnimalState state, int time) {
    if (_state != AnimalState::free && state != AnimalState::free) {
        std::cout << "Illegal state. Current state not free." << std::endl;
        exit(2);
    }

    _state = state;
    _time = time;
}

void Animal::setState(AnimalState state) {
    if (state != AnimalState::sleeping && state != AnimalState::eating) {
        std::cout << "Illegal argument. Only sleeping or eating state" << std::endl;
        exit(3);
    }
    if (_state != AnimalState::free) {
        std::cout << "Illegal state. Current state not free." << std::endl;
        exit(2);
    }

    _state = state;
    _time = state == AnimalState::sleeping ? getSleepingTime() : getEatingTime();
}

void Animal::reset() {
    _state = AnimalState::free;
    _fatigue = MIN_FATIGUE;
    _satiety = MAX_SATIETY;
    _time = 0;
}


Animal::~Animal() = default;