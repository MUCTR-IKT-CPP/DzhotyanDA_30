#ifndef WORKER_FUNCTIONS_H
#define WORKER_FUNCTIONS_H

#include <string>
#include <vector>
#include "worker_structs.cpp"

using namespace std;

string genderToString(Gender gender);

vector<Worker> findWorkerByFullNameSubstring(vector<Worker> workers, string input_full_name);

vector<Worker> sortWorkersByAge(vector<Worker> workers);

vector<Worker> makeSliceWorkersByAge(vector<Worker> workers, int minYear, int maxYear);

vector<vector<Worker>> distributeWorkersByGenderAndAge(vector<Worker> workers);

void printWorkers(vector<Worker> workers);

void printGroupsWorkers(vector<vector<Worker>> groups);

#endif // WORKER_FUNCTIONS_H