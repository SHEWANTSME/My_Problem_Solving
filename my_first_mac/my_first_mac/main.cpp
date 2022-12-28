////
////  main.cpp
////  my_first_mac
////
////  Created by 김준현 on 2022/12/22.
////
// 이게 26215번 눈 치우기
#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
bool prime[119];
vector<int>v;
//int sosu[30] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,101, 103, 107, 109, 113};
int main(){
    fastio;
    for(int i=2 ; i<119 ; i++) prime[i]=1;
    for(int i=2; i*i<119;i++){
        if(prime[i]){
            for(int k= i*i ; k<119; k+=i){// 소수에 어떤 값을 곱해도 소수임!!
                prime[k] = 0;
            }
        }
    }
    for(int i=0; i<119 ; i++){
        if(prime[i]) v.push_back(i);
    }


    int n; cin >>n;
    while(n--){
        int t; cin>>t;
        bool flag = 0;
        for(int i=0; i<v.size(); i++){
            for(int j=i ; j<v.size() ; j++){
                if(v[i]+v[j]==t){flag = 1;}
            }
        }
        if(flag==1){cout<<"Yes"<<endl; continue;}
        else {cout<<"No"<<endl;continue;}
    }
}
//
// 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,101, 103, 107, 109, 113,

// 26517번 : 연속인가?
#include<iostream>
#include<vector>
#define endl "\n"
using namespace std;
int main(){
    int k,a,b,c,d;
    cin>>k>>a>>b>>c>>d;
    if(a*k+b == c*k+d){cout<<"Yes"<<" "<<a*k+b<<endl;}
    else cout<<"No"<<endl;
}

/*
 1 2 3 4 5
 1-5
 1-4 4-5
 1-3 3-5
 1-3 3-4 4-5
 1-2 2-5
 1-2 2-4 4-5
 1-2 2-3 3-5
 1-2 2-3 3-4 4-5
 8개
 */
// 1 2 3 4 가 있으면
/**
 1-4
 1-3, 3-4
 1-2, 2-4
 1-2, 2-3, 3-4
 4개
 
 */
// 1-3 이면
/*
 1-3
 1-2, 2-3
 2개
 
 1-2이면
 1개
 */
