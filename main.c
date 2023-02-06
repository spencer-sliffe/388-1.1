/*
*Spencer Sliffe
*EECS 388 Lab 1
*27 January 2023
*This is a terminal application that gives users 7 different operations they can choose from. 
*Application is programmed in C and checks almost all user input for mistake !*I would say almost 90% of user input is checked for error*!.
*There is a timer function that will pause the application and start a 10 second timer before continuing if the user tries to break the application 
or makes a mistake.  

!!Side note!! This was the lab i attended on Thursday insteed of Monday due to my cat being in the ER. I emailed him about it and CCed you in. Thanks.

TO RUN APPLICATION
------------------
1. copy and paste the following into a file in the same folder named "Makefile"

HelloWorld: main.o
	gcc -std=c11 -g -Wall main.o -o HelloWorld

main.o: main.c
	gcc -std=c11 -g -Wall -c main.c

clean:
	rm *.o HelloWorld

2. Open terminal and navigate to the folder containing main.c and Makefile

3. Type in "make" then type in ./HelloWorld to run
*/

//Importing libraries
#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#include <time.h>

#include <string.h>

//Main application controller
int main() {
    //Defining functions in the application
    extern void calc();
    extern void tall();
    extern void primes(char a);
    extern void binary();
    extern void duplicates();
    extern void length();
    extern void duplicateCheck(int arr[], int size);
    extern int add(int x, int y);
    extern int sub(int x, int y);
    extern int mul(int x, int y);
    extern int divi(int x, int y);
    extern void timer(char a);
    extern void letterCheck(int x, int y, char c, char d, char id, char cal);
    int choice;

    //Runs Application until the user desides to exit 
    while (1) {
        printf("\n\n\tWELCOME\n\nC is the best language!\n-----------------------\n");
        printf("Function options:\n1. Calculator\n2. How tall are you really?\n3. Primes\n4. Binary Hex Swap\n5. Duplicates\n6. String Length\n7.Exit");
        printf("\nInput a choice by number: ");
        scanf("%d", & choice);

        //Runs functions based on user input
        if (choice == 1) {
            printf("\n-----------------------------");
            calc();
        } else if (choice == 2) {
            printf("\n-----------------------");
            tall();
        } else if (choice == 3) {
            printf("\n-----------------------");
            primes('p');
        } else if (choice == 4) {
            printf("\n-----------------------");
            binary();
        } else if (choice == 5) {
            printf("\n-----------------------");
            duplicates();
        } else if (choice == 6) {
            printf("\n-----------------------");
            length();
        } else if (choice == 7) {
            printf("GOODBYE\n");
            exit(1);
        } else {
            timer('m');
        }
    }
    exit(1);
}

/*
------------------------------------------------------------------------------------------
1. Calculator - Add, Subtract, Multiply, or Divide 4 numbers
------------------------------------------------------------------------------------------
*/

void calc() {
    //defines functions and variables used
    extern void timer(char a);
    extern void letterCheck(int x, int y, char c, char d, char id, char cal);
    int x, y;
    char ch[7];
    double p;
    char c, d;
    char choice;
    printf("\n\tCALCULATOR\n-----------------------------\nWould you like to:\n(A) ADD\n(S) SUBTRACT\n(M) MULTIPLY\n(D) DIVIDE\n(R) Squareroot\n(C) Ceiling\n(F) Floor\n(Q) Square\n(E) Exit\nEnter Selection by Letter: ");
    scanf(" %c", & choice);
    if (choice == 'A' || choice == 'a') {
        printf("\nADDITION!");
    } else if (choice == 'S' || choice == 's') {
        printf("\nSUBTRACTION!");
    } else if (choice == 'M' || choice == 'm') {
        printf("\nMULTIPLICATION!");
    } else if (choice == 'D' || choice == 'd') {
        printf("\nDIVISION!");
    } else if (choice == 'R' || choice == 'r') {
        printf("\nSQUARE ROOT!");
        printf("\nInput number to square root: ");
        scanf("%lf", & p);
        printf("%lf", sqrt(p));
        calc();
        return;
    } else if (choice == 'C' || choice == 'c') {
        printf("\nCEILING!");
        printf("\nInput a number to take the ceiling of: ");
        scanf("%lf", & p);
        printf("\nThe ceiling is: %lf", ceil(p));
        calc();
        return;
    } else if (choice == 'F' || choice == 'f') {
        printf("\nFLOOR!");
        printf("\nInput a number to take the floor of: ");
        scanf("%lf", & p);
        printf("\nThe floor is: %lf", floor(p));
        calc();
        return;
    } else if (choice == 'Q' || choice == 'q') {
        printf("\nSQARE!");
        printf("\nInput something to take the square of it: ");
        scanf("%s", & * ch);
        if (ch[0] != '(' || ch[1] != 'a' || ch[2] != '+' || ch[3] != 'b' || ch[4] != ')' || ch[5] != '^' || ch[6] != '2') {
            printf("\nDidnt work");
            calc();
            return;
        } else {
            printf("\n");
            for (int i = 0; i <= 6; i++) {
                printf("%c", ch[i]);
            }
            calc();
            return;
        }
    } else if (choice == 'E' || choice == 'e') {
        main();
        return;
    } else {
        timer('c');
    }
    printf("\nInput first number: ");
    scanf("%d", & x);
    scanf("%c", & c);
    printf("\nInput second number:");
    scanf("%d", & y);
    scanf("%c", & d);
    letterCheck(x, y, c, d, 'c', choice);
}

