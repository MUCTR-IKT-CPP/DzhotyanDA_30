#ifndef CONSTANTS_H
#define CONSTANTS_H

const int MIN_SATIETY = 0;
const int MAX_SATIETY = 1000;
const int THRESHOLD_SATIETY = 20;

const int MIN_FATIGUE = 0;
const int MAX_FATIGUE = 1000;
const int THRESHOLD_FATIGUE = 80;

const std::string NAMES[]{
        "Tomas",
        "Bon",
        "Rich",
        "Jassy",
        "Linda",
        "Graf",
        "Uta",
        "Bublic",
        "Nika",
        "Jack",
        "Sonya",
        "Jonny",
        "Gerda",
        "Miha",
        "Rex"
};
const int NUM_OF_NAMES = 15;

//// RAND CONFIG ////

const int NUM_OF_CATS = 2;
const int NUM_OF_DOGS = 2;
const int NUM_OF_WOMBATS = 2;
const int NUM_OF_RATS = 2;

const int MIN_INTERACT_TIME = 5;
const int MAX_INTERACT_TIME = 30;

//// CAT ////

const int MIN_CAT_YEAR_OLD = 1;
const int MAX_CAT_YEAR_OLD = 20;

const int CAT_FATIGUE_INTERACT_WITH_PEOPLE = 6;
const int CAT_SATIETY_INTERACT_WITH_PEOPLE = -4;

const int CAT_FATIGUE_INTERACT_WITH_ANIMALS = 4;
const int CAT_SATIETY_INTERACT_WITH_ANIMALS = -3;

const int CAT_FATIGUE_PASSIVE = 3;
const int CAT_SATIETY_PASSIVE = -2;

const int CAT_SATIETY_SLEEPING = -1;

const int CAT_FATIGUE_EATING = 3;

const int CAT_SLEEPING_TIME = 45;
const int CAT_EATING_TIME = 90;

//// DOG ////

const int MIN_DOR_YEAR_OLD = 1;
const int MAX_DOR_YEAR_OLD = 20;

const int DOG_FATIGUE_INTERACT_WITH_PEOPLE = 8;
const int DOG_SATIETY_INTERACT_WITH_PEOPLE = -5;

const int DOG_FATIGUE_INTERACT_WITH_ANIMALS = 5;
const int DOG_SATIETY_INTERACT_WITH_ANIMALS = -3;

const int DOG_FATIGUE_PASSIVE = 2;
const int DOG_SATIETY_PASSIVE = -2;

const int DOG_SATIETY_SLEEPING = -2;

const int DOG_FATIGUE_EATING = 5;

const int DOG_SLEEPING_TIME = 90;
const int DOG_EATING_TIME = 20;

//// WOMBAT ////

const int MIN_WOMBAT_YEAR_OLD = 1;
const int MAX_WOMBAT_YEAR_OLD = 25;

const int WOMBAT_FATIGUE_INTERACT_WITH_PEOPLE = 13;
const int WOMBAT_SATIETY_INTERACT_WITH_PEOPLE = -10;

const int WOMBAT_FATIGUE_INTERACT_WITH_ANIMALS = 9;
const int WOMBAT_SATIETY_INTERACT_WITH_ANIMALS = -6;

const int WOMBAT_FATIGUE_PASSIVE = 6;
const int WOMBAT_SATIETY_PASSIVE = -3;

const int WOMBAT_SATIETY_SLEEPING = -5;

const int WOMBAT_FATIGUE_EATING = 9;

const int WOMBAT_SLEEPING_TIME = 60;
const int WOMBAT_EATING_TIME = 40;

//// RAT ////

const int MIN_RAT_YEAR_OLD = 1;
const int MAX_RAT_YEAR_OLD = 3;

const int RAT_FATIGUE_INTERACT_WITH_PEOPLE = 20;
const int RAT_SATIETY_INTERACT_WITH_PEOPLE = -20;

const int RAT_FATIGUE_INTERACT_WITH_ANIMALS = 10;
const int RAT_SATIETY_INTERACT_WITH_ANIMALS = -10;

const int RAT_FATIGUE_PASSIVE = 5;
const int RAT_SATIETY_PASSIVE = -5;

const int RAT_SATIETY_SLEEPING = -5;

const int RAT_FATIGUE_EATING = 10;

const int RAT_SLEEPING_TIME = 45;
const int RAT_EATING_TIME = 10;


#endif // CONSTANTS_H
