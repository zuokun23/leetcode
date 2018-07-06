/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //1
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL)
            return l2;
        //把q结点插入p结点的后面
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = l1;
        ListNode *p = dummyHead , *q = l2;
        while(q){
            
            while(p->next && q->val >= p->next->val)
                p = p->next;
            if(p->next == NULL){
                
                p->next = q;
                break;
            }
            
            ListNode* tmp = q;
            q = q->next;//q先溜了
            tmp->next = p->next;
            p->next = tmp;
            p = p->next;//更新
        }
        
        l1 = dummyHead->next;
        delete dummyHead;
        return l1;
    }
};
