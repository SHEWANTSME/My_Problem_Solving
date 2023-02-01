//#include<iostream>
//#include<algorithm>
//#define ll long long
//using namespace std;
//int n,m;
//ll ans=0;
//ll arr[501][501];
//ll dp[501][501];
//bool visited[501][501];
//int dx[4] = {0,1,-1,0};
//int dy[4] = {1,0,0,-1};
//void DFS(int x, int y){
//    if(x<0 or y<0 or x>=n or y>=m)return;
//    if(visited[x][y]) return;
//    ll now = arr[x][y];
//    visited[x][y]=1;
//    DFS(x+1,y);
//    DFS(x,y+1);
//    DFS(x-1,y);
//    DFS(x,y-1);
//}
//// dp[x-1][y] -> 1 , dp[x][y-1] ->2, dp[x+1][y] ->3 , dp[x][y+1]->4
//// dp[x][y] =
//// dp[x][y][4] -> 현재위치(x,y)가 젤 작고
//// {이전값,방향(위에서 온건지 , 아래서 온건지, 왼쪽에서 왔는지 , 오른쪽) , 현재값}
///*
// 어떻게 해야 괜찮은 DFS +DP를 짤 수 있을까
// void DFS(x, y):
//    if(x<0 or y<0 or x>=n or y>=m) return;
//    int now = arr[x][y];
//    if(
//
//
//
// */
//int main(){
//    cin>>n>>m;
//    for(int i=0; i<n ; i++){
//        for(int j=0; j<m ; j++){
//            cin>>arr[i][j];
//        }
//    }
//    for(int i=0; i<=500 ; i++){
//        for(int j=0 ; j<=500 ; j++)
//            dp[i][j]=-1;
//    }
//    dp[0][0]=1;
//}

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;
int dp[501][501];
int tc;
int arr[501];
int sum[501];
int main(){
    cin>>tc;
    while(tc--){
        int n; cin>>n;
        int minn = 1e9;
        for(int i=1 ; i<=n ; i++) cin>>arr[i];
        for(int i=1; i<=n;i++)
            for(int j=1; j<=n;j++)
                dp[i][j]=-1;
        sum[1]=arr[1];
        dp[1][1] = arr[1];
        for(int i=2 ; i<=n ; i++) {sum[i] =sum[i-1]+arr[i];dp[i][i]=arr[i];}
        for(int i=1 ; i<=n ; i++){
            for(int j=i ; j<=n;j++){
                //dp[i][j] -> arr[i] 부터 arr[j]까지 부분합중 min
                if(dp[i][j]!=-1){ continue;}
                for(int k = 1 ; k<j;k++){
                    if(j-i==1) dp[i][j] = dp[i][k] + dp[k+1][j];
                    else dp[i][j] = dp[i][k] + dp[k+1][j] + sum[j];
                }
                //minn = (minn<dp[i][j])?minn : dp[i][j];
                cout<<"i ,j : "<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
        }
        // 아 왜 안풀리지 ㅜ 내일 다시 도전..
        for(int i=1 ; i<n ; i++){
            minn = min(dp[1][i]+dp[i+1][n]+sum[n],minn);
        }
        minn = min(dp[1][n],minn);
        cout<<minn<<endl;
        for(int i=1; i<=n ; i++){arr[i]=0;sum[i]=0;}
        for(int i=1; i<=n;i++)
            for(int j=1; j<=n;j++)
                dp[i][j]=0;
        
       
    }
    
}
