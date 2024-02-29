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