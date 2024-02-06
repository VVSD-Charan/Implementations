# Implementations 

### Implementation of HashSet

```
class MyHashSet {

    vector<list<int>>arr;
    int max_size = 100;

public:
    MyHashSet() 
    {
        arr.resize(max_size);
    }
    
    list<int>::iterator search(int key,int index)
    {
        return find(arr[index].begin(),arr[index].end(),key);
    }

    void add(int key) 
    {
        int index = (key % max_size);

        if(search(key,index) != arr[index].end())return;
        arr[index].push_back(key);
    }
    
    void remove(int key) 
    {
        int index = (key % max_size);
        list<int>::iterator it = search(key,index);

        if(it == arr[index].end())return;
        arr[index].erase(it);
    }
    
    bool contains(int key) 
    {
        int index = (key % max_size);
        return (search(key,index) != arr[index].end());
    }
};
```

### Implementation of HashMap

```
class MyHashMap {

    vector<list<pair<int,int>>>arr;
    int max_size = 100;

public:
    MyHashMap() 
    {
        arr.resize(max_size);    
    }

    list<pair<int,int>>::iterator search(int key,int index)
    {
        list<pair<int,int>>::iterator it = arr[index].begin();

        while(it != arr[index].end())
        {
            if(it->first == key)return it;
            it++;
        }

        return it;
    }
    
    void put(int key, int value) 
    {
        int index = (key % max_size);
        list<pair<int,int>>::iterator it = search(key,index);

        if(it != arr[index].end())
        {
            arr[index].erase(it);
        }

        arr[index].push_back({key,value});
    }
    
    int get(int key) 
    {
        int index = (key % max_size);
        list<pair<int,int>>::iterator it = search(key,index);

        if(it == arr[index].end())return -1;
        return it->second;     
    }
    
    void remove(int key) 
    {
        int index = (key % max_size);
        list<pair<int,int>>::iterator it = search(key,index);

        if(it == arr[index].end())return;
        arr[index].erase(it);    
    }
};
```
