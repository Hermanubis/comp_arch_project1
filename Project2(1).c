#include <stdio.h>

/*
Team number:
Team members:
*/

/* PROJECT 1 */

/* In this assignment you will examine a program consisting of a number of functions - labelled ques1.c to ques16.c -- each of which tests your knowledge of bitwise C operations (and data representation and logic operators). Your goal is to (a) determine what each function does and (b) if there
is a simpler way to implement the function using other operators, conditionals, loops etc.. For questions where the function returns a boolean value, figure out when it returns a 1. Thus, there are two parts to the requirements.  */

/* Assume 32 bit integers */

/* PART A: You need to determine what each function is doing .
You have to determine what each function is doing WITHOUT running the code -- simply handing in the results of your program execution. You must provide an explanation for your answer - you will get no credit if you correctly identify the function but provide  an incorrect or insufficient/incomplete explanation. Providing an 
example of output of each function for a given input is NOT a formal explanation and will get you no credit. 
 Once you determine the function, make sure you run the code and check your answer on various boundary conditions.
To run the code to test your function, you will need to insert appropriate C code to call the function and print out the result; a sample of what this may
require is provided in function main to call function ques0.
 Once you are done showing what each function does, you should then answer part b. */

/* PART B: For each function, can you write a simpler equivalent function in C (using any C operators) that produces the same result.
 By simpler, we are interested in fewer operations in C but also more readable code. */


/*
 As an example, consider the answers to function ques0 - which you worked out in class.

 HANDIN Instruction. 
Part A: You must write out your answers to Part A in a report to be submitted (as a tarfile or zipfile, along with your code) - in addition to the report, 
you can include comments in your code that may provide a secondary explanation (in case  your report has errors). You MUST provide an explanation for what
 the function does and justify your answer. Simply providing an example is NOT an explanation - so don't expect any credit if  your answers are simply a 
collection of examples or code comments. You are welcome to provide formal proofs where appropriate, but use your judgement on whether to pursue a formal 
proof or not. It is preferable to write your answers as comments in the code - but do not feel pressured to do so (this gets complicated if you  used
figures and examples in your explanation). */
/*
Part B: For part B, write out your code in this file with the answer (a simpler code if it exists) after each of the assigned functions in a manner similar
 to the example shown in ques0 (i.e., the answer to function ques7 should be named ans7). In Function main you MUST call both the question and answer 
functions and print out the results. Refer to the example shown for ques0 and ans0. This will also help you check if your code is giving the same
answer as the functions you are to decipher. HINT: For some of the questions, you may want to read in (and print out) the input variables in hex format -- 
similar to the inclass exercise (the first variable you entered, which was sent to function whoamI).

TEAM WORK DISTRIBUTION: At the top of your submission (the code and the report) clearly specify what each team member did; if each was responsible for a 
set of questions then specify that information. We will take team member contributions into consideration during our grading.

 IMPORTANT: The code you submit must compile correctly (using gcc). If the code you submit does not compile (i.e., we expect zero errors!),
 you will get a zero for Part B of this project.

 GRADING: Each question has a specific number of points (i.e., not all questions have the same level of difficulty). Your grade will be based
 on (a) the correctness of your answers, (b) expressing the answer as a logical function where possible, and (c) the efficiency and readability of your
 rewritten code.

 Collaboration: You should work your teammates. But you CANNOT refer to online sources to get help; you can refer to the C syntax documentations. Your report must include names of all members of the team -- failure to do so would imply you are claiming you worked on your own, and may constitute a violation of academic integrity policies.*/

/* EXAMPLE
 this function is similar to CallMeLast in the inclass exercises */
/*  function ques0(x,y) returns (x-y) since ~y +1 is the two's complement of y, i.e., -y. */
/* the function ans0 does the same in one C statement */

int ques0(int x, int y){
    int temp;
    temp = ~y;
    temp = temp +1;
    temp = temp + x;
    return (temp);
}

/* Answer to PART B: */
int ans0(int x, int y){


    return (x-y);
}

/* QUESTIONS */






/* Question 1 */
int ques1(int x, int y){
    int x_and_y = x&y;
    int x_or_y = ~(~x & ~y);
    return (x_or_y & ~(x_and_y));
    }


/* Question 2 */
int ques2(x) {
    int mask = x>>31;
    int y= (x ^ mask);
    int z = (~mask + 1);

    return (y+z);
}



