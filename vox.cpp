// =========================================================
// File: vox_operator.h
// Author: Felipe de Jesus Damian Rodrigue<
// Date:12/06/2024
// Description:
// =========================================================
#include "vox.h"

// Constructor con parámetros
VoxOperator::VoxOperator(int id, double talkingCharge, double messageCost, double networkCharge, double discountRate, OperatorType type)
    : Operator(id, talkingCharge, messageCost, networkCharge, discountRate, type) {};

// Constructor de copia
VoxOperator::VoxOperator(const VoxOperator& other)
    : Operator(other) {}


// Método para calcular el costo de las llamadas
double VoxOperator::calculateTalkingCost(int minutes, int age) {
    if (minutes <= 0 || age <= 0) return 0;
    double cost = minutes * talkingCharge;
    if (age < 18 || age > 65) {
        cost *= (1 - discountRate);
    }
    return cost;
}

// Método para calcular el costo de los mensajes
double VoxOperator::calculateMessageCost(int quantity, int thisOpId, int otherOpId) {
    if (quantity <= 0) return 0;
    double cost = quantity * messageCost;
    if (thisOpId == otherOpId) {
        cost *= (1 - discountRate);
    }
    return cost;
}

// Método para calcular el costo de uso de la red
double VoxOperator::calculateNetworkCost(double amount) {
    if (amount <= 0) return 0;
    return amount * networkCharge;
}