#include <iostream>
using namespace std;
struct Node 
{
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};
class DoublyLinkedList 
{
private:
    Node* head;
public:
    DoublyLinkedList() : head(nullptr) {}
    void insert_front(int data) 
    {
        Node* new_node = new Node(data);
        if (!head) 
        {
            head = new_node;
        } 
        else 
        {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
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
        new_node->prev = last;
    }
    void insert_before(int target, int data) 
    {
        if (!head) return;
        Node* current = head;
        while (current && current->data != target) 
        {
            current = current->next;
        }
        if (current) 
        {
            Node* new_node = new Node(data);
            new_node->next = current;
            new_node->prev = current->prev;
            if (current->prev) 
            {
                current->prev->next = new_node;
            } 
            else 
            {
                head = new_node;  
            }
            current->prev = new_node;
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
            new_node->prev = current;
            if (current->next) 
            {
                current->next->prev = new_node;
            }
            current->next = new_node;
        }
    }
    void delete_head() 
    {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) 
        {
            head->prev = nullptr;
        }
        delete temp;
    }
    void delete_last() 
    {
        if (!head) return;
        Node* last = head;
        if (!head->next) 
        { 
            delete head;
            head = nullptr;
            return;
        }
        while (last->next) 
        {
            last = last->next;
        }
        last->prev->next = nullptr;
        delete last;
    }
    void delete_value(int value) 
    {
        if (!head) return;
        Node* current = head;
        while (current && current->data != value) 
        {
            current = current->next;
        }
        if (current) 
        {
            if (current->prev) 
            {
                current->prev->next = current->next;
            } 
            else 
            {
                head = current->next;  
            }
            if (current->next) 
            {
                current->next->prev = current->prev;
            }
            delete current;
        }
    }
    void display() 
    {
        Node* current = head;
        while (current) 
        {
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};
int main() 
{
    DoublyLinkedList dll;
    dll.insert_front(5);
    dll.insert_front(10);
    dll.insert_end(15);
    dll.insert_after(10, 12);
    dll.insert_before(15, 13);
    cout << "List after insertions: ";
    dll.display(); 
    dll.delete_head();  
    dll.delete_last();  
    dll.delete_value(13);  
    cout << "List after deletions: ";
    dll.display();  
    return 0;
}
