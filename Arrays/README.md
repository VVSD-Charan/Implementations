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