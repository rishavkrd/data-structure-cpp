#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

class compare_numeric{
    public:
        int operator()(pair<string, string> a, pair<string, string> b){
            return stoi(a.first)<stoi(b.first);
        }
};

vector<pair<string, string>> extract_keys(vector<string> inputs, int col){
    int n = inputs.size();
    vector<pair<string, string>> keys;
    for(int i=0;i<n;i++){
        cout<<"Inp: "<< inputs[i]<<endl;
        string inp = inputs[i];
        char * inp_arr = (char *)inp.c_str();
        string key = strtok(inp_arr, " ");
        for(int j=1; j<col; j++){
            key = strtok(NULL, " ");
        }
        keys.push_back({key, inputs[i]});
        cout<<"Key: "<<key<< " : "<< inputs[i]<<endl;
    }
    return keys;
}

int main(){
    int n;
    cin>>n;
    cin.get();
    vector<string> inputs;
    for(int i=0; i<n; i++){
        string inp;
        getline (cin, inp);
        inputs.push_back(inp);
    }
    int col;
    string reverse, sort_type;

    cin>>col>>reverse>>sort_type;

    cout<<"Inputs: "<<endl;
    for(int i=0; i<n; i++){
        cout<<inputs[i]<<endl;
    }

    vector<pair<string, string>> kp;
    kp = extract_keys(inputs, col);

    sort(kp.begin(), kp.end(), compare_numeric());
    cout<<"output"<<endl;
    for(auto p : kp){
        cout<<p.second<<endl;
    }

    return 0;
}