/* Question 3 */
int ques3(int x) {
    int y = x >> 31;
    int z = !!x;

    return y | z;
}

/* Question 4 */

int ques4(int x, int y) {
	int a = x >> 31;
	int b = y >> 31;
	return ! ((a & !b) | (( !(a ^b)) & (~y +x)>>31));
	  
}

/* Question 5 */

int ques5(int x, int n) {
    /* for this question ONLY, you can  assume x and n are not  negative numbers  */

    int temp = (1 << n);
    int z = temp + ~0;

    return (z & x);
}

/* Question 6 */

int ques6(int x, int n){
  /* assume n<=30 */
  int mask = (1 <<n) + ( ~0);
  int bias = (x >> 31) & mask;
  return ((x+bias)>> n);
}


/* Question 7 */

int ques7(int x, int y){
    int sum= x+y;
    int x_neg= x>>31;
    int y_neg = y>>31;
    int s_neg = sum>>31;
    return !(~(x_neg^y_neg) & (x_neg^s_neg));
    }

/* Question 8  */
int ques8(void) {
    int byte = 0xAA;
    int word = byte | byte<<8;

    return word | word<<16;
}

/* Question 9 */
int ques9(int x){
    int m8= 0xAA;
    int m16 = m8 | m8 <<8;
    int m32 = m16 | m16<<16;
    int y = x | m32;
    return !! y;
    }

/* Question 10 */
int ques10(int x){
    int m8= 0xAA;
    int m16 = m8 | m8 <<8;
    int m32 = m16 | m16<<16;
    int fillx = x | m32;
    return !(~fillx);
}

/*Question 11 */
int ques11(int x, int y){
    int x_and_y = x &y;
    int nx_and_ny = (~x & ~y);
    return (x_and_y | nx_and_ny );
    }

/* Question 12 */

int ques12(int x, int n){
  /* assume n is <= 32 */
	int shift = 32 + ~n +1 ;
	int move = (x << shift) >> shift;
	return !(x^move);
	}

/* Question 13 */
int ques13(int x, int n){
  int z = n << 3;
  int y = ~(0xFF << z);
  return (y & x);
}

/* Question 14 */

int ques14(int x, int n, int m){
/* assume 0 <= n <=3 and 0 <= m <=3 */
	int n8= n <<3;
	int m8 = m <<3;
	int n_mask = 0xff << n8;
	int m_mask = 0xff << m8;
	int n_byte = ((x & n_mask) >>n8) & 0xff;
	int m_byte = ((x & m_mask) >> m8) & 0xff;
	int bytes_mask = n_mask | m_mask ;
	int leftover = x & ~bytes_mask;
	return ( leftover | (n_byte <<m8)| (m_byte << n8) );
	}


/* Question 15 */

int ques15(int x){
  int nx = ~x;
  int nxnz = !!nx;
  int nxov = !( nx +nx);
  return (nxnz & nxov);
}

/* Question 16 */
int ques16(int x){
    int wd16 = x ^ (x>>16);
    int wd8 = wd16 ^ (wd16 >>8);
    int wd4 = wd8 ^ (wd8<<4);
    int wd2= wd4 ^ (wd4<<2);
    int bit = (wd2 ^ (wd2>>1)) & (0x1);
    return bit;
}



  /* main is used only for testing the results of each function */
int main(){

  /* the variables defined in main are used to pass arguments to functions and get return value from the functions. */

  /* Example for ques0 */
  int a, b;/* input parameters to be sent to function  ques0 */
   int t1;

 	printf("Enter first number, an integer stored into variable A preferably between 1 and 20:");
 	scanf ("%d",&a);
	printf("\n");
 	printf("Enter second number, an integer stored into variable B preferably between 1 and 20:");
 	scanf ("%d", &b);
	printf("\n");


	printf("you entered a= %d b= %d  \n", a,b);


	t1=ques0(a,b); /* call function ques0; return value is stored in t1 . Next, print out the return value. */
	printf("output of ques0 is t1 = %d  \n", t1);
	t1=ans0(a,b); /* call function ans0, return value is in t1. Next, print out the return value */
	printf("output of ans0 is t1 = %d  \n", t1);

	/* To test/run the functions, you will need to mimic the above process (input numbers and then call each of the functions, and print
 the return value) for each of the questions and answers */


	return 0;
}
