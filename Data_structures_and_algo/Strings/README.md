### KMP (Knuth Morris Pratt) Algorithm

The KMP matching algorithm makes finding patterns faster by noticing when parts of the pattern repeat. It speeds up the search by skipping unnecessary comparisons based on what it already knows about the pattern and text. This reduces the worst-case complexity to O(n+m).

```

vector <int> search(string pat, string txt)
        {
            //code here
            string res = pat + "$" + txt;
            vector<int>match(res.length());
            
            vector<int>arr;
            
            match[0] = 0;
            for(int i = 1 ; i < res.length() ; i++)
            {
                int j = match[i-1];
                
                while(j > 0 && res[i] != res[j])
                {
                    j = match[j-1];
                }
                
                if(res[i] == res[j])
                {
                    j = j + 1;
                }
                match[i] = j;
                
                if(match[i] == pat.length())arr.push_back(i);
            }
            
            for(int i = 0 ; i < arr.size() ; i++)
            {
                int end_index = arr[i] - pat.length();
                int start_index = end_index - pat.length() + 1;
                
                arr[i] = start_index;
            }
            
            return arr;
        }

```
