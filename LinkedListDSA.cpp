#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        // Constructor to initialize a node
        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }
};

class LinkedList {
    public:
        Node* head;
        int size;

        LinkedList(){
            this->head = nullptr;
            this->size = -1;
        }

        void insertAtEnd(int data) {
            Node* newNode = new Node(data);
            if (this->head == nullptr) {
                this->head = newNode; 
            } else {
                Node* temp = this->head;
                while (temp->next != nullptr) {
                    temp = temp->next; 
                }
                temp->next = newNode; 
            }
            this->size++; 
        }

        void insertAtFront(int data){
            Node* newNode = new Node(data);
            if(this->head == nullptr){
                this->head = newNode;
            }else{
                newNode->next = this->head;
                this->head = newNode;
            }
        }

        void insertAtIndex(int index,int data){
            Node* newNode = new Node(data);
            if(index == 0){
                insertAtFront(data);
            }
            else if(index > 0 && index <= this->size){
                Node* temp = this->head;
                for(int i = 0; i<index; i++){
                    temp = temp->next;
                }
                newNode->next = temp->next;
                temp->next = newNode;
            }
            size++;
        }

        void updateAtIndex(int index, int data){
            if(index == 0){
                this->head->data = data;

            }else if(index > 0 && index <= this->size){
                Node* temp = this->head;
                for(int i=0; i<index;i++){
                    temp = temp->next;
                }
                temp->data = data;
            }
        }

        void deleteAtIndex(int index){
            if (index == 0){
                Node* toDelete = this->head;
                this->head = this->head->next;
                delete toDelete;
            }else if(index > 0 && index <= this->size){
                Node* temp = this->head;
                for(int i=0; i<index-1; i++){
                    temp = temp->next;
                }
                Node* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
            }
        }

        void deleteAtFront(){
            if(this->head == nullptr){
                cout<<"List is empty"<<endl;
                return;
            }
            Node* toDelete = this->head;
            this->head = this->head->next;
            delete toDelete;
        }

        void deleteAtEnd(){
            if(this->head == nullptr){
                cout<<"List is empty"<<endl;
                return;
            }
            if(this->head->next == nullptr){
                delete this->head;
                this->head = nullptr;
                return;
            }
            Node* temp = this->head;
            while(temp->next->next != nullptr){
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
        
        void displayList(){
            Node* temp = this->head;
            while (temp != nullptr) {
                cout << temp->data << " -> ";
                temp = temp->next; 
            }
            cout << "NULL" << endl; 
        }


};

int main() {
    LinkedList list;
    int choice;

    do{
        cout<<"Enter 1 to insert at end"<<endl;
        cout<<"Enter 2 to insert at front"<<endl;
        cout<<"Enter 3 to insert at index"<<endl;
        cout<<"Enter 4 to update at index"<<endl;
        cout<<"Enter 5 to delete at index"<<endl;
        cout<<"Enter 6 to display the list"<<endl;
        cout<<"Enter 0 to exit"<<endl;
        cin>>choice;

        switch(choice){
            case 1:{
                int data;
                cout<<"Enter the data to insert at end: ";
                cin>>data;
                list.insertAtEnd(data);
                break;
            }
            case 2:{
                int data;
                cout<<"Enter the data to insert at front: ";
                cin>>data;
                list.insertAtFront(data);
                break;
            }
            case 3:{
                int index, data;
                cout<<"Enter the index to insert at: ";
                cin>>index;
                cout<<"Enter the data to insert at index "<<index<<": ";
                cin>>data;
                list.insertAtIndex(index, data);
                break;
            }
            case 4:{
                int index, data;
                cout<<"Enter the index to update: ";
                cin>>index;
                cout<<"Enter the data to update at index "<<index<<": ";
                cin>>data;
                list.updateAtIndex(index, data);
                break;
            }
            case 5:{
                int index;
                cout<<"Enter the index to delete: ";
                cin>>index;
                list.deleteAtIndex(index);
                break;
            }
            case 6:{
                cout<<"The linked list is: ";
                list.displayList();
                break;
            }
            case 0:{
                cout<<"Exiting..."<<endl;
                break;
            }
            default:{
                cout<<"Invalid choice. Please try again."<<endl;
                break;
            }
        }
    }while(choice != 0);

    return 0;
}