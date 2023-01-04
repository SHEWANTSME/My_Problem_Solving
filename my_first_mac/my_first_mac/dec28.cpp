//#include<iostream>
//#include<vector>
//#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
//#define ll long long
//using namespace std;
//int ans;
//int main() {
//    fastio;
//    int n; cin>>n;
//    vector<int>v;
//    for(int i=0; i<n ; i++){
//        int t; cin>>t;
//        v.push_back(t);
//    }
//    for(int i=0 ; i<n-1; i++){
//        int alpha = v[i];
//        int beta = v[i+1];
//        int p1 = abs(alpha-beta);
//        int p2 = alpha+beta;
//        ans += p1*p1 + p2*p2;
//    }
//    cout<<ans<<endl;
//}
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
// 되돌리기 1360번
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int main(){
    fastio;
    int n;cin>>n;
    string empty;
    vector<pair<string,int>>vec;
    vector<string>ans;
    while(n--){
        string text,s1; int num;
        cin>>text>>s1>>num;
        if(text[0]=='u'){
            int mid = stoi(s1);
            int val = num - mid-1;
            string now = "";
            for(int i=vec.size()-1; i>=0; i--){
                if(vec[i].second<=val){
                    now = vec[i].first;
                    break;
                }
            }
            vec.push_back({now,num});
           // ans.push_back(now);
        }
        else{
            //if(vec.empty()) vec.push_back({s1,num});
            //else  vec.push_back({vec.back().first+s1,num});
            empty+=s1;
            vec.push_back({empty,num});
            
            //ans.push_back(empty);
        }
    }
    //cout<<ans.back();
    cout<<vec.back().first<<endl;
}
/*
 
 using namespace std;
 int N;
 vector<pair<string,int>> ans;
 string get_ans(int target_sec)
 {
     for(int i=ans.size()-1;i>=0;i--)
     {
         if(target_sec>ans[i].second) return ans[i].first;
     }
     return "";
 }
 int main()
 {
     cin >> N;
     for(int i=0;i<N;i++)
     {
         string cmd,val; int sec;
         cin >> cmd >> val >> sec;
         if(cmd == "type")
         {
             string push_val;
             if(ans.size())push_val = ans.back().first+val;
             else push_val = val;
             ans.push_back({push_val,sec});
         }
         else
         {
             ans.push_back({get_ans(sec-atoi(val.c_str())),sec});
         }
     }
     cout << ans.back().first;
 }


 */
