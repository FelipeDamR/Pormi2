// =========================================================
// File: internet_operator.h
// Author: Felipe de Jesus Damian Rodrigue<
// Date:12/06/2024
// Description:
// =========================================================

#include "internet.h"

// Constructor con parámetros
InternetOperator::InternetOperator(int id, double talkingCharge, double messageCost, double networkCharge, double discountRate, OperatorType type)
    : Operator(id, talkingCharge, messageCost, networkCharge, discountRate, type) {}

// Constructor de copia
InternetOperator::InternetOperator(const InternetOperator &other)
    : Operator(other) {}

// Método para calcular el costo de las llamadas
double InternetOperator::calculateTalkingCost(int minutes, int age) {
    if (minutes <= 0 || age <= 0) {
        return 0;
    }
    double cost = minutes * getTalkingCharge();
    if (minutes < 2) {
        cost *= (1 - getDiscountRate());
    }
    return cost;
}

// Método para calcular el costo de los mensajes
double InternetOperator::calculateMessageCost(int quantity, int thisOpId, int otherOpId) {
    if (quantity <= 0) {
        return 0;
    }
    double cost = quantity * getMessageCost();
    if (quantity < 3) {
        cost *= (1 - getDiscountRate());
    }
    return cost;
}

// Método para calcular el costo de uso de la red
double InternetOperator::calculateNetworkCost(double amount) {
    if (amount <= 0) {
        return 0;
    }
    if (amount <= LIMITGB) {
        return 0;
    }
    return (amount - LIMITGB) * getNetworkCharge();
}
