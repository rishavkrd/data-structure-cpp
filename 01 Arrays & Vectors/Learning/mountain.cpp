#include <iostream>
#include <vector>
using namespace std;

int highest_mountain(vector<int> arr){
	int max=0;
	for(int i=1;i<arr.size()-1;i++){
		if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
			
			int k=i-1, prev=arr[i];
			int count=1;
			while(arr[k]<prev && k>=0){
				count++;
				prev=arr[k];
				k--;
			}
			prev = arr[i];
			i++;
			while(arr[i]<prev && i<arr.size()){
				count++;
				prev = arr[i];
				i++;
			}
			max = count>max? count : max;
		}
	}
	return max;
}

int main(){

	vector<int> arr{5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};

	cout<< highest_mountain(arr)<<endl;



	return 0;
}