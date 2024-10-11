#include<iostream>
#include<vector>

using namespace std;

void find_segments(int * plots, int size, int target, vector<vector<int>> *result){
    int l=0, r=1;
    int sum = plots[l]+plots[r];
    while(r<size && l<r){

        while(sum<target){
            r++;
            sum+=plots[r];
        }
        if(sum==target){
            result->push_back({l,r});
        }
        sum-=plots[l];
        l++;
        
    }
}

void find_segments2(vector<int> plots, int target, vector<vector<int>> &result){
    int r=0, sum=0;
    for(int l=0; l<plots.size(); l++){
        
        while(sum<target && r<plots.size()){
            sum+=plots[r];
            r++;
        }
        if(sum==target) result.push_back({l,r});
        sum-=plots[l];
    }

}

int main(){
    int plots[] = { 1 ,3 ,2 ,1 ,4 ,1 ,3 ,2 ,1 ,1};
    vector<int> p = { 1 ,3 ,2 ,1 ,4 ,1 ,3 ,2 ,1 ,1};
    int size = sizeof(plots)/sizeof(int);
    int k=8;

    vector<vector<int>> result;

    find_segments2(p, k, result);

    for(auto res : result){
        for(int i= res[0]; i<res[1]; i++)
            cout<<p[i]<<",";
        cout<<endl;
    }

    return 0;
}