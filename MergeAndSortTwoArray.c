#include <stdio.h>

void main() {
    int n1, arr1[60], n2, arr2[60], n3, arr3[120]; 
    int i, j;

    printf("Enter the size of the first array: ");
    scanf("%d", &n1);
    printf("Enter the elements of the first array: ");
    for (i = 0; i < n1; i++)
 { 
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of the second array: ");
    scanf("%d", &n2);
    printf("Enter the elements of the second array: ");
    for (j = 0; j < n2; j++) 
	{ 
        scanf("%d", &arr2[j]);
    }

    n3 = n1 + n2;

    
    for (i = 0; i < n1; i++) {
        arr3[i] = arr1[i];
    }
    for (i = 0; i < n2; i++) {
        arr3[n1 + i] = arr2[i];
    }

    printf("Merged array: ");
    for (i = 0; i < n3; i++) {
        printf("%d ", arr3[i]); 
    }
    printf("\n");

    
    for (i = 0; i < n3 - 1; i++) {
        for (j = 0; j < n3 - i - 1; j++) {
            if (arr3[j] > arr3[j + 1]) {
                int temp = arr3[j];
                arr3[j] = arr3[j + 1];
                arr3[j + 1] = temp;
            }
        }
    }

    printf("Sorted array: ");
    for (i = 0; i < n3; i++) {
        printf("%d ", arr3[i]); 
    }
    printf("\n");
}

