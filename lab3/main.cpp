#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include "worker_generator.cpp"

using namespace std;

enum class Gender { male, female };

struct birthDate
{
      int year;
};

struct Worker
{
      string full_name;
      Gender gender;
      birthDate birth_date;
};

/*
*
* Переводит значение Gender в строку
*
* @param gender   объект Gender
* @return         строка о поле
*/
string genderToString(Gender gender)
{
      return gender == Gender::male ? "МУЖ" : "ЖЕН";
}

/*
 * Генерирует пол работника
 *
 * @return возвращает сгенерированный пол работника
 */
Gender generateWorkerGender()
{
      int x = 0 + rand() % 2;
      return x == 0 ? Gender::male : Gender::female;
}

/*
 * Генерирует объект структуры Worker
 *
 * @return возвращает объект структуры Worker
 */
Worker generateWorker()
{
      Worker worker;
      worker.gender = generateWorkerGender();
      worker.birth_date.year = generateWorkerBirthYear();

      if (worker.gender == Gender::male)
      {
            worker.full_name = generateWorkerFullNameMale();
      }

      else if (worker.gender == Gender::female)
      {
            worker.full_name = generateWorkerFullNameFemale();
      }

      return worker;
}

/*
 * Выводит информацию о работнике по ФИО
 *
 * @param   *workers            список работников
 * @param   number_workers      количество работников
 * @param   full_name           ФИО работника
 */
void findWorkerByFullName(Worker* workers, int number_workers, string full_name)
{
      bool workerFinded = false;
      for (int i = 0; i < number_workers; i++)
      {
            if (workers[i].full_name == full_name)
            {
                  printf("Работник %d -> ФИО: %s, Пол: %s, Год рождения: %d\n", i + 1, workers[i].full_name.c_str(), genderToString(workers[i].gender).c_str(), workers[i].birth_date.year);
                  workerFinded = true;
                  break;
            }
      }

      if (!workerFinded)
      {
            cout << "Работник с данным ФИО не найден" << endl;
      }
}

/*
 * Выводит информация о работниках по полу
 *
 * @param   *workers            список работников
 * @param   number_workers      количество работников
 * @param   gender              Пол работника
 */
void printStatsWorkersByGender(Worker* workers, int number_workers, string gender)
{
      for (int i = 0; i < number_workers; i++)
      {
            if (genderToString(workers[i].gender) == gender)
            {
                  printf("Работник %d -> ФИО: %s, Пол: %s, Год рождения: %d\n", i + 1, workers[i].full_name.c_str(), genderToString(workers[i].gender).c_str(), workers[i].birth_date.year);
            }
      }
}

/*
 * Сортирует массив работников по возрасту
 *
 * @param   *workers            список работников
 * @param   number_workers      количество работников
*/
void sortWorkersByAge(Worker* workers, int number_workers)
{
      const double factor = 1.247;
      int step = number_workers / factor - 1;

      while (step >= 1)
      {
            for (int i = 0; i + step < number_workers; i++)
            {
                  if (workers[i].birth_date.year < workers[i + step].birth_date.year)
                  {
                        swap(workers[i], workers[i + step]);
                  }
            }
            step /= factor;
      }
      for (int i = 0; i < number_workers; i++)
      {
            printf("Работник %d -> ФИО: %s, Пол: %s, Год рождения: %d\n", i + 1, workers[i].full_name.c_str(), genderToString(workers[i].gender).c_str(), workers[i].birth_date.year);
      }
}

void createSliceWorkersByAge(Worker* workers, int number_workers, int minYear, int maxYear)
{
      vector<Worker> new_workers_vector;
      for (int i = 0; i < number_workers; i++)
      {
            if (minYear <= workers[i].birth_date.year && workers[i].birth_date.year <= maxYear)
            {
                  new_workers_vector.push_back(workers[i]);
            }
      }

      for (int i = 0; i < new_workers_vector.size(); i++)
      {
            printf("Работник %d -> ФИО: %s, Пол: %s, Год рождения: %d\n", i + 1, new_workers_vector[i].full_name.c_str(), genderToString(new_workers_vector[i].gender).c_str(), new_workers_vector[i].birth_date.year);
      }
}

int main()
{
      srand(time(0));
      int N;
      cout << "Введите количество работников: ";
      cin >> N;

      Worker workers[N];
      for (int i = 0; i < N; i++)
      {
            workers[i] = generateWorker();
            printf("Работник %d -> ФИО: %s, Пол: %s, Год рождения: %d\n", i + 1, workers[i].full_name.c_str(), genderToString(workers[i].gender).c_str(), workers[i].birth_date.year);
      }

      return 0;
}