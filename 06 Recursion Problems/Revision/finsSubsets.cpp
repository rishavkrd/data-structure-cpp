#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<string> subsets;
unordered_set<string> set;

void allSubsequences(string input, string output){
    if(input == ""){
        subsets.push_back(output);
        return;
    }
    //keep the (first) character
    allSubsequences (input.substr(1), output + input[0]);
    //Don't keep the character
    allSubsequences (input.substr(1), output);

    return;

}

string swap (string &inp, int i, int j){
    char temp = inp[i];
    inp[i] = inp[j];
    inp[j] = temp;
    return inp;
}

void allPermutations(string inp, int fix_index){
     
    for(int i=fix_index; i< inp.size(); i++){
        swap(inp, fix_index, i);
        allPermutations(inp, fix_index+1);
        // swap(inp, fix_index, i);
    }
    set.insert(inp);
    return;
}

int main(){
    string inp;
    getline(cin, inp);

    allPermutations(inp, 0);
    

    for(auto s : set){
        cout<<s<<endl;
    }
    cout<<set.size()<<endl;
    return 0;
}