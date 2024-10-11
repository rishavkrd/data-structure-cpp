#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int count_triplets(vector<int> arr,int r){

    int n = arr.size();
    unordered_map<long,long> right,left;

    //Init the Right Map with freq, Left map = 0
    for(auto x : arr){
        right[x]++;
        left[x] = 0;
    }

    //compute by iterating left to right
    int ans = 0;
    for(int i = 0; i < n; i++){

        right[arr[i]]--;

        if(arr[i]%r==0){
            long b = arr[i];
            long a = arr[i]/r;
            long c = arr[i]*r;

            ans += left[a] * right[c];
        }

        left[arr[i]]++;

    }    
    return ans;

}

int count_triplets2(vector<int> arr, int r){
    unordered_map<long, long> left, right;
    for(long x : arr){
        left[x] = 0;
        right[x]++;
    }
    int res=0;
    for(int x : arr){
        right[x]--;
        long arth = x/r;
        long ar = x*r;
        int lfreq = 0, rfreq = 0;
        lfreq = left[arth];
        rfreq = right[ar];
        
        res += lfreq*rfreq;

        left[x]++;
        

    }
    return res;
}

int main() {
    
    int n,r;
    cin>>n>>r;
    vector<int> arr(n,0);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<count_triplets2(arr,r);

    return 0;
}
