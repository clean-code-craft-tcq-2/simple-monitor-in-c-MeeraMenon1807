#include <stdio.h>
#include <assert.h>
#include "checksum.h"

#define TOLERANCE_PERCENTAGE 0.05F

#define MIN_TEMPERATURE 0
#define MAX_TEMPERATURE 45
#define TEMPERATURE_TOLERANCE_VALUE (MAX_TEMPERATURE * TOLERANCE_PERCENTAGE)
#define MIN_TEMPERATURE_WARNING_LEVEL (MIN_TEMPERATURE + TEMPERATURE_TOLERANCE_VALUE)
#define MAX_TEMPERATURE_WARNING_LEVEL (MAX_TEMPERATURE - TEMPERATURE_TOLERANCE_VALUE)

#define MIN_SOC 20
#define MAX_SOC 80
#define SOC_TOLERANCE_VALUE (MAX_SOC * TOLERANCE_PERCENTAGE)
#define MIN_SOC_WARNING_LEVEL (MIN_SOC + SOC_TOLERANCE_VALUE)
#define MAX_SOC_WARNING_LEVEL (MAX_SOC - SOC_TOLERANCE_VALUE)

#define MAX_CHARGERATE 0.8F
#define MAX_CHARGERATE_WARNING_LEVEL (MAX_CHARGERATE - (MAX_CHARGERATE * TOLERANCE_PERCENTAGE))

int checkOutOfRange(int lowerLimit, int upperLimit, float val) {
    return (val < lowerLimit || val > upperLimit);
}

int checkTemperatureOutOfRange(float temperature) {
    int isTemperatureOutOfRange = checkOutOfRange(MIN_TEMPERATURE, MAX_TEMPERATURE, temperature);
    setTempError(isTemperatureOutOfRange);
    if(!isTemperatureOutOfRange) {
        setTempWarning(checkOutOfRange(MIN_TEMPERATURE_WARNING_LEVEL, MAX_TEMPERATURE_WARNING_LEVEL, temperature));
    }
    return isTemperatureOutOfRange;
}

int checkSocOutOfRange(float soc) {
    int isSocOutOfRange = checkOutOfRange(MIN_SOC, MAX_SOC, soc);
    setSocError(isSocOutOfRange);
    if(!isSocOutOfRange) {
        setSocWarning(checkOutOfRange(MIN_SOC_WARNING_LEVEL, MAX_SOC_WARNING_LEVEL, soc));
    }
    return isSocOutOfRange;
}

int checkChargeRateOutOfRange(float chargeRate) {
    int isChargeRateOutOfRange = chargeRate > MAX_CHARGERATE;
    setChargeRateError(isChargeRateOutOfRange);
    if(!isChargeRateOutOfRange) {
        setChargeRateWarning(chargeRate > MAX_CHARGERATE_WARNING_LEVEL);
    }
    return isChargeRateOutOfRange;
}

void printWarning(char* message, int hasWarning) {
    if(hasWarning) {
        printf("%s\n", message);
    }
}

int batteryIsOk(float temperature, float soc, float chargeRate) {

    checkTemperatureOutOfRange(temperature);
    checkSocOutOfRange(soc);
    checkChargeRateOutOfRange(chargeRate);

    int isTemperatureOutOfRange = hasTempError();
    printWarning("Temperature out of range!", isTemperatureOutOfRange);
    printWarning("Temperature nearing out of range!", hasTempWarning());

    int isSocOutOfRange = hasSocError();
    printWarning("State of Charge out of range!", isSocOutOfRange);
    printWarning("State of Charge nearing out of range!", hasSocWarning());

    int isChargeRateOutOfRange = hasChargeRateError();
    printWarning("Charge Rate out of range!", isChargeRateOutOfRange);
    printWarning("Charge Rate nearing out of range!", hasChargeRateWarning());
    
    return (isTemperatureOutOfRange + isSocOutOfRange + isChargeRateOutOfRange) == 0;
    
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
  assert(batteryIsOk(44, 79, 0.77));
}
