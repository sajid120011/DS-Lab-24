#include <iostream>
using namespace std;
struct Node 
{
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
class SinglyLinkedList 
{
private:
    Node* head;
public:
    SinglyLinkedList() : head(nullptr) {}
    void insert_front(int data) 
    {
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }
    void insert_end(int data) 
    {
        Node* new_node = new Node(data);
        if (!head) 
        {
            head = new_node;
            return;
        }
        Node* last = head;
        while (last->next) 
        {
            last = last->next;
        }
        last->next = new_node;
    }
    void reverse_list() 
    {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr) 
        {
            next = current->next;  
            current->next = prev;  
            prev = current;        
            current = next;
        }
        head = prev;  
    }
    void display() 
    {
        Node* current = head;
        while (current) 
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};
int main() 
{
    SinglyLinkedList ll;
    ll.insert_front(1);
    ll.insert_front(2);
    ll.insert_front(3);
    ll.insert_front(4);
    cout << "Original list: ";
    ll.display();
    ll.reverse_list();
    cout << "Reversed list: ";
    ll.display();
    return 0;
}
