#include<iostream>
#include<vector>

using namespace std;

int lower_bs(vector<int> input, int target){
    int s=0, e=input.size()-1;
    int lower_index = -1;

    while(s<=e){
        int pivot = (s+e)/2;
        if(input[pivot] == target){
            lower_index = pivot;
            cout<<"lower: "<<pivot<<endl;
            e = pivot -1;
        }
        else if(input[pivot] > target){
            e = pivot-1;
        } else{
            s = pivot+1;
        }
    }
    return lower_index;
}

int upper_bs(vector<int> input, int target){
    int s=0, e=input.size()-1;
    int upper_index = -1;

    while(s<=e){
        int pivot = (s+e)/2;
        if(input[pivot] == target){
            upper_index = pivot;
            cout<<"upper: "<<pivot<<endl;
            s = pivot +1;
        }
        else if(input[pivot] > target){
            e = pivot-1;
        } else{
            s = pivot+1;
        }
    }
    return upper_index;
}

int main(){
    vector<int> input = {0,1,1,2,3,3,3,3,3,4,5,5,5,10};
    int target = 3;

    int low = lower_bs(input, target);
    int high = upper_bs(input, target);

    cout<<high-low+1;
    return 0;
}