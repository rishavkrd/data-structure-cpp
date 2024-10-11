#include <iostream>
#include <vector>
using namespace std;

bool divideK(vector<int> a, int n, int k, int val){
    int curr = 0, count = 0;
    for(int i =0; i<n; i++){
        if(curr+a[i]<val){
            curr+=a[i];
        } else{
            count++;
            curr=0;
        }
    }
    return count>=k;
}

bool divideAmongK(vector<int> arr,int n,int k,int limit){
    //return true if every partition gets atleast limit no of coins

        int cnt = 0;
        int current_sum = 0;
        
        for(int i=0;i<n;i++){
            if(current_sum + arr[i] >=limit){
                cnt +=1;
                current_sum = 0;
            }
            else{
                current_sum += arr[i];
            }
        } 
       
    return cnt>=k;
}

int k_partition(vector<int> a, int n, int k){
    int s = 0, e=0,res=-1;
    for(int x : a){
        e+=x;
    }
    while(s<=e){
        int mid = (s+e)/2;
        
        if(divideK(a, n, k, mid)){
            res = mid;
            s = mid + 1;
        } else{
            e = mid - 1;
        }
        // cout<<mid<<endl;
        
    }
    return res;
}

int main(){
    vector<int> v = {1,2,3,4};
    int n = v.size();
    int k;
    cin>>k;
    cout<<k_partition(v,n,k)<<": ans"<<endl;
    return 0;
}



// int k_partition(int arr[],int n,int k){
   
//     int e = 0;
//     int s = 0;
//     for(int i=0;i<n;i++){
//         e += arr[i];
//     }
//     //mid
//     int mid;
//     int ans;
//     //search range (s,e)
//     while(s<=e){
//          mid = (s+e)/2;
         
//         bool isPossible = divideAmongK(arr,n,k,mid);

//         if(isPossible){
//             s = mid + 1;
//             ans = mid;
//         }
//         else{
//             e = mid - 1;
//         }
//     }
//     return ans;

// }
// int main() {
//     int a[] = {1,2,3,4};
//     int n  = sizeof(a)/sizeof(int);
//     int k = 4;
//     cout<< k_partition(a,n,k)<<endl;
//     return 0;
// }
