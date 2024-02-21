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