#include<iostream>

using namespace std;

class Node{
    public:
    int val;
    Node *next;

    Node(int v){
        this->val = v;
        this->next = NULL;
    }
    Node* append(Node* n){
        n->next = this;
        return n;
    }
};

Node* createLL(){
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5);
    Node *n6 = new Node(6);
    Node *n7 = new Node(7);
    Node *n8 = new Node(8);

    Node* head = n8;
    head = head->append(n7);
    head = head->append(n6);
    head = head->append(n5);
    head = head->append(n4);
    head = head->append(n3);
    head = head->append(n2);
    head = head->append(n1);

    return head;
}


Node* reverseLL(Node* head, int count){
    if(count==1){
        return head;
    }
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        return head;
    }
    // cout<<head->val<<endl;
    Node* nextNode = head->next;
    Node* newHead = reverseLL(nextNode, count-1);
    nextNode->next = head;
    head->next = NULL;

    return newHead;

}


Node* kreverse(Node* head, int k){
    if(head == NULL){
        return NULL;
    }
    Node* nextChain=head;
    int count = k;
    while(nextChain!=NULL && count!=0){
        nextChain = nextChain->next;
        count--;
    }
    Node* newHead = reverseLL(head, k);

    if(nextChain!=NULL) head->next = kreverse(nextChain, k);

    return newHead;
}

int main(){
    
    Node* head = createLL();

    head = kreverse(head, 3);

    while(head!=NULL){
        cout<<head->val<<endl;
        head = head->next;
    }

    return 0;
}