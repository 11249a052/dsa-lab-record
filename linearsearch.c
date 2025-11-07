#include<stdio.h>
//Function to perform linear search 
int linearSearch(int arr[], int size, int key)
{   
	for (int i=0; i<size; i++)
	{
		if (arr[i]==key)
		{
			return i; // return index if found
		}
	}
	return -1; // return -1 if not found
}
int main()
{
	int n,key,position;
	// Input array size
	printf("Enter the number of elements:");
	scanf("%d",&n);
	int arr[n];// array declaration
	// Input array elements
	printf("Enter %d elements :",n);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	// Input the element to search
	printf("Enter the element to search:");
	scanf("%d",&key);
	// Perform linear search
	position=linearSearch(arr,n,key);
	// Output result
	if (position==-1)
	{
		printf("Element %d not found in the array.\n",key);
	}
	else
	{
		printf("Element %d found at position %d (index %d).\n",key,position+1,position);
	}
	return 0;
}
