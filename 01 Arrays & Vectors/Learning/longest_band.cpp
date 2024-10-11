#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int longest_band(vector<int> arr){
	unordered_set <int> set;
	int max=0;
	for(int i : arr){
		set.insert(i);
	}
	for(int i : arr){
		if(set.count(i)>0){
			if(set.count(i-1)>0){
				continue;
			} else {
				int count=1;
				while(set.count(i+1)>0){
					count++;
					i++;
				}
				max = count>max?count:max;
			}
		}
	}
	return max;
}

int main (){
	vector <int> arr{1, 9, 3, 0, 18, 5, 4, 2, 10, 7, 12, 6};
	cout<< longest_band(arr)<< endl;
}