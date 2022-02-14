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
    return chargeRate > 0.8;
}

void printWarning(char* message, bool hasWarning) {
    if(hasWarning) {
        printf("%s\n", message);
    }
}

int batteryIsOk(float temperature, float soc, float chargeRate) {
    printWarning("Temperature out of range!", checkTemperatureOutOfRange(temperature));
    printWarning("State of Charge out of range!", checkSocOutOfRange(soc));
    printWarning("Charge Rate out of range!", checkChargeRateOutOfRange(chargeRate));
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(batteryIsOk(50, 85, 0));
}
	
	
	
	
	
	
	
	
	
	
	
	
