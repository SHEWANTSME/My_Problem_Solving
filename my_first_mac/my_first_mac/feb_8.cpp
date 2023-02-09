#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
    //vector<bool> visited(1,10);

int main(){
    vector<int>v{4,3,3,4,5,5,1,2,1,3};
    auto x = unique(v.begin() , v.end()); // unique 자체로는 근처값들만
    cout<<" 이것은 unique 후 나온 결과"<<*x<<endl;
    v.erase(x , v.end());
    for(auto &e : v)
        cout<<e<<" ";
    cout<<endl;
    vector<int>vv{4,3,3,5,1,2,3};
    sort(vv.begin() , vv.end()); // 오름차순일테니까 1 2 3 3 3 4 5
    vv.erase(unique(vv.begin() , vv.end()) , vv.end());
    for(auto &e : vv)
        cout<<e<<" ";
    cout<<endl;

    vector<int>vp ={2,3,4,5,7};
    cout<<upper_bound(vp.begin(), vp.end(),6) - vp.begin()<<endl;
    cout<<&*upper_bound(vp.begin(), vp.end(),6)<<endl;
    cout<<&*vp.begin()<<endl;
    cout<<&*upper_bound(vp.begin(), vp.end(),6) - &*vp.begin()<<endl;
// 이렇게 이해하면 되려나?
// upperbound랑 begin 둘다 iterator임 -> 포인터임
// 그래서 asterisk가 붙어야 참조값을 볼 수 있음
// 그 참조값의 주소 자체는 0x~~ 로 되어있지만 실상 따지고 보면
// 배열 바구니의 주소임 그래서 우리가 주소값 찍어서 볼때는 모르지만, 컴퓨터상으로는 그냥 옆에 몇집 , 몇칸 떨어진걸 알 수 있음
// asterisk가 붙은 놈의 주소를 알려면 ampersand를 붙임. v.begin()의 주소는 맨처음 바구니의 집주소
// upperbound의 주소는 해당 upperbound값이 담긴 바구니의 집 주소
// 각각의 집 주소를 빼면 거리가 나오겠지 (501호랑 1701호랑 거리는 17-5인것처럼(단순계산))
// 그래서 저렇게 나오는거고, 결과론적으로는 &*이면 없는것과 마찬가지기 때문에 맨처음처럼 써도 무방하다는 말임.

    cout<<*upper_bound(vp.begin(), vp.end(),6) << *vp.begin()<<endl;
    cout<<distance(vp.begin(), upper_bound(vp.begin(),vp.end(),6))<<endl;
    string delta = "whatthe";
    delta+="abc";
    cout<<delta<<endl;
    delta.append("fuckyou");
    cout<<delta<<endl;
    vector<int>vpp{9,2,3,1,7,0};
    cout<<vpp.front()<<endl;
    cout<<*vpp.begin()<<endl;
    cout<<vpp.back()<<endl;
    cout<<*vpp.end()<<endl;
    cout<<&vpp.back()<<endl;
    cout<<&*vpp.end()<<endl;
    cout<<&vpp.front()<<endl;
    cout<<&*vpp.begin()<<endl;
    //cout<<v.begin()<<endl;
    // 그리고 distance를 써먹어도 됨. 근데 정렬된 상탠데 굳이 쓸 필요가 있을까 싶다.

    vector<bool>visited(10,3);// 10개의 공간에다가 3을 때려박자
    for(auto &e : visited)
        cout<<e<<endl;
    vector<int> kate(1000,100); // 1000개의 공간에 100을 때려박자
    cout<<kate[0]<<endl;
    for(auto &e : kate)
        if(e != -1) cout<<'what'<<endl;
    cout<<"kate"<<endl; // ㅅㅂ 왜 안돼??
    //vector<bool> why(6);
    // 포인터로 접근을 못한대.. vector<bool>은 -> 실제 bool값을 지닌게 아니고
    // bitfield를 이용해 bool값을 가지고 있는 것 처럼 흉내만 낸다고 한다 -> just use deque or bitset
    // in this case
    //for(auto &e : why)
       // cout<<e<<endl;

    vector<vector<int>>vec_1;
    vector<vector<int>>vec_2(10,vector<int>(10,0));
    vector<int>vec_3[10];
    for(vector<int>vec_1 : vec_2){
        for(int i :v)cout<<i<<" ";
        cout<<endl;
    }
    for(int i=0 ; i<10 ; i++){
        vector<int>cc;
        vec_1.push_back(cc);
    }
}