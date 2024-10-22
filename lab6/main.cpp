#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory>
#include <cstdlib>
#include <ctime>

/*
 * Класс Fighter (Боец), представляющий бойца с основными параметрами здоровья, брони, урона, инициативы и дальности атаки.
 *
 * @param name Имя бойца.
 * @param health Здоровье бойца.
 * @param armor Уровень брони бойца, который снижает получаемый урон.
 * @param bonusDamage Бонусный урон, добавляемый к базовой атаке.
 * @param initiative Инициатива бойца, определяющая порядок ходов в бою.
 * @param moveRange Дальность перемещения бойца (не используется в текущей версии).
 * @param attackRange Дальность атаки бойца (влияет на возможность атаковать на расстоянии).
 */
class Fighter {
protected:
    std::string name;  ///< Имя бойца.
    int health;  ///< Текущий уровень здоровья бойца.
    int armor;  ///< Уровень брони бойца.
    int bonusDamage;  ///< Дополнительный урон, который добавляется к основному урону.
    int initiative;  ///< Инициатива бойца, определяющая порядок его действий.
    int moveRange;  ///< Дальность перемещения бойца (в текущей версии не используется).
    int attackRange;  ///< Дальность атаки бойца (насколько далеко боец может атаковать).

    int totalDamageDealt = 0;  ///< Суммарный урон, нанесенный бойцом за весь бой.
    int totalAttacks = 0;  ///< Общее количество атак, выполненных бойцом.

public:
    /*
     * Конструктор класса Fighter
     *
     * @param name Имя бойца.
     * @param health Здоровье бойца.
     * @param armor Уровень брони бойца.
     * @param bonusDamage Бонусный урон, добавляемый к базовой атаке.
     * @param initiative Инициатива бойца, определяющая порядок ходов в бою.
     * @param moveRange Дальность перемещения бойца.
     * @param attackRange Дальность атаки бойца.
     */
    Fighter(std::string name, int health, int armor, int bonusDamage, int initiative, int moveRange, int attackRange)
        : name(name), health(health), armor(armor), bonusDamage(bonusDamage), initiative(initiative),
          moveRange(moveRange), attackRange(attackRange) {}

    /*
     * Виртуальный деструктор для корректного удаления объектов-наследников.
     */
    virtual ~Fighter() {}

    /*
     * Метод, который уменьшает здоровье бойца при получении урона, с учетом его брони.
     *
     * @param damage Количество урона, которое боец получает.
     */
    void takeDamage(int damage) {
        int reducedDamage = std::max(0, damage - armor);
        health = std::max(0, health - reducedDamage);
    }

    /*
     * Возвращает текущее здоровье бойца.
     *
     * @return Уровень здоровья бойца.
     */
    int getHealth() const { return health; }

    /*
     * Возвращает инициативу бойца.
     *
     * @return Уровень инициативы бойца.
     */
    int getInitiative() const { return initiative; }

    /*
     * Возвращает имя бойца.
     *
     * @return Имя бойца.
     */
    std::string getName() const { return name; }

    /*
     * Возвращает дальность атаки бойца.
     *
     * @return Дальность атаки бойца.
     */
    int getAttackRange() const { return attackRange; }

    /*
     * Проверяет, жив ли боец.
     *
     * @return True, если боец жив (здоровье больше 0), иначе False.
     */
    bool isAlive() const { return health > 0; }

    /*
     * Виртуальный метод атаки, который должен быть реализован в классах-наследниках.
     *
     * @param target Ссылка на бойца-цель для атаки.
     */
    virtual void attack(Fighter& target) = 0;

    /*
     * Увеличивает статистику атак бойца, увеличивая общий нанесенный урон и количество атак.
     *
     * @param damage Урон, нанесенный за текущую атаку.
     */
    void incrementAttackStats(int damage) {
        totalDamageDealt += damage;
        totalAttacks++;
    }

    /*
     * Перегрузка оператора вывода для отображения основных параметров бойца.
     *
     * @param os Поток вывода.
     * @param fighter Боец, параметры которого будут выведены.
     * @return Ссылка на поток вывода.
     */
    friend std::ostream& operator<<(std::ostream& os, const Fighter& fighter) {
        os << fighter.name << " {Health: " << fighter.health << ", Armor: " << fighter.armor
           << ", Bonus Damage: " << fighter.bonusDamage << ", Initiative: " << fighter.initiative << "}";
        return os;
    }

