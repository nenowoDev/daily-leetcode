
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

        ListNode *temp=list1;
        ListNode *temp2=list1;
        

        for(int i=0;i<=b;i++)
            temp2=temp2->next;
        

        for(int i=0;i<a-1;i++)
                temp=temp->next;      
        
        temp->next=list2;


        while(temp->next!=nullptr)
            temp=temp->next;
        
        temp->next=temp2;

        return list1;


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

    
    ListNode *list1 = new ListNode(10);
    list1->next = new ListNode(1);
    list1->next->next = new ListNode(13);
    list1->next->next->next = new ListNode(6);
    list1->next->next->next->next = new ListNode(9);
    list1->next->next->next->next->next = new ListNode(5);

    ListNode *list2 = new ListNode(1000000);
    list2->next = new ListNode(1000001);
    list2->next->next = new ListNode(1000002);
    Solution a;

    printList(a.mergeInBetween(list1,3,4,list2));




}