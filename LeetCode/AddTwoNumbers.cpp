
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *t1 = l1;
        ListNode *t2 = l2;
        int size1 = 0, size2 = 0;
        while (t1 != nullptr)
        {
            size1++;
            t1 = t1->next;
        }
        while (t2 != nullptr)
        {
            size2++;
            t2 = t2->next;
        }
        if (size1 < size2)
        {
            ListNode *temp = l1;
            l1 = l2;
            l2 = temp;
        }
        t1 = l1;
        t2 = l2;
        ListNode *value = l1;
        int tempval;
        bool carry = false;
        ListNode *lastnode;
        while (t1 != nullptr)
        {
            tempval = t1->val;
            t1 = t1->next;
            if (carry)
            {
                tempval += 1;
                carry = false;
            }
            if (t2 != nullptr)
            {
                tempval += t2->val;
                t2 = t2->next;
            }
            carry = tempval >= 10 ? true : false;
            tempval = carry ? tempval - 10 : tempval;

            value->val = tempval;
            value = value->next;
            if (t1 != nullptr && t1->next == nullptr)
            {
                lastnode = t1;
            }
        }
        if (carry)
        {
            ListNode *last = new ListNode(1);
            t1 = last;
            lastnode->next = t1;
        }
        return l1;
    }
};