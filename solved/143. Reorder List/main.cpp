#include <stack>
#include <iostream>
using namespace std;
//0 1 2 3 4 a - - b 9 10

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reorderList(ListNode* head) {
        
        stack<ListNode*> stack;
        
        ListNode* temp;
        ListNode* b;
        
        if(head==nullptr||head->next==nullptr)
            return head;
        
        temp=head;
        stack.push(temp);
        while(temp->next!=nullptr){
            temp=temp->next;
            stack.push(temp);
        }


        temp=head;
        b=head;
        int i=0;
        
        
        int sizee=stack.size();
        if(stack.size()%2)
            sizee+=1;
        

        while(i<(sizee/2)-1){
            temp=temp->next;
            
            b->next=stack.top();
            stack.pop();
            
            stack.top()->next=nullptr;
            b=b->next;
            b->next=temp;
            b=b->next;
            i++;
            
        }
        
        


        return head;
        
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){

    
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);
    list1->next->next->next = new ListNode(4);
    list1->next->next->next->next = new ListNode(5);
    list1->next->next->next->next->next = new ListNode(6);

    ListNode *list2 = new ListNode(1000000);
    list2->next = new ListNode(1000001);
    list2->next->next = new ListNode(1000002);
    Solution a;

    printList(a.reorderList(list1));
    // cout<<a.reorderList(list1);





}