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
    void insert_before(int target, int data) 
    {
        if (!head) return;

        if (head->data == target) 
        {
            insert_front(data);
            return;
        }
        Node* prev = nullptr;
        Node* current = head;
        while (current && current->data != target) 
        {
            prev = current;
            current = current->next;
        }
        if (current) 
        {
            Node* new_node = new Node(data);
            prev->next = new_node;
            new_node->next = current;
        }
    }
    void insert_after(int target, int data) 
    {
        Node* current = head;
        while (current && current->data != target) 
        {
            current = current->next;
        }
        if (current) 
        {
            Node* new_node = new Node(data);
            new_node->next = current->next;
            current->next = new_node;
        }
    }
    void delete_head() 
    {
        if (head) 
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void delete_last() 
    {
        if (!head) return;
        if (!head->next) 
        {  
            delete head;
            head = nullptr;
            return;
        }
        Node* second_last = head;
        while (second_last->next->next) 
        {
            second_last = second_last->next;
        }
        delete second_last->next;
        second_last->next = nullptr;
    }
    void delete_value(int value) 
    {
        if (!head) return;
        if (head->data == value) 
        {
            delete_head();
            return;
        }
        Node* prev = nullptr;
        Node* current = head;
        while (current && current->data != value) 
        {
            prev = current;
            current = current->next;
        }
        if (current) 
        {
            prev->next = current->next;
            delete current;
        }
    }
    int count_nodes() 
    {
        int count = 0;
        Node* current = head;
        while (current) 
        {
            count++;
            current = current->next;
        }
        return count;
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
    ll.insert_front(3);
    ll.insert_front(2);
    ll.insert_end(5);
    ll.insert_after(3, 4);
    ll.insert_before(5, 6);
    ll.display();
    ll.delete_head();
    ll.delete_last();
    ll.delete_value(4);
    ll.display();
    cout << "Number of nodes: " << ll.count_nodes() << endl;
    return 0;
}
