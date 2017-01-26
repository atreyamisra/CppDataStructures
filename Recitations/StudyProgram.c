#include "stdio.h";




int main() {
	/*	int x, y, z;
	x = 3;
	y = 3;
	z = x + y;
	float r = (float)z;
	printf("Result in int is: %d\n", z);
	printf("Result in float is: %f\n", r);
	float a = 3.14;
	float b = 0.00159;
	float c = a + b;
	int d = (int)c;
	printf("Result in int is: %d\n", d);
	printf("Result in float is: %f\n", c);
	x = 4;
	y = 7;
	printf("%d\n", addtwo(x, y));
	int gsi = 0;
	int identifier = 0;
	int code = 0;
	int item = 0;
	int digit = 0;
	printf("Enter ISBN: ");
	scanf("%d-%d-%d-%d-%d", &gsi, &identifier, &code, &item, &digit);
	printf("GSI Prefix: %d\nGroup identifier: %d\nPublisher Code: %d\nItem Number: %d\nCheck Digit: %d\n", gsi, identifier, code, item, digit);
	printf("\n\n\n");
	int num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, num11, num12, num13, num14, num15, num16;
	printf("Enter the numbers from 1 to 16 in any order (seperated by spaces):\n");
	scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &num1, &num2, &num3, &num4, &num5, &num6, &num7, &num8, &num9, &num10, &num11, &num12, &num13, &num14, &num15, &num16);
	printf("\n%d %d %d %d\n%d %d %d %d\n%d %d %d %d\n%d %d %d %d\n", num1, num2, num3, num4, num5, num6, num7, num8, num9, num10, num11, num12, num13, num14, num15, num16);
	printf("Row Sums: %d %d %d %d\n", num1 + num2 + num3 + num4, num5 + num6 + num7 + num8, num9 + num10 + num11 + num12, num13 + num14 + num15 + num16);
	printf("Column Sums: %d %d %d %d\n", num1 + num5 + num9 + num13, num2 + num6 + num10 + num14, num3 + num7 + num11 + num15, num4 + num8 + num12 + num16);
	printf("Diagonal Sums: %d %d\n", num1 + num6 + num11 + num16, num4 + num7 + num10 + num13);
	int days;
	int startday;
	printf("Enter Number Days in Month: ");
	scanf("%d", &days);
	printf("\nEnter starting day of the week (1=Sun, 7=Sat): ");
	scanf("%d", &startday);
	printf("\n");
	y = 0;
	int j = startday;
	while (y < days + 1) {
		for (j; j < 8; j++) {
			if (y == 0) {
				for (int i = 1; i < startday; i++) {
					printf("   ");
				}
				j--;
				y++;
			}
			else {
				if (y < days + 1) {
					printf("%3d", y);
					y++;
				}
					
			}
		}
		j = 1;
		printf("\n");
	}
	
	int numerator, denominator, gcd;
	printf("Enter a fraction: ");
	scanf("%d/%d", &numerator, &denominator);
	for (int i = 1; i <= numerator; i++) {
		if ((numerator % i == 0) && (denominator % i == 0))
			gcd = i;
	}
	numerator = numerator/gcd;
	denominator = denominator / gcd;
	printf("In lowest terms: %d/%d", numerator, denominator);
	getchar();
	getchar();
	int tens, ones, input;
	printf("Enter a two-digit number: ");
	scanf("%d", &input);
	tens = input / 10;
	ones = input - tens*10;
	printf("You entered the number ");
	if ((input < 20) && (input > 9)) {
		switch (input)
		{
		case 10: 
			printf("ten");
			break;
		case 11:
			printf("eleven");
			break;
		case 12:
			printf("twelve");
			break;
		case 13:
			printf("thirteen");
			break;
		case 14:
			printf("fourteen");
			break;
		case 15:
			printf("fifteen");
			break;
		case 16:
			printf("sixteen");
			break;
		case 17:
			printf("seventeen");
			break;
		case 18:
			printf("eighteen");
			break;
		case 19:
			printf("nineteen");
			break;
		}
		goto end;
	}
	if (tens != 0) {
		switch (tens) {
		case 2:
			printf("twenty");
			break;
		case 3:
			printf("thirty");
			break;
		case 4:
			printf("fourty");
			break;
		case 5:
			printf("fifty");
			break;
		case 6:
			printf("sixty");
			break;
		case 7:
			printf("seventy");
			break;
		case 8:
			printf("eighty");
			break;
		case 9:
			printf("ninety");
			break;
		}
	}
	if ((tens != 0) && (ones != 0))
		printf("-");
	if (ones != 0) {
		switch (ones){
		case 1:
			printf("one");
			break;
		case 2:
			printf("two");
			break;
		case 3:
			printf("three");
			break;
		case 4:
			printf("four");
			break;
		case 5:
			printf("five");
			break;
		case 6:
			printf("six");
			break;
		case 7:
			printf("seven");
			break;
		case 8:
			printf("eight");
			break;
		case 9:
			printf("nine");
			break;
		}
	}

end:
	printf(".");
	*/
	int x = 0;
	int day[31][100], iterations = 0;
	int i = 0;
	int j = 0;
	char reminder[31][100][100];
	char tempstring[1000];
	for (i; i < 31; i++) {
		for (j; j < 100; j++) {
			day[i][j] = 32;
		}	
	}
	i = 0;
	j = 0;
	for (i; i < 31; i++) {
		for (j; j < 100; j++) {
			strcpy(reminder[i][j], "fuck");
		}
	}
	i = 0;
	j = 0;

	while (i != -1) {
		printf("Enter day and reminder: ");
		scanf("%d %s", &i, &tempstring);
		while (day[i][j] != 32) {
			if (day[i][j] == 32)
				day[i][j] = i;
			else
				j++;
		}
		j = 0;
		day[i][0] = i;
		while (reminder[i][j] != 'fuck') {
			if (reminder[i][j] == 'fuck')
				strcpy(reminder[i][j], tempstring);
			else
				j++;
		}
		j = 0;
		strcpy(reminder[i][0], tempstring);
		if (day[0][0] == 0)
			goto print;
	}
	print:
	printf("Day Reminder");

	getchar();
	getchar();
	getchar();
	getchar();
	getchar();

}