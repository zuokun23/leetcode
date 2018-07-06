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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        
        while(cur->next != NULL){//要删除cur后面的结点数目
            
            if(cur->next->next == NULL || cur->next->val != cur->next->next->val){//没有要删除的结点
                cur = cur->next;
                continue;
            }
            //要删除结点
            ListNode* pos = cur->next->next;
            while(pos->next != NULL && pos->next->val == pos->val)
                pos = pos->next;
            
            ListNode* del = cur->next;//删除
            cur->next = pos->next;
            while(del != pos){
                ListNode* tmp = del;
                del = del->next;
                delete tmp;
            }
        }
        //返回
        ListNode* retNode = dummyHead->next;
        delete dummyHead;
        return retNode;
    }
};
//2
//思路：创建一个虚拟头结点可以为操作带来极大的遍历，然后就是如果发现重复元素，则开始判断以后的是不是等于这个元素，是的话都删掉。不是的话就遍历下一个。
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode *pHead = new ListNode(0), *p=pHead, *q;
        pHead->next = head;
        int val = head->val;
        while(p)
        {
            q = p->next;
            if(q && q->next && q->val == q->next->val)
            {
                int val = q->val;
                while(q && q->val == val)
                {
                    p->next = q->next;
                    delete q;
                    q = p->next;
                }
            }
            else p = p->next;
        }
        head = pHead->next;
        delete pHead;
        return head;
    }
};
