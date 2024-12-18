#include <iostream>
#include <cmath>
using namespace std;

struct Node
{
    int info;     
    Node* next;  
                 
};

void print_list(Node* top)
{
    Node* p = top; 
    while (p != nullptr) {
        cout << p->info << " "; 
        p = p->next; 
    }
}

bool list_is_sorted(Node* top)
{
    Node* p = top; 

    while (p != nullptr && p->next != nullptr) {
      
        if (p->info < p->next->info)
            return false;
        p = p->next;  
    }

    return true;
}

bool is_prime(int number)
{
    if (number < 2) return false; 
    if (number == 2) return true;  
    if (number % 2 == 0) return false; 
    int r = sqrt(number);
    for (int d = 3; d <= r; d += 2)  
        if (number % d == 0) return false;
    return true;
}

void sort_list(Node* top)
{
    for (Node* a = top; a->next != nullptr; a = a->next)
        for (Node* b = a->next; b != nullptr; b = b->next)
            if (a->info < b->info) swap(a->info, b->info);
}

void duplicate_numbers(Node* top)
{
    Node* p = top;
    while (p != nullptr) {
        
        if (p->info % 10 == 0) {
            Node* q = new Node;  
            q->info = p->info;  
            q->next = p->next;    
            p->next = q;
            p = q->next; 
        }
        else {
            p = p->next; 
        }
    }
}

void remove_numbers(Node*& top)
{
    while (top != nullptr && is_prime(top->info)) {
        Node* temp = top->next;
        delete top;
        top = temp;
    }

    Node* p = top;
    while (p != nullptr && p->next != nullptr) {
        Node* temp = p->next;
        if (is_prime(temp->info)) { 
            p->next = temp->next;
            delete temp;
        }
        else {
            p = temp;
        }
    }
}

void delete_list(Node * top)
{
    Node * p = top;
    while (p != nullptr) {
        Node * temp = p->next;
        delete p;
        p = temp;
    }
}

int main()
{
    Node * top = nullptr;

    int n;   
    cin >> n; 
    
    int x;
    cin >> x;

    top = new Node;
    top->info = x;
    top->next = nullptr;

    Node * pp = top;

   
    for (int i = 1; i < n; i++) {
        cin >> x;
        Node * p = new Node;  
        pp->next = p;  
        p->info = x;  
        p->next = nullptr; 
        pp = p;  
    }

    cout << "Введённый список: ";
    print_list(top);

    cout << endl;

    sort_list(top);
    cout << "Отсортированный список: ";
    print_list(top);

    cout << endl;
    duplicate_numbers(top);
    cout << "Список после дублирования элементов, оканчивающихся на 0: ";
    print_list(top);

    cout << endl;

    remove_numbers(top);
    cout << "Список после удаления простых чисел(элементов): ";
    print_list(top);
    cout << endl;
    delete_list(top);

    return 0;
}