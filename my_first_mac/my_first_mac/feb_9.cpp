// build 하고 나서 생기는 unknown text file은 지워도 될 듯 하다.
// 빌드 한 내역을 저장하는 것 같은데 굳이 없어도 될것같다. 어차피 다시 빌드하면 다시 생긴다.
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
// 잘 알려줌 : https://colinch4.github.io/2021-01-14/struct_class_constructor/
// https://blog.hexabrain.net/165
// https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=kartmon&logNo=221510676043
// 위의놈은 linkedlist 구현한건데 이해해보고 나도 짤 수 있도록.. 노력해보자!
// 구조체 연습
// case1 : struct + 구조체명 -> 이럴때는 굳이 typedef 안써도됨
struct BasketballPlayer{ 
    string name;
    string team;
    int age;
    string position;
    double avg;
}; // 괄호때문에 함수처럼 보일 수 있지만 함수가 아니고 선언문임(definition) 그래서
// 세미콜론을 붙여야함!
// or you can do like this too
// case2 : typedef struct {} 구조체명;
typedef struct {// typedef : 사용자 정의 구조체를 만들어라!
    string name;
    int age;
} june;

/*
그냥 알아듣기 쉽게 한가지로 fix 하자
1. 앞으로 구조체 짤때 typedef struct{} june; 이런식으로 하자. 
(헷갈리는거 질색임)
2. 구조체는 선언문임(definition) 그래서 semicolon붙음
*/
typedef struct{
    int num ; 
    string position;
    double era;
}bbPlayer;
void changeStruct(bbPlayer *structTest){
    // 헷갈리면 안되는게 이건 void 함수고 이 함수의
    // parameter가 'bbPlayer *' 라는 자료형을 가지고 있음 -> 포인터 변수 선언할때랑 비슷하게 생각하셈
    // 그러면 저 변수의 ㄹㅇ값을 가리키고 싶으면 asterisk를 사용해야겠지
    // 그래서 *을 붙인 *structTest가 가리키는 값을 나타내는데 이건 지금 구조체니까
    // .name을 통해서 멤버변수를 찾을 수 있어
    // 그래서 (*structTest).name 이런식으로
    // 근데 쓰기 귀찮으니까 그냥 structTest -> name 이렇게 하자는 얘기지
    structTest -> num = 60;
    (*structTest).position = "helloworld";
    structTest->era = 0;
}

// 다시 해보자
class Node{
public:
    int data;// 노드에 담겨있는 데이터
    Node * next;// 다음 노드를 가리키는 포인터변수
    Node(){
        data = 0; next = NULL;
    }
}
class Linked_List{
    private:
        Node* head;
        Node* tail;
        Node* cur;
    public:
        Linked_List();// 포인터변수들을 NULL로 초기화
        void insert_node(int);
        void print_all(); // 현재 리스트에 있는 모든 데이터 출력
        void delete_all(); // ''             ''     삭제
}

int main(){
    // BasketballPlayer guard;
    // BasketballPlayer *powerforward;
    // BasketballPlayer arr[100];
    // june junny;
    bbPlayer player;
    bbPlayer *player_ptr = &player;
    player.num = 42;
    player.position = "starting";
    player.era = 2.42;
    changeStruct(player_ptr);
    cout<<player.era<<endl; 
    cout<<player.num<<endl; 
    cout<<player.position<<endl; 

}