    /*
     * Показывает статистику атак бойца после боя, включая общее количество нанесенного урона и количество атак.
     */
    void showStatistics() const {
        std::cout << name << " dealt a total of " << totalDamageDealt << " damage over " << totalAttacks << " attacks.\n";
    }
};

/*
 * Класс Warrior представляет воина, который является бойцом.
 * В классах-наследниках задаются конкретные характеристики и реализация метода атаки.
 */

class Warrior : public Fighter {
public:
    /*
     * Конструктор Warrior инициализирует воина с заданными параметрами.
     * Дальность перемещения и атаки для воина фиксированы на уровне класса.
     *
     * @param name имя воина.
     * @param health здоровье воина.
     * @param armor броня воина.
     * @param bonusDamage бонусный урон воина.
     * @param initiative инициатива воина.
     */
    Warrior(std::string name, int health, int armor, int bonusDamage, int initiative)
        : Fighter(name, health, armor, bonusDamage, initiative, 1, 1) {} // Воин имеет минимальную дальность перемещения и атаки.

    /*
     * Метод attack реализует атаку воина на цель.
     * Наносит случайный урон, прибавляя бонус воина.
     *
     * @param target цель атаки, другой боец.
     */
    void attack(Fighter& target) override {
        int damage = rand() % 20 + 1 + bonusDamage;
        std::cout << name << " attacks " << target.getName() << " dealing " << damage << " damage.\n";
        target.takeDamage(damage);
        incrementAttackStats(damage);
    }
};

/*
 * Класс Archer представляет лучника, который является бойцом.
 */

class Archer : public Fighter {
public:
    /*
     * Конструктор Archer инициализирует лучника с заданными параметрами.
     * Задает повышенную дальность атаки.
     *
     * @param name имя лучника.
     * @param health здоровье лучника.
     * @param armor броня лучника.
     * @param bonusDamage бонусный урон лучника.
     * @param initiative инициатива лучника.
     */
    Archer(std::string name, int health, int armor, int bonusDamage, int initiative)
        : Fighter(name, health, armor, bonusDamage, initiative, 1, 10) {} // Лучник имеет большую дальность атаки.

    /*
     * Метод attack реализует атаку лучника на цель.
     * Наносит случайный урон, прибавляя бонус лучника.
     *
     * @param target цель атаки, другой боец.
     */
    void attack(Fighter& target) override {
        int damage = rand() % 20 + 1 + bonusDamage;
        std::cout << name << " shoots an arrow at " << target.getName() << " dealing " << damage << " damage.\n";
        target.takeDamage(damage);
        incrementAttackStats(damage);
    }
};

/*
 * Класс Mage представляет мага, который является бойцом.
 */

class Mage : public Fighter {
public:
    /*
     * Конструктор Mage инициализирует мага с заданными параметрами.
     * Задает специальную дальность атаки.
     *
     * @param name имя мага.
     * @param health здоровье мага.
     * @param armor броня мага.
     * @param bonusDamage бонусный урон мага.
     * @param initiative инициатива мага.
     */
    Mage(std::string name, int health, int armor, int bonusDamage, int initiative)
        : Fighter(name, health, armor, bonusDamage, initiative, 1, 5) {} // Маг имеет среднюю дальность атаки.

    /*
     * Метод attack реализует атаку мага на цель.
     * Наносит случайный урон, прибавляя бонус мага.
     *
     * @param target цель атаки, другой боец.
     */
    void attack(Fighter& target) override {
        int damage = rand() % 20 + 1 + bonusDamage;
        std::cout << name << " casts a spell on " << target.getName() << " dealing " << damage << " damage.\n";
        target.takeDamage(damage);
        incrementAttackStats(damage);
    }
};
/**
 * Проводит дуэль между двумя бойцами.
 *
 * @param fighter1 Первый боец, участвующий в дуэли.
 * @param fighter2 Второй боец, участвующий в дуэли.
 */
