#include<iostream>
#include<queue>
using namespace std;

int my_attempt(){
	priority_queue<int> leftheap;
	priority_queue<int, vector<int>, greater<int>> rightheap;
	int l=0, r=0;

	int d;
	cin>>d;
	float med = d;
	cout<<"med: "<<med<<endl;
	leftheap.push(d);
	l++;
	cin>>d;
	while(d!=-1){
		if(d<med){
			//insert on left heap
			if(l>r){
				int x = leftheap.top();
				leftheap.pop();
				l--;
				rightheap.push(x);
				r++;
				leftheap.push(d);
				l++;
				med = (leftheap.top()+rightheap.top())/2.0;
				// cout<<"l>r med: "<<med<<endl;
			} else{
				leftheap.push(d);
				l++;
				if(l==r) med = (leftheap.top() + rightheap.top())/2.0;
				else med = leftheap.top();
				// cout<<"l<=r med: "<<med<<endl;
			}
		} else{
			//insert on right heap
			if(r>l){
				int x = rightheap.top();
				rightheap.pop();
				r--;
				leftheap.push(x);
				l++;
				rightheap.push(d);
				r++;
				med = (leftheap.top()+rightheap.top())/2.0;
				// cout<<"r>l med: "<<med<<endl;
			} else{
				rightheap.push(d);
				r++;
				if(l==r) med = (leftheap.top() + rightheap.top())/2.0;
				else med = rightheap.top();
				// cout<<"r<=l med: "<<med<<endl;
			}
			// cout<<endl;
		}
		cout<<"med: "<<med<<endl;
		cin>>d;

	}
	return 0;
}

//Running Median Heaps
int main(){



	priority_queue<int> leftheap; //maxheap
	priority_queue<int,vector<int>,greater<int> > rightheap; //min heap

	int d;
	cin>>d;
	leftheap.push(d);

	float med = d;
	cout<< med <<" ";

	cin>>d;
	while(d!=-1){
		//left or right or equal
		if(leftheap.size() > rightheap.size()){
			if(d < med){
				rightheap.push(leftheap.top());
				leftheap.pop();
				leftheap.push(d);
			}
			else{
				rightheap.push(d);
			}
			med = (leftheap.top() + rightheap.top())/2.0;
		}
		else if(leftheap.size()==rightheap.size()){
			if(d < med){
				leftheap.push(d);
				med = leftheap.top();
			}
			else{
				rightheap.push(d);
				med = rightheap.top();
			}

		}
		else{
			if(d < med){
				leftheap.push(d);
			}
			else{
				leftheap.push(rightheap.top());
				rightheap.pop();
				rightheap.push(d);
			}
			med = (leftheap.top() + rightheap.top())/2;

		}

		cout<< med<<" ";
		cin>>d;
	}

	return 0;
}