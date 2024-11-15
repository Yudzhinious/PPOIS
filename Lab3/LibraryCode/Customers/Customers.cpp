#include "Customers.h"

Customers::Customers(int money, int koef, std::string source,int cash) : Budget(money, koef, source) {
    this->cash = cash;
}

void Customers::ShowInfoCust() {
    std::cout << " На расходы покупателем было потрачено " << cash << " рублей." << std::endl;
}

void Customers::AddExpense(int amount) {
    if (amount > 0) {
        cash += amount;
        std::cout << "Добавлено " << amount << " рублей к расходам. Общая сумма расходов: " << cash << " рублей." << std::endl;
    }
    else {
        std::cout << "Ошибка: Сумма должна быть положительной." << std::endl;
    }
}

void Customers::ReduceExpense(int amount) {
    if (amount > 0 && amount <= cash) {
        cash -= amount;
        std::cout << "Уменьшено на " << amount << " рублей. Текущая сумма расходов: " << cash << " рублей." << std::endl;
    }
    else {
        std::cout << "Ошибка: Сумма должна быть положительной и не превышать текущие расходы." << std::endl;
    }
}

void Customers::AverageMonthlyExpense(int months) const {
    if (months > 0) {
        double average = static_cast<double>(cash) / months;
        std::cout << "Средний расход за " << months << " месяц(ев): " << average << " рублей в месяц." << std::endl;
    }
    else {
        std::cout << "Ошибка: Количество месяцев должно быть положительным." << std::endl;
    }
}

bool Customers::HasHigherExpenseThan(const Customers& other) const {
    if (cash > other.cash) {
        std::cout << "Текущий покупатель потратил больше, чем другой." << std::endl;
        return true;
    }
    else {
        std::cout << "Текущий покупатель потратил меньше или столько же, сколько другой." << std::endl;
        return false;
    }
}

