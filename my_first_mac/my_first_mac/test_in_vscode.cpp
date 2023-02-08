// #include<iostream>
// #include<algorithm>
// #include<vector>
// // alt(option) shift R -> run code
// using namespace std;
// vector<pair<int,int>>vs;
// int main(){
//     int a=3;
//     int b=4;
//     vs.push_back({3,4});
//     if(b<a)cout<<"yes"<<endl;
//     else cout<<'n'<<endl;
//     cout<<"FICLKS:DLFKS:LDKF"<<endl;vector<int>v;
//     v.push_back(3);
//     v.push_back(7);
//     for(auto &e : v){
//         cout<<e<<endl;
//     }
// }               
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

//#include<bits/stdc++.h> -> Just don't use this 
vector<string>split(string s , string delim){
    vector<string>ret;
    long long pos = 0;
    string token="";
    while((pos = s.find(delim))!=string::npos){
        token = s.substr(0,pos);
        ret.push_back(token);
        s.erase(0,pos+delim.length());
    }
    ret.push_back(s);
    return ret;
}

vector<string> split2(string s, string delim) {
    vector<string> ret;
    auto pos = 0, prev_pos = 0; // 굳이 long long 이나 size_t로 헷갈릴바엔 auto를 쓰자.
    while ((pos = s.find(delim, prev_pos)) != string::npos) {
        ret.push_back(s.substr(prev_pos, pos - prev_pos));
        prev_pos = pos + delim.length();
    }
    ret.push_back(s.substr(prev_pos));
    return ret;
}
// please just use this method for using split func

// 내 방식대로 하는게 더 편함-> 아냐 니 방식은 옳지 않아.. 그냥 하라는 대로 하자 젭알
// vector<string>split2(string s, string delim,int idx){
//     vector<string>ret;
//     for(int i=idx; i<s.size() ; i++){

//     }
    
// }
using namespace std;
int main(){
    string s = "he is fucking asshole and too fat pig";
    vector<string> vv = split(s," ");
    for(auto &e : vv)
        cout<<e<<endl;
    vector<string>ss = split2(s," ");
    for(auto &e : ss)
        cout<<e<<endl;

    vector<int>vec{11,2,33,4,54};
    auto now = vec.begin()+1;
    advance(now , 3);
    cout<< *now<<endl;//54
}