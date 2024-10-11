#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int> &arr, int s, int e){
    int mid = (s+e)/2;
    int l=s, r = mid+1;

    vector<int> vec(e-s+1,0);
    int i=0;
    while(l<=mid && r<=e){
        if(arr[r]<arr[l]){
            vec[i++] = arr[r++];
        } else{
            vec[i++] = arr[l++];
        }
    }
    while(l<=mid){
        vec[i++] = arr[l++];
    }
    while(r<=e){
        vec[i++] = arr[r++];
    }

    for(int j=0;j<vec.size(); j++){
        arr[j+s] = vec[j];
    }

}

void mergesort(vector<int> &arr, int s, int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;

    mergesort(arr, s, mid);
    mergesort(arr, mid+1, e);

    merge (arr, s, e);
}

int main(){
    vector<int> arr = {5,6,7,2,3,4,5,1};
    mergesort(arr, 0, arr.size()-1);
    for(auto n : arr){
        cout<<n<<", ";
    }
    cout<<endl;
    return 0;
}