#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode(int x){
        val = x;
        next = nullptr;
    }
};

ListNode* removeElements(ListNode* head, int val) {
        ListNode temp(0);
        temp.next = head;

        ListNode* curr = &temp;

        while(curr->next != NULL){
            if(curr->next->val == val){
                ListNode* del = curr->next;
                curr->next = curr->next->next;
                delete del;
            }
            else{
                curr = curr->next;
            }
        }

        return temp.next;
    }

void printLists(ListNode* head){
    ListNode* curr = head;
    while(curr != nullptr){
        cout << curr->val << " ";
        curr = curr->next;
    }
}

int main(){
    ListNode* head = new ListNode(6);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(6);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next->next = new ListNode(6);

    int val = 6;

    head = removeElements(head, val);
    printLists(head);

    return 0;
}