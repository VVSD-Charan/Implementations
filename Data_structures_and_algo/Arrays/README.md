## Dutch national flag algorithm

<li>It is a three pointer solution to sort an array of 0 1 2</li>
<li>Time complexity of algorithm is O(n).</li>
<li>Space complexity of algorithm is O(1).</li>

```

 void sortColors(vector<int>& nums) 
    {
        int start_index = 0;
        int end_index = nums.size()-1;
        int index = 0;

        while(index <= end_index && start_index <= end_index)
        {
            if(nums[index] == 2)
            {
                swap(nums[index],nums[end_index]);
                end_index--;
            }
            else if(nums[index] == 0)
            {
                swap(nums[index],nums[start_index]);
                start_index++;
                index++;
            }
            else
            {
                index++;
            }
        }    
    }

```

## Kadane's algorithm
<li>It is an algorithm to find out maximum sum of subarray in an array.</li>
<li>Time complexity is O(n) and space complexity is O(1).</li>

```

int maxSubArray(vector<int>& nums) 
    {
        int max_sum = INT_MIN;
        int n = nums.size();
        int curr_sum = 0;

        for(int i = 0 ; i < n ; i++)
        {
            curr_sum = curr_sum + nums[i];
            max_sum = max(max_sum,curr_sum);

            if(curr_sum < 0)
            {
                curr_sum = 0;
            }
        }    

        return max_sum;
    }

```

### Maximum product subarray(Modified kadane's algorithm)
<li>The issue in this problem is when we have odd number of negative elements.</li>
<li>To find maximum product in odd number of negative elements case , we must either eliminate last negative or first negative element.</li>
<li>So, if we traverse array in both directions i.e left to right and right to left , we can get maximum product after neglecting first and last negative elements.</li>
<li>Time complexity of this algorithm is O(n) and space complexity is O(1).</li>

```

int maxProduct(vector<int>& nums) 
    {
        int max_product = INT_MIN;
        int curr_product = 1;
        int n = nums.size();

        for(int i = 0 ; i < n ; i++)
        {
            curr_product = curr_product * nums[i];
            max_product = max(max_product, curr_product);

            if(curr_product == 0)curr_product = 1;
        }

        curr_product = 1;

        for(int i = n-1 ; i >= 0 ; i--)
        {
            curr_product = curr_product * nums[i];
            max_product = max(max_product , curr_product);

            if(curr_product == 0)curr_product = 1;
        }

        return max_product;
    }

```

## Moore's voting algorithm

<li>According to the problem, an element with frequency greater than (n/2) is considered as a majority element.</li>
<li>We can observe that if an element has a frequency > (n/2) i.e majority element , then difference between frequency of majority element and combined frequencies of all other elements will be > 0.</li>
<li>In this algorithm we maintain a variable named majority_element, and a variable counter which is incremented when current element is our assumed majority_element, otherwise it is decremented. When counter becomes zero , it means that frequencies of candidate majority element and other elements have been cancelled.</li>
<li>After iterating entire array, we get a candidate majority element. Now, we must verify if it is actually the element we wanted. If it is not the one, then it means that there is no majority element in array.</li>

```

int majorityElement(vector<int> v)
{
	int majority_element = v[0];
	int counter = 1;
	int n = v.size();

	for(int i = 1 ; i < n ; i++)
	{
		if(v[i] == majority_element)
		{
			counter++;
		}
		else
		{
			counter--;
		}

		if(counter == 0)
		{
			counter = 1;
			majority_element = v[i];
		}
	}

	int freq = 0;

	for(int i = 0 ; i < n ; i++)
	{
		freq = freq + (v[i] == majority_element);
	}

	return (freq > (n/2) ? majority_element : -1);
}

```

### Rotating array towards right k times

<li>If arr = [1,2,3,4,5,6,7] and k = 3 , then resultant should be [5,6,7,1,2,3,4] i.e last k elements [5,6,7] will be shifted to right.</li>
<li>We must partition array into two parts , second of size k ([5,6,7]) as they must be moved right and first partition of size n-k ([1,2,3,4]).</li>
<li>Reverse both the parts, then they become   [4,3,2,1] | [7,6,5]</li>
<li>Now , reverse the entire array , we get [5,6,7,1,2,3,4] which is the required resultant array.</li>

```

 void reverseArray(vector<int>&nums,int i,int j)
    {
        while(i < j)
        {
            swap(nums[i],nums[j]);
            i = i + 1;
            j = j - 1;
        }
    }

    void rotate(vector<int>& nums, int k) 
    {
        int n = nums.size();
        if(k >= n){
            k = (k % n);
        }
        if(k == 0)return;

        k = n - k;
        reverseArray(nums,0,k-1);
        reverseArray(nums,k,n-1);
        reverseArray(nums,0,n-1);
    }

```

## Count number of reverse pairs (Using merge sort algorithm)

<li><strong>Question :</strong> Given an integer array nums, return the number of reverse pairs in the array.A reverse pair is a pair (i, j) where: 
0 <= i < j < nums.length and
nums[i] > 2 * nums[j].</li>
<li>We can solve this using merge sort. Slight modification of merge sort is that we use an extra function just before merging recursively sorted sub-arrays.</li>
<li>Time complexity is O(NlogN) in worst case.</li>
<li>Space complexity is O(2*N) as we use a vector of pairs.</li>

```

 void mergeArrays(vector<pair<int,int>>&arr,int lo,int mid,int hi)
    {
        vector<pair<int,int>>temp(hi-lo+1);
        int i = lo;
        int j = mid + 1;
        int index = 0;

        while(i <= mid && j <= hi)
        {
            if(arr[i].first > arr[j].first)
            {
                temp[index] = arr[j];
                j = j + 1;
            }
            else
            {
                temp[index] = arr[i];
                i = i + 1;
            }
            index = index + 1;
        }

        while(i <= mid)
        {
            temp[index++] = arr[i++];
        }

        while(j <= hi)
        {
            temp[index++] = arr[j++];
        }

        for(i = lo ; i <= hi ; i++)
        {
            arr[i] = temp[i - lo];
        }
    }

    void countReversePairs(vector<pair<int,int>>&arr,int lo,int mid,int hi,int &counter)
    {
        int total_count = 0;
        int j = mid + 1;

        for(int i = lo ; i <= mid ; i++)
        {
            while(j <= hi && (long long)arr[i].first > (long long)2*(long long)arr[j].first)
            {
                total_count++;
                j = j + 1;
            }
            counter += total_count;
        }
    }

    void mergeSort(vector<pair<int,int>>&arr,int lo,int hi,int &counter)
    {
        if(lo >= hi)return;

        int mid = (lo + hi)>>1;

        mergeSort(arr,lo,mid,counter);
        mergeSort(arr,mid+1,hi,counter);

        countReversePairs(arr,lo,mid,hi,counter);
        mergeArrays(arr,lo,mid,hi);
    }

    int reversePairs(vector<int>& nums) 
    {
        vector<pair<int,int>>arr;
        int n = nums.size();

        for(int i = 0 ; i < n ; i++)
        {
            arr.push_back({nums[i],i});
        }   

        int ans = 0;
        mergeSort(arr,0,n-1,ans);
        return ans;
    }

```