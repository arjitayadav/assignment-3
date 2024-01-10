#include <iostream>
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};
Node* sortLinkedList(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    bool swapped;
    Node* temp;
    Node* lastSorted = nullptr;

    do {
        swapped = false;
        temp = head;

        while (temp->next != lastSorted) {
            if (temp->data > temp->next->data) {
                std::swap(temp->data, temp->next->data);
                swapped = true;
            }
            temp = temp->next;
        }

        lastSorted = temp;
    } while (swapped);

    return head;
}
void printLinkedList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}
Node* insertAtBeginning(Node* head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    return newNode;
}

int main() {
    Node* head = nullptr;
    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 1);
    head = insertAtBeginning(head, 4);
    head = insertAtBeginning(head, 2);

    std::cout << "Original linked list: ";
    printLinkedList(head);
    head = sortLinkedList(head);

    std::cout << "Sorted linked list: ";
    printLinkedList(head);

    return 0;
}