/*
------------------------------------------------------------------------------------------
Math Operations
------------------------------------------------------------------------------------------
*/

//Adds 2 integers and returns difference
int add(int x, int y) {
    int z = x + y;
    return z;
}

//Subtracts 2 integers and returns difference
int sub(int x, int y) {
    int z = x - y;
    return z;
}

//Multiplies 2 integers and returns product
int mul(int x, int y) {
    int z = x * y;
    return z;
}

//Divides 2 integers and returns quotients
int divi(int x, int y) {
    int z = x / y;
    return z;
}

/*
--------------------------------------------------------------------------------------------
2. How tall are you? - Receives integer value in cm and responds with tall, short, or medium
--------------------------------------------------------------------------------------------
*/

void tall() {
    extern void letterCheck(int x, int y, char c, char d, char id, char cal);
    int h;
    char c;
    printf("\nHOW TALL ARE YOU REALLY\n-----------------------\nEnter height in cm or E to exit: ");
    scanf("%d", & h);
    scanf("%c", & c);
    if (c == 'E') {
        main();
    } else {
        letterCheck(h, h, c, c, 't', 't');
    }
}

/*
------------------------------------------------------------------------------------------
3. Primes -  C program to print all the prime numbers within a limit set by a user input.
------------------------------------------------------------------------------------------
*/

void primes(char a) {
    extern void letterCheck(int x, int y, char c, char d, char id, char cal);
    int x, y;
    char c, d;
    printf("\n\tPRIMES\n-----------------------\n");
    printf("Please enter positive number to be minimum of limit or E to exit: ");
    scanf("%d", & x);
    scanf("%c", & c);
    if (c == 'E' || c == 'e') {
        main();
    }
    printf("\nPlease enter positive number to be maximum of limit or E to exit: ");
    scanf("%d", & y);
    scanf("%c", & d);
    if (d == 'E' || d == 'e') {
        main();
    } else {
        letterCheck(x, y, c, d, 'p', 'p');
        return;
    }
}

/*
------------------------------------------------------------------------------------------
4. Binary to Hex and Hex to Binary
------------------------------------------------------------------------------------------
*/

void binary() {
    extern void timer(char a);
    long int bin, hex = 0, i = 1, remainder;
    int choice;
    char word[50];
    printf("\n\tBINARY and HEX\n-----------------------\n");
    printf("Options:\n1. Convert Binary to Hexidecimal\n2. Convert Hexidecimal to Binary\nPlease choose from the options above by correlating number: ");
    scanf("%d", & choice);
    if (choice == 1) {
        printf("\n\nPlease enter the binary number: ");
        scanf("%ld", & bin);
        while (bin != 0) {
            remainder = bin % 10;
            hex = hex + remainder * i;
            i = i * 2;
            bin = bin / 10;
        }
        printf("\nEquivalent hexadecimal value: %lX", hex);
    } else if (choice == 2) {
        i = 0;
        printf("\n\nPlease enter the hexadecimal number: ");
        scanf("%s", & * word);
        for (i = 0; i <= strlen(word); i++) {
            char
            var = word[i];
            switch (var) {
            case '0':
                printf("0000");
                break;
            case '1':
                printf("0001");
                break;
            case '2':
                printf("0010");
                break;
            case '3':
                printf("0011");
                break;
            case '4':
                printf("0100");
                break;
            case '5':
                printf("0101");
                break;
            case '6':
                printf("0110");
                break;
            case '7':
                printf("0111");
                break;
            case '8':
                printf("1000");
                break;
            case '9':
                printf("1001");
                break;
            case 'A':
            case 'a':
                printf("1010");
                break;
            case 'B':
            case 'b':
                printf("1011");
                break;
            case 'C':
            case 'c':
                printf("1100");
                break;
            case 'D':
            case 'd':
                printf("1101");
                break;
            case 'E':
            case 'e':
                printf("1110");
                break;
            case 'F':
            case 'f':
                printf("1111");
                break;
            }
        }
    } else {
        timer('b');
        return;
    }

}

