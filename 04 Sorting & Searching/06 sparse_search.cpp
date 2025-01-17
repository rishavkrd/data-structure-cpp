#include <iostream>
#include<cstring>
using namespace std;

// int sparse_search(string a[],int n,string key){
    
//     // sparse search
//     int s=0;
//     int e = n-1;
//     while(s<=e){
//         int mid = (s+e)/2;
//         int mid_left = mid - 1;
//         int mid_right = mid + 1;
//         if(a[mid]==""){
//             while(1){
//                 if(mid_left<s and mid_right>e){
//                     return -1;
//                 }
//                 else if(mid_right<=e and a[mid_right]!=""){
//                     mid = mid_right;
//                     break;
//                 }
//                 else if(mid_left>=s and a[mid_left]!=""){
//                     mid = mid_left;
//                     break;
//                 }
//                 mid_left--;
//                 mid_right++;
//             }
//         }
//         if(a[mid]==key){
//             return mid;
//         }
//         else if(a[mid] > key){
//             e = mid - 1;
//         }
//         else{
//             s = mid + 1;
//         }
//     }
//     return -1;
// }

int sparse_search(string a[], int n, string key){
    int s=0, e=n-1;
    

    while(s<e){
        int mid = (s+e)/2;
        if(a[mid]==""){
            int l=mid-1, r=mid+1;
            while(a[l] == "" && a[r]== ""){
                if(l>0 && l>s) l--;
                
                if(r<n-1 && r<e) r++;
                // if(r==e && l==s) return -1;
                // cout<<"stuck 1";
            }
            if(a[l]!="") mid = l;
            else mid = r;
        }
        cout<<a[mid]<<endl;
        if(key<a[mid]){
            e = mid-1;
        } else if(a[mid] == key){
            return mid;
        }
         else {
            s = mid+1;
        }
        // cout<<"stuck 2";
    }
    return -1;
}

int main() {
    string arr[] = {"ai", "", "","bat", "","","car","cat","","","dog","",""};
    int n = 12;

    string f;
    cin>>f;
    cout<<sparse_search(arr,n,f)<<endl;


    return 0;
}
