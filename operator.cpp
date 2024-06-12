// =========================================================
// File: operator.h
// Author: Felipe de Jesus Damian Rodrigue<
// Date:12/06/2024
// Description:
// =========================================================
#include "operator.h"

// Constructor con parámetros
Operator::Operator(int id, double talkingCharge, double messageCost, double networkCharge, double discountRate, OperatorType type)
    : id(id), talkingCharge(talkingCharge), messageCost(messageCost), networkCharge(networkCharge), discountRate(discountRate),
      totalSpentTalkingTime(0), totalMessageSent(0), totalInternetUsage(0.0), type(type) {}

// Constructor de copia
Operator::Operator(const Operator& other)
    : id(other.getId()), talkingCharge(other.getTalkingCharge()), messageCost(other.getMessageCost()), networkCharge(other.getNetworkCharge()),
      discountRate(other.getDiscountRate()), totalSpentTalkingTime(other.getTotalSpentTalkingTime()), totalMessageSent(other.getTotalMessageSent()),
      totalInternetUsage(other.getTotalInternetUsage()), type(other.getType()) {}

// Destructor virtual
Operator::~Operator() {}

// Métodos de acceso
int Operator::getId() const {
    return id;
}

double Operator::getDiscountRate() const {
    return discountRate;
}

double Operator::getTalkingCharge() const {
    return talkingCharge;
}

double Operator::getMessageCost() const {
    return messageCost;
}

double Operator::getNetworkCharge() const {
    return networkCharge;
}

int Operator::getTotalSpentTalkingTime() const {
    return totalSpentTalkingTime;
}

int Operator::getTotalMessageSent() const {
    return totalMessageSent;
}

double Operator::getTotalInternetUsage() const {
    return totalInternetUsage;
}

OperatorType Operator::getType() const {
    return type;
}

// Métodos para agregar valores a los contadores
void Operator::addTalkingTime(int minutes) {
    if (minutes > 0) {
        totalSpentTalkingTime += minutes;
    }
}

void Operator::addTotalMessageSent(int quantity) {
    if (quantity > 0) {
        totalMessageSent += quantity;
    }
}

void Operator::addTotalInternetUsage(double amount) {
    if (amount > 0) {
        totalInternetUsage += amount;
    }
}

// Método toString para representación en cadena
std::string Operator::toString() const {
    std::stringstream ss;
    ss << "Operator #" << getId() << " : " << getTotalSpentTalkingTime() << " " << getTotalMessageSent() << " " << std::fixed << std::setprecision(2) << getTotalInternetUsage();
    return ss.str();
}
