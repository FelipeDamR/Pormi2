// =========================================================
// File: customer.h
// Author: Felipe de Jesus Damian Rodrigue<
// Date:12/06/2024
// Description:
// =========================================================

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "operator.h"
#include "bill.h"

class Customer {
private:
    int id;
    std::string name;
    int age;
    int totalSpentTalkingTime;
    int totalMessageSent;
    double totalInternetUsage;
    Operator* op;
    Bill* bill;

public:
    Customer(int id, std::string name, int age, Operator* op, double limitAmount);
    Customer(const Customer &other);
    ~Customer();

    int getId() const;
    std::string getName() const;
    int getAge() const;
    int getTotalSpentTalkingTime() const;
    int getTotalMessageSent() const;
    double getTotalInternetUsage() const;
    Operator* getOperator() const;
    Bill* getBill() const;

    void setOperator(Operator* newOperator);
    
    void talk(int minutes, Customer &other);
    void message(int quantity, const Customer &other);
    void connection(double amount);
    void pay(double amount); // Asegúrate de añadir esta línea
    std::string toString() const;
};

#endif // CUSTOMER_H
