#include<iostream>
#include<queue>
using namespace std;


// int main(){

// 	int arr[] = {10,15,20,13,6,90};
// 	int n = sizeof(arr)/sizeof(int);

// 	priority_queue<int, vector<int> , greater<int> >  heap;

// 	for(int x : arr){
// 		heap.push(x);
// 	}

// 	while(!heap.empty()){
// 		cout << heap.top() <<endl;
// 		heap.pop(); 
// 	}




// 	return 0;
// }

class Compare{
public:
	bool operator()(int a, int b){
		return a>b;
	}
};

void printNearestCars(int k){
	int arr[] = {5,4,3,2,1,6,7,8};
	int n = 8;
	priority_queue<int> heap;

	for(int i=0;i<k;i++){
		heap.push(arr[i]);
	}
	for(int i=k;i<n;i++){
		if(arr[i]<heap.top()) {
			heap.pop();
			heap.push(arr[i]);
		}
	}
	while(!heap.empty()){
		cout<<heap.top()<<endl;
		heap.pop();
	}
}

int main(){
	priority_queue<int, vector<int>, Compare> heap;
	int arr[] = {10,15,20,13,6,90};
	int n = sizeof(arr)/sizeof(int);

	for(int i : arr){
		heap.push(i);
	}
	// while(!heap.empty()){
	// 	cout<<heap.top()<<endl;
	// 	heap.pop();
	// }
	int k;
	cin>>k;
	printNearestCars(k);
	return 0;
}