#ifndef WORKER_GENERATORS_H
#define WORKER_GENERATORS_H

#include <string>
#include "worker_structs.cpp"

using namespace std;

Worker generateWorker();

string generateWorkerFullNameFemale();

string generateWorkerFullNameMale();

BirthDate generateWorkerBirthDate();

Gender generateWorkerGender();

#endif // WORKER_GENERATORS_H