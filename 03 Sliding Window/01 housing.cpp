#include <iostream>
using namespace std;


// void housing(int *arr,int n,int k){

//     int i=0;
//     int j= 0;
//     int cs = 0;

//     while(j<n){

//         //expand to right
//         cs += arr[j];
//         j++;

//         //remove elements from the left till cs > sum and i<j
//         while(cs > k and i<j){
//             cs = cs - arr[i];
//             i++;
//         }

//         //check if any given point 
//         if(cs==k){
//             //print that window
//             cout<< i <<" - "<<j-1 <<endl;
//         }

//     }
//     return;
// }

// void housing(int * arr, int n, int k){
//     int l=0, r=0;
//     int sum = 0;
//     while(l<=r && r<=n){
        
//         if(sum<k){
//             sum+=arr[r];
//             r++;
//         } else if (sum>k){
//             sum-=arr[l];
//             l++;
//         } else{
//             cout<<l<<","<<r-1<<endl;
//             sum-=arr[l];
//             l++;
//         }
//     }
//     return;
// }

void housing(int * arr, int n, int k){
    int l=0,r=0;
    int cs = 0, len=n;
    int res[2];
    while(r<n){
        cs+=arr[r];
        r++;

        while(l<r && cs>k){
            cs-=arr[l];
            l++;
        }
        if(cs==k){
            cout<<l<<" - "<<r-1 <<endl;
            if(r-l < len) {
                len = r-l;
                res[0]=l;
                res[1]=r-1;
            }
            
        }
    }
    cout<<"res: "<<res[0]<<" - "<<res[1]<<endl;
}

int main() {

    //smallest window that contains the reqd sum
    // handle if you have negative integers in the arrays 

    int plots[] = { 1 ,3 ,2 ,1 ,4 ,1 ,3 ,2 ,1 ,1};
    int  n = sizeof(plots)/sizeof(int);
    int k = 8;

    housing(plots,n,k);


    return 0;
}
