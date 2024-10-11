#include <iostream>
#include <vector>
using namespace std;

//Complete this method, don't write main
vector<string> fizzbuzz(int n){
    
    vector <string> arr(n,"");
    for(int i=1; i<=n; i++){
        if(i%3 == 0 || i%5 == 0 ){
            if(i%3 == 0) arr[i-1] += "Fizz";
            if(i%5 == 0) arr[i-1] += "Buzz";
        } else {
            arr[i-1] = to_string(i);
        }
        // cout<<arr[i]<<endl;
    }
    
    return arr;
}

int main (){
	// vector <int> vec(10, 9);
	// // vec = {1,2,3,5,7,8,15};

	// vec.push_back(20);

	vector <vector<int>> arr2d = {{1,2,3},
		{4,5,6,7,8},
		{9,10}
	};
	// for(int i=0;i<arr2d.size();i++){
	// 	for(int x : arr2d[i]){
	// 		cout << x <<"," ;
	// 	}
	// 	cout << endl;
	// }
	
	// cout << vec.capacity() <<endl ;
	vector <string> vec = fizzbuzz(15);
	for (int i=0; i<vec.size();i++){
		cout << vec[i] <<endl;
	}

	return 0;
}
