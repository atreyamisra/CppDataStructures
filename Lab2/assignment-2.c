#include <stdio.h>
#include "assignment-2.h"
/*Misra, Atreya
am73676
16215
EE312-Assignment	1
*/
int main() {
	int conversionNumber;
	int x = 1;
	while (x == 1) {
		printf("1. Convert a given Austin time to Irish time\n");
		printf("2. Convert a given Irish time to Austin time\n");
		printf("3. Convert a given USD value to EUR\n");
		printf("4. Convert a given EUR value to USD value\n");
		printf("5. Convert a given Fahrenheit temperature to Celsius\n");
		printf("6. Convert a given Celsius temperature to Fahrenheit\n");
		printf("7. Convert a given weight in kg to pounds, ounces\n");
		printf("8. Convert a given weight in pounds, ounces to kg\n");
		printf("9. Convert a given distance in km to miles\n");
		printf("10. Convert a given distance in miles to km\n");
		printf("11. Stop doing conversions and quit the program\n");
		printf("Enter a number from the menu (1-11) to select a specific conversion to perform or to quit: ");
		scanf("%d", &conversionNumber);
		switch (conversionNumber) {
		case 1: printf("Enter an Austin time to be converted, expressed in hours and minutes: ");
			int hour;
			int minute;
			int IrHour;
			int IrMinute;
			int IrDay;
			scanf("%d %d", &hour, &minute);
			AuTimeToIr(hour, minute, &IrHour, &IrMinute, &IrDay);
			if (IrDay == 0)
				printf("The time in Ireland equivalent to %d:%02d in Austin is %d:%02d of the same day.\n", hour, minute, IrHour, IrMinute);
			else
				printf("The time in Ireland equivalent to %d:%02d in Austin is %d:%02d of the next day.\n", hour, minute, IrHour, IrMinute);
			break;
		case 2: printf("Enter an Irish time to be converted, expressed in hours and minutes: ");
			int AuHour;
			int AuMinute;
			int AuDay;
			scanf("%d %d", &hour, &minute);
			IrTimeToAu(hour, minute, &AuHour, &AuMinute, &AuDay);
			if (AuDay == -1)
				printf("The time in Austin equivalent to %d:%02d in Ireland is %d:%02d of the previous day.\n", hour, minute, AuHour, AuMinute);
			else
				printf("The time in Austin equivalent to %d:%02d in Ireland is %d:%02d of the same day.\n", hour, minute, AuHour, AuMinute);
			break;
		case 3: printf("Enter a dollar Value to be converted to Euros: ");
			int dollars; 
			int cents;
			scanf("%d %d", &dollars, &cents);
			double euros = USDToEUR(dollars, cents);
			printf("%.2lf Euros is equivalent to $%d.%02d in US Dollars.\n", euros, dollars, cents);
			break;
		case 4: printf("Enter a Euro Value to be converted to dollars, expressed in dollars and cents: ");
			scanf("%lf", &euros);
			EURToUSD(euros, &dollars, &cents);
			printf("$%d.%02d in US Dollars is equivalent to %.2lf Euros.\n", dollars, cents, euros);
			break;
		case 5:printf("Enter a Fahrenheit temperature to be converted to Celsius: ");
			int fahrenheit;
			scanf("%d", &fahrenheit);
			double celsius1 = fahrenheitToCelsius(fahrenheit);
			printf("%lf Celsius is equivalent to %d Fahrenheit.\n", celsius1, fahrenheit);
			break;
		case 6:printf("Enter a Celsius temperature to be converted to Fahrenheit: ");
			double celsius;
			scanf("%lf", &celsius);
			int fahrenheit1 = celsiusToFahrenheit(celsius);
			printf("%d Fahreneheit is equivalent to %lf Celsius.\n", fahrenheit1, celsius);
			break;
		case 7: printf("Enter a weight in kg to be converted to pounds, ounces: ");
			double kg;
			int lb; 
			int oz;
			scanf("%lf", &kg);
			kgToLbOz(kg, &lb, &oz);
			printf("%d lb %d oz is equivalent to %lf kg.\n", lb, oz, kg);
			break;
		case 8: printf("Enter a weight in pounds, ounces to be converted to kg: ");
			scanf("%d %d", &lb, &oz);
			double kg1=lbOzToKg(lb, oz);
			printf("%lf kg is equivalent to %d lb %d oz.\n", kg1, lb, oz);
			break;
		case 9: printf("Enter a distance in km to be converted to miles: ");
			double km;
			scanf("%lf", &km);
			double a = kmToMi(km);
			printf("%lf miles is equivalent to %lf km.\n", a, km);
			break;
		case 10: printf("Enter a distance in miles to be converted to km: ");
			double mi;
			scanf("%lf", &mi);
			mi=miToKm(mi);
			printf("%lf km is equivalent to %lf miles.\n", mi, km);
			break;
		case 11: x = 0;
		}


	}
	
}
void AuTimeToIr(int hour, int minute, int* IrHour, int* IrMinute, int* IrDay) {
	if (hour > 17) {
		*IrHour = hour - 18;
		*IrDay = 1;
	}
	else {
		*IrHour = hour + 6;
		*IrDay = 0;
	}
	*IrMinute = minute;
}
void IrTimeToAu(int hour, int minute, int* AuHour, int* AuMinute, int* AuDay) {
	if (hour < 6) {
		*AuHour = hour + 18;
		*AuDay = -1;
	}
	else {
		*AuHour = hour - 6;
		*AuDay = 0;
	}
		
	*AuMinute = minute;
}
double USDToEUR(int dollars, int cents) {
	double euros;
	euros = dollars * 100;
	euros = euros + cents;
	euros = euros / 100;
	euros = euros*.74;
	return euros;
}
void EURToUSD(double euros, int* dollars, int* cents) {
	double dollarsfloat;
	double centsfloat;
	dollarsfloat = euros * 1.36;
	*dollars = (int)dollarsfloat;
	centsfloat = dollarsfloat - *dollars;
	centsfloat = centsfloat * 100;
	centsfloat = centsfloat + 0.5;
	*cents = (int)centsfloat;
}
double fahrenheitToCelsius(int fahrenheit) {
	double celsius;
	celsius = fahrenheit - 32;
	celsius = celsius / 9;
	celsius = celsius * 5;
	return celsius;
}
int celsiusToFahrenheit(double celsius) {
	int fahrenheit;
	fahrenheit = celsius * 9;
	fahrenheit = fahrenheit / 5;
	fahrenheit = fahrenheit + 32;
	return fahrenheit;
}
void kgToLbOz(double kg, int* lb, int* oz) {
	double lbfloat;
	double ozfloat;
	lbfloat = kg * 1000;
	lbfloat = lbfloat / 453.59237;
	*lb = (int)lbfloat;
	ozfloat = lbfloat - *lb;
	ozfloat = ozfloat * 16;
	ozfloat = ozfloat + .5;
	*oz = (int)ozfloat;
}
double lbOzToKg(int lb, int oz) {
	double kg;
	kg = oz;
	kg = kg / 16;
	kg = lb + kg;
	kg = kg * 453.59237;
	kg = kg / 1000;	
	return kg;
}
double kmToMi(double km) {
	km = km * 0.6213712;
	return km;
}
double miToKm(double mi) {
	double km;
	km = mi / 0.6213712;
	return km;
}

