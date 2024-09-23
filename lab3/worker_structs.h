#ifndef WORKER_STRUCTS_H
#define WORKER_STRUCTS_H

#include <string>

enum class Gender { male, female };

struct birthDate
{
    int year;
};

struct Worker
{
    std::string full_name;
    Gender gender;
    birthDate birth_date;
};

#endif // WORKER_STRUCTS_H