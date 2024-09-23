#ifndef WORKER_STRUCTS_H
#define WORKER_STRUCTS_H

#include <string>

enum class Gender { male, female };

struct BirthDate
{
    int year;
    int month;
    int day;
};

struct Worker
{
    std::string full_name;
    Gender gender;
    BirthDate birth_date;
};

#endif // WORKER_STRUCTS_H