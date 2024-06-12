// =========================================================
// File: operator.h
// Author:
// Date:
// Description:
// =========================================================

#ifndef OPERATOR_H
#define OPERATOR_H

#include <string>
#include <sstream>
#include <iomanip>

typedef enum { VOX, INTERNET } OperatorType;

class Operator {
protected:
    int id;
    double talkingCharge;
    double messageCost;
    double networkCharge;
    double discountRate;
    double totalInternetUsage;
    int totalSpentTalkingTime;
    int totalMessageSent;
    OperatorType type;

public:
    Operator(int id, double talkingCharge, double messageCost, double networkCharge, double discountRate, OperatorType type);
    Operator(const Operator& other);
    virtual ~Operator();

    int getId() const;
    double getDiscountRate() const;
    double getTalkingCharge() const;
    double getMessageCost() const;
    double getNetworkCharge() const;
    int getTotalSpentTalkingTime() const;
    int getTotalMessageSent() const;
    double getTotalInternetUsage() const;
    OperatorType getType() const;

    void addTalkingTime(int minutes);
    void addTotalMessageSent(int quantity);
    void addTotalInternetUsage(double amount);

    std::string toString() const;

    virtual double calculateTalkingCost(int minutes, int age) = 0;
    virtual double calculateMessageCost(int quantity, int thisOpId, int otherOpId) = 0;
    virtual double calculateNetworkCost(double amount) = 0;
};

#endif // OPERATOR_H
