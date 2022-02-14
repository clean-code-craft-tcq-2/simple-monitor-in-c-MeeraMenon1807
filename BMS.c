#include <stdio.h>
#include <assert.h>

int checkInRange(int lowerLimit, int upperLimit, float val) {
    return (val >= lowerLimit && val <= upperLimit);
}

int checkTemperatureInRange(float temperature) {
    return checkInRange(0, 45, temperature);
}

int checkSocInRange(float soc) {
    return checkInRange(20, 80, soc);
}

int checkChargeRateInRange(float chargeRate) {
    return chargeRate <= 0.8F;
}

void printWarning(char* message, int hasWarning) {
    if(hasWarning == 0) {
        printf("%s\n", message);
    }
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    int isTemperatureInRange = checkTemperatureInRange(temperature);
    printWarning("Temperature out of range!", isTemperatureInRange);
    
    int isSocInRange = checkSocInRange(soc);
    printWarning("State of Charge out of range!", isSocInRange);
    
    int isChargeRateInRange = checkChargeRateInRange(chargeRate);
    printWarning("Charge Rate out of range!", isChargeRateInRange);
    
    return (isTemperatureInRange + isSocInRange + isChargeRateInRange) == 3;
}

int main() {
  assert(checkInRange(10, 20, 15.5F));
  assert(!checkInRange(10, 20, 25.5F));
  assert(!checkInRange(10, 20, 5.5F));
  assert(checkInRange(10, 20, 10));
  assert(checkInRange(10, 20, 20));
  
  assert(checkTemperatureInRange(25));
  assert(!checkTemperatureInRange(46));
  assert(!checkTemperatureInRange(-1));
  assert(checkTemperatureInRange(0));
  assert(checkTemperatureInRange(45));
  
  assert(checkSocInRange(70));
  assert(!checkSocInRange(19));
  assert(!checkSocInRange(81));
  assert(checkSocInRange(20));
  assert(checkSocInRange(80));
  
  assert(checkChargeRateInRange(0.7F));
  assert(!checkChargeRateInRange(1));
  assert(checkChargeRateInRange(0.8F));
  
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool checkOutOfRange(int lowerLimit, int upperLimit, float val) {
    return (val < lowerLimit || val > upperLimit);
}

bool checkTemperatureOutOfRange(float temperature) {
    return checkOutOfRange(0, 45, temperature);
}

bool checkSocOutOfRange(float soc) {
    return checkOutOfRange(20, 80, soc);
}

bool checkChargeRateOutOfRange(float chargeRate) {
    return chargeRate > 0.8F;
}

void printWarning(char* message, bool hasWarning) {
    if(hasWarning) {
        printf("%s\n", message);
    }
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    bool isTemperatureOutOfRange = checkTemperatureOutOfRange(temperature);
    printWarning("Temperature out of range!", isTemperatureOutOfRange);
    
    bool isSocOutOfRange = checkSocOutOfRange(soc);
    printWarning("State of Charge out of range!", isSocOutOfRange);
    
    bool isChargeRateOutOfRange = checkChargeRateOutOfRange(chargeRate);
    printWarning("Charge Rate out of range!", isChargeRateOutOfRange);
    
    int result = isTemperatureOutOfRange || isSocOutOfRange || isChargeRateOutOfRange;
    return result;
    
}

int main() {
  assert(!checkOutOfRange(10, 20, 15.5F));
  assert(checkOutOfRange(10, 20, 25.5F));
  assert(checkOutOfRange(10, 20, 5.5F));
  assert(!checkOutOfRange(10, 20, 10));
  assert(!checkOutOfRange(10, 20, 20));
  
  assert(!checkTemperatureOutOfRange(25));
  assert(checkTemperatureOutOfRange(46));
  assert(checkTemperatureOutOfRange(-1));
  assert(!checkTemperatureOutOfRange(0));
  assert(!checkTemperatureOutOfRange(45));
  
  assert(!checkSocOutOfRange(70));
  assert(checkSocOutOfRange(19));
  assert(checkSocOutOfRange(81));
  assert(!checkSocOutOfRange(20));
  assert(!checkSocOutOfRange(80));
  
  assert(!checkChargeRateOutOfRange(0.7F));
  assert(checkChargeRateOutOfRange(1));
  assert(!checkChargeRateOutOfRange(0.8F));
  
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