void duel(Fighter& fighter1, Fighter& fighter2) {
    std::cout << "Duel between " << fighter1.getName() << " and " << fighter2.getName() << " starts!\n";

    // Определяем, кто ходит первым по инициативе
    Fighter* first = (fighter1.getInitiative() >= fighter2.getInitiative()) ? &fighter1 : &fighter2;
    Fighter* second = (first == &fighter1) ? &fighter2 : &fighter1;

    // Цикл атаки до тех пор, пока один из бойцов не погибнет
    while (fighter1.isAlive() && fighter2.isAlive()) {
        first->attack(*second);
        if (second->isAlive()) {
            second->attack(*first);
        }
    }

    // Выводим победителя дуэли
    if (fighter1.isAlive()) {
        std::cout << fighter1.getName() << " wins the duel!\n";
    } else {
        std::cout << fighter2.getName() << " wins the duel!\n";
    }

    // Отображаем статистику после дуэли
    fighter1.showStatistics();
    fighter2.showStatistics();
}

/**
 * Сортирует бойцов по их инициативе в порядке убывания.
 *
 * @param fighters Вектор бойцов, которые будут отсортированы.
 */
void sortFightersByInitiative(std::vector<std::shared_ptr<Fighter>>& fighters) {
    std::sort(fighters.begin(), fighters.end(), [](const std::shared_ptr<Fighter>& a, const std::shared_ptr<Fighter>& b) {
        return a->getInitiative() > b->getInitiative();
    });
}

/**
 * Проводит бой между двумя командами бойцов.
 *
 * @param team1 Первая команда бойцов.
 * @param team2 Вторая команда бойцов.
 */
void battle(std::vector<std::shared_ptr<Fighter>>& team1, std::vector<std::shared_ptr<Fighter>>& team2) {
    std::cout << "Battle between two teams starts!\n";

    // Комбинируем все бойцов для системы поочередных ходов, основанной на инициативе
    std::vector<std::shared_ptr<Fighter>> allFighters = team1;
    allFighters.insert(allFighters.end(), team2.begin(), team2.end());

    // Сортируем бойцов по инициативе
    sortFightersByInitiative(allFighters);

   // Цикл, который продолжается, пока в обеих командах есть хотя бы один живой боец
    while (std::any_of(team1.begin(), team1.end(), [](const std::shared_ptr<Fighter>& f) { return f->isAlive(); }) &&
       std::any_of(team2.begin(), team2.end(), [](const std::shared_ptr<Fighter>& f) { return f->isAlive(); })) {

    // Проходим по всем бойцам (включая обе команды)
    for (auto& fighter : allFighters) {
        // Если боец мёртв, пропускаем его и переходим к следующему
        if (!fighter->isAlive()) continue;

        // Определяем команду-противника:
        // Если боец из команды 1, то цель - команда 2, и наоборот
        std::vector<std::shared_ptr<Fighter>>& targetTeam =
            std::find(team1.begin(), team1.end(), fighter) != team1.end() ? team2 : team1;

        // Находим первую живую цель в команде-противнике
        auto target = std::find_if(targetTeam.begin(), targetTeam.end(), [](const std::shared_ptr<Fighter>& f) {
            return f->isAlive();
        });

        // Если нашлась живая цель, атакуем её
        if (target != targetTeam.end()) {
            fighter->attack(**target);
        }
    }
}

    // Определяем победившую команду
    if (std::any_of(team1.begin(), team1.end(), [](const std::shared_ptr<Fighter>& f) { return f->isAlive(); })) {
        std::cout << "Team 1 wins!\n";
    } else {
        std::cout << "Team 2 wins!\n";
    }

    // Отображаем финальную статистику боя
    std::cout << "\nFinal Statistics:\n";

    std::cout << "Team 1 Stats:\n";
    for (auto& fighter : team1) {
        fighter->showStatistics();
    }

    std::cout << "\nTeam 2 Stats:\n";
    for (auto& fighter : team2) {
        fighter->showStatistics();
    }
}

int main() {
    std::srand(std::time(0));

    // Создаем команды
    std::vector<std::shared_ptr<Fighter>> team1 = {
        std::make_shared<Warrior>("Warrior1", 100, 10, 5, 8),
        std::make_shared<Archer>("Archer1", 80, 5, 3, 6),
        std::make_shared<Mage>("Mage1", 70, 3, 4, 7)
    };

    std::vector<std::shared_ptr<Fighter>> team2 = {
        std::make_shared<Warrior>("Warrior2", 100, 10, 5, 9),
        std::make_shared<Archer>("Archer2", 80, 5, 3, 7),
        std::make_shared<Mage>("Mage2", 70, 3, 4, 5)
    };

    battle(team1, team2);

    return 0;
}