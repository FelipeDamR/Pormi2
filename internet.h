// =========================================================
// File: internet_operator.h
// Author: Felipe de Jesus Damian Rodrigue<
// Date:12/06/2024
// Description:
// =========================================================
#ifndef INTERNETOPERATOR_H
#define INTERNETOPERATOR_H

#include "operator.h"

class InternetOperator : public Operator {
private:
    const double LIMITGB = 1.0;

public:
    InternetOperator(int id, double talkingCharge, double messageCost, double networkCharge, double discountRate, OperatorType type);
    InternetOperator(const InternetOperator &other);

    double calculateTalkingCost(int minutes, int age) override;
    double calculateMessageCost(int quantity, int thisOpId, int otherOpId) override;
    double calculateNetworkCost(double amount) override;
};

#endif // INTERNETOPERATOR_H
