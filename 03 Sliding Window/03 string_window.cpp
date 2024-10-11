#include<iostream>
#include<climits>
#include<string>
using namespace std;

string find_window(string s,string p){


	//Array as a Freq Map or you can hashmap
	int FP[256] = {0};
	int FS[256] = {0};

	for(int i=0;i<p.length();i++){
		FP[p[i]]++;
	}

	//Sliding Window Algorithm
	int cnt = 0;
	int start = 0; // left contraction
	int start_idx = -1; //start_idx for best window
	int min_so_far = INT_MAX; //large number
	int window_size ;


	for(int i=0 ; i < s.length(); i++){
		//expand the window by including current character
		char ch = s[i];
		FS[ch]++;

		//Count how many characters have been matched till now (string and pattern)
		if(FP[ch]!=0 and FS[ch]<= FP[ch]){
			cnt += 1;
		}

		//another thing 
		//if all characters of the pattern are found in the current window then you can start contracting
		if(cnt==p.length()){

			//start contracting from the left to remove unwanted characters 
			
			while(FP[s[start]]==0 or FS[s[start]] > FP[s[start]]){
				FS[s[start]]--;
				start++;
			}

			//note. the window size
			window_size = i - start + 1;
			if(window_size < min_so_far){
				min_so_far = window_size;
				start_idx = start;
			}

		}

	}
	if(start_idx==-1){
		return "No window found";
	}
	return s.substr(start_idx,min_so_far);
}
bool fit(int *arrbig, int* arrsm){
	for(int i=0;i<256;i++){
		if(arrbig[i]<arrsm[i]) return false;
	}
	return true;
}
string minWindow(string s, string p){
    if(s.length()<p.length()) return "";
	int FP[256] = {0};
	int FS[256] = {0};
	int start_idx=0;
	int min_window_len = s.size();
	int len=s.size(), count=0;
    bool flag=false;
	for(char c : p){
		FP[c]++;
	}
	int i=0,j=0;
	while(j<s.size()){
		FS[s[j]]++;
        if(FP[s[j]]>0 && FS[s[j]]<=FP[s[j]]){
            count++;
        }
		while(count==p.size()){
            flag=true;
			len = j-i+1;
			if(len<min_window_len){
				min_window_len=len;
				start_idx=i;
			}
			// cout<<start_idx<<','<<min_window_len;
			FS[s[i]]--;
            if(FS[s[i]]<FP[s[i]]){
                count--;
            }
			i++;
		}
		j++;

	}
    if(!flag) return "";
	return s.substr(start_idx,min_window_len);

}


int main(){

	string s,p;
	cin>>s>>p;


    cout<<find_window(s,p)<<endl;



	return 0;
}