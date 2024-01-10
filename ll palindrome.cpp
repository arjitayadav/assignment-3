#include <iostream>
struct Node {
    char data;
    Node* next;
    
    Node(char value) : data(value), next(nullptr) {}
};
bool isPalindrome(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return true;
    }
    int length = 0;
    Node* current = head;
    while (current != nullptr) {
        length++;
        current = current->next;
    }
    char arr[length];
    current = head;
    for (int i = 0; i < length; i++) {
        arr[i] = current->data;
        current = current->next;
    }
    for (int i = 0, j = length - 1; i < j; i++, j--) {
        if (arr[i] != arr[j]) {
            return false;
        }
    }

    return true;
}

int main() {
    Node* head = new Node('1');
    head->next = new Node('2');
    head->next->next = new Node('3');
    head->next->next->next = new Node('2');
    head->next->next->next->next = new Node('1');
    if (isPalindrome(head)) {
        std::cout << "The linked list is a palindrome.\n";
    } else {
        std::cout << "The linked list is not a palindrome.\n";
    }
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}