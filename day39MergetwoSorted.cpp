#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    
    // Constructor with parameter
    Node(int data) : val(data), next(nullptr) {}
    
    // Default constructor for dummy node
    Node() : val(0), next(nullptr) {}
};

// Function to merge two sorted linked lists
Node* sortedlinkedlist(Node* list1, Node* list2) {
    // If one of the lists is empty, return the other
    if(list1 == nullptr) return list2;
    if(list2 == nullptr) return list1;
    
    // Create a dummy node to serve as the new head
    Node* new_head = new Node();
    Node* ptr3 = new_head;
    Node* ptr1 = list1;
    Node* ptr2 = list2;
    
    // Merge the two lists while both have nodes
    while(ptr1 != nullptr && ptr2 != nullptr) {
        if(ptr1->val < ptr2->val) {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        } else {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }
    
    // Append the remaining nodes (if any)
    if(ptr1 != nullptr)
        ptr3->next = ptr1;
    else
        ptr3->next = ptr2;
    
    // Get the head of the merged list and free the dummy node
    Node* merged_head = new_head->next;
    delete new_head;
    return merged_head;
}

// Helper function to print the linked list
void printList(Node* head) {
    while(head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create first sorted linked list: 1 -> 3 -> 5
    Node* list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = new Node(5);
    
    // Create second sorted linked list: 2 -> 4 -> 6
    Node* list2 = new Node(2);
    list2->next = new Node(4);
    list2->next->next = new Node(6);
    
    // Merge the two sorted linked lists
    Node* merged = sortedlinkedlist(list1, list2);
    
    // Print the merged linked list
    cout << "Merged sorted linked list: ";
    printList(merged);
    
    return 0;
}
