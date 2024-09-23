#ifndef WORKER_FUNCTIONS_H
#define WORKER_FUNCTIONS_H

#include <iostream>
#include <stdio.h>
#include <vector>
#include "worker_structs.h"

using namespace std;

string genderToString(Gender gender);

/**
 * Выводит информацию о работнике по ФИО
 *
 * @param   *workers            массив работников
 * @param   number_workers      количество работников
 * @param   full_name           ФИО работника
 */
vector<Worker> findWorkerByFullNameSubstring(vector<Worker> workers, string input_full_name)
{
      vector<Worker> result_workers;
      for (int i = 0; i < workers.size(); i++)
      {
            if (workers[i].full_name.find(input_full_name) == 0)
            {
                  result_workers.push_back(workers[i]);
            }
      }
      return result_workers;
}

/**
 * Сортирует вектор работников по возрасту
 *
 * @param   workers     вектор работников
 * @return              возвращает вектор отсортированных работников
 */
vector<Worker> sortWorkersByAge(vector<Worker> workers)
{
      int size = workers.size();

      const double factor = 1.247;
      int step = size / factor - 1;

      while (step >= 1)
      {
            for (int i = 0; i + step < size; i++)
            {
                  if (workers[i].birth_date.year < workers[i + step].birth_date.year)
                  {
                        swap(workers[i], workers[i + step]);
                  }
            }
            step /= factor;
      }

      return workers;
}

/**
 * Формирует срез работников из вектора по году рождения (больше или меньше)
 *
 * @param    workers     вектор работников
 * @param    minYear     начальный год
 * @param    maxYear     конечный год
 * @return               возвращает вектор работников
 */
vector<Worker> makeSliceWorkersByAge(vector<Worker> workers, int minYear, int maxYear)
{
      vector<Worker> selected_workers;
      for (int i = 0; i < workers.size(); i++)
      {
            if (minYear < workers[i].birth_date.year && workers[i].birth_date.year < maxYear)
            {
                  selected_workers.push_back(workers[i]);
            }
      }
      return selected_workers;
}

/**
 * Распределение работников по полу и возрастным группам (группы выбираются с шагом не менее 5 лет)
 * 
 * @param   workers     вектор работников
 */
void distributeWorkersByGenderAndAge(vector<Worker> workers)
{
      vector<vector<Worker>> groups;
      for (int i = 0; i < workers.size(); i++)
      {
            for (int j = 0; j < groups.size(); j++)
            {
                  if (groups[j].size() == 0)
                  {
                        groups[j].push_back(workers[i]);
                  }
                  else if (groups[j][0].birth_date.year - workers[i].birth_date.year <= 5 && groups[j][0].gender == workers[i].gender)
                  {
                              groups[j].push_back(workers[i]);
                  }
            }
      }

      for (int i = 0; i < groups.size(); i++)
      {
            printf("Группа %d:\n", i + 1);
            for (int j = 0; j < groups[i].size(); j++)
            {
                  printf("Работник %d -> ФИО: %s, Пол: %s, Год рождения: %d\n", j + 1, workers[j].full_name.c_str(), genderToString(workers[j].gender).c_str(), workers[j].birth_date.year);
            }
      }
}

/**
 * Вывод списка работников
 * 
 * @param workers вектор работников
 */
void printWorkers(vector<Worker> workers)
{
      for (int i = 0; i < workers.size(); i++)
            printf("Работник %d -> ФИО: %s, Пол: %s, Год рождения: %d\n", i + 1, workers[i].full_name.c_str(), genderToString(workers[i].gender).c_str(), workers[i].birth_date.year);
}

/**
 * Переводит значение Gender в строку
 *
 * @param gender   объект Gender
 * @return         строка о поле
*/
string genderToString(Gender gender)
{
      return gender == Gender::male ? "МУЖ" : "ЖЕН";
}

#endif // WORKER_FUNCTIONS_H