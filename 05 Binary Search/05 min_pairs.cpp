#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

// void min_pair(vector<int> a1,vector<int> a2){


// 	//Sort the array
// 	sort(a2.begin(),a2.end());

// 	int p1,p2;
// 	int diff = INT_MAX;

// 	//iteratte over 1 array and look for closes elements in the second array
// 	for(int x : a1){
// 		auto lb = lower_bound(a2.begin(),a2.end(),x) - a2.begin();

// 		//left
// 		if(lb>=1 and x - a2[lb-1] < diff){
// 			diff = x - a2[lb-1];
// 			p2 = x;
// 			p1 = a2[lb-1];
// 		}
// 		//greater / right
// 		if(lb!=a2.size() and a2[lb]-x < diff){
// 			diff = a2[lb] - x;
// 			p1 = x;
// 			p2 = a2[lb];
// 		}

// 	}
// 	cout<<"Min Pair "<<p1<<" and "<<p2 <<endl;
// 	return;

// }

void min_pair(vector<int> a1, vector <int> a2){
	sort(a2.begin(), a2.end());
	int d=INT_MAX, min_d = INT_MAX;
	int p1,p2;

	for(int i : a1){
		auto u=0;
		// auto u = upper_bound(a2.begin(), a2.end(), i) - a2.begin();
		auto l = lower_bound(a2.begin(), a2.end(), i) - a2.begin();
		//left
		if(l >= 1 && i - a2[l - 1] < d){
			d = i - a2[l-1];
			p2 = i;
			p1 = a2[l-1];
			// u = l-1;
		}
		if(l!=a2.size() && a2[l]-i <d){
			d = a2[l]-i;
			p1 = i;
			p2 = a2[l];

		}
		//handle the upper case where, there is no element less than element of a1.
		// int ub = abs(a2[u] - i);
		// int lb = abs(i - a2[l]);
		// cout<<"i: "<<i<<" up, low: "<<a2[u]<<','<<a2[l]<<endl;
		// d = min(ub, lb);

		// if(d<min_d){
		// 	min_d = d;
		// 	p1 = i;
		// 	p2 = ub<lb?a2[u]:a2[l];
		// }
	}
	cout<<p1<<','<<p2<<endl;
	return;
}

int  main(){

	vector<int> a1 = {-1, 5, 10, 20, 3};
	vector<int> a2 = {26, 134, 135, 15, 17};
	min_pair(a1,a2);


	return 0;
}