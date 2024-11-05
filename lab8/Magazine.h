#ifndef MAGAZINE_H
#define MAGAZINE_H

#include <queue>
#include <unistd.h>
#include <cstdlib>
#include "Constants.h"
#include "Patron.h"
#include "SubsonicPatron.h"
#include "SupersonicPatron.h"
#include "TracingPatron.h"

class Magazine {
private:
    std::queue<Patron*> _patrons;
    
    static const int _capacity = MAGAZINE_CAPACITY;

    static const std::string _avalaibleTypesPatrons[AVALAIBLE_PATRONS_COUNT]; 

public:
    bool IsEmpty();

    int GetCapacity();

    int GetSize();

    Patron* GetPatron();

    void AddPatron(Patron* p);

    /**
     * Генерация патрона
     * 
     * @return  Patron*  Ссылка на объект патрон
     */
    static Patron* GeneratePatron()
    {
        int x = rand() % AVALAIBLE_PATRONS_COUNT;

        if (_avalaibleTypesPatrons[x] == "Subsonic") {
            return new SubsonicPatron();
        }

        if (_avalaibleTypesPatrons[x] == "Supersonic") {
            return new SupersonicPatron();
        }

        if (_avalaibleTypesPatrons[x] == "Tracing") {
            return new TracingPatron();
        }

        return nullptr;
    }
};

#endif // MAGAZINE_H