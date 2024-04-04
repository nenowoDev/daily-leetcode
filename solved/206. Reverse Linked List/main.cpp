
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
    ListNode* reverseList(ListNode* head) {
        ListNode *before=head;
        ListNode *ahead=head;
        ListNode *newhead=head;
        ListNode *tempnewhead=head;

        if(!head)
            return head;
        
        while(newhead->next!=nullptr)
            newhead=newhead->next;
        
        tempnewhead=newhead;

        while(head->next!=nullptr){
            before=head;
            ahead=head->next;

            while(ahead->next!=nullptr){
                ahead=ahead->next;
                before=before->next;
            }
            ahead=nullptr;
            before->next=nullptr;
            tempnewhead->next=before;
            tempnewhead=tempnewhead->next;
        }
        

        return newhead;
        
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

    printList(a.reverseList(list1));

    cout<<"ok";




}