#include <stdio.h>
#include<stdlib.h>
#include "isort.h"
#define bSIZE 50

int main() {

    //insertion sort printf- Question 1-B
//    printf("Now's the function of insertion_sort \n");
//    printf("1b- Please insert 50 numbers to the array \n");
    int myInt;
    int arrFifty[bSIZE];
    int *arrFP= arrFifty;
    for (int i = 0; i < bSIZE; i++) {
        scanf("%d", &myInt);
        *arrFP=myInt;
        arrFP++;
    }

 //   int j=0;
 //   while (j < bSIZE) {
 //       printf("arrFifty in place %d is %d \n", j, arrFifty[j]);
 //       j++;
 //   }
//    printf("Now's the function of insertion_sort on Q1B \n");

    int *arrFPS= arrFifty;
    insertion_sort(arrFPS, bSIZE); //from the beginning of the array, shift 1 element right

//    printf("Finished the function \n");

 //   printf("Now, the array is: \n");
//    j = 0;
 //   while (j < bSIZE) {
 //       printf("arr in place %d is %d \n", j, arrFifty[j]);
 //       j++;
 //   }

//    printf("Printf to the console \n");

    int *arrNow= arrFifty;
for (int k=0; k< bSIZE; k++){
	if(k==bSIZE-1){
	printf("%d", *(arrNow+k));
	}
	else{
		printf("%d,", *(arrNow+k));
	}
}
 //   int j=0;

  ///  printf("first is %d \n", *arrNow);
//	printf("%d", *arrNow);
//	j++;
 //   while (j < bSIZE) { //#bsize instead of 5
 //       arrNow++;
 //       j++;
//		printf(",%d", *arrNow);
 //   }
    return 0;
}

///////////////1)a.
void shift_element(int* arrP, int i){
    printf("Got into the function \n");
    int* endP = arrP+i;
    //got a pointer to the end of an array
//    printf("the last element in the arr is %d \n",*endP);
    while(i>0){     //while you still got more cells to move right
        printf(" The value in the array is  %d \n",*arrP);
        *endP=*(endP-1);
        endP--;
        i--;
    }
//    printf("now the function has ENDED, and the last value is %d \n", *(endP-1));
}

///////////////1)b.
// by insertion sort pseudo code

void insertion_sort(int* arr , int len){
    for(int i=0; i<len; i++){
        int key=*arr;
        int *j=arr-1;
        while(j>0 && *j > key ) {
            *(j + 1) = *j;
            j--;
        }
        *(j+1)=key;
        arr++;
    }
}
