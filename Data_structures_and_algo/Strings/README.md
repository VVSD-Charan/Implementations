## KMP (Knuth Morris Pratt) Algorithm

<li>The KMP matching algorithm makes finding patterns faster by noticing when parts of the pattern repeat.</li> 
<li>It speeds up the search by skipping unnecessary comparisons based on what it already knows about the pattern and text.</li>
<li>This reduces the worst-case complexity to O(n+m).</li>
<li>Space complexity is O(n+m).</li> <br>

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

## Rabin Karp algorithm

```

class Solution
{
    bool verify(string &s,string t)
    {
        for(int i = 0 ; i < s.length() ; i++)
        {
            if(s[i] != t[i])return false;
        }
        
        return true;
    }
    
    public:
        vector <int> search(string pattern, string text)
        {
            //code here.
            int m = pattern.length();
            int n = text.length();
            
            int pow_m = 1;
            int digits = 26;
            int prime = 109;
            
            for(int i = 0 ; i < m-1 ; i++)
            {
                pow_m = ((pow_m * digits) % prime); 
            }
            
            int required_hash = 0;
            int current_hash = 0;
            
            for(int i = 0 ; i < m ; i++)
            {
                required_hash = (((required_hash * digits)%prime) + (pattern[i]-'a'+1))%prime;
                current_hash = (((current_hash * digits)%prime) + (text[i]-'a'+1))%prime;
            }
            
            vector<int>arr;
            if(current_hash == required_hash){
                if(verify(pattern,text.substr(0,m))){
                    arr.push_back(1);
                }
            }
            
            for(int i = m ; i < n ; i++)
            {
                int to_be_removed = (text[i-m] - 'a' + 1)*pow_m;
                current_hash = (((((current_hash - to_be_removed)*digits) % prime) + (text[i]-'a'+1) + prime)%prime); 
                
                if(current_hash == required_hash){
                    if(verify(pattern,text.substr(i-m+1,m))){
                        arr.push_back(i-m+2);
                    }
                }
            }
            
            return arr;
        }
     
};


```
