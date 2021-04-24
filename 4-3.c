#include "PolishCalculatorFunctions.h"



int main(void) {
 
	int type;
	double op2;
	double op1;	
	char s[MAXOP];


	while ((type = getop(s)) != EOF) {


		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0) {
				push(pop() / op2);
			} else {
				printf("error: zero divisor\n");
			}			
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		case '%':	
			op2 = pop();
			op1 = pop();
			push(((op1 / op2) - ((int) op1 / (int) op2)) * op2);
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;		

		}

	}



	return 0;

}