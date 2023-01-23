// 백준 16166 서울의 지하철
#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
using namespace std;
int n,endpoint,len,ans=1e9;
vector<int>line[11];
vector<int>st;// 시작 (0) 담는 벡터
int line_check[11]; // 지금 위치가 체크된 호선이면 더이상 환승을 안하니까
// 가능한 총 호선의 개수인 10개'만' check가능하게끔 짜면 됨
// 지하철 호선의 개수의 맥시멈이 10개고, 0(시작점)이 있는 벡터가 몇호선인지가 중요한거니까
long long anss = 1e14;
void DFS(int line_num , int cnt){// 호선번호, 환승횟수
    line_check[line_num]=1;
    for(auto &e : line[line_num]){
        if(e == endpoint){
            ans = (ans<cnt)?ans : cnt;
            line_check[line_num]=0;
            return;
        }
        for(int i=0 ; i<n ; i++){// 완탐부분
            if(i == line_num or line_check[i])continue;// 0호선부터 n-1호선중 현재 호선(line_num)은 제외하고
            for(auto &x : line[i]){// 다른 호선의 역중에 지금 호선의 역과 겹치는게 있는지(환승역)+지나왔던 호선 아니여야함
                if(e==x ) DFS(i,cnt+1);
            }
        }
    }
    line_check[line_num]=0;
    //return ans;
}
int main(){
    cin>>n;// 총 노선 개수
    for(int i=0 ; i<n ; i++){// 차례로 0호선, 1호선, .. n-1호선 이렇게
        cin>>len;
        for(int j=0 ; j<len ; j++){
            int t;cin>>t;
            line[i].push_back(t);
            if(t==0)st.push_back(i);// 0번역이 환승역이면 여러개 가능해서 따로 st 벡터에 추가
            // 0번역이 어느호선에 있는지가 중요
        }
    }
    cin>>endpoint;
    while(not st.empty()){
        DFS(st.back(), 0);
        st.pop_back();
    }
    if(ans==1e9)cout<<-1<<endl;
    else cout<<ans<<endl;
}


//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<queue>
//#define ll long long
//#define pp pair<int,int>;
//using namespace std;
//int n,len,endpoint,ans=1e9,cnt=0;
//vector<int>line[11];
//vector<int>st;
//bool vis[11];
//void check(vector<int> )
//void BFS(int now , int cnt){
//    queue<int>Q;
//    Q.push(now);
//    vis[now]=1;
//    while(not Q.empty()){
//        while(Q.size()--){
//
//        }
//    }
//}
//
//int main(){
//    cin>>n;
//    for(int i=1 ; i<=n ; i++){
//        cin>>len;
//        for(int j=1 ; j<=n  ; j++){
//            int t; cin>>t;
//            line[i].push_back(t);
//            if(t==0)st.push_back(i);
//        }
//    }
//    cin>>endpoint;
//    while(not st.empty()){
//        int now = st.back();
//        BFS(now , 0);
//        st.pop_back();
//    }
//
//    if(ans==1e9)cout<<-1<<endl;
//    else cout<<ans<<endl;
//}
//  아 나중에 더 생각해보자..
