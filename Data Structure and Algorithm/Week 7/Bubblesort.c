// Including all the headers files

# include <stdio.h>
# include <stdlib.h>

// Starting the main function

int main(){
	
	int arr[10];
	
	printf("Enter the elements in the array: \n");
	
	for(int i = 0; i<10; i++){
		
		scanf("%d", &arr[i]);
	}
	
	
	// Applying bubble sorting
	
	int temp; // swapper variable
	
	for(int i = 0;i<10;i++){
		for(int j = 0; j<10;j++){
			
			// Comparing the elemnets in the array
			if(arr[i]<arr[j]){
				
				// Applying swapping method
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
	
	printf("Array after bubble sorting we get: \n");
	
	for(int i = 0;i<10;i++){
		printf("%d  ", arr[i]);
	
	}	
}
