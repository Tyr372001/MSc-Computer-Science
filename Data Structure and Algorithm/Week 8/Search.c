// Including all the necessary header files

#include <stdio.h>

// Linear search function
int linearSearch(int array[], int length, int key, int index) {
    // Base case: if index is out of bounds, return -1 (element not found)
    if (index >= length) {
        return -1;
    }

    // Check if the current element matches the key
    if (array[index] == key) {
    	// Return the index if the key is found
        return index;  
    }

    // Recursively search in the remaining part of the array
    return linearSearch(array, length, key, index + 1);
}

// Binary search function
int binarySearch(int array[], int key, int low, int high) {
    // Base case: if low exceeds high, the element is not present
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;

    // Check if the key is present at mid
    if (array[mid] == key) {
        return mid;
    }

    // If the key is smaller than mid, search the left subarray
    if (key < array[mid]) {
        return binarySearch(array, key, low, mid - 1);
    }

    // If the key is larger than mid, search the right subarray
    return binarySearch(array, key, mid + 1, high);
}

int main() {
    int choice = 1;
    while (choice == 1) {
        printf("Enter the length of the array: ");
        int length;
        scanf("%d", &length);

        int array[length];
        printf("\n\nEnter the elements in the array: ");
        for (int i = 0; i < length; i++) {
            scanf("%d", &array[i]);
        }

        int key;
        printf("\n\nEnter the key element to be searched: ");
        scanf("%d", &key);

        // Recursive Linear Search
        int linearResult = linearSearch(array, length, key, 0);
        if (linearResult >= 0) {
            printf("Element found at position %d (Linear Search Algorithm was used)\n\n", linearResult);
        } else {
            printf("Element not found (Linear Search Algorithm was used)!!!\n\n");
        }

        // Recursive Binary Search
        printf("\n\n(Note: Binary Search requires a sorted array!)\n");
        int binaryResult = binarySearch(array, key, 0, length - 1);
        if (binaryResult >= 0) {
            printf("Element found at position %d (Binary Search Algorithm was used)\n\n", binaryResult);
        } else {
            printf("Element not found (Binary Search Algorithm was used)!!!\n\n");
        }

        printf("Do you want to continue? Enter 1 for yes, or any other number for no: ");
        scanf("%d", &choice);
    }

    return 0;
}
