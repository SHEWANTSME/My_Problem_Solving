#include<iostream>
#include<vector>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
#define ll long long
using namespace std;
int ans;
int main() {
    fastio;
    int n; cin>>n;
    vector<int>v;
    for(int i=0; i<n ; i++){
        int t; cin>>t;
        v.push_back(t);
    }
    for(int i=0 ; i<n-1; i++){
        int alpha = v[i];
        int beta = v[i+1];
        int p1 = abs(alpha-beta);
        int p2 = alpha+beta;
        ans += p1*p1 + p2*p2;
    }
    cout<<ans<<endl;
}
// 왜 이렇게 되는지 설명은 적어뒀음 -> 26646번 백준
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
