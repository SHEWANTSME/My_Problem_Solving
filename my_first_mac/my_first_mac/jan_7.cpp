//2527번 직사각형
#include<iostream>
#include<algorithm>
#define endl "\n"
using namespace std;
int main(){
    int k=4;
    while(k--){
        int a,b,c,d,e,f,g,h;
        cin>>a>>b>>c>>d>>e>>f>>g>>h;
        if(a>g or b>h or e>c or f>d )cout<<'d'<<endl;// 아 이거 찾느라 시간 ㅈㄴ씀 개멍청하네
        else{
            int check = (a==g)+(b==h)+(e==c)+(f==d);// 이게 만나는게 선분이면 무조건 1임 위에서 'd'인건 다 걸러서 만나긴 만나는 애들인데 1이 나왔다는건 선분일수 밖에 없음
            if(check==1)cout<<'b'<<endl;
            else if(check==2)cout<<'c'<<endl; // 2이면 좌표(x,y)가 둘다 같다는거니까 점
            else cout<<'a'<<endl; // 뭣도 아니면 직사각형이겠지 (이건 그냥 될거같아서 해봄)
        }
    }
}
//// 좀만 자야겠다 ㅅㅂ...
//#include<iostream>
//using namespace std;
//int main(){
//    for(int i=1 ; i<=10 ; i++){
//        if(!(i&1))cout<<i<<endl;
//    }
//}
