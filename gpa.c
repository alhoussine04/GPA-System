#include <stdio.h>

#define MAX_SIZE  32
#define MIN_SN  100000000																																																																																																																																																					
#define MAX_SN  199999999       
#define MIN_GPA 0               
#define MAX_GPA 12																																							

#define C_OK             0	// Success flag
#define C_ERR_ARR_FULL  -1	// Error code for array is full
#define C_ERR_BAD_SN    -2	// Error code for a bad student number
#define C_ERR_BAD_GPA   -3	// Error code for a bad GPA
#define C_INVALID_VALUE -1     

int  getStuData(int*, float*);
void printStuData(int*, float*, int);
int  orderStuData(int*, float*, int);

int  validateSN(int);
int  validateGPA(float);
void printErrorMsg(int);
int  findMaxIndex(float*, int);


int main()
{
  int sn[MAX_SIZE] ;
  float gp[MAX_SIZE];

  
  int num = getStuData(sn, gp);
  if (num == C_ERR_ARR_FULL){
    printf("\n\nError: Array is Full\n\n");
  } else if (num == C_ERR_BAD_SN){
    printf("\n\nError: You have entered a wrong student number.\n\n");
  } else if (num == C_ERR_BAD_GPA){
    printf("\n\nError: You have entered a wrong GPA score.\n\n");
  }
  

  printf("\nOriginal Data:\n");
  printStuData(sn, gp, num);  
  orderStuData(sn, gp, num);
  printf("\nOrdered Data:\n");
  printStuData(sn, gp, num);


  return(0);
}

/*
   Function:  validateSN
         in:  integer of student number
     return:  flags and error checkers
*/
int validateSN(int sn){
  if(MIN_SN < sn && sn < MAX_SN){
    return C_OK;
  }
  else {
    return C_ERR_BAD_SN;
  }
}


/*
   Function:  validateGPA
         in:  float of student GPA
     return:  flags and error checkers
*/
int validateGPA(float gp){
  if(MIN_GPA <= gp && gp <= MAX_GPA){
    return C_OK;
  } else {
    return C_ERR_BAD_GPA;
  }
}


/*
   Function:  getStuData																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																							
        out:  array of initialized student numbers
        out:  array of initialized student GPAs
     return:  flags and error checkers
*/
int getStuData(int* sn, float* gp){
  int inStu;
  float inGPA;
  for (int i=0; i<MAX_SIZE+1; ++i) {
    printf("Please enter the student number and GPA: ");
    scanf("%d %f", &inStu, &inGPA);
    if(inStu == C_INVALID_VALUE||inGPA == C_INVALID_VALUE){
      return i;
    } else if(validateSN(inStu)==C_ERR_BAD_SN){
      return C_ERR_BAD_SN;
    } else if(validateGPA(inGPA)==C_ERR_BAD_GPA){
      return C_ERR_BAD_GPA;
    } else if(i==MAX_SIZE){
      return C_ERR_ARR_FULL;
    }
    sn[i]=inStu;
    gp[i]=inGPA;
  }
}


/*
   Function:  printStuData 
         in:  array of initialized student numbers
         in:  array of initialized student GPAs
     return:  n/a
*/
void printStuData(int* sn, float* gp, int num){
  printf("\n");
  for (int i=0; i<num; ++i) {
    printf("%d %.2f \n", sn[i], gp[i]);
  }
}


/*
   Function:  findMaxIndex
         in:  an initialized array
         in:  integer size of an array
     return:  maximum index
*/
int finMaxIndex(float* arr, int num){
  int max = 0;
  for(int i = 1; i < num; i++){
    if(arr[i]>arr[max]){
      max = i;
    }
  }
  return max;
}


/*
   Function:  orderStuData
         in:  array of initialized student numbers
         in:  array of initialized student GPAs
        out:  array of initialized student numbers in 
              descending order of GPAs
        out:  array of initialized student GPAs in 
              descending order
     return:  flag
*/
int orderStuData(int* sn, float* gp, int num){
  int snCopy[num];
  float gpCopy[num];
  for(int i = 0; i < num; i++){
    snCopy[i] = sn[i];
    gpCopy[i] = gp[i];
  }
  for(int i = 0; i < num; i++){
    int max = finMaxIndex(gpCopy, num);
    sn[i] = snCopy[max];
    gp[i] = gpCopy[max];
    gpCopy[max] = -1;
  }
  return C_OK;
}
