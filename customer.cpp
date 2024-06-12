// =========================================================
// File: bill.cpp
// Author: Felipe de Jesus Damian Rodrigue<
// Date:12/06/2024
// Description:
// =========================================================

#include "customer.h"

// Constructor
Customer::Customer(int id, std::string name, int age, Operator* op, double limitAmount)
    : id(id), name(name), age(age), totalSpentTalkingTime(0), totalMessageSent(0), totalInternetUsage(0.0), op(op) {
    bill = new Bill(limitAmount);
}

// Constructor de copia
Customer::Customer(const Customer &other)
    : id(other.id), name(other.name), age(other.age), totalSpentTalkingTime(other.totalSpentTalkingTime), totalMessageSent(other.totalMessageSent), totalInternetUsage(other.totalInternetUsage), op(other.op) {
    bill = new Bill(*other.bill);
}

// Destructor
Customer::~Customer() {
    delete bill;
}

// Métodos de acceso (getters)
int Customer::getId() const { return id; }
std::string Customer::getName() const { return name; }
int Customer::getAge() const { return age; }
int Customer::getTotalSpentTalkingTime() const { return totalSpentTalkingTime; }
int Customer::getTotalMessageSent() const { return totalMessageSent; }
double Customer::getTotalInternetUsage() const { return totalInternetUsage; }
Operator* Customer::getOperator() const { return op; }
Bill* Customer::getBill() const { return bill; }

// Método de modificación (setter)
void Customer::setOperator(Operator* newOperator) { op = newOperator; }

// Otros métodos
void Customer::talk(int minutes, Customer &other) {
    if (minutes > 0 && this != &other) {
        double cost = op->calculateTalkingCost(minutes, age);
        if (bill->check(cost)) {
            bill->add(cost);
            totalSpentTalkingTime += minutes;
            op->addTalkingTime(minutes);
            if (op != other.getOperator()) {
                other.getOperator()->addTalkingTime(minutes);
            }
        }
    }
}

void Customer::message(int quantity, const Customer &other) {
    if (quantity > 0 && this != &other) {
        double cost = op->calculateMessageCost(quantity, op->getId(), other.getOperator()->getId());
        if (bill->check(cost)) {
            bill->add(cost);
            totalMessageSent += quantity;
            op->addTotalMessageSent(quantity);
        }
    }
}

void Customer::connection(double amount) {
    if (amount > 0) {
        double cost = op->calculateNetworkCost(amount);
        if (bill->check(cost)) {
            bill->add(cost);
            totalInternetUsage += amount;
            op->addTotalInternetUsage(amount);
        }
    }
}

void Customer::pay(double amount) {
    if (amount > 0) {
        bill->pay(amount);
    }
}

std::string Customer::toString() const {
    std::ostringstream oss;
    oss << "Customer #" << id << ": " << bill->getTotalMoneySpent() << " " << bill->getCurrentDebt();
    return oss.str();
}
