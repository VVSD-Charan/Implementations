### Cycle detection in linked list

```

ListNode* detectCycle(ListNode *head) 
{
    if(head == NULL || head->next == NULL)return NULL;

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast && fast->next)
    {
        slow = slow -> next;
        fast = fast -> next -> next;

        if(slow == fast)
        {
            ListNode* temp = head;

            while(temp != slow)
            {
                temp = temp->next;
                slow = slow->next;
            }

            return slow;
        }
    }

    return NULL;    
}

```

### Merge Sort on linked list 

```

class Solution{
    
    Node* getMiddle(Node* head)
    {
        if(head == NULL || head->next == NULL)return head;
        
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    Node* mergeLists(Node* l,Node* r)
    {
        if(l == NULL)return r;
        if(r == NULL)return l;
        
        Node* new_head = NULL;
        Node* tail = NULL;
        
        Node* list1 = l;
        Node* list2 = r;
        
        while(list1 && list2)
        {
            if(list1->data < list2->data)
            {
                if(new_head == NULL)
                {
                    new_head = newNode(list1->data);
                    tail = new_head;
                }
                else
                {
                    tail->next = newNode(list1->data);
                    tail = tail->next;
                }
                list1 = list1->next;
            }
            else
            {
                if(new_head == NULL)
                {
                    new_head = newNode(list2->data);
                    tail = new_head;
                }
                else
                {
                    tail->next = newNode(list2->data);
                    tail = tail->next;
                }
                list2 = list2->next;
            }
        }
        
        if(list1)tail->next = list1;
        if(list2)tail->next = list2;
        
        return new_head;
    }
    
    Node* mergeSort(Node* head)
    {
        if(head == NULL || head->next == NULL)return head;
        
        Node* mid = getMiddle(head);
        
        Node* temp = mid->next;
        mid->next = NULL;
        
        Node* l = mergeSort(head);
        Node* r = mergeSort(temp);
        
        return mergeLists(l,r);
    }
    
public:
    Node* sortList(Node* head)
    {
        // Your Code Here
        return mergeSort(head);
    }
};

```