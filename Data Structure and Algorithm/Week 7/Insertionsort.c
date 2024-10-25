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
	
	
	// Applying insertion sorting
	
	int key;
	for(int i = 0;i<10;i++){
		key = arr[i];
		
		int j = i-1;
		
		while(j >= 0 && arr[j] > key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
		
		// Placing the key at its correct position
	}
	
	printf("Array after insertion sorting we get: \n");
	
	for(int i = 0;i<10;i++){
		printf("%d  ", arr[i]);
	
	}	
}
