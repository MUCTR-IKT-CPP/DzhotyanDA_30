#ifndef WORKER_GENERATORS_H
#define WORKER_GENERATORS_H

#include <string>
#include "worker_structs.h"

using namespace std;

Gender generateWorkerGender();
BirthDate generateWorkerBirthDate();
string generateWorkerFullNameFemale();
string generateWorkerFullNameMale();

/**
 * Генерация объекта структуры Worker
 *
 * @return  объект структуры Worker
 */
Worker generateWorker()
{
      Worker worker;
      worker.gender = generateWorkerGender();
      worker.birth_date = generateWorkerBirthDate();

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
 * @return  сгенерированная строка фамилия + имя + отчество
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
 * @return  сгенерированная строка фамилия + имя + отчество
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
 * Генерирует дату рождения работника
 *
 * @return  сгенерированная дата рождения работника
 */
BirthDate generateWorkerBirthDate()
{
      BirthDate date;
      date.year = rand() % 36 + 1970;
      date.month = rand() % 12 + 1;

      if (date.month == 2)
      {
            bool leapYear = (date.year % 4 == 0 && date.year % 100 != 0 || date.year % 400 == 0);
            date.day = leapYear ? rand() % 29 + 1 : rand() % 28 + 1;
      }
      else if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) 
      {
            date.day = rand() % 30 + 1;
      }
      else
      {
            date.day = rand() % 31 + 1;
      }
      return date;
}

/**
 * Генерирует пол работника
 *
 * @return  сгенерированный пол работника
 */
Gender generateWorkerGender()
{
      int x = 0 + rand() % 2;
      return x == 0 ? Gender::male : Gender::female;
}

#endif // WORKER_GENERATORS_H