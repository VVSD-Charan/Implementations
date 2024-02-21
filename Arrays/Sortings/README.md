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
 
        // Move elements of arr[0..i-1],
        // that are greater than key, 
        // to one position ahead of their
        // current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

```