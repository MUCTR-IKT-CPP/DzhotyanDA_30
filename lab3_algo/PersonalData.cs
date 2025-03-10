using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab3_algo
{
    struct PersonalData
    {
        private readonly DateTime MinBirthDate = new DateTime(1980, 1, 1);

        private readonly DateTime MaxBirthDate = new DateTime(2020, 1, 1);

        private string Name;

        private string Surname;

        private string Patronymic;

        private DateTime BirthDate;
    
        public PersonalData(string name, string surname, string patronymic, DateTime birthDate)
        {
            if (birthDate < MinBirthDate || birthDate > MaxBirthDate)
            {
                throw new Exception("Birth date is invalid");
            }

            Name = name;
            Surname = surname;
            Patronymic = patronymic;
            BirthDate = birthDate;
        }

        public static PersonalData GenerateData(int N)
        {
            Random random = new Random();

            string[] names =
            {
                "Александр", "Дмитрий", "Максим", "Иван", "Артём",
                "Сергей", "Андрей", "Алексей", "Роман", "Михаил",
                "Евгений", "Олег", "Кирилл", "Игорь", "Виталий",
                "Павел", "Артур", "Виктор", "Владислав", "Тимур"
            };

            string[] surnames =
            {
                "Иванов", "Смирнов", "Кузнецов", "Попов", "Соколов",
                "Лебедев", "Козлов", "Новиков", "Морозов", "Петров",
                "Волков", "Зайцев", "Павлов", "Семёнов", "Голубев",
                "Виноградов", "Богданов", "Осипов", "Фёдоров", "Беляев"
            };

            string[] patronymics =
            {
                "Александрович", "Дмитриевич", "Максимович", "Иванович", "Артёмович",
                "Сергеевич", "Андреевич", "Алексеевич", "Романович", "Михайлович",
                "Евгеньевич", "Олегович", "Кириллович", "Игоревич", "Витальевич",
                "Павлович", "Артурович", "Викторович", "Владиславович", "Тимурович"
            };

            DateTime startDate = new DateTime(1980, 1, 1);
            DateTime endDate = new DateTime(2020, 1, 1);
            int totalDays = (endDate - startDate).Days;

            DateTime[] birthDates = new DateTime[N];

            for (int i = 0; i < birthDates.Length; i++)
            {
                birthDates[i] = startDate.AddDays(random.Next(totalDays));
            }

            int nameIndex = random.Next(0, names.Length);
            int surnameIndex = random.Next(0, surnames.Length);
            int patronymicIndex = random.Next(0, patronymics.Length);
            int birthDateIndex = random.Next(0, birthDates.Length);

            PersonalData data = new PersonalData(names[nameIndex], surnames[surnameIndex], patronymics[patronymicIndex], birthDates[birthDateIndex]);
            return data;
        }

        public DateTime GetBirthDate() => BirthDate;
    }
}