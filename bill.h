// =========================================================
// File: bill.h
// Author: Felipe de Jesus Damian Rodrigue<
// Date:12/06/2024
// Description:
// =========================================================


#ifndef BILL_H
#define BILL_H

class Bill {
private:
    double limitAmount;
    double currentDebt;
    double totalMoneySpent;

public:
    Bill();
    Bill(double limit);
    Bill(const Bill &other);

    double getLimitAmount() const;
    double getCurrentDebt() const;
    double getTotalMoneySpent() const;

    void add(double amount);
    void pay(double amount);
    void changeTheLimit(double amount);
    bool check(double amount) const;
};

#endif // BILL_H