/*
------------------------------------------------------------------------------------------
5. Write a program in C to count a total number of duplicate elements in an array.  
------------------------------------------------------------------------------------------
*/

void duplicates() {
    extern void duplicateCheck(int arr[], int size);
    extern void letterCheck(int x, int y, char c, char d, char id, char cal);
    int size;
    char num;
    printf("\n\tDUPLICATES\n-----------------------\n");
    printf("Enter the # of integers youd like to array or (E/e) to exit: ");
    scanf("%d", & size);
    scanf("%c", & num);
    if (num == 'E' || num == 'e') {
        main();
        return;
    }
    letterCheck(0, 0, num, '0', 'd', '0');
    int arr[size];
    for (int i = 0; i < size; i++) {
        int t = 0;
        printf("\nEnter an integer: ");
        scanf("%d", & t);
        scanf("%c", & num);
        letterCheck(0, 0, num, '0', 'd', '0');
        arr[i] = t;
    }
    duplicateCheck(arr, size);
    return;
}
//Function to find duplicates in array
void duplicateCheck(int arr[], int size) {
    int j;
    int count = 0;
    //Nested loop comparing values inside of the array
    for (int i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
            if (arr[i] != arr[j]) {
                continue;
            }
        }
    }
    printf("\nThere are %d duplicates!", count);
    duplicates();
    return;
}
/* 
------------------------------------------------------------------------------------------
6. Write a program in C to Calculate the length of the string using a pointer.    
------------------------------------------------------------------------------------------
*/

void length() {
    int count = 0;
    int offset = 0;
    char str[100] = {
        0
    };
    printf("\n\tWORD LENGTH\n-----------------------\n");
    printf("\nPlease enter a word: ");
    scanf("%s", & * str);
    while ( * (str + offset) != '\0') {
        ++count;
        ++offset;
    }
    printf("The length is: %d", count);
    main();
    return;

}

/* 
------------------------------------------------------------------------------------------
Functions to make sure terminal application does not break.
------------------------------------------------------------------------------------------
*/

void letterCheck(int x, int y, char c, char d, char id, char cal) {
    extern void timer(char a);
    extern void primes(char a);
    extern int add(int x, int y);
    extern int sub(int x, int y);
    extern int mul(int x, int y);
    extern int divi(int x, int y);
    if ((id == 'd' || id == 'p' || id == 't' || id == 'c') && (c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'g' || c == 'h' || c == 'i' || c == 'j' || c == 'k' || c == 'l' || c == 'm' ||
            c == 'n' || c == 'o' || c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't' || c == 'u' || c == 'v' || c == 'w' || c == 'x' || c == 'y' || c == 'z' ||
            c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F' || c == 'G' || c == 'H' || c == 'I' || c == 'J' || c == 'K' || c == 'L' || c == 'M' ||
            c == 'N' || c == 'O' || c == 'P' || c == 'Q' || c == 'R' || c == 'S' || c == 'T' || c == 'U' || c == 'V' || c == 'W' || c == 'X' || c == 'Y' || c == 'Z')) {
        timer(id);
        return;
    } else if ((id == 'p' || id == 'c') && (d == 'a' || d == 'b' || d == 'c' || d == 'd' || d == 'e' || d == 'f' || d == 'g' || d == 'h' || d == 'i' || d == 'j' || d == 'k' || d == 'l' || d == 'm' ||
            d == 'n' || d == 'o' || d == 'p' || d == 'q' || d == 'r' || d == 's' || d == 't' || d == 'u' || d == 'v' || d == 'w' || d == 'x' || d == 'y' || d == 'z' ||
            d == 'A' || d == 'B' || d == 'C' || d == 'D' || d == 'E' || d == 'F' || d == 'G' || d == 'H' || d == 'I' || d == 'J' || d == 'K' || d == 'L' || d == 'M' ||
            d == 'N' || d == 'O' || d == 'P' || d == 'Q' || d == 'R' || d == 'S' || d == 'T' || d == 'U' || d == 'V' || d == 'W' || d == 'X' || d == 'Y' || d == 'Z')) {
        timer(id);
        return;
    } else if (id == 'p' && (x < 0 || y < 0)) {
        timer(id);
        return;
    } else if (id == 'p' && (x > 0 && y > 0)) {
        if (x > y) {
            int z = x;
            x = y;
            y = z;
        }
        int i, N, count;
        printf("\n\nPrimes: ");
        for (N = x; N <= y; N++) {
            count = 0;
            for (i = 2; i <= N / 2; i++) {
                if (N % i == 0) {
                    count++;
                    break;
                }
            }
            if (count == 0 && N != 1) {
                printf("%d, ", N);
            }
        }
        primes('p');
    } else if (id == 't') {
        if (x < 0 || x > 270) {
            timer('t');
        } else if (x > 0 && x <= 162) {
            printf("\nYou are short!\n\n");
            main();
        } else if (x >= 163 && x <= 180) {
            printf("\nYou are medium!\n\n");
            main();
        } else if (x > 180) {
            printf("\nYou are tall!\n\n");
            main();
        } else {
            timer(id);
        }
        tall();
    } else if (id == 'c') {
        if (cal == 'A' || cal == 'a') {
            int z = add(x, y);
            printf("\nThe sum is %d\n", z);
            calc();
        } else if (cal == 'S' || cal == 's') {
            int z = sub(x, y);
            printf("\nThe difference is %d\n", z);
            calc();
        } else if (cal == 'M' || cal == 'm') {
            int z = mul(x, y);
            printf("\nThe product is %d\n", z);
            calc();
        } else if (cal == 'D' || cal == 'd') {
            int z = divi(x, y);
            printf("\nThe quotient is %d\n", z);
            calc();
        } else {
            timer(id);
        }
    }
}

