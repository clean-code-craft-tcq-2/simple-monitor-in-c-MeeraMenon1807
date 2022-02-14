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
    return isTemperatureOutOfRange || isSocOutOfRange || isChargeRateOutOfRange ? 0 : 1;
}

int main() {
  assert(!checkOutOfRange(10, 20, 15.5F));
  assert(checkOutOfRange(10, 20, 25.5F));
  assert(!checkTemperatureOutOfRange(25));
  assert(checkTemperatureOutOfRange(46));
  assert(!checkSocOutOfRange(70));
  assert(checkSocOutOfRange(19));
  assert(!checkChargeRateOutOfRange(0.7F));
  assert(checkChargeRateOutOfRange(1));
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
