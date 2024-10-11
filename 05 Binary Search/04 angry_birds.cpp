#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool birdsFit(vector<int> arr, int d, int b){
	int prev = arr[0];
	int count = 1;
	for(int i=1; i<arr.size(); i++){
		
		if(arr[i] - prev >= d) {
			prev = arr[i];
			count++;
		}
	}
	cout<<"count: "<<count<<endl;
	return count>=b;
}

int main(){
	vector<int> nests = {1,2,4,8,9};
	sort(nests.begin(), nests.end());
	int n = 5;
	int b, res;
	cin>>b;

	int s = 0, e = nests[n-1] - nests[0];

	while(s<=e){
		int mid = (s+e)/2;
		if(birdsFit(nests, mid, b)){
			res = mid;
			s = mid + 1;
		} else{
			e = mid - 1;
		}
	}
	cout << res<< endl;
	return 0;

}








// bool canPlaceBirds(int B,int N,vector<int> nests,int sep){

// 	int birds = 1;
// 	int location = nests[0];

// 	for(int i=1; i<=N-1; i++){
// 		int current_location = nests[i];
// 		if(current_location - location >= sep){
// 			birds++;
// 			location = current_location;

// 			if(birds==B){
// 				return true;
// 			}
// 		}
// 	}
// 	return false;

// }


// int main(){
// 	int B = 3;
// 	vector<int> nests{1,2,4,8,9};
// 	//sorting
// 	sort(nests.begin(),nests.end());
// 	int N = nests.size();

// 	//Binary Search
// 	int s = 0;
// 	int e = nests[N-1] - nests[0];
// 	int ans = -1;

// 	while(s<=e){
// 		int mid = (s+e)/2;

// 		bool canPlace = canPlaceBirds(B,N,nests,mid);
// 		if(canPlace){
// 			ans = mid;
// 			s = mid + 1;
// 		}
// 		else{
// 			e = mid - 1;
// 		}
// 	}

// 	cout << ans <<endl;

// 	return 0;
// }