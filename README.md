# Implementations 

### Implementation of HashSet

class MyHashSet {

    vector<list<int>>arr;
    int max_size = 1e6;

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
