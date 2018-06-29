/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //非递归算法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* pre = NULL;//初始化
        ListNode* cur = head;//初始化
        while(cur != NULL){
            
            ListNode* next = cur->next;//初始化 + 更新
            
            cur->next = pre;
            pre = cur;//更新
            cur = next;//更新
        }
        
        return pre;//此时cur==NULL
    }
};

//递归算法
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        // 递归终止条件
        if(head == NULL || head->next == NULL)
            return head;

        ListNode* rhead = reverseList(head->next);

        // head->next此刻指向head后面的链表的尾节点
        // head->next->next = head把head节点放在了尾部
        head->next->next = head;
        head->next = NULL;

        return rhead;
    }
};
