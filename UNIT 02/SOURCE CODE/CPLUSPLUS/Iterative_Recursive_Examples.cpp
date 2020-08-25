
/*************************************************************************************/
/*                      ITERATIVE AND RECURSIVE ALGORITHMS                           */
/* This script contains a few more examples of iterative and recursive algorithms    */
/*                                                                                   */
/*************************************************************************************/


#include <iostream>

using namespace std;


/******************************************************************************/
/*                              PRINT ARRAY VALUES                            */
/******************************************************************************/

// ITERATIVE FUNCTON TO DISPLAY ARRAY VALUES ON STANDARD OUTPUT */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << "\t";
	cout << endl;
}


// RECURSIVE FUUNCTON TO DISPLAY ARRAY VALUES ON STANDARD OUTPUT */
void recursivePrintArray(int arr[], int startIndex, int endIndex)
{
	if (startIndex > endIndex) {}
	else
	{
		cout << arr[startIndex] << "\t";
		recursivePrintArray(arr, startIndex + 1, endIndex);
	}

}


/******************************************************************************/
/*                            INDEX OF SMALLEST                               */
/* let A[0..n-1] be an array of n values indexed from 0 to n-1.               */
/* The indexofSmallest function loops through values in array A and returns   */
/* the index of the smallest value                                            */
/******************************************************************************/

//ITERATIVE IndexOfSmallest FUNCTION
int indexOfSmallest(int arr[], int startIndex, int endIndex)
{
	int smallestIndex = startIndex;
	for (int i = startIndex; i <= endIndex; i++)
	{
		if (arr[i] < arr[smallestIndex])
			smallestIndex = i;
	}

	return smallestIndex;
}

//RECURSIVE IndexOfSmallest FUNCTION
int recursiveIndexOfSmallest(int a[], int startIndex, int endIndex)
{
	if (startIndex == endIndex)
		return startIndex;

	// Find index of smallest of remaining elements 
	int smallIndex = recursiveIndexOfSmallest(a, startIndex + 1, endIndex);

	// Return minimum of current and remaining. 
	return (a[startIndex] < a[smallIndex]) ? startIndex : smallIndex;
}


/******************************************************************************/
/*                               SELECTION SORT                               */
/******************************************************************************/
/* PSEUDOCODE                                                                 */
/* BEGIN                                                                      */
/*    let A[0..n-1] be an array of n values indexed from 0 to n-1             */
/*    for each array index value i  starting from 0 to n-1 do                 */
/*    BEGIN                                                                   */
/* 	      find index of smallest value (say t) in the range A[i..n-1];        */
/* 		  Swap the values A[i] and A[t]                                       */
/* 	  END                                                                     */
/* END                                                                        */
/******************************************************************************/

//utlity function to swap any two values
void swap(int& xp, int& yp)
{
	int temp = xp;
	xp = yp;
	yp = temp;
}

//ITERATIVE SELECTION SORT FUNCTION
void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray 
	for (i = 0; i < n - 1; i++)
	{
		// Find the minimum element in unsorted array 
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		// Swap the found minimum element with the first element 
		swap(arr[min_idx], arr[i]);
	}
}



//REVISED ITERATIVE SELECTION SORT FUNCTION-- uses indexOfSmallest function 
void SelectionSort2(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		// Find the minimum element in unsorted array 
		int min_idx = indexOfSmallest(arr, i, n - 1);

		// Swap the found minimum element with the first element 
		swap(arr[min_idx], arr[i]);
	}
}



//ITERATIVE SELECTION SORT FUNCTION
void recursiveSelectionSort(int a[], int n, int startIndex = 0)
{
	// Return when starting index and size n are same 
	if (startIndex == n)
		return;

	// calling indexOfSmallest function for minimum index 
	int k = indexOfSmallest(a, startIndex, n - 1);

	// Swapping when index nd minimum index are not same 
	if (k != startIndex)
		swap(a[k], a[startIndex]);

	// Recursively calling selection sort function 
	recursiveSelectionSort(a, n, startIndex + 1);
}




/******************************************************************************/
/*                              LINEAR SEARCH                                 */
/* let A[0..n-1] be an array of n values indexed from 0 to n-1.               */
/* let x be a value/element in the array                                      */
/* The linearSearch function loops throught array A and returns the index     */
/* position of value x. It returns -1 if x is not found in array A            */
/******************************************************************************/

// ITERATIVE LINEAR SEARCH ALGORITHM
int linearSearch(int arr[], int n, int x)
{
	int i;
	for (i = 0; i < n; i++)
		if (arr[i] == x)
			return i;
	return -1;
}


// RECURSIVE LINEAR SEARCH ALGORITHM
int recursiveLinearSearch(int arr[], int l, int r, int x)
{
	if (r < l)
		return -1;
	if (arr[l] == x)
		return l;
	if (arr[r] == x)
		return r;
	return recursiveLinearSearch(arr, l + 1, r - 1, x);
}



/******************************************************************************/
/*                              BINARY SEARCH                                 */
/* let A[0..n-1] be a SORTED array of n values indexed from 0 to n-1.         */
/* let x be a value/element in the array                                      */
/* The binarySearch function loops throught array A and returns the index     */
/* position of value x. It returns -1 if x is not found in array A            */
/******************************************************************************/

// RECURSIVE BINARY SEARCH FUNCTION
int binarySearch(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		// If the element is present at the middle 
		// itself 
		if (arr[mid] == x)
			return mid;

		// If element is smaller than mid, then 
		// it can only be present in left subarray 
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);

		// Else the element can only be present 
		// in right subarray 
		return binarySearch(arr, mid + 1, r, x);
	}

	// We reach here when element is not 
	// present in array 
	return -1;
}


// ITERATIVE BINARY SEARCH FUNCTION
int iterativeBinarySearch(int arr[], int l, int r, int x)
{
	while (l <= r) {
		int m = l + (r - l) / 2;

		// Check if x is present at mid 
		if (arr[m] == x)
			return m;

		// If x is greater, ignore left half 
		if (arr[m] < x)
			l = m + 1;

		// If x is smaller, ignore right half 
		else
			r = m - 1;
	}

	// if we reach here, then element was 
	// not present 
	return -1;
}


int main()
{
	int arr[] = { 64, 25, 12, 22, 11 };
	int n = sizeof(arr) / sizeof(arr[0]);       // determine size of array

	recursivePrintArray(arr, 0, n - 1);         // calls recursive printArray
	cout << endl;
	cout << linearSearch(arr, 5, 25) << endl;   // calls iterative linearSearch

	cout << endl;
	cout << recursiveLinearSearch(arr, 0, n - 1, 25) << endl; // calls recursive linearSearch

	recursiveSelectionSort(arr, n);            // calls recursive selection sort
	cout << "Sorted array: \n";
	printArray(arr, n);

	cout << endl;
	cout << binarySearch(arr, 0, n - 1, 25) << endl; // calls recursive binary search


	cout << endl;
	cout << iterativeBinarySearch(arr, 0, n - 1, 25) << endl; // calls iterative binary search

	system("pause");
	return 0;
}
