// LinkedLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// The linked list stores data in sequential storage, like arrays.Though the data are stored sequentially, the memory locations are not contiguous.
// Unlike an array, the linked list can store data of different data types.

#include <iostream>

// Node class to represent
// a node of the linked list.
class Node {
public:
    int data;
    Node* next;
    // UPDATE //
    // This makes thid Node class capable of being used in a doubly-linked list
    Node* prev;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
        // UPDATE //
        prev = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        // UPDATE //
        this->prev = NULL;
    }
};

// Linked list class to
// implement a linked list.
class Linkedlist {
    Node* head;
    // UPDATE //
    // We can track the end of the list now as well, and traverse
    // backwards from it if need be.
    Node* tail;

public:
    // Default constructor
    Linkedlist() {
        this->head = NULL;
        // UPDATE //
        this->tail = NULL;
    }

    // Function to insert a
    // node at the end of the
    // linked list.
    void insertNode(int);

    // Function to print the
    // linked list.
    void printList();

    // Function to delete the
    // node at given position.
    void deleteNode(int);

    // Function to print the
    // linked list backwards.
    void printListBackwards();
};

// Function to insert a new node.
void Linkedlist::insertNode(int data) {
    // Create the new Node.
    Node* newNode = new Node(data);

    // Assign to head
    if (head == NULL) {
        head = newNode;
        return;
    }

    // Traverse till end of list
    Node* temp = head;
    while (temp->next != NULL) {
        // Update temp
        temp = temp->next;
    }
    // UPDATE //
    // Temp should be the last node, which we can set to tail.
    tail = temp;

    // UPDATE //
    // Insert at the last position, give it a prev value of the old tail, and
    // update tail to be the newly inserted node.
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

// Function to delete the
// node at given position
void Linkedlist::deleteNode(int nodeOffset) {
    Node* temp1 = head, * temp2 = NULL;
    int ListLen = 0;

    // If list is empty
    if (head == NULL) {
        std::cout << "List empty." << std::endl;
        return;
    }

    // Find length of the linked-list.
    while (temp1 != NULL) {
        temp1 = temp1->next;
        ListLen++;
    }

    // Check if the position to be
    // deleted is less than the length
    // of the linked list.
    if (ListLen < nodeOffset) {
        std::cout << "Index out of range"
            << std::endl;
        return;
    }

    // Declare temp1 to head
    temp1 = head;

    // If we are deleting the head:
    if (nodeOffset == 1) {

        // Update head
        head = head->next;
        // UPDATE //
        // When we delete the head, we have to set the new head's prev to null.
        head->prev = NULL;
        delete temp1;
        return;
    }

    // UPDATE //
    // If we are deleting the tail
    // We create a pointer for the node that will become the new tail, and
    // assign it. we then delete the old tail, set the new tail's next
    // value as NULL, and update the tail value.
    if (nodeOffset == ListLen) {
        Node* newTail = tail->prev;
        delete tail;
        newTail->next = NULL;
        tail = newTail;
        return;
    }

    // Traverse the list to
    // find the node to be deleted.
    while (nodeOffset-- > 1) {

        // Update temp2
        temp2 = temp1;

        // Update temp1
        temp1 = temp1->next;
    }

    // Change the next pointer
    // of the previous node.
    temp2->next = temp1->next;

    // UPDATE //
    // The way the traversal is setup now is temp2->next is pointing towards
    // the correct node, but temp2->next also needs to point backwards to the
    // correct node, which is temp2.
    temp2->next->prev = temp2;

    // Delete the node
    delete temp1;
}

// Function to print the
// nodes of the linked list.
void Linkedlist::printList() {
    Node* temp = head;

    // Check for empty list.
    if (head == NULL) {
        std::cout << "List empty" << std::endl;
        return;
    }

    // Traverse the list.
    while (temp != NULL) {
        std::cout << temp->data << " " << std::endl;
        temp = temp->next;
    }
}

// This function prints the list backwards, starting from the tail. First, I
// create a temp node that I will use to traverse the list with. I then check
// if the list is empty, and if it is, print that and return out of the function.
// Otherwise, I can traverse the list from the tail, same as we do going
// forwards, just by using the prev value node instead of the next node.
void Linkedlist::printListBackwards() {
    Node* tmp = tail;

    if (head == NULL) {
        std::cout << "List empty" << std::endl;
        return;
    }

    while (tmp != NULL) {
        std::cout << tmp->data << std::endl;
        tmp = tmp->prev;
    }
}

// Driver Code
int main() {
    Linkedlist list;

    // Inserting nodes
    list.insertNode(1);
    list.insertNode(2);
    list.insertNode(3);
    list.insertNode(4);

    std::cout << "Elements of the list are: " << std::endl;

    // Print the list
    list.printList();
    std::cout << std::endl;

    // Delete node at position 2.
    list.deleteNode(2);

    std::cout << "Elements of the list are: " << std::endl;
    list.printList();
    std::cout << std::endl;

    std::cout << "Now let's do it backwards!" << std::endl;
    list.printListBackwards();
    std::cout << std::endl;

    return 0;
}