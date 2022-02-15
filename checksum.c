#include "checksum.h"

#define TEMP_ERR_INDEX 0
#define TEMP_WARN_INDEX 1
#define SOC_ERR_INDEX 2
#define SOC_WARN_INDEX 3
#define CHARGERATE_ERR_INDEX 4
#define CHARGERATE_WARN_INDEX 5

int checksum[6] = {0, 0, 0, 0, 0, 0};

int hasTempError() {
    return checksum[TEMP_ERR_INDEX];
}

int hasTempWarning() {
    return checksum[TEMP_WARN_INDEX];
}

int hasSocError() {
    return checksum[SOC_ERR_INDEX];
}

int hasSocWarning() {
    return checksum[SOC_WARN_INDEX];
}

int hasChargeRateError() {
    return checksum[CHARGERATE_ERR_INDEX];
}

int hasChargeRateWarning() {
    return checksum[CHARGERATE_WARN_INDEX];
}

void setTempError(int val) {
    checksum[TEMP_ERR_INDEX] = val;
}

void setTempWarning(int val) {
    checksum[TEMP_WARN_INDEX] = val;
}

void setSocError(int val) {
    checksum[SOC_ERR_INDEX] = val;
}

void setSocWarning(int val) {
    checksum[SOC_WARN_INDEX] = val;
}

void setChargeRateError(int val) {
    checksum[CHARGERATE_ERR_INDEX] = val;
}

void setChargeRateWarning(int val) {
    checksum[CHARGERATE_WARN_INDEX] = val;
}