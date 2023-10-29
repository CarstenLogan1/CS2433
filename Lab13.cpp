#include <cstdlib>
#include <iostream>
using namespace std;

class LinkedList{
    class Node{
    public:
        char data;
        Node * next; 
        Node (char c){data =c; }
    }; 

public:
    Node * head;
    int size;

    
    void addFirst(char c){
        Node * temp=new Node(c);
        temp->next=head;
        head=temp;
        size++;
    }

    
    void addLast(char c){
        Node * current=head;
        if(head==nullptr) addFirst(c);
        else {
            while(current) {
                current=current->next;
                if(current->next==nullptr){
                    Node * last=new Node(c);
                    current->next=last;
                    last->next=nullptr;
                    size++;
                    break;
                }
            }
        }
    }

    
    void print(){
        Node * current= head;
        cout<<"[";
        while(current){
            cout<< current->data <<" ";
            current=current->next;
        }
        cout<<"]";
        cout<<endl;
    }

    
    char get(int a){
        if(a < 0 || a >= size){
            cout << "Invalid index!" << endl;
            return -1; // return -1 for invalid index
        }

        Node * current = head;
        for(int i = 0; i < a; i++){
            current = current->next;
        }
        return current->data;
    }

    
    void addAt(int position, char c){
        if(position < 0 || position > size){
            cout << "Invalid position!" << endl;
            return;
        }

        if(position == 0){
            addFirst(c);
            return;
        }

        Node * current = head;
        for(int i = 0; i < position - 1; i++){
            current = current->next;
        }

        Node * newNode = new Node(c);
        newNode->next = current->next;
        current->next = newNode;
        size++;
    }
}; 

int main(int argc, char** argv) {
    LinkedList * l = new LinkedList;
    l->addFirst('A');
    l->addFirst('B');
    l->addLast('C');
    l->addLast('D');
    l->print();

    
    char data = l->get(3);
    cout << "Data at index 3: " << data << endl;

    l->addAt(1, 'a');
    l->addAt(3, 'b');
    l->print();

    return 0;
}
