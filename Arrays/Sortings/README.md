### Bubble sort

<li>We keep elements in correct position.</li>
<li>We place elements in correct positions from right to left.</li>
<li>We repeatedly swap adjacent elements if they are in wrong order.</li>
<li>Time complexity in average and worst case is O(n^2)</li>
<li>Space complexity is O(n).</li>
<li>Worst case happens if elements are in descending order.</li>

```

void bubbleSort(int arr[], int n) 
{ 
    int i, j; 

    for (i = 0; i < n - 1; i++) 
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        } 
    }
} 

```


### Selection Sort

<li>In this algorithm , we repeatedly find minimum element in unsorted part and keep it at the back of sorted part. </li>
<li>Unlike bubble sort , in selection sort we start keeping eleemnts in correct positions from left to right.</li>
<li>Time complexity in average and worst case is O(n^2)</li>
<li>Space complexity is O(1)</li>

```

void selectionSort(int arr[], int n)  
{  
    int i, j, min_idx;  
  
    for (i = 0; i < n-1; i++)  
    {  
        min_idx = i;  
        for (j = i+1; j < n; j++) 
        { 
            if (arr[j] < arr[min_idx])
            {  
                min_idx = j;
            }  
        }  
        swap(&arr[min_idx], &arr[i]);  
    }  
}  

```

### Insertion Sort

<li>In this algorithm , we keep correcting the order of left sub-array.</li>
<li>Average and worst case time complexity is O(n^2).</li>
<li>Time complexity of best case is O(n).</li>

```

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

```


### Merge Sort algorithm

<li>In this algorithm , we split array recursively into halves until it cannot be broken further i.e till array has only one element remaining. Then we start merging broken sub-arrays into sorted order.</li>
<li>These sorted subarrays will slowly be combined to get sorted array.</li>
<li>Time complexity is O(NlogN)</li>
<li>Space complexity is O(N)</li>
<li>It can be used to sort large datasets.</li>
<li>For small data sets merge sort has higher time complexity than some other sorting algorithms.</li>

```

void merge(int array[], int const left, int const mid,
           int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
 
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
 
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
 
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
 
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
 
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
 
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;
 
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

```

### Quick sort algorithm

<li>In quick sort algorithm, we choose an element as pivot, keep it in its correct position , keep lesser elements in left and greater elements in right subarrays. After placing pivot in correct position, we then recursively sort left and right subarrays.</li>
<li>Quick sort is an algorithm based on Divide and conquer.</li>
<li>Choices to chosse pivot : 
    <ol>
        <li>Picking first element always as pivot.</li>
        <li>Picking last element always as pivot.</li>
        <li>Picking random element as a pivot.</li>
        <li>Pick middle element as pivot.</li>
    </ol>
</li>
<li>Quick sort algorithm has an average case complxity of θ(NlogN)</li>
<li>Worst case time complexity of quick sort is O(N^2), when array is already sorted.</li>
<li>If we donot consider recursive stack space , then space complexity is O(1) , else it is O(N)</li>
<li>Quick sort is efficient for large data sets.</li>
<li>Quick sort has low overhead , as it only requires a small amount of memory to function.</li>
<li>It is not a good choice for small data sets.</li>
<li>It is not a stable sort i.e if two elements have same value , then their relative order in sorted array will not be maintained.</li>

```

int partitionArray(int input[], int start, int end) 
{
	int pivot = input[end];
	int first_index = start-1;

	for(int i = start ; i <= end ; i++)
	{
		if(input[i] < pivot)
		{
			first_index++;
			swap(input[first_index],input[i]);
		}
	}

	swap(input[first_index+1],input[end]);
	return (first_index + 1);
}

void quickSort(int input[], int start, int end) 
{
	if(start < end)
	{
		int partition_index = partitionArray(input,start,end);

		quickSort(input,start,partition_index-1);
		quickSort(input,partition_index+1,end);
	}
}

```