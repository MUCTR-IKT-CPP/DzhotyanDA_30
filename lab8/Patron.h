#ifndef PATRON_H
#define PATRON_H

class Patron {
public:
    Patron() = default;

    Patron(const Patron& other);

    virtual ~Patron();
    
    virtual void Sound();
};

#endif // PATRON_H