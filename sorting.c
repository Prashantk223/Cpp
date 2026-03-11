Sorting technique
Selection sort
Inse
//bubble sort

void bubblesort()
{
	//no. of passes
	for(i = 0; i < n-1;)
	{
		for(int j = 0; j < n-1-i; j++)
		{
			//no. of comparision. for every pass we need one less compariison
			if(A[j] > A[j+1])
			{
				temp = A[j];
				A[j] = A[j+1];
				A[j + 1] = temp; 
				//check if for this pass has there been atleast one comparision. If not then array is already sorted
				flag = 1
			}
		}
		
		if(flag == 0)
			break;
	}
}


//insertion sort
void insertionSort()
{
	for(i = 1; i < n; i++)
	{
		temp = a[i];
		j = i - 1;
		while(j>=0 && a[j] > temp)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = temp;
	}
}


#include <stdio.h>

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
