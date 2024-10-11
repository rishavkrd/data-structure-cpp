#include<iostream>
#include<vector>

using namespace std;

int search(vector<int> nums, int key){
    int s=0, e=nums.size()-1;

    while(s<=e){
        int pivot = (s+e)/2;

        if(nums[pivot] == key){
            return pivot;
        }
        if(nums[pivot]>=nums[s]){
            //L1
            if(key>=nums[s] && key <=nums[pivot]){
                e = pivot -1;
            } else {
                s = pivot +1;
            }
        } else{
            //L2
            if(key<=nums[e] && key >= nums[pivot]){
                s = pivot +1;
            } else{
                e = pivot -1;
            }
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {4,5,6,7,0,1,2,3};
    int key = 2;

    cout<< search(nums, key);
    return 0;
}