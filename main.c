#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//runs functions


int main(){
	extern void calc();
	extern int tall();
	extern int primes();
	extern int binary();
	extern int duplicates();
	extern int length();
	extern int math();
	extern int add(int x, int y);
	extern int sub(int x, int y);
	extern int mul(int x, int y);
	extern int divi(int x, int y);
	
	int choice;
	char exit = 'n';
	while(exit == 'n' || exit == 'N'){
 		printf("\n\n\tWELCOME\n\nC is the best language!\n-----------------------\n");
		printf("Function options:\n1. Calculator\n2. How tall are you really?\n3. Primes\n4. Binary Hex Swap\n5. Duplicates\n6. String Length\n7. Math Stuff\n8. Exit");
        printf("\nInput a choice by number: ");
		scanf("%d", &choice); 		
		
		//application controller
		if(choice == 1){
			printf("\n-----------------------\n");
			calc();
		}
		else if(choice == 2){
			printf("\n-----------------------\n");
			tall();
		}
		else if(choice == 3){
			printf("\n-----------------------\n");
			primes();
		}
		else if(choice == 4){
			printf("\n-----------------------\n");
			binary();
		}
		else if(choice == 5){
			printf("\n-----------------------\n");
			duplicates();
		}
		else if(choice == 6){
			printf("\n-----------------------\n");
			length();
		}
		else if(choice == 7){
			printf("\n-----------------------\n");
			math();
		}
		else if(choice == 8){
			exit = 'y';
		}
		else{
			printf("\nYou failed to follow simple instructions.... closing application!");
		}
		
	}
}


/*
1. Write a program that will work as a basic calculator that can perform addition, 
subtraction, multiplication and division on a user input data for two operands. (Something 
like 5 → + → 6 user input will print result: “Sum of 5 and 6 is 11”).

------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------

*/    

void calc(){
	extern int add(int x, int y);
	extern int sub(int x, int y);
	extern int mul(int x, int y);
	extern int divi(int x, int y);
	int x;
	int y;
	int z;
	char choice;
	printf("\n\n\tCALCULATOR\n-----------------------\nWould you like to:\n(A) ADD\n(S) SUBTRACT\n(M) MULTIPLY\n(D) DIVIDE\n(E) Exit\nEnter Selection by Letter: ");
	scanf("%s", &choice); 
	if(choice == 'A' || choice == 'a'){
        printf("\nADDITION!\nInput first number: ");
		scanf("%d", &x); 
        printf("\nInput second number:");
		scanf("%d", &y); 	
		z = add(x, y);
		printf("\nThe sum is %d", z);
		calc();
	}
	else if(choice == 'S' || choice == 's'){
        printf("\nSUBTRACTION!\nInput first number: ");
		scanf("%d", &x); 
        printf("\nInput second number: ");
		scanf("%d", &y); 	
		z = sub(x, y);
		printf("\nThe difference is %d", z);
		calc();
	}
	else if(choice == 'M' || choice == 'm'){
        printf("\nMULTIPLICATION!\nInput first number: ");
		scanf("%d", &x); 
        printf("\nInput second number: ");
		scanf("%d", &y); 	
		z = mul(x, y);
		printf("\nThe product is %d", z);
		calc();
	}
	else if(choice == 'D' || choice == 'd'){
        printf("\nDIVISION!\nInput first number: ");
		scanf("%d", &x); 
        printf("\nInput second number: ");
		scanf("%d", &y); 	
		z = divi(x, y);
		printf("\nThe quotient is %d", z);
		calc();
	}	
	else if(choice == 'E' || choice == 'e'){
		exit(0);
	}
exit(0);
}
int add(int x, int y){
	int a = x;
	int b = y;
	int z = a + b;
	return z;
}

int sub(int x, int y){
	int a = x;
	int b = y;
	int z = a - b;
	return z;
}	

int mul(int x, int y){
	int a = x;
	int b = y;
	int z = a * b;
	return z;
}	

int divi(int x, int y){
	int a = x;
	int b = y;
	int z = a / b;
	return z;
}		
/*
2. Write  a  C  program  to  accept  the  height  of  a  person  in  centimeter  and  categorize  the 
person according to their height whether the person is tall/medium/short.   

------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------

*/    

int tall(){
	return 1;
	
}

/*
3. Write a C program to print all the prime numbers within a limit set by a user input.

------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------

*/    

int primes(){
	return 1;
}

/*
4. Write a C program to create a converter from Binary to Hexadecimal and vice-versa. 

------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------

*/    

int binary(){
	return 1;
}

/*
5. Write a program in C to count a total number of duplicate elements in an array.    

------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------

*/    

int duplicates(){
	return 1;
}

/* 
6. Write a program in C to Calculate the length of the string using a pointer.    

------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------

*/    

int length(){
	return 1;
}

/* 
7. Extend  the  assignment  1  by  including  math.h  header  file  in  your  program  and  add  the 
following  functionalities  to  your  calculator  by  utilizing  the  built-in  functions  of  math.h: 
Square Root, Ceiling, Flooring and Power. Also, create your own function for custom math 
operation that returns (𝑎+𝑏)2 if (a+b)^2 given as user input. 

------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------

*/    

int math(){
	return 1;
}