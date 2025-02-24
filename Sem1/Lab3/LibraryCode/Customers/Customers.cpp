#include "Customers.h"

Customers::Customers(int money, int koef, std::string source,int cash) : Budget(money, koef, source) {
    this->cash = cash;
}

void Customers::ShowInfoCust() {
    std::cout << " �� ������� ����������� ���� ��������� " << cash << " ������." << std::endl;
}

void Customers::AddExpense(int amount) {
    if (amount > 0) {
        cash += amount;
        std::cout << "��������� " << amount << " ������ � ��������. ����� ����� ��������: " << cash << " ������." << std::endl;
    }
    else {
        std::cout << "������: ����� ������ ���� �������������." << std::endl;
    }
}

void Customers::ReduceExpense(int amount) {
    if (amount > 0 && amount <= cash) {
        cash -= amount;
        std::cout << "��������� �� " << amount << " ������. ������� ����� ��������: " << cash << " ������." << std::endl;
    }
    else {
        std::cout << "������: ����� ������ ���� ������������� � �� ��������� ������� �������." << std::endl;
    }
}

void Customers::AverageMonthlyExpense(int months) const {
    if (months > 0) {
        double average = static_cast<double>(cash) / months;
        std::cout << "������� ������ �� " << months << " �����(��): " << average << " ������ � �����." << std::endl;
    }
    else {
        std::cout << "������: ���������� ������� ������ ���� �������������." << std::endl;
    }
}

bool Customers::HasHigherExpenseThan(const Customers& other) const {
    if (cash > other.cash) {
        std::cout << "������� ���������� �������� ������, ��� ������." << std::endl;
        return true;
    }
    else {
        std::cout << "������� ���������� �������� ������ ��� ������� ��, ������� ������." << std::endl;
        return false;
    }
}

