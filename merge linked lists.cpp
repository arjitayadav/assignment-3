#include <iostream>
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

Node* mergeSortedLists(Node* head1, Node* head2) {
    Node* dummy = new Node(0);
    Node* current = dummy;
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data <= head2->data) {
            current->next = head1;
            head1 = head1->next;
        } else {
            current->next = head2;
            head2 = head2->next;
        }
        current = current->next;
    }
    if (head1 != nullptr) {
        current->next = head1;
    } else {
        current->next = head2;
    }
    Node* mergedHead = dummy->next;
    delete dummy;

    return mergedHead;
}

int main() {
    Node* list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = new Node(5);

    Node* list2 = new Node(2);
    list2->next = new Node(4);
    list2->next->next = new Node(6);
    Node* mergedList = mergeSortedLists(list1, list2);
    std::cout << "Merged List: ";
    while (mergedList != nullptr) {
        std::cout << mergedList->data << " ";
        mergedList = mergedList->next;
    }
    std::cout << std::endl;
    while (list1 != nullptr) {
        Node* temp = list1;
        list1 = list1->next;
        delete temp;
    }

    while (list2 != nullptr) {
        Node* temp = list2;
        list2 = list2->next;
        delete temp;
    }

    return 0;
}