  //LeetCode 206  反转链表
  //Programmer: Luchangcheng  2020/01/22
  //Compiler: gcc version 9.2.1 20191008 (Ubuntu 9.2.1-9ubuntu2)  tested on Ubuntu Kylin 19.10.1
  ListNode* reverseList(ListNode* head) 
  {
        if (head == NULL)
            return NULL;
        stack<ListNode*>stk;
        while (head != NULL)
        {
            stk.push(head);
            head = head->next;
        }

        ListNode* node = stk.top();
        ListNode* ans = node;
        stk.pop();
        while (!stk.empty())
        {
            node->next = stk.top();
            stk.pop();
            node = node->next;
        }
        node->next = NULL;
        
        return ans;
 }
