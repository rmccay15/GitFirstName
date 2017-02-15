/*
 * Lab2.c
 *
 *  Created on: Jan 31, 2017
 *      Author: panth
 */

#include <stdio.h>


int operations(void);//function prototypes for the 2 programs inside
int binary(void);

int main(void){

	//Let the user decide which program should be executed
	int program;
	printf("Which program would you like to run?\n(1)Arithmetic Operations\n(2)Binary Representation\n: ");
	fflush(stdout);
	scanf("%d",&program);
//error checking for 'program'
	while(program < 1 || program > 2){
	printf("****************ERROR**************\nMUST CHOOSE 1 or 2!\n\nWhich program would you like to run?\n(1)Arithmetic Operations\n(2)Binary Representation\n: ");
	fflush(stdout);
	scanf("%d",&program);
	}
//If the input is 1, run the operations function, otherwise run the binary function
	if(program == 1){
		operations();
	}else{
		binary();
	}
}


//operations function
int operations(void){
	int again = 1;
do{//infinite loop
	int div1,div2;
	char menu;
	unsigned short fact;
	unsigned short leap=0;
	unsigned long fans = 1;
	float num1,num2;


	printf("Please Choose A Selection:\n(A)Find the factorial of a number\n(B)Leap Year or Not\n(C)Maximum Number\n(D)Division of Two Integers\n(E)EXIT\n: ");
	fflush(stdout);
	scanf("%c",&menu);
	menu = getchar();

	//error checking for menu input
	while(menu < 65 || menu > 69){
	printf("\n\n************ERROR***********\nMUST CHOOSE BETWEEN A-E (Uppercase)\n\nPlease Choose A Selection:\n(A)Find the factorial of a number\n(B)Leap Year or Not\n(C)Maximum Number\n(D)Division of Two Integers\n(E)EXIT\n: ");
	fflush(stdout);
	scanf("%c",&menu);
	menu = getchar();
	}

	//switch case dependent on the menu input
	switch(menu){

		case 'A':
			printf("\n\nWhat number would you like use? ");
			fflush(stdout);
			scanf("%hu",&fact);

			while(fact < 0 || fact > 12){
				printf("\n\n*************ERROR*************\nNumber exceeds the size of an unsigned long integer \n\n\nWhat number would you like use? ");
				fflush(stdout);
				scanf("%hu",&fact);
			}

			for(int i = 1; i<=fact;i++){
				fans = fans*i;
			}

			printf("\nThe Factorial of %hu is %lu\n\n",fact,fans);
			break;

		case 'B':
			printf("\n\nWhat Year Would You Like To Check? ");
			fflush(stdout);
			scanf("%hu",&leap);

			//error checking if leap exceeds the size of an unsigned short integer
			while(leap > 65535||leap == 0){
				printf("\n\n***********ERROR***********\nYEAR MUST BE GREATER THAN ZERO\n\nWhat Year Would You Like To Check? ");
				fflush(stdout);
				scanf("%hu",&leap);
			}

			//using conditional operator to print one of two statements
			(leap%4==0)?printf("\n%u is a leap year!\n\n",leap):printf("\n%u is not a leap year!\n\n",leap);
			break;

		case 'C':

			printf("\nEnter First Number: ");
			fflush(stdout);
			scanf("%f",&num1);
			printf("\nEnter Second Number: ");
			fflush(stdout);
			scanf("%f",&num2);

			//accounting for the fact that the two numbers will equal each other
			if(num1 == num2){
				printf("\n%f and %f are equal\n\n",num1,num2);
			}else{

				(num1>num2)?printf("\n%f is larger than %f\n\n",num1,num2):printf("\n%f is larger than %f\n\n",num2,num1);
			}
			break;

		case 'D':
			printf("\nEnter Numerator: ");
			fflush(stdout);
			scanf("%d",&div1);
			printf("\nEnter Denominator: ");
			fflush(stdout);
			scanf("%d",&div2);
			if(div2 == 0){
				printf("\n\n************ERROR*************\nCANNOT DIVIDE BY ZERO\n\n");
				break;
			}
			printf("\n\n%d divided by %d equals %f\n\n",div1,div2,(float)div1/div2);//type casting for the division of two integers
			break;

		case 'E':
			again = 0;
			break;
	}

}while(again == 1);

printf("\n\n******************GOODBYE****************");
return 0;
}


//Function allows the user to choose 2 options when converting a decimal to its equivalent binary representation
//after the user chooses one of two, the program converts the decimal to binary by either arithmetic or bitwise operations
int binary(void){

	int choice,rem,bin[16]= {0},i=15;
	unsigned short dec;
	printf("What method of binary representation would you like to use:\n(1)Arithmetic\n(2)Bitwise\n: ");
	fflush(stdout);
	scanf("%d",&choice);

	//error checking for the binary function menu
	while(choice<1 || choice>2){
		printf("************ERROR************\nMUST CHOOSE 1 or 2\n\nWhat method of binary representation would you like to use:\n(1)Arithmetic\n(2)Bitwise\n: ");
		fflush(stdout);
		scanf("%d",&choice);
	}

	printf("Enter a decimal number: ");
	fflush(stdout);
	scanf("%hu",&dec);
	//error checking if the decimal number is greater than its capacity
	while(dec < 0 || dec > 65535){
		printf("*************ERROR*************\nMUST CHOOSE A NUMBER BETWEEN 0-65535\nAN 'unsigned short int' CONSISTS OF 2BYTES [16 BITS = 0-65535]\n\nEnter a decimal number: ");
		fflush(stdout);
		scanf("%hu",&dec);
	}
	if(choice == 1){
		while(dec != 0){
			rem = dec%2;
			bin[i]=rem;
			dec /= 2;
			--i;
		}
		for(i=0;i<16;i++){
			printf("%d",bin[i]);
		}

	}else{
		//bitwise operations check how large the number is by ANDing it to 8000 hex
		//Once the sign has been determined, the while statement prints out the rest
		//of the decimal in 1's and 0's
		int buff = 0x4000;
		if((dec & 0x8000)==0)
			printf("0");
		   else
		      printf("1");
		   while (buff != 0) {
		      if ((dec & buff) == 0)
		         printf("0");
		      else
		         printf("1");
		      buff = buff >> 1;
		   }
		}

return 0;
}
