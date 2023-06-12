#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void printLinkedList(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << std::endl;
}

// also add iterative logic to reverse linked list
Node* reverseLinkedList(Node* node) {
    if(node == nullptr || node->next == nullptr) {
        return node;
    }

    Node* reversedLL = reverseLinkedList(node->next);
    node->next->next = node;
    node->next = nullptr;
    return reversedLL;
}


int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node{1, nullptr};
    Node* second = new Node{2, nullptr};
    Node* third = new Node{3, nullptr};
    Node* fourth = new Node{4, nullptr};
    Node* fifth = new Node{5, nullptr};

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    std::cout << "Original linked list: ";
    printLinkedList(head);

    // Reverse the linked list
    Node* reversedHead = reverseLinkedList(head);

    std::cout << "Reversed linked list: ";
    printLinkedList(reversedHead);

    // Clean up the memory
    Node* current = reversedHead;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}







