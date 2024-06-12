// =========================================================
// File: bill.cpp
// Author: Felipe de Jesus Damian Rodrigue<
// Date:12/06/2024
// Description:
// =========================================================

#include "bill.h"

// Constructor por defecto
Bill::Bill() : limitAmount(0), currentDebt(0), totalMoneySpent(0) {};

// Constructor con un parámetro
Bill::Bill(double limit) : limitAmount(limit), currentDebt(0), totalMoneySpent(0) {};

// Constructor de copia
Bill::Bill(const Bill &other) : limitAmount(other.getLimitAmount()), currentDebt(other.getCurrentDebt()), totalMoneySpent(other.getTotalMoneySpent()) {};

// Métodos de acceso
double Bill::getLimitAmount() const {
    return limitAmount;
}

double Bill::getCurrentDebt() const {
    return currentDebt;
}

double Bill::getTotalMoneySpent() const {
    return totalMoneySpent;
}

// Métodos de modificación
void Bill::add(double amount) {
    if (amount > 0) {
        currentDebt += amount;
    }
}

void Bill::pay(double amount) {
    if (amount > 0 && amount <= currentDebt) {
        currentDebt -= amount;
        totalMoneySpent += amount;
    }
}

void Bill::changeTheLimit(double amount) {
    if (amount > 0 && amount > currentDebt) {
        limitAmount = amount;
    }
}

bool Bill::check(double amount) const {
    return (currentDebt + amount <= limitAmount);
}