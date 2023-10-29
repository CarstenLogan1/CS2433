#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Linked{
    class Node{
    public:
        char data;
        Node * next; 
        
       Node(char c){
            data =c;
        }
        
        
       ~Node(){
            cout << "Node destructor is being called" << endl;
            data = ' ';
            next = nullptr;
        }
    };

  	public:
  		Node * head;
  		int size;
    
    
    Linked(){
        head=NULL;
        size=0;
    }
    
    
    ~Linked(){
        cout << "Linked List destructor is being called" << endl;
        Node * current = head;
        while (current != NULL){
            Node * next = current->next;
            delete current;
            current = next;
        }
        head = NULL;
        size = 0;
    }
    
   
    void addFirst(char c){
        Node * temp=new Node(c);
        temp->next=head;
        head=temp;
        size++;
    }
    
   
    void addLast(char c){
        Node * current=head;
        if(head==nullptr) addFirst(c);
        else{
            while(current){
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
        while(current){
            cout<< current->data <<" ";
            current=current->next;
        }
        cout<<endl;
    }
    
    
    int find(char c){
        Node * current=head;
        int index=0;
        while(current){
            if(current->data==c){
                return index;
            }
            current=current->next;
            index++;
        }
        return -1;
    }
    
    
    void addAt(int position, char c){
        if(position < size && position > 0){
            Node * current=head;
            int index=0;
            while(current){
                if(index+1==position){
                    Node * temp= new Node(c);
                    Node * currentNext=current->next;
                    current->next=temp;
                    temp->next=currentNext;
                    size++;
                    break;
                }
                current=current->next;
                index++;
            }
        }
        else {
        	cout<< "invalid position"<<endl;
        }
    }
    
    void deleteAt(int pos){
    if(pos < 0 || pos >= size){
        cout << "invalid position" << endl;
        return;
    }
    
    Node* current = head;
    Node* previous = nullptr;
    int index = 0;
    
    while (index != pos) {
        previous = current;
        current = current->next;
        index++;
    }

    if (previous != nullptr) {
        previous->next = current->next;
    } else {
        head = current->next;
    }

    delete current;
    size--;
	}
};


int main(int argc, char** argv) {
	Linked * l=new Linked;
	l->addFirst('A');
	l->addFirst('B');
	l->addLast('C');
	l->addLast('x');
	
	l->print();
	
	cout<<"Found x at index "<<l->find('x')<<endl;;
	cout<<"====Adding F to index 3===="<<endl;
	
	l->addAt(3,'F');
	l->print();
	
	cout<<"====Delete index 2========"<<endl;
	cout<<"====Delete index 1 ========"<<endl;
	cout<<" Destruct all Nodes from the LinkedList "<<endl;
	
	return 0;
}


