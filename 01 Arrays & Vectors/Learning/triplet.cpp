#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> triplets(vector <int> arr, int sum){
	sort(arr.begin(), arr.end());
	vector<vector<int>> res;
	for(int i=0; i<arr.size();i++){
		int target = sum - arr[i];

		int l=i+1,r=arr.size()-1;
		while (l<r){
			if(arr[l] + arr[r] < target){
				l++;
			}
			else if(arr[l] + arr[r] > target){
				r--;
			}
			else{
				vector <int> val;
				val.push_back(arr[i]);
				val.push_back(arr[l]);
				val.push_back(arr[r]);

				res.push_back(val);
				l++;
				r--;
			}
		}
	}
	return res;
}

int main(){
	vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
	int S = 18;

	auto result = triplets(arr,S);

	for(auto v : result){
		for(auto no : v){
			cout<<no<<",";
		}
		cout<<endl;
	}
	return 0;
}