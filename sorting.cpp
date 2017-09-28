// File:        sorting.cpp
// Author:      Geoffrey Tien
//              (your name)
// Date:        2015-06-10
// Description: Skeleton file for CMPT 225 assignment #3 sorting functions and helpers
//              Function bodies to be completed by you!

// Complete your sorting algorithm function implementations here

// selection sort implementation.
//in reference to lecture note "07-exception-sorting-1154" page.10
template <class T>
int SelectionSort(T arr[], int n)
{
	int comparison = 0;
	for(int i = 0; i < n-1; i++)
	{
		int smallest = i;              
		for(int j = i+1; j<n;j++)             //barometer function
		{
			if ( arr[j] < arr[smallest])
			{
				smallest = j;
			}		
			comparison++;
		}
		T temp = arr[i];
		arr[i]=arr[smallest];
		arr[smallest]=temp;
	}
	return comparison;
}

//implementation of Quicksort
template <class T>
int Quicksort(T arr[], int n)
{
	int baro = 0;
	int high = n-1;
	int low = 0;
	 QuicksortHelper(arr, low, high, baro);
	  return baro;
}

// Quicksort Helper function implementation
template <class T>
void QuicksortHelper(T arr[], int low, int high, int& counter)
{
	  if (low < high)
  {
	  int pivot = QSPartition(arr, low, high, counter);
	  QuicksortHelper(arr, low, pivot-1, counter);
	  QuicksortHelper(arr, pivot+1, high, counter);
  }
}

// the partition function for Quick Sort
// in reference to "http://www.sourcetricks.com/2011/06/what-is-quick-sort-algorithm-how-to.html#.VYpLnPlVhBc"
template <class T>

int QSPartition(T arr[], int low, int high, int& counter)
{
	 T pivot = arr[high];   //set pivot to the last item in the arr                     
    while ( low < high )                         
    {
        while ( arr[low] < pivot || arr[high] > pivot)     // barometer instruction              
		{ 
			if(arr[low] < pivot)             //increment low if item at position low is less than pivot;  
			{low++;}
			else
			{high--;}
			counter++;
		}
 
        if ( arr[low] == arr[high] )            //if they are equal we dont have to swap any thing thus low++ allows us to terminate the loop
			{low++;}
        else if ( low < high )
        {
            T temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
        }
    }
    return high;
}
// Mergesort Implementation
template <class T>
int Mergesort(T arr[], int n)
{
	int low = 0;
	int high = n-1;
	int baro = 0;

	MergesortHelper(arr, low, high, n, baro);
	return baro;
}

// Mergesort helper function
template <class T>
void MergesortHelper(T arr[], int low, int high, int n, int& counter)
{
  if (low < high)
  {
	  int mid = (high+low)/2;
	MergesortHelper(arr, low, mid,n,counter); // sort the left half
	MergesortHelper(arr,mid+1,high,n,counter); //sort the right half
	Merge(arr, low,mid,high,n,counter); // merge the sorted half
  }

}

// in reference to textbook page 316
template <class T>
void Merge(T arr[], int low, int mid, int high, int n, int& counter)
{
	T* tempArr= new T[n];                // need a dynamite temporary array of size n
	int low1=low;          //fisrt element of  left subarray
	int high1=mid;		   //last element of left subarray
	int low2=mid+1;			//first element of right subarray
	int high2=high;			//last element of right subarray

	int i=low1;         //next availilable location in temparry
	while((low1 <= high1) && (low2<=high2))           //copy smaller item in to temparry
	{
		if (arr[low1] <= arr[low2])
		{
			tempArr[i] = arr[low1];         
			low1++;
		}
		else
		{
			tempArr[i]=arr[low2];
			low2++;
		}
		i++;
	}
	while(low1<=high1)   //finish the first subarray
	{
		tempArr[i] = arr[low1];
		low1++;
		i++;
	}
	while(low2<=high2)  //finish the second subarray
	{
		tempArr[i] = arr[low2];
		low2++;
		i++;
	}
	for(i=low;i<=high;i++)            // copy the result back to the original array
	{
		arr[i]= tempArr[i]; 
		counter++;					//this for loop executes the most among all for/while loop, thus it is the barometer function
	}   
	delete[] tempArr;
	
}

// in reference to http://www.sanfoundry.com/cplusplus-program-implement-shell-sort/
template <class T>
int ShellSort(T arr[], int n)
{
  int j;
  int counter = 0;
  //devide array by 2 everytime
  for (int gap = n / 2; gap > 0; gap /= 2)
  {
    for (int i = gap; i < n; ++i)
    {
      T temp = arr[i];
	   counter++;
      for (j = i; j >= gap && temp < arr[j - gap]; j -= gap)          //barometer instruction
      {
        arr[j] = arr[j - gap];
		counter++;
      }
      arr[j] = temp;

    } 

  }
  return counter;
}