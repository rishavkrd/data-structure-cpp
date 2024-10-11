#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// int lower_bound(vector<int> arr,int key){

// 	int s = 0;
// 	int e = arr.size() - 1;

// 	int ans = -1;

// 	while(s<=e){
// 		int mid = (s+e)/2;

// 		if(arr[mid]==key){
// 			ans = mid;
// 			e = mid - 1;
// 		}
// 		else if(arr[mid] > key){
// 			e = mid - 1;
// 		}
// 		else{
// 			s = mid + 1;
// 		}
// 	}
// 	return ans;

// }
// int upper_bound(vector<int> arr,int key){

// 	int s = 0;
// 	int e = arr.size() - 1;

// 	int ans = -1;

// 	while(s<=e){
// 		int mid = (s+e)/2;

// 		if(arr[mid]==key){
// 			ans = mid;
// 			s = mid + 1;
// 		}
// 		else if(arr[mid] > key){
// 			e = mid - 1;
// 		}
// 		else{
// 			s = mid + 1;
// 		}
// 	}
// 	return ans;

// }

int lower_bound(vector<int> arr, int key){
	int s=0, e=arr.size()-1;
	int res=-1;
	while(s<=e){
		int mid = (s+e)/2;
		if(key==arr[mid]){
			res = mid;
			e = mid -1;
		} else if(key > arr[mid]){
			s = mid + 1;
		} else{
			e = mid - 1;
		}
	}
	return res;

}

int upper_bound(vector<int> arr, int key){
	int s=0, e = arr.size()-1;
	int res=-1;

	while(s<=e){
		int mid = (s+e)/2;
		if(arr[mid]==key){
			res = mid;
			s = mid + 1;
		}
		else if(key>arr[mid]){
			s = mid +1;
		} else{
			e = mid -1;
		}
	}
	return res;
}

int main(){

	vector<int> arr = {0,1,1,2,3,3,3,3,3,4,5,5,5,10};
	int n = arr.size();

	cout<< upper_bound(arr,4) - lower_bound(arr,4)   + 1 <<endl;

	//STL
	cout << upper_bound(arr.begin(),arr.end(),3) - lower_bound(arr.begin(),arr.end(),3)<<endl;


	return 0;
}