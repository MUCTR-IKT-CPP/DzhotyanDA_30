#include <iostream>
#include <stdio.h>
#include <vector>
#include <tuple>
#include <map>
#include "worker_structs.cpp"
#include "worker_functions.h"

using namespace std;

// Перегрузка оператора < для сравнения объектов BirthDate
bool operator < (const BirthDate& a, const BirthDate& b) {
  return std::tie(a.year, a.month, a.day) < std::tie(b.year, b.month, b.day);
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

/**
 * Нахождение информацию о работнике по ФИО (частично)
 *
 * @param   workers             вектор работников
 * @param   input_full_name     ФИО работника
 * @return                      вектор найденных работников
 */
vector<Worker> findWorkerByFullNameSubstring(vector<Worker> workers, string input_full_name)
{
      vector<Worker> result_workers;
      for (vector<Worker>::size_type i = 0; i < workers.size(); i++)
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
      long unsigned int size = workers.size();

      const double factor = 1.247;
      long unsigned int step = size / factor - 1;

      while (step >= 1)
      {
            for (vector<Worker>::size_type i = 0; i + step < size; i++)
            {
                  if (workers[i].birth_date < workers[i + step].birth_date)
                  {
                        swap(workers[i], workers[i + step]);
                  }
            }
            step /= factor;
      }

      return workers;
}

/**
 * Формирование среза работников из вектора по году рождения (больше или меньше)
 *
 * @param    workers     вектор работников
 * @param    minYear     начальный год
 * @param    maxYear     конечный год
 * @return               сформированный вектор работников
 */
vector<Worker> makeSliceWorkersByAge(vector<Worker> workers, int minYear, int maxYear)
{
      vector<Worker> selected_workers;
      for (vector<Worker>::size_type i = 0; i < workers.size(); i++)
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
vector<vector<int>> distributeWorkersByGenderAndAge(vector<Worker> workers)
{
      vector<vector<int>> groups(11, vector<int> (2, 0));
      for (vector<Worker>::size_type i = 0; i < workers.size(); i++)
      {
            int age = 2024 - workers[i].birth_date.year;
            int group_index = (age - 18) / 5;
            if (workers[i].gender == Gender::male)
            {
                  groups[group_index][0]++;
            }
            else
            {
                  groups[group_index][1]++;
            }
      }
      return groups;
}

/**
 * Вывод списка работников
 * 
 * @param   workers     вектор работников
 */
void printWorkers(vector<Worker> workers)
{
      for (vector<Worker>::size_type i = 0; i < workers.size(); i++)
      {
            printf("Работник %zu -> ФИО: %s, Пол: %s, Дата рождения: %d.%d.%d\n", i + 1, workers[i].full_name.c_str(), genderToString(workers[i].gender).c_str(), workers[i].birth_date.day, workers[i].birth_date.month, workers[i].birth_date.year);
      }
}

/**
 * Вывод групп работников
 * 
 * @param   groups      группы работников
*/
void printGroupsWorkers(vector<vector<int>> groups)
{
      for (size_t i = 0; i < groups.size(); ++i)
      {
            int age_start = 18 + i * 5;
            int age_end = age_start + 5;
            if (i == groups.size() - 1) 
            {
                  printf("Возрастная группа %d лет и старше:\n", age_start);
            }
            else
            {
                  printf("Возрастная группа %d-%d лет:\n", age_start, age_end);
            }
            printf("\tМужчины: %d, Женщины: %d\n", groups[i][0], groups[i][1]);
      }
}