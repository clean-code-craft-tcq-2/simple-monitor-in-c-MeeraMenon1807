#include "BMS.h"

int BattTempCheck(float temp){
    if (temp < 0 || temp > 45)
	{
	return 0;
	}
	return 1;
}

int BattSocCheck(float Soc){
if (Soc < 20 || Soc > 80)
	{
	return 0;
	}
	return 1;
}

int BattChargeRateCheck(float ChargeRate){
if (ChargeRate > 0.8)
	{
	return 0;
	}
	return 1;
}

char BattConditionCheck(int BatteryCondition, char* parameter){
	char warning[100] = " out of range!\n";
	char Output[100];
	char warning1[100]; 
	strcpy(warning1, warning);
	if (BatteryCondition == 0)
	{
		Output = strcat(parameter, warning);
		printf("%s \n", Output);
	}
}

int batteryIsOk(float temp, float Soc, float ChargeRate) {
	int BatteryCondition1 = BattTempCheck(temp);
	BattConditionCheck(BatteryCondition1, "Temperature");
	int BatteryCondition2 = BattSocCheck(Soc);
	BattConditionCheck(BatteryCondition2, "State of charge");
	int BatteryCondition3 = BattChargeRateCheck(ChargeRate);
	BattConditionCheck(BatteryCondition3, "Battery Charge rate");
	int BatteryCondition = BatteryCondition1 && BatteryCondition2 && BatteryCondition3;
	return BatteryCondition;
}
	
int main() {
  assert(batteryIsOk(25, 70, 0.7) == 1);
  assert(batteryIsOk(50, 85, 0) == 0);
}	
	
	
	
	
	
	
	
	
	
	
	
	
