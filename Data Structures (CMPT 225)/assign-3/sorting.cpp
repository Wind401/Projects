// File:        sorting.cpp
// Author:      Geoffrey Tien
//              (your name)
// File:        sorting.cpp
// Author:      Geoffrey Tien
//              (your name)
// Date:        2016-02-08
// Description: Skeleton file for CMPT 225 assignment #3 sorting functions and helpers
//              Function bodies to be completed by you!

// Complete your sorting algorithm function implementations here

# include<iostream>
# include<cstdlib>
# include<stdexcept>
using namespace std;

// Selection Sort
// (your comments here)
template <class T>
int SelectionSort(T arr[], int n)
{
	int count = 0;
	if (n < 0)
	{
    throw out_of_range("Invalid Index");
	}
	else
	{
		for (int i = 0; i < n - 1; ++i)
		{
			int smallestElement = i;
			//find the index of the smallest element by comparing first item with each elements in an array
			for (int j = i + 1; (j < n) && (count++ != -1); ++j) //BAROMETER OPERATION COUNTER SET HERE
			{
				if (arr[j] < arr[smallestElement])
				{
					smallestElement = j;
				}

			}
			//swaps the current item with the smallest item
			T temp = arr[i];
			arr[i] = arr[smallestElement];
			arr[smallestElement] = temp;
		}
	}
	return count;
}


// Quicksort
// (your comments here)
template <class T>
int Quicksort(T arr[], int n)
{
    if(n<0)
    {
        throw out_of_range("Invalid Index");
    }
	int count = 0;
	QuicksortHelper(arr, 0, n - 1, count);
	return count;
}


template <class T>
void QuicksortHelper(T arr[], int low, int high, int& counter)
{
	int pivot;
	if (low < high)
	{
		pivot = QSPartition(arr, low, high, counter);
		QuicksortHelper(arr, low, pivot - 1, counter);				//sorts smalls
		QuicksortHelper(arr, pivot + 1, high, counter);				//sorts bigs
	}
}


template <class T>
int QSPartition(T arr[], int low, int high, int& counter)
{
	//set markers for pivot, smalls and bigs regions
	int pivot = high;
	int LeftWall = low;
	int RightWall = high - 1;
	bool flag= false;
	while (!flag)
	{

		while ((counter++ != -1) && (arr[LeftWall] < arr[pivot]))
		{
			LeftWall++;
		}

		while (((arr[RightWall] > arr[pivot]) && (LeftWall < RightWall)))
		{
			RightWall--;
		}
		//swap elements from 'smalls' and 'bigs' when the value at indexFromLeft < indexFromRight
		if ((LeftWall < RightWall))
		{
			T swap = arr[RightWall];
			arr[RightWall] = arr[LeftWall];
			arr[LeftWall] = swap;
			LeftWall++;
			RightWall--;
		}
		else
		{
			flag = true;
		}
	}
	//swap values at pivot and indexFromRight[or Left since they are pointing to the same index now].
	T swap = arr[pivot];
	arr[pivot] = arr[LeftWall];
	arr[LeftWall] = swap;
	pivot = LeftWall;
	return pivot;
}

// Mergesort
// (your comments here)
template <class T>
int Mergesort(T arr[], int n)
{
	int count = 0;
	if(n<0)
	{
        throw out_of_range("Invalid Index");
	}
	MergesortHelper(arr, 0, n - 1, n, count);
	return count;
}

template <class T>
void MergesortHelper(T arr[], int low, int high, int n, int& counter)
{
	if (low < high) // array has more than 1 element
	{
		int mid = low + (high - low) / 2;

		//sort the left half
		MergesortHelper(arr, low, mid, n, counter);

		//sort the right half
		MergesortHelper(arr, mid + 1, high, n, counter);

		//Merge the sorted halves
		Merge(arr, low, mid, high, n, counter);
	}
}

template <class T>
void Merge(T arr[], int low, int mid, int high, int n, int& counter)
{
	T* leftArray = NULL;
	T* rightArray = NULL;

	int leftWall;
	int rightWall;
	int current;

	int size_of_Left = mid - low + 1;
	int size_of_Right = high - mid;

	leftArray = new T[size_of_Left];
	rightArray = new T[size_of_Right];


	for (leftWall = 0; leftWall < size_of_Left; leftWall++)
	{
		leftArray[leftWall] = arr[low + leftWall];
	}

	for (rightWall = 0; rightWall < size_of_Right; rightWall++)
	{
		rightArray[rightWall] = arr[mid + 1 + rightWall];
	}

	// resets index of each array starting from the smallest 0
	leftWall = 0;
	rightWall = 0;
	current = low;


	while ((leftWall < size_of_Left && rightWall < size_of_Right) && (counter++ != -1)) //BAROMETER OPERATION COUNTER SET HERE
	{
		if ((leftArray[leftWall] <= rightArray[rightWall]))
		{
			arr[current] = leftArray[leftWall];
			leftWall++;
		}
		else
		{
			arr[current] = rightArray[rightWall];
			rightWall++;
		}
		current++;
	}


	while (leftWall < size_of_Left)
	{
		arr[current] = leftArray[leftWall];
		leftWall++;
		current++;
	}


	while (rightWall < size_of_Right)
	{
		arr[current] = rightArray[rightWall];
		rightWall++;
		current++;
	}

	// delete all the dynamically allocated memory
	delete[] leftArray;
	delete[] rightArray;
}

// Shell Sort
// (your comments here)
template <class T>
int ShellSort(T arr[], int n)
{
    if(n<0)
    {
        throw out_of_range("Invalid Index");
    }
	int count = 0;
	int i, j;
	int space;
	T temp;
	space = n / 2;
	//divides the array size in half everytime the loop is executed.
	while (space)
	{

		for (i = space; (i < n) && (count++ != -1); i++) //BAROMETER OPERATION COUNTER GOES HERE
		{
			temp = arr[i];
			j = i;

			while ((j >= space && (arr[j - space] > temp)))
			{
				arr[j] = arr[j - space];
				j = j - space;
			}
			arr[j] = temp;
		}
		space=space/2;
	}
	return count;
}// Randomized Quicksort
// (your comments here)
template <class T>
int RQuicksort(T arr[], int n)
{

  int count = 1;

	if (n < 1)
	{
	throw out_of_range("Invalid Index");
	}

	else if (n == 1 || n == 2)
	{
		QuicksortHelper(arr, 0, n - 1, count);
	}

	count++;
	if (n != 1) {
		int pivot_index = rand() % n;

		RQuicksortHelper(arr, 0, pivot_index, count);
		RQuicksortHelper(arr, pivot_index + 1, n - 1, count);
	}

	return count;

}

template <class T>
void RQuicksortHelper(T arr[], int low, int high, int& counter)
{
	counter = counter + 2; // 1 comparison, 1 assignment
	if (low < high)
	{
		int pivot = RQSPartition(arr, low, high, counter);
		counter++; // 1 assignment

		RQuicksortHelper(arr, low, pivot - 1, counter);
		RQuicksortHelper(arr, pivot + 1, high, counter);
	}
}

template <class T>
int RQSPartition(T arr[], int low, int high, int& counter)
{

    int pivotindex = low + rand()%(high-low+1);
    int tmp=high;
    high=pivotindex;
    pivotindex=tmp;
    return QSPartition(arr, low, high, counter);

	}
