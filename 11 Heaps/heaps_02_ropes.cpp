#include<iostream>
#include<queue>
using namespace std;

int join_ropes(int ropes[], int n) {

	//min heap
	priority_queue<int,vector<int> , greater<int> > pq(ropes,ropes+n);


	//logic
	int cost = 0;

	while(pq.size() > 1){

		int A = pq.top();
		pq.pop();

		int B = pq.top();
		pq.pop();


		int new_rope = (A+B);
		cost  += new_rope;
		pq.push(new_rope);

	}

	return cost;

}

int join_ropes2(int * ropes, int n){
	priority_queue<int, vector<int>, greater<int>> heap(ropes, ropes+n);

	// for(int i : ropes){
	// 	heap.push(i);
	// }
	int cost=0;
	for(int i=1; i<n; i++){
		int a = heap.top();
		heap.pop();
		int b = heap.top();
		heap.pop();
		cost+=a+b;
		heap.push(a+b);
	}
	// cost+=heap.top();
	return cost;
}

int main() {
	int ropes[] = {4, 3, 2, 6};
	int n = 4;

	cout << join_ropes2(ropes, n) << endl;




	return 0;
}