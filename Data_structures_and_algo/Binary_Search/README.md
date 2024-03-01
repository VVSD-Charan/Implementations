### Finding median of two sorted arrays
<li>This can be solved using two pointers as well which takes time complexity of O(n+m).</li>
<li>Optimal way is to use binary search on how many elements can we take from first array from picking nothing (0 elements) to picking all elements(n elements).</li>

```
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        if(nums1.size() > nums2.size())return findMedianSortedArrays(nums2,nums1);

        int n = nums1.size();
        int m = nums2.size();

        int required = (n + m + 1)/2;
        int lo = 0;
        int hi = n;

        while(lo <= hi)
        {
            int n1 = (lo + hi)>>1;
            int n2 = required - n1;

            int l1 = n1 > 0 ? nums1[n1-1] : INT_MIN;
            int l2 = n2 > 0 ? nums2[n2-1] : INT_MIN;
            int r1 = (n1 < n && n1 >= 0) ? nums1[n1] : INT_MAX;
            int r2 = (n2 < m && n2 >= 0) ? nums2[n2] : INT_MAX;

            if(l1 <= r2 && l2 <= r1)
            {
                if(((n + m) % 2) == 0)
                {
                    double median = ((double)max(l1,l2) + (double)min(r1,r2))/2.0;
                    return median;
                }
                return (double)max(l1,l2);
            }
            else if(l1 > r2)
            {
                hi = n1-1;
            }
            else
            {
                lo = n1+1;
            }
        }

        return (double)0;
    }

```

### Peak element
 <li><strong>Question : </strong>An element is considered to be peak if it's value is greater than or equal to the values of its adjacent elements (if they exist). The array is guaranteed to be in ascending order before the peak element and in descending order after it.</li>
 <li>This problem can be solved using binary search.</li>
 <li>if arr[mid] >= arr[mid-1] , then it means that till the index mid , the array is still in ascending order. So, the peak will be towards right side of the index. In this case , we will shift low to mid.</li>
 <li>if arr[mid] < arr[mid-1] , then it means that the descending order has already started. In this case, the peak element will remain on the left side. So , we shift high in this case.</li>
 <li>Time complexity is O(logN) , as we just perform simple binary search.</li>
 <li>Space complexity is O(1) , as we just use low , high and mid variables.</li>

 ```

int peakElement(int arr[], int n)
    {
       int lo = 0;
       int hi = n-1;
       
       while(hi - lo > 1)
       {
           int mid = (lo + hi)>>1;
           
           if(arr[mid] >= arr[mid-1])
           {
               lo = mid;
           }
           else
           {
               hi = mid;
           }
       }
       
       if((lo == 0 || arr[lo] >= arr[lo-1]) && (lo == n-1 || arr[lo] >= arr[lo+1]))return lo;
       return hi;
    }

 ```