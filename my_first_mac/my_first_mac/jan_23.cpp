//// 2841번 외계인의 기타연주
//#include<iostream>
//#include <stack>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int n, p;
//stack<pair<int,int>>ststk;
//int visited[7];
////bool visited[7];// 1~6번줄
//stack<int>stk[7];
//int main(){
//    cin>>n>>p;
//    //stack<int>stk[7];
//    //vector<int>vec[p+1];
//    int cnt = 0;
//    int mx = -1;
//    for(int i=0 ; i<=6 ; i++) visited[i]= -1;
//    for(int i=0 ; i<n;i++){
//        int line, fret;
//        cin>>line>>fret;
//        if(visited[line]!=-1){// 아 이거 fret번호를 push하는게 아니고 그냥
//            // cnt만 push하면 되는구나 ㅇㅅㅇ..
//            // 이미 해당 줄을 누르고 있는 상황
//            if(fret>visited[line]){
//                cnt++; visited[line]=fret;
//                stk[line].push(cnt);continue;
//            }
//            else{
//                while(not stk[line].empty()){
//                    int now = stk[line].top();
//                    if(now>)
//                }
//            }
//        }
//        else{// 해당 줄을 처음 누르고 있게 된 상황
//            if(i==0){ // 나눌 이유가 있나?
//                cnt++;
//                visited[line]=fret;
//                stk[line].push(cnt);continue;
//            }
//            else{
//                cnt++; visited[line]=fret;
//                stk[line].push(cnt);continue;
//            }
//
//
//        }
//    }
//}

// 다시 해보자
#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;
int n,p;
//int visited[7];
stack<int>stk[7];
long long arr[7][300001]; // 애초에 이 조건은 필요가 없던 조건임... 생각해보니까
// 그리고 처음에 생각했던 -> 이미 눌려있으면 pass하는게 아니고 stack에서 pop하고 rethink하는게 맞는거였음

int cnt=0;
void Recur(int i , int line, int fret){
    if(i==1 or stk[line].empty()){
        stk[line].push(fret); cnt++;
        arr[line][fret]=1;
        return;
    }
    int top = stk[line].top();
    if(top<fret){
        stk[line].push(fret);cnt++;arr[line][fret]=1;
        return;
    }
    if(top==fret){return;}
    if(top>fret){// 8 10 12 10 5
        arr[line][top]=0;
        cnt++;
        stk[line].pop();
        top = stk[line].top();
        Recur(i,line,fret);
    }
}
int main(){
    cin>>n>>p;
    //for(int i=1 ; i<=6 ; i++)visited[i]=-1;
    for(int i=1; i<=n ; i++){
        int line,fret;cin>>line>>fret;
        Recur(i,line,fret);
    }
    cout<<cnt<<endl;
}
//
//7 15
//1 5
//2 3
//2 5
//2 7
//2 4
//1 5
//1 3
