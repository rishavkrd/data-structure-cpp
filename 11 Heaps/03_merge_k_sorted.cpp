#include <iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> mergeKArrays(vector<vector<int> > arrays){
    //logic  
  
    int k = arrays.size();
    //triplet -> element, array idx, element idx
    priority_queue< vector<int> , vector<vector<int> > , greater<vector<int> > > q;


    vector<int> output;

    //init the heap 
    for(int i=0;i<k;i++){
        int element = arrays[i][0];
        q.push({element,i,0});
    }

    //start popping & pushing more elements
    while(!q.empty()){

        auto top = q.top();
        q.pop();

        int element = top[0];
        int a_idx = top[1];
        int e_idx = top[2];


        output.push_back(element);

        if(e_idx + 1 < arrays[a_idx].size()){
            int next_element = arrays[a_idx][e_idx+1];
            q.push({next_element,a_idx,e_idx+1});
        }

    }




    return output;
}

vector<int> mergeKArrays2(vector<vector<int>> arrays){
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> heap;

    int k = arrays.size();

    for(int i=0;i<k;i++){
        heap.push({arrays[i][0], i, 0});    //val, array_idx, element_idx
    }
    vector<int> res;
    while(!heap.empty()){
        int min = heap.top()[0];
        int arr_idx = heap.top()[1];
        int ele_idx = heap.top()[2];

        res.push_back(min);
        heap.pop();
        if(ele_idx!= arrays[arr_idx].size() -1 ) heap.push({arrays[arr_idx][ele_idx+1], arr_idx, ele_idx+1});
    }

    return res;
}

int main() {
    

    vector<vector<int> > arr = {{10,15,20,30},
                                {2,5,8,14,24},
                                {0,11,60,90}};

    //various approaches 
    vector<int> result = mergeKArrays2(arr);
    

    //output
    for(auto x:result){
        cout<<x <<" ";
    }


    return 0;
}
