#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int>v{4,3,3,4,5,5,1,2,1,3};
    auto x = unique(v.begin() , v.end());
    cout<<" 이것은 unique 후 나온 결과"<<*x<<endl;
    v.erase(x , v.end());
    for(auto &e : v)
        cout<<e<<" ";
    cout<<endl;
    vector<int>vv{4,3,3,5,1,2,3};
    sort(vv.begin() , vv.end()); // 오름차순일테니까 1 2 3 3 3 4 5
    vv.erase(unique(vv.begin() , vv.end()) , vv.end());
    for(auto &e : vv)
        cout<<e<<" ";
    cout<<endl;
}