// #include<iostream>
// #include<algorithm>
// #include<vector>
// #include<queue>
// #include<string>
// #include<string.h>
// #include<stack>
// #define endl "\n"
// // 값 + (x,y) 동시 저장
// int check[101][71]; // 해당 지점마다 1,2,3,4값을 저장할 수 있는데
// // 1이면 -> 2a
// #define ll long long
// #define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
// using namespace std;
// int arr[101][71];
// int visited[101][71];
// // 이럴때를 대비해서 backtracking을 사용하는건가?

// // 봉우리가 가능한 경우를 찾아보자
// // 현재 위치에서 근처라 하면 -> 왼 위 오른 아래 가 근처인데
// // 현 위치가 maxx보다 크면 
// int maxx = -1;
// int dx[4] = {0,1,-1,0};
// int dy[4] = {1,0,0,-1};
// int n, m;
// void DFS(int x, int y,int height){
//     int now = arr[x][y];
//     if(now>height)height = now;
//    // visited[x][y]=1;
//     for(int i=0; i<4 ; i++){
//         int nx = x + dx[i];
//         int ny = y + dy[i];
//        // if(visited[nx][ny])continue;
//         if(nx<0 or ny<0 or nx>=n or ny>=m)continue;
//         // 하 ㅅㅂ 머리아프니까 일단 하나씩 찍어보자
//         if(arr[nx][ny]>now){
//             cout<<"1. 현재 nx : "<<nx <<"ny : "<<ny << "now값 : "<<now << "arr[nx][ny]값 :  "<<arr[nx][ny]<<endl; 
//             //now는 봉우리가 될 수가 없음
//             DFS(nx,ny,arr[nx][ny]);
//         }
//         if(arr[nx][ny]<=now){
//             cout<<"2. 현재 nx : "<<nx <<"ny : "<<ny << "now값 : "<<now << "arr[nx][ny]값 :  "<<arr[nx][ny]<<endl; 

//             //now는 봉우리 일수도있고 아닐수도 있음
//             DFS(nx,ny,now);
//         }
        
//     }
// }
// int main(){
//     cin>>n>>m;
//     for(int i=0; i<n ; i++){
//         for(int j=0 ; j<m ; j++){
//             cin>>arr[i][j];
//             visited[i][j]=-1;
//         }
//     }
//     DFS(0,0,-1);
// }





//     // int x1=x+1,y1=y;
//     // int x2=x-1,y2=y;
//     // int x3=x,y3=y+1;
//     // int x4=x,y4=y-1;

//     // x+1;y;
//     // x-1;y;
//     // x;y+1;
//     // x;y-1;

// 2000 -> 1998
// 봉우리 문제 -> 1245번은 나중에 꼭 다시 풀기
// 지금 할 문제는 1560 비숍
// 걍 그려보면 알수있음
// 숫자 작으면 nqueen처럼 backtracking인가보다 -> 숫자 ㅈㄴ큼 -> 엥 이거 dp인가? -> 그려봄 -> 걍 규칙성
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
string sum(string a, string b) {
    int as = a.size(); int bs = b.size();
    int diff = max(as, bs) - min(as, bs);
    if(as < bs) for(int i=0; i<diff; i++) a = "0" + a;
    if(as > bs) for(int i=0; i<diff; i++) b = "0" + b;

    vector<int> v;
    for(int i=0; i<as; i++) v.push_back(a[i] - '0' + b[i] - '0');

    reverse(v.begin(), v.end());
// for(int i=0; i<v.size(); i++) {
//         if(v[i] < 10) continue;

//         if(i < v.size()-1) v[i+1] += v[i]/10;
//         else v.push_back(v[i]/10);

//         v[i] %= 10;
//     }
    for(int i=0; i<v.size(); i++) {
        if(v[i] < 10) continue;
        if(i==v.size()-1){v.push_back(v[i]/10);v[i] %= 10;}
        if(i!=v.size()-1){
            v[i+1] += v[i]/10;
        v[i] %= 10;
        }
        
    }
    reverse(v.begin(), v.end());
    string ans="";
    if(v.empty())return "씨발";
    else{
        for(auto &e : v){
        if(e>=0 and e<=9)ans+=e+48;// ascii '0' = 48이니까 숫자 0은 
        else continue;
    }

    char last = ans[ans.size()-1];
    if(last>='2'){// '0'=48 , '1'= 49  , '2'= 50 이니까
        ans.pop_back();
        ans.push_back(last-2);
        return ans;
    }
    else{
        //'0'=48,'1'=49,'2'=50,'3'=51,'4'=52,'5'=53,'6'=54,'7'=55,'8'=56,'9'=57
        //2001 -> 1999 , 181 -> 179 , 20101 -> 20099 , 1001 -> 999
     
            string temp = "";
            //bool tmp= false;
            bool chk= false;
            if(last=='1') temp.push_back('9');
            else if(last =='0')temp.push_back('8');//1100이면 89
            for(int i = ans.size()-2 ; i>=0 ; i--){
                char now = ans[i];
                if(chk==true){
                    temp.push_back(now);continue;
                }
                if(now=='0'){
                   // tmp=true;
                    temp.push_back('9');
                }
                if(now !='0' /*and tmp == false*/){
                    temp.push_back(now-1);chk=1;
                }
                /*if(now !='0' and tmp == true){
                    temp.push_back(now-1);chk=1;
                }*/
            }
            reverse(temp.begin(),temp.end());
            string realans="";
            for(int i=0 ; i<temp.size() ; i++){
                if(i==0 and temp[i]=='0')continue;
                realans.push_back(temp[i]);
            }
            return realans;
        
       
    }
   // return ans;
    }
    // for(auto &e : v){
    //     cout << e << " ";
    // }
    // string ret;
    // int i = 0; while(v[i] == 0) i++;
    // if(i >= v.size()) ret.push_back('0');

    // while(i < v.size()) {
    //     ret.push_back(char(v[i] + '0'));
    //     i++;
    // }

    // return ret;
}


ll n;
int main(){// 1000+100 = 1100 -2 = 1008
    cout<<sum("100","1000")<<endl; // 2331 -2 = 2331
    //cout<<sum(sum("2000","."),"2000")<<endl; -> this doesn't work correctly
    //cout<<sum("456" , "78")<<endl;
//     cin>>n;
//    if(n<=2)cout<<n<<endl;
//    else cout<<n*2-2<<endl; 
int a =3;
int b = 7;
while(b>a){
    a++;
}
cout<<a << " "<<b<<endl;
cout<<"fuckyou"<<endl;
}
// debug할떄 그냥 fn+f5 누르고 하자 나머지는 동일
// 그리고 함수 호출하고 ㅅㅂ 왜 안되지?