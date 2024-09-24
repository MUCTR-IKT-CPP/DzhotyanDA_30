#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <string>
#include "worker_generators.h"
#include "worker_functions.h"
#include "worker_structs.cpp"

using namespace std;

/**
 * Отображение пользовательского меню
 *
 * @param workers вектор работников
 */
void handleMenu(vector<Worker> workers)
{
      int choice;
      while (true)
      {
            cout << "\n===== Меню =====\n";
            cout << "1. Найти работника по ФИО (частично)\n";
            cout << "2. Вывести работников по возрасту (больше/меньше)\n";
            cout << "3. Распределить работников по полу и возрастным группам\n";
            cout << "4. Отсортировать работников по возрасту\n";
            cout << "0. Выйти\n";
            cout << "================\n";
            cout << "Выберите действие: ";
            
            cin >> choice;

            vector<Worker> selected_workers;
            vector<vector<Worker>> groups;
            string input_full_name;
            int minYear, maxYear;

            switch (choice)
            {
                  case 1:
                        cout << "Введите ФИО: ";
                        cin >> input_full_name;
                        cout << endl;
                        selected_workers = findWorkerByFullNameSubstring(workers, input_full_name);

                        if (selected_workers.size() == 0)
                              cout << "Работники не найдены" << endl;
                        else
                              printWorkers(selected_workers);

                        break;
                  case 2:
                        cout << "Введите мин. год: ";
                        cin >> minYear;
                        cout << endl;
                        
                        cout << "Введите макс. год: ";
                        cin >> maxYear;
                        cout << endl;

                        selected_workers = makeSliceWorkersByAge(workers, minYear, maxYear);
                  
                        if (selected_workers.size() == 0)
                              cout << "Работники не найдены" << endl;
                        else
                              printWorkers(selected_workers);

                        break;
                  case 3:
                        groups = distributeWorkersByGenderAndAge(workers);
                        printGroupsWorkers(groups);
                        break;
                  case 4:
                        selected_workers = sortWorkersByAge(workers);
                        printWorkers(selected_workers);
                        break;
                  case 0:
                        break;
                  default:
                        break;
            }
      }
}

int main()
{
      srand(time(0));
      int N;
      cout << "Введите количество работников: ";
      cin >> N;

      vector<Worker> workers;
      for (int i = 0; i < N; i++)
      {
            workers.push_back(generateWorker());
      }
      
      printWorkers(workers);
      handleMenu(workers);

      return 0;
}