#include <iostream>
using namespace std;

class Node {
public:
    Node* next;

    Node(int data, int id) { //Constructor
        this->data = data;
        this->id = id;
        this->next = nullptr;
    }

    Node(const Node *s) { //Copy Constructor
        data = s->data;
        next = nullptr;
        id = s->id + 1;
    }
    
    //Node(const Stack& copy) : Stack{copy.getData(), copy.getId()} {} //The Displacement constructor
    
    //Node(int data, int id) : data(data),  id(id){} //Constructor with an initialization list

    ~Node() { cout << "Object was deleted" << endl; }


    int getData() const{return data;}
    int getId() const { return id; }

private:
    int data;
    int id;
};


class Stack {
public:

    void push(int data) {
        if (head == nullptr) {
            head = new Node(data, 0); 
        }
        else {
            Node* newNode = new Node(data, size());
            Node* currentNode = head;
            while (currentNode->next != nullptr) {
                currentNode = currentNode->next;
            }
            newNode->next = currentNode->next;
            currentNode->next = newNode;
        }
    }

    int pop() {
        int lastElemId = size()-1;
        int tempData = searchById(lastElemId)->getData();
        delete searchById(lastElemId);
        searchById(lastElemId - 1)->next = nullptr;
        return tempData;
    }
    int checkPop() {return searchById(size() - 1)->getData(); }



    Node* searchById(int id) {
        Node* currentNode = head;
        while (id != currentNode->getId() && currentNode->next != nullptr) {
            currentNode = currentNode->next;
        }
        return currentNode;
    }

    bool empty() {
        if (head == nullptr) {return true;}
    }
    
    int size() {
        if (head == nullptr) { return 0; }
        else {
            Node* current = head; 
            int i = 1;
            while (current->next != nullptr) {
                current = current->next;
                i++;

            }
            return i;
        }
    }

    void clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* tempNext = current->next;
            delete current;
            current = tempNext;
        }
    }


    void printStack() {
        if (head == nullptr) {cout << "Stack is empty";}
        else {
            Node* currentNode = head;
            for (int i = 0; i < 5; i++) {
                cout << "Element number " << currentNode->getId() << " = " << currentNode->getData() << endl;
                currentNode = currentNode->next;
            }
        }
    }

    void top(int arg) {
        pop();
        push(arg);
    }

private:
    Node* head;
};

int main()
{
    cout << "Hello World!\n";
    Stack* stack = new Stack();
    stack->push(2);
    stack->push(3);
    stack->push(4);
    stack->push(6);
    stack->push(5);
    stack->printStack();
    cout << endl;
    stack->top(7);
    stack->printStack();

}