void timer(char a) {
    if (a == 'm') {
        printf("\n\n\nYou did not follow the instructions!\nDont fret, take some time to rethink your answer before app resumes...");
    } else if (a == 'c') {
        printf("\n\n\nSorry, the calculator did not like that!\nDont fret, take some time to rethink your answer before app resumes...");
    } else if (a == 't') {
        printf("\n\n\nThat was not your height!\nDont fret, take some time to rethink your answer before app resumes...");
    } else if (a == 'p') {
        printf("\n\n\nInvalid input!\nDont fret, take some time to research what a prime is online before app resumes...");
    } else if (a == 'b') {
        printf("\n\n\nThat was not a choice!\nDont fret, take some time to research what a prime is online before app resumes...");
    } else if (a == 'd') {
        printf("\n\n\nYou need to enter an integer!\nDont frent, take some time to rethink what an integer is before app resumes...");
    }
    printf("\nHeres some time to rethink your answer...");

    unsigned int x_hours = 0;
    unsigned int x_minutes = 0;
    unsigned int x_seconds = 0;
    unsigned int x_milliseconds;
    unsigned int totaltime, count_down_time_in_secs, time_left;
    clock_t x_startTime, x_countTime;
    count_down_time_in_secs = 10;
    x_startTime = clock(); //Starts the countdown
    time_left = count_down_time_in_secs - x_seconds; //Updates the timer
    while (time_left > 3) {
        x_countTime = clock(); // update timer difference
        x_milliseconds = x_countTime - x_startTime;
        x_seconds = (x_milliseconds / (CLOCKS_PER_SEC)) - (x_minutes * 60);
        x_minutes = (x_milliseconds / (CLOCKS_PER_SEC)) / 60;
        x_hours = x_minutes / 60;
        time_left = count_down_time_in_secs - x_seconds; // subtract to get difference 
    }
    while (time_left > 0 && time_left <= 3) {
        x_countTime = clock(); // update timer difference
        x_milliseconds = x_countTime - x_startTime;
        x_seconds = (x_milliseconds / (CLOCKS_PER_SEC)) - (x_minutes * 60);
        x_minutes = (x_milliseconds / (CLOCKS_PER_SEC)) / 60;
        x_hours = x_minutes / 60;
        time_left = count_down_time_in_secs - x_seconds; // subtract to get difference 
        //printf("\nApplication will resume in %d seconds!", time_left);
        printf("_00000000000-%d-seconds-left-000000000000\n_00___________________________________00\n_00___________________________________00\n__00_________________________________00_\n__00_________________________________00_\n___00_______________________________00__\n___00______________________________00___\n____000__________________________000____\n_____0000_00000000000000000000_0000_____\n_______0000_0000000000000000_0000_______\n_________0000_000000000000_0000_________\n___________00000_0000000_0000___________\n______________0000_000_000______________\n________________%d%d%d_%d_%d%d________________\n_________________%d%d%d_%d%d_________________\n__________________%d%d_%d%d_________________\n__________________%d%d_%d__________________\n__________________%d%d_%d%d_________________\n________________%d%d%d_%d_%d%d%d_______________\n_____________00000_000_00000____________\n__________00000_____0_____0000__________\n________0000________0_______00000_______\n_______000__________0__________0000_____\n_____000____________0____________000____\n____000_____________0______________00___\n___000______________0_______________00__\n___00_______________0________________00_\n__00________________0________________00_\n__00_______________000________________0_\n__00_00000000000000000000000000000000_00\n__00_00000000000000000000000000000000_00\n__000000000000-%d-seconds-left-0000000000\n\n\n", time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left);
        printf("_00000000000-%d-seconds-left-000000000000\n_00___________________________________00\n_00___________________________________00\n__00_________________________________00_\n__00_________________________________00_\n___00_______________________________00__\n___00______________________________00___\n____000__________________________000____\n_____0000______________________0000_____\n_______0000_0000000000000000_0000_______\n_________0000_000000000000_0000_________\n___________00000_0000000_0000___________\n______________0000_000_000______________\n________________%d%d%d_%d_%d%d________________\n_________________%d%d%d_%d%d_________________\n__________________%d%d_%d%d_________________\n__________________%d%d_%d__________________\n__________________%d%d_%d%d_________________\n________________%d%d%d_%d_%d%d%d_______________\n_____________00000_000_00000____________\n__________00000_____0_____0000__________\n________0000________0_______00000_______\n_______000__________0__________0000_____\n_____000____________0____________000____\n____000_____________0______________00___\n___000______________0_______________00__\n___00_______________0________________00_\n__00_______________000_______________00_\n__00_00000000000000000000000000000000_0_\n__00_00000000000000000000000000000000_00\n__00_00000000000000000000000000000000_00\n__000000000000-%d-seconds-left-0000000000\n\n\n", time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left);
        printf("_00000000000-%d-seconds-left-000000000000\n_00___________________________________00\n_00___________________________________00\n__00_________________________________00_\n__00_________________________________00_\n___00_______________________________00__\n___00______________________________00___\n____000__________________________000____\n_____0000______________________0000_____\n_______0000__________________0000_______\n_________0000_000000000000_0000_________\n___________00000_0000000_0000___________\n______________0000_000_000______________\n________________%d%d%d_%d_%d%d________________\n_________________%d%d%d_%d%d_________________\n__________________%d%d_%d%d_________________\n__________________%d%d_%d__________________\n__________________%d%d_%d%d_________________\n________________%d%d%d_%d_%d%d%d_______________\n_____________00000_000_00000____________\n__________00000_____0_____0000__________\n________0000________0_______00000_______\n_______000__________0__________0000_____\n_____000____________0____________000____\n____000_____________0______________00___\n___000______________0_______________00__\n___00______________000_______________00_\n__00_0000000000000000000000000000000_00_\n__00_00000000000000000000000000000000_0_\n__00_00000000000000000000000000000000_00\n__00_00000000000000000000000000000000_00\n__000000000000-%d-seconds-left-0000000000\n\n\n", time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left);
        printf("_00000000000-%d-seconds-left-000000000000\n_00___________________________________00\n_00___________________________________00\n__00_________________________________00_\n__00_________________________________00_\n___00_______________________________00__\n___00______________________________00___\n____000__________________________000____\n_____0000______________________0000_____\n_______0000__________________0000_______\n_________0000______________0000_________\n___________00000_________0000___________\n______________0000_000_000______________\n________________%d%d%d_%d_%d%d________________\n_________________%d%d%d_%d%d_________________\n__________________%d%d_%d%d_________________\n__________________%d%d_%d__________________\n__________________%d%d_%d%d_________________\n________________%d%d%d_%d_%d%d%d_______________\n_____________00000_000_00000____________\n__________00000_____0_____0000__________\n________0000________0_______00000_______\n_______000__________0__________0000_____\n_____000____________0____________000____\n____000_____________0______________00___\n___000_____________000______________00__\n___00_000000000000000000000000000000_00_\n__00_0000000000000000000000000000000_00_\n__00_00000000000000000000000000000000_0_\n__00_00000000000000000000000000000000_00\n__00_00000000000000000000000000000000_00\n__000000000000-%d-seconds-left-0000000000\n\n\n", time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left, time_left);
    }

    printf("\n\n\nResuming Application - Lets Try Again\n------------------------------");
    if (a == 'm') {
        main();
    } else if (a == 'c') {
        calc();
    } else if (a == 't') {
        tall();
    } else if (a == 'p') {
        primes('p');
    } else if (a == 'b') {
        binary();
    } else if (a == 'd') {
        duplicates();
    }
}