/*
AIM: To Minimum and Maximum of an Array using C language.
AUTHOR: Subhradeep Sarkar
PLATFORM: DEV C/C++
DATE: Friday, 23 August
*/

#include <stdio.h>

//Declaring a global array
int list[] = {23,15,52,68,101,456,78,89};


//Declaring a functions to determine Minimum and Maximum of the given array
void findMinMax(){
	int min = list[0];
	int max = list[0];
	int length = sizeof(list)/sizeof(list[0]);
	for(int i = 0; i<length;i++){
		if(min>list[i]){
			min = list[i];
		}
		else if(max < list[i]){
			max = list[i];
		}
		
		else{
			continue;
		}
	}
	
	printf("The Max element in the array is : %d", max);
	printf("\n \n");
	printf("The Min element in the array is : %d", min);
	printf("\n \n");
}

int main(){
	
	printf("The Given Array is : ");
	
	for(int i=0; i<(sizeof(list)/sizeof(list[0])); i++)
	{
	  printf("%d, ", list[i]);
	}
	
	printf("\n \n");
	
	findMinMax();
	
	return 0;
	
}
