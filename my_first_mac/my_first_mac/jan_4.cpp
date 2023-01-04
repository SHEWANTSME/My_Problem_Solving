#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n,m;
vector<int>vec[1001];
priority_queue<int,vector<int>,greater<>>pq[1001];
priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> >ppq;
int dp[1001];
int main(){
    cin >> n>>m; // n = 과목수( 과목 수 카운트가 과목의 이름임)
    // m = (선수과목 조건)
    for(int i=1; i<=n ; i++){
        vec[i].push_back(0);
        //pq[i].push(0);
        dp[i] =1;
        //ppq.push({i,0});
    }
    while(m--){
        int a, b;cin>>a>>b;
        //pq[b].push(a);
        //vec[b].push_back(a);
        ppq.push({a,b});
        //dp[b] = dp[a]+1;
    }
    while(not ppq.empty()){
        int now1= ppq.top().first;
        int now2= ppq.top().second;
        vec[now2].push_back(/*vec[now1].size() now1*/1);
        //dp[now2]+=dp[now1];
        dp[now2]=max(dp[now1]+1,dp[now2]);
        cout << now1<< " " << now2<< endl;
        ppq.pop();
    }
    for(int i=1; i<=n ; i++){
        cout<<dp[i]<<" ";
    }cout<<endl;
    
//    for(int i=1; i<=n ; i++){
//        int now =1;
//        for(auto &e : vec[i]){
//            now+=e;
//            //cout<<e<<endl;
//        }//cout<<endl;
//        cout<<now << " ";
//        //cout<<vec[i].size()<<" ";
//    }
    
//    for(int i=1 ; i<=n ; i++){
//        while(not pq[i].empty()){
//            int now = pq[i].top();
//            cout<<i<<" "<<now<<endl;
//            pq[i].pop();
//        }
//    }
    //sort(vec )
    //for(int i=1 ; i<=n ; i++){
      //  cout<<dp[i]<<" dp "<<endl;
        //cout<<vec[i].size()<<" ";
 //   }
}
