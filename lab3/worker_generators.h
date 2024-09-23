#ifndef WORKER_GENERATORS_H
#define WORKER_GENERATORS_H

#include <string>
#include "worker_structs.h"

using namespace std;

Gender generateWorkerGender();
int generateWorkerBirthYear();
string generateWorkerFullNameFemale();
string generateWorkerFullNameMale();

/**
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

/**
 * Генерация ФИО работника (ЖЕН)
 *
 * @return возвращает сгенерированную строку фамилия + имя + отчество
 */
string generateWorkerFullNameFemale()
{
      string surnames[] = {"Егоровна", "Васильевна", "Алексеевна", "Федоровна", "Михайлова",
                           "Беляева", "Тарасова", "Борисовна", "Гусева", "Киселева"};

      string names[] = {"Евгения", "Влада", "Ксения", "Анна", "София",
                        "Светлана", "Мария", "Яна", "Камила", "Анастасия"};

      string patronymics[] = {"Евгеньевна", "Владимировна", "Павловна", "Константиновна", "Юрьевна",
                              "Алексеевна", "Викторовна", "Игоревна", "Антоновна", "Олеговна"};

      int size = sizeof(surnames) / sizeof(surnames[0]);
      string surname = surnames[rand() % size];
      string name = names[rand() % size];
      string patronymic = patronymics[rand() % size];
      return surname + " " + name + " " + patronymic;
}

/**
 * Генерация ФИО работника (МУЖ)
 *
 * @return возвращает сгенерированную строку фамилия + имя + отчество
 */
string generateWorkerFullNameMale()
{
      string surnames[] = {"Иванов", "Петров", "Сидоров", "Кузнецов", "Смирнов",
                           "Попов", "Лебедев", "Козлов", "Новиков", "Морозов"};

      string names[] = {"Александр", "Сергей", "Андрей", "Дмитрий", "Максим",
                        "Артем", "Иван", "Роман", "Николай", "Михаил"};

      string patronymics[] = {"Александрович", "Сергеевич", "Андреевич", "Дмитриевич", "Максимович",
                              "Артемович", "Иванович", "Романович", "Николаевич", "Михайлович"};

      int size = sizeof(surnames) / sizeof(surnames[0]);
      string surname = surnames[rand() % size];
      string name = names[rand() % size];
      string patronymic = patronymics[rand() % size];
      return surname + " " + name + " " + patronymic;
}

/**
 * Генерирует год рождения работника
 *
 * @return возвращает сгенерированный год рождения работника
 */
int generateWorkerBirthYear()
{
      return rand() % 36 + 1970;
}

/**
 * Генерирует пол работника
 *
 * @return возвращает сгенерированный пол работника
 */
Gender generateWorkerGender()
{
      int x = 0 + rand() % 2;
      return x == 0 ? Gender::male : Gender::female;
}

#endif // WORKER_GENERATORS_H