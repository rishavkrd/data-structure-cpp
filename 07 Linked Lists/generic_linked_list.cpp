#include<iostream>
using namespace std;

template <typename T> 
class Node{
public:
	// Node<T> * head;
	T data;
	Node<T> * next;

	Node(){
		this->data = 0;
		next = NULL;
	}
	Node(T data){
		this->data = data;
		this->next = NULL;
		// this->head = this;
	}
	void append(Node<T>* node){
		node->next = this;
		// this->next = node;
	}
	Node<int>* append(int x){
		Node<int>* temp = new Node<int>(x);
		temp->next = this;
		// this->head = temp;
		return temp;
	}

};
template <typename T> 
class LinkedList{
public:
	Node<T> * head;
	LinkedList(){
		this->head = NULL;
	}
	LinkedList(Node<T> * node){
		this->head = node;
	}
	void append(Node<T>* node){
		node->next = this->head;
		this->head = node;
	}
	void append(T val){
		Node<T> * temp = new Node<T>(val);
		temp->next = head;
		this->head = temp;
	}
	void insertInMiddle(int x, int pos){
		Node<T>* current  = this->head;
		
		if(pos==0){
			append(x);
			return;
		}

		Node<T>* temp = new Node<int>(x);
		while(--pos){
			
			current = current->next;
		}
		temp->next = current->next;
		current->next = temp;
		return;
	}
	void reverse(Node<T>* node){
		if(node == NULL) return;
		Node<T>* next = node->next;
		if(next == NULL) {
			node->next = this->head;
			this->head = node;
			return;
		}
		Node<T>* temp = next->next;
		if(node!=this->head) node->next = this->head;		//back link
		else node->next = NULL;
		next->next = node;				//reverse link of consecutive nodes
		this->head = next;
		reverse(temp);
	}
	Node<T>* betterreverse(Node<T>* head){
		if(head==NULL || head->next == NULL){
			return head;
		}
		Node<T> * shead = betterreverse( head->next);
		head -> next -> next = head;
		head -> next = NULL;
		this->head = shead;
		return shead;
	}
	void itrReverse(){
		Node<T> * current = this->head;
		Node<T> * prev= NULL, *next=current->next;

		// current->next = NULL;

		while(current != NULL){
			next = current->next;
			current->next = prev;

			prev = current;
			current = next;
		}
		this->head = prev;
		
	}

	Node<T>* onlyfirstkReverse(Node<T>* head, int k){
		if(head==NULL || head->next == NULL) return head;
		
		// Node<T>* next = head->next;
		Node<T>* shead;
		if(k!=1)shead = kReverse(head->next, k-1);
		else{
			shead = head;
		}
		head->next->next = head;
		head->next = NULL;
		this->head = shead;
		return head;
	}

	Node<T>* kReverse(Node<T>* head, int k){
		Node<T> * current = head;
		Node<T> * prev= NULL, *next=current->next;

		// current->next = NULL;
		int count =1;

		while(current != NULL && count<=k){
			next = current->next;
			current->next = prev;

			prev = current;
			current = next;
			count++;
		}
		if(current!=NULL){
			LinkedList<int>* ll = new LinkedList<int>(current);
			head->next = ll->kReverse(ll->head, k);
		}

		this->head = prev;
		return prev;
		
	}


};

void printLL(Node<int>* head){
	Node<int> * current = head;
	while(current!=NULL){
		cout<<current->data<<endl;
		current = current->next;
	}
}

Node<int>* mergeSortedLinkedList(Node<int> * a, Node<int>* b){
	Node<int> *dummy = new Node<int>();
	Node<int> *node = dummy;
	while(a!=NULL && b!=NULL){

		if(a->data<b->data){
			// temp1 = node->next;
			node->next = a;
			node = a;
			a = a->next;
		} else{
			node->next = b;
			node = b;
			b = b->next;
		}
	}
	if(a!=NULL) node->next = a;
	if(b!=NULL) node->next = b;
	return dummy->next;

}

Node<int>* recMergeSortedList(Node<int>* a, Node<int>* b){
	if(a==NULL) return b;
	if(b==NULL) return a;

	Node<int>* c;
	if(a->data<b->data){
		c = a;
		c->next = recMergeSortedList	(a->next, b);
	} else{
		c = b;
		c->next = recMergeSortedList(a, b->next);
	}
	return c;
}

Node<int>* mergesortLL(Node<int>* head){
	if(head == NULL || head->next == NULL) return head;
	Node<int>* fast=head->next, *slow = head, *head2;

	while(fast!=NULL && fast->next!=NULL){
		fast = fast->next->next;
		slow = slow->next;
	}

	head2 = slow->next;
	slow->next = NULL;
	// cout<<slow->data<<endl;

	return mergeSortedLinkedList (mergesortLL(head), mergesortLL(head2));

}

int main(){
	Node<int> *a = new Node<int>(10);
	Node<int> *b = new Node<int>(11);
	Node<int> * node;
	// a->next = b;
	LinkedList <int> *ll = new LinkedList<int>();


	b->append(a);
	// append(a);
	Node<int>* head = new Node<int>(20);
	head = head->append(15);
	head = head->append(14);
	head = head->append(7);
	head = head->append(5);
	head = head->append(3);

	// ll->append(head);

	
	// Node<int> * current = head;
	ll->append(1);
	// ll->append(7);
	ll->append(3);
	// ll->append(5);
	ll->append(5);
	// ll->append(3);
	ll->append(4);
	ll->append(2);

	// ll->insertInMiddle(55, 5);
	// ll->insertInMiddle(65, 3);
	// ll->betterreverse(ll->head);
	// ll->kReverse(ll->head,2);
	// printLL(head);
	node = mergeSortedLinkedList(head, ll->head);
	// node = recMergeSortedList(head, ll->head);
	node = mergesortLL(ll->head);
	printLL(node);
	return 0;
}

