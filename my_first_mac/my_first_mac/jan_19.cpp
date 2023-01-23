// 1495 기타리스트
#include<iostream>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;
int n, s, m;
bool dp[102][1001];// 가능성 없는애들 가지치는 용도 -> 돼 안돼 -> bool
int arr[102];
int main(){
    cin>>n>>s>>m;
    for(int i=1 ; i<=n ; i++)cin>>arr[i];
    dp[0][s]=1;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<=m ; j++){
            if(dp[i][j]){
                if(j-arr[i+1]>=0)dp[i+1][j-arr[i+1]]=1;
                           if(j+arr[i+1]<=m)dp[i+1][j+arr[i+1]]=1;
            }
        }
    }
    priority_queue<int>pq;
    int mx = -1;
    for(int k=0 ; k<=m ; k++){
        if(dp[n][k]!=0){pq.push(k);mx = max(mx,k);}
        else pq.push(-1);
    }
    //for(auto &e : dp[n])pq.push(e);
    cout<<pq.top()<<endl;
    cout<<mx<<endl;
}
//#include<iostream>
//
//using namespace std;
//
//int n, s, m, v;
//bool dp[101][1001];
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);  cout.tie(NULL);
//
//    cin >> n >> s >> m;
//    dp[0][s] = true;
//
//    for (int i = 1; i <= n; i++) {
//        cin >> v;
//        for (int j = 0; j <= m; j++) {
//            if (dp[i - 1][j]) {
//                if (j + v <= m) dp[i][j + v] = true;
//                if (j - v >= 0) dp[i][j - v] = true;
//            }
//        }
//    }
//
//    bool flag = false;
//    for (int i = m; i >= 0; i--) {
//        if (dp[n][i]) {
//            cout << i;
//            flag = true;
//            break;
//        }
//    }
//    if (!flag)   cout << -1;
//}
