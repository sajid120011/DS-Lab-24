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
    void segregate_even_odd() 
    {
        Node* even_start = nullptr;
        Node* even_end = nullptr;
        Node* odd_start = nullptr;
        Node* odd_end = nullptr;
        Node* current = head;
        while (current) 
        {
            int value = current->data;
            if (value % 2 == 0) 
            {
                if (!even_start) 
                {
                    even_start = current;
                    even_end = even_start;
                } 
                else 
                {
                    even_end->next = current;
                    even_end = even_end->next;
                }
            } 
            else 
            {
                if (!odd_start) 
                {
                    odd_start = current;
                    odd_end = odd_start;
                } 
                else 
                {
                    odd_end->next = current;
                    odd_end = odd_end->next;
                }
            }
            current = current->next;
        }
        if (!even_start) 
        {
            return;
        }
        even_end->next = odd_start;
        if (odd_end) 
        {
            odd_end->next = nullptr;
        }
        head = even_start;
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
    ll.insert_end(17);
    ll.insert_end(15);
    ll.insert_end(8);
    ll.insert_end(12);
    ll.insert_end(10);
    ll.insert_end(5);
    ll.insert_end(4);
    ll.insert_end(1);
    ll.insert_end(7);
    ll.insert_end(6);
    cout << "Original List: ";
    ll.display();
    ll.segregate_even_odd();
    cout << "Segregated List (Even first, Odd after): ";
    ll.display();
    return 0;
}
