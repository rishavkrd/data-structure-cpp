#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

vector<string> extractKeys(vector<string> inp, int col){
    vector<string> keys;
    for(auto line : inp){
        char* c = strtok((char*)line.c_str(), " ");
        for(int i=1; i< col; i++){
            c = strtok(NULL, " ");
            cout<<"keys: "<< c <<endl;
        }
        keys.push_back(c);
    }
    return keys;
}

vector<string> extractKeys2(vector<string> inp, int col){
    vector<string> keys;

    for(string line : inp){
        char* key = strtok((char*) line.c_str(), " ");
        for(int i=0; i<col-1; i++){
            key = strtok(NULL, " ");
        }
        keys.push_back(key);

    }
    return keys;
}

int numeric(pair<string,string> a, pair<string, string> b){
    return stoi(a.first)<stoi(b.first);
}
int lexico(pair<string,string> a, pair<string, string> b){
    return a.first<b.first;
}

int main(){
	int n;
    cin>>n;
    cin.get();
    vector<string> inputs;
    for(int i=0;i<n;i++){
        string inp;
        getline(cin, inp);
        inputs.push_back(inp);
        // cout<<inp<<endl;
    }
    int col;
    string do_reverse, sort_type;
    cin>>col>>do_reverse>>sort_type;

    cout<<"inputs: "<<col<<endl<<do_reverse<<endl<<sort_type<<endl;

    vector<string> keys = extractKeys2(inputs, col);
    vector<pair<string, string>> sp;

    for(int i=0;i<keys.size(); i++){
        sp.push_back({keys[i], inputs[i]});
        cout<<"pushed "<< sp[i].first<<endl;
    }

    if(sort_type == "numeric"){
        sort(sp.begin(), sp.end(), numeric);
    } else if(sort_type == "lexico"){
        sort(sp.begin(), sp.end(), lexico);
    }

    if(do_reverse == "true"){
        reverse(sp.begin(), sp.end());
    }

	for(auto i : sp){
		cout<<i.second<<endl;
	}

	return 0;
}
