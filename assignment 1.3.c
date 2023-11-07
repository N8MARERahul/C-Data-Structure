// WAP to convert temperature from degree centigrade to Fahrenheit.

#include<stdio.h>

int main () {
	int tc, tf;
	printf("Enter the temperature in celcius: ");
	scanf("%d", &tc);
	
	tf = (tc * 9 / 5) + 32;
	
	printf("%d deg C = %d deg F", tc, tf);
	
	return 0;
}
