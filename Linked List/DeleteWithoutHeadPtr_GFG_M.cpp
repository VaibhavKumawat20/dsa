#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to delete a node value when 
// only a pointer to that node is given
void deleteNode(Node* delNode ) {
    
    // Ensure the node to be deleted is not the last node
    if (delNode  == nullptr || delNode ->next == nullptr) {
        return;  
    }

    // Copy data from the next node into the current node
    Node* temp = delNode ->next;
    delNode ->data = temp->data;

    // Link current node to the node after the next node
    delNode ->next = temp->next;

    // Delete the next node (the one whose data was copied)
    delete temp;
}

void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    
    // Creating a linked list: 4 -> 5 -> 6 -> 7 -> 8
    Node* head = new Node(4);
    head->next = new Node(5);
    head->next->next = new Node(6);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(8);

    deleteNode(head);

    printList(head);

    return 0;
}