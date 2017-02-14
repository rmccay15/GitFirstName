#include <stdio.h>
#include <string.h>
#include <math.h>
#define pi 3.14

int main(void){

	int operation,again = 1,opagain = 1;//two do-while loops need two values
do{
	printf("What operation would you like to perform:\n(1) Compute The Area Of A Circle\n(2) Profit or Loss\n(3) Operator\n(4) EXIT\n: ");
	fflush(stdout);
	scanf("%d",&operation);
//Error checking for operation
	while(operation < 1 || operation > 4){

	printf("\n\n****************ERROR************\nMUST CHOOSE 1-4!!!!\n\nWhat operation would you like to perform:\n(1) Compute The Area Of A Circle\n(2) Profit or Loss\n(3) Operator\n(4) EXIT\n: ");
	fflush(stdout);//flush is needed anytime the buffer needs to output or a variable is needed to be scanned
	scanf("%d",&operation);
	}

	switch(operation){//switch operation is dependent on operation variable

	case 1:{
		float area,radius;

		printf("What is the radius, in meters, of the circle?\n");
		fflush(stdout);
		scanf("%f",&radius);
//error checking for radius
		while(radius <= 0){

		printf("**************ERROR****************\nRADIUS CANNOT BE LESS THAN ZERO\n\nWhat is the radius, in meters, of the circle? \n");
		fflush(stdout);
		scanf("%f",&radius);

		}

		area = (float)pow((double)radius,2)*pi;//type casting to allow area to be printed

		printf("\nThe area of a circle with radius %.2f meters is %.2f meters^2\n",radius,area);
		break;
	}
	case 2:{
		float sell=0,cost=0,profit=0;

		printf("How much did the item cost? \n$");
		fflush(stdout);

		scanf("%f",&cost);
//error checking for cost
		while(cost < 0){
			printf("***************ERROR****************\nCOST PRICE MUST BE GREATER THAN ZERO\n\nHow much did the item cost? \n$");
			fflush(stdout);
			scanf("%f",&cost);
		}
		printf("How much did the item sell for? \n$");
		fflush(stdout);
		scanf("%f",&sell);
//error checking for sell
		while(sell < 0){
			printf("***************ERROR****************\nTHE SALE PRICE MUST BE GREATER THAN ZERO\n\nHow much did the item sell for? \n$");
			fflush(stdout);
			scanf("%f",&sell);
		}

		profit = sell - cost;

		if(profit > 0){

			printf("\nWith the item costing %.2f dollars and selling for %.2f dollars,\nA total profit of %.2f dollars.",cost,sell,profit);
		}else if(profit < 0){
			printf("\nWith the item costing %.2f dollars and selling for %.2f dollars,\nA total loss of %.2f dollars.",cost,sell,profit*-1);

		}else{
			printf("\nThe item sold for the same amount that it cost: BROKE EVEN!");

		}


	}

		break;

	case 3:

		do{//second do-while for the switch case

		char operator;
		float op1,op2;


		printf("\nEnter:\nFirst Operand: ");
		fflush(stdout);
		scanf("%f",&op1);
		printf("\nOperator: ");
		fflush(stdout);
		scanf("%c",&operator);
		operator = getchar();//getchar() is needed after the scanf function
		printf("\nSecond Operand: ");
		fflush(stdout);
		scanf("%f",&op2);
		float answer;
		switch(operator){//switch case dependent on operator

			case '+':
				answer = op1 + op2;
				printf("\n\n%f %c %f = %f",op1,operator,op2,answer);
				break;
			case '-':
				answer = op1 - op2;
				printf("\n\n%f %c %f = %f",op1,operator,op2,answer);
				break;
			case '*':
				answer = op1*op2;
				printf("\n\n%f %c %f = %f",op1,operator,op2,answer);
				break;
			case '/':
				if(op2 == 0){

					printf("\n\n*******CANNOT DIVIDE BY ZERO**********\n");
					break;
				}
				answer = op1/op2;
				printf("\n\n%f %c %f = %f",op1,putchar(operator),op2,answer);
				break;
			default:
				printf("*************Wrong Operator************\n");
				break;
		}

		printf("\n\nWould you like to compute another operation?\n(1)YES\n(2)NO\n: ");
		fflush(stdout);
		scanf("%d",&opagain);
//error checking for opagain
		while(opagain < 1 || opagain > 2){

		printf("****************ERROR***************\nMUST CHOOSE 1 OR 2!!!!\n\nWould you like to compute another operation?\n(1)YES\n(2)NO\n: ");
		fflush(stdout);
		scanf("%d",&opagain);
		}


		}while(opagain == 1);//end of inner do-while
		break;

	case 4:
		printf("\n\n**************GOODBYE*************");//exit inner do-while if 4 is entered
		return 0;

	default:

		break;

	}

	printf("\n\nWould you like to run the program again?\n(1)YES\n(2)NO\n: ");
	fflush(stdout);
	scanf("%d",&again);
//error checking for outer do-while loop
	while(again < 1 || again > 2){

		printf("****************ERROR***************\nMUST CHOOSE 1 OR 2!!!!\n\nWould you like to go again?\n(1)YES\n(2)NO\n: ");
		fflush(stdout);
		scanf("%d",&again);
	}

}while(again == 1);

printf("\n******************GOODBYE*****************");
	return 0;
}

