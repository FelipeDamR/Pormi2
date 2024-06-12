// =========================================================
// File: vox.h
// Author:Felipe de J
// Date:
// Description:
// =========================================================

#ifndef VOXOPERATOR_H
#define VOXOPERATOR_H

#include <string>
#include <sstream>
#include <iomanip>
#include "operator.h"

class VoxOperator : public Operator {
public:
    VoxOperator(int id, double talkingCharge, double messageCost, double networkCharge, double discountRate, OperatorType type);
    VoxOperator(const VoxOperator& other);

    double calculateTalkingCost(int minutes, int age) override;
    double calculateMessageCost(int quantity, int thisOpId, int otherOpId) override;
    double calculateNetworkCost(double amount) override;
};

#endif // VOXOPERATOR_H