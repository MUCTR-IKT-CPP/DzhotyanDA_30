#include <string>
using namespace std;

/*
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

/*
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

/*
 * Генерирует год рождения работника
 *
 * @return возвращает сгенерированный год рождения работника
 */
int generateWorkerBirthYear()
{
      return rand() % 36 + 1970;
}