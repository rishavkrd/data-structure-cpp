#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class compare{
public:
	bool operator()(const vector<int> a, const vector<int> b) const{
		return a[2]<b[2];
	}
};
int box_stack(vector<vector<int>> boxes){
	sort(boxes.begin(), boxes.end(),compare());
	vector<int> dp(boxes.size(), 0);
	int max_stack = 0;
	for(int i=0; i<boxes.size(); i++){
		int current_height = dp[i] = boxes[i][2];
		for(int j=0; j<i;j++){
			if(boxes[i][0]>boxes[j][0] && 
				boxes[i][1]>boxes[j][1] &&
				boxes[i][2]>boxes[j][2]) dp[i] = max(dp[i], current_height + dp[j]);
		}
		max_stack = max(dp[i], max_stack);
	}
	return max_stack;

}

int main(){
	vector<vector<int>> arr = {
		{2,1,2},
		{3,2,3},
		{2,2,8},
		{2,3,4},
		{2,2,1},
		{4,4,5}
	};
	cout<<box_stack(arr)<<endl;
	return 0;
}