#include <iostream>
#include <map>

using namespace std;
class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;

    }

    //destructor
    ~Node(){
            int value = this->data;
            //memory free
            if(this->next!=NULL){
                    delete next;
                    this->next = NULL;
            }
    }
};

void insertAtHead(Node* &head,int d){
        //create node to be inserted
        Node* temp = new Node(d);
        temp->next = head;
        head = temp;
}

void insertAtTail(Node* &tail,int d){
    //create node to be inserted
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;

    }

void print(Node* &head){
    if(head == NULL) {
        cout<<"the list is empty"<<endl;
    }
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp= temp->next;
    }
    cout<<endl;
} 

void insertAtPosition(Node* &head,Node* &tail,int position, int d){
    

    //insert at start of list
    if(position == 1){
        insertAtHead(head,d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    //create a loop to reach the position to insert at
    while(cnt<position){
        temp = temp->next;
        cnt++;
    }

    //insert at end of list
    if(temp->next == NULL){
        insertAtTail(tail,d);
        return;
    }

    //now we insert at position
    Node* nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void DeleteNode(Node* &head,int position){
    //delete first node in list
    if(position==1){
        Node* temp = head;
        head = temp->next;
        //memory free kardo
        temp->next = NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;

        while(cnt<position) {
            prev = curr;
            curr = curr->next;;
            cnt++;

    }
    prev->next = curr->next;
    curr->next = NULL;;
    delete curr;
}
}



int main(){
    Node* node1 = new Node(10);

    Node* head = node1;
    Node* tail = node1;
}