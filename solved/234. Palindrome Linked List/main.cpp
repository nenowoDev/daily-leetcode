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
    bool isPalindrome(ListNode* head) {
        
        stack<int> test;
        
        ListNode* temp;

        if(head==nullptr)
            return true;
        
        temp=head;
        test.push(temp->val);

        while(temp->next!=nullptr){
            temp=temp->next;
            test.push(temp->val);
        }

        temp=head;
        while(temp->next!=nullptr){
        
            if(temp->val!=test.top())
                return false;
            test.pop();
            temp=temp->next;
        }


        return true;
        
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
    list1->next->next->next = new ListNode(3);
    list1->next->next->next->next = new ListNode(2);
    list1->next->next->next->next->next = new ListNode(1);

    ListNode *list2 = new ListNode(1000000);
    list2->next = new ListNode(1000001);
    list2->next->next = new ListNode(1000002);
    Solution a;

    // printList(a.isPalindrome(list1));
    cout<<a.isPalindrome(list1);





}