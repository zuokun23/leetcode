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
    ListNode* removeElements(ListNode* head, int val) {
        //if(head == NULL)
        //    return NULL;
        
        //如果头节点的值要删除时
        //if(head->val == val){
        //    ListNode* delNode = head;
        //    head = head->next;
        //    delete delNode;
        //}
        while(head != NULL && head->val == val){//陷阱1：可能新head的值要删除,用while 陷阱2：可能新的head==NULL,不能访问其值
            ListNodne* delNode = head;
            head = head->next;
            delete delNode;
        }
        
        //陷阱3：完成上面循环此时head == NULL ,当然此时初始head == NULL判断可以去除
        if(head == NULL)
            return NULL;
        
        ListNode* cur = head;
        while( cur->next != NULL ){//为了安全，要先判断cur->next是否为空
            
            if(cur->next->val == val){
                //删除cur->next
                ListNode* delNode = cur->next;
                cur->next = delNode->next;
                delete delNode;
                //很多语言不需要手动释放内存
                //delNode->next = NULL;这样系统知道这些节点没有用，系统自动释放内存
            }else
                cur = cur->next;
            
        }
        return head;
    }
};
//2
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        
        ListNode* cur = dummyHead;
        while(cur->next != NULL){
            
            if(cur->next->val == val){
                ListNode* delNode = cur->next;
                cur->next = delNode->next;
                delete delNode;
            }else
                cur = cur->next;
        }
        
        //return dummyHead->next;
        ListNode* retNode = dummyHead->next;
        delete dummyHead;
        
        return retNode;
    }
};
