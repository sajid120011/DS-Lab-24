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
    Node* merge(Node* first, Node* second) 
    {
        if (!first) return second;
        if (!second) return first;
        if (first->data < second->data) 
        {
            first->next = merge(first->next, second);
            first->next->prev = first;
            first->prev = nullptr;
            return first;
        } 
        else 
        {
            second->next = merge(first, second->next);
            second->next->prev = second;
            second->prev = nullptr;
            return second;
        }
    }
    Node* split(Node* head) 
    {
        Node* fast = head, *slow = head;
        while (fast->next && fast->next->next) 
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        Node* second = slow->next;
        slow->next = nullptr;
        if (second) second->prev = nullptr;
        return second;
    }
    Node* merge_sort(Node* node) 
    {
        if (!node || !node->next) return node;
        Node* second = split(node);
        node = merge_sort(node);
        second = merge_sort(second);
        return merge(node, second);
    }
public:
    DoublyLinkedList() : head(nullptr) {}
    void insert_end(int data) {
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
    void sort_list() 
    {
        head = merge_sort(head);
    }
    void remove_duplicates() 
    {
        if (!head) return;
        Node* current = head;
        while (current->next) 
        {
            if (current->data == current->next->data) 
            {
                Node* duplicate = current->next;
                current->next = duplicate->next;
                if (duplicate->next) 
                {
                    duplicate->next->prev = current;
                }
                delete duplicate;
            } 
            else 
            {
                current = current->next;
            }
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
    dll.insert_end(4);
    dll.insert_end(2);
    dll.insert_end(4);
    dll.insert_end(8);
    dll.insert_end(10);
    dll.insert_end(8);
    dll.insert_end(12);
    dll.insert_end(4);
    cout << "Original List: ";
    dll.display();
    dll.sort_list();
    cout << "Sorted List: ";
    dll.display();
    dll.remove_duplicates();
    cout << "List after removing duplicates: ";
    dll.display();
    return 0;
}
