#include<iostream>
using namespace std;

// float square_root(int N,int P){
//     int s = 0;
//     int e = N ;
//     float ans = 0;

//     //Binary Search (Search Space 0....N)
//     while(s<=e){
//     	int mid = (s+e)/2;
//     	if(mid*mid==N){
//     		return mid;
//     	}
//     	else if(mid*mid < N){
//     		ans = mid;
//     		s = mid + 1;
//     	}

//     	else{
//     		e = mid - 1;
//     	}

//     }

//     //Linear Search for each place (for floating part)
//     float inc = 0.1;

//     for(int place=1;place<=P;place++){

//     	//do linear search
//     	while(ans*ans <=N){
//     		ans += inc;
//     	}

//     	//take one step back
//     	ans = ans - inc;
//     	inc = inc/10.0;
//     }

   
//     return ans;
// }

float square_root(int n, int p){
    int s = 0, e = n, ans;
    while(s<=e){
        int mid = (s+e)/2;
        if(mid*mid <= n){
            ans = mid;
            s = mid +1;
        } else{
            e = mid -1;
        }
    }
    float res = (float) ans;
    float d = 0.1;
    for(int i =0; i<p; i++){
        while(res*res<=n){
            res+=d;
        }
        res-=d;
        d=d/10;
    }

    return res;
}



int main(){

	int n,p;
	cin>>n>>p;

	cout<<square_root(n,p)<<endl;

	return 0;
}