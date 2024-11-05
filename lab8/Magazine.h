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
    std::queue<Patron*> GetMagazine();

    bool IsEmpty();

    int GetCapacity();

    int GetSize();

    Patron* GetPatron();

    void AddPatron(Patron* p);

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

    static Patron** GeneratePatrons() 
    {
        Patron** patrons = new Patron*[_capacity];
        
        for (int i = 0; i < _capacity; i++) {
            
            int x = rand() % AVALAIBLE_PATRONS_COUNT;

            if (_avalaibleTypesPatrons[x] == "Subsonic") {
                patrons[i] = new SubsonicPatron();
            }

            if (_avalaibleTypesPatrons[x] == "Supersonic") {
                patrons[i] = new SupersonicPatron();
            }

            if (_avalaibleTypesPatrons[x] == "Tracing") {
                patrons[i] = new TracingPatron();
            }
        }

        return patrons;
    }
};

#endif // MAGAZINE_H