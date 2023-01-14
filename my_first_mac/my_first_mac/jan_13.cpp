#include<iostream>
#include<string>
// 프로그래머스 괄호변환
using namespace std;
string Rec(string p) {
    if (p == "")    return p;
    string u="",v="";
    int lc =0,rc=0;
    for(int i=0 ; i<p.size() ; i++){
        if(p[i]=='(')lc++;
        else rc++;
        if(lc==rc){
            for(int j=0; j<i+1; j++) u +=p[j];
            for(int k=i+1; k<p.size() ; k++) v+=p[k];
            break;
        }
    }
    int tt = 0;
    bool chk = 1;
    for(int i=0 ; i<u.size() ; i++){
        if(u[i]==')' and tt ==0){chk=0; break;}
        if(u[i]==')' and tt!=0)tt--;
        if(u[i]=='(')tt++;
    }
    if(chk==1)return u + Rec(v);
    else{
        string temp = "(";
        temp += Rec(v)+")";
        string ttemp = "";
        for(int i=1 ; i<u.size()-1 ; i++){
            if(u[i] ==')')temp+='(';
            else temp+=')';
        }
       return temp;
    }
}
string solution(string p) {
    int ttt = 0;
    bool chkk = 1;
    for(int i=0 ; i<p.size() ; i++){
        if(p[i]==')' and ttt ==0){chkk=0; break;}
        if(p[i]==')' and ttt!=0)ttt--;
        if(p[i]=='(')ttt++;
    }
    if(chkk==1)return p;
    return Rec(p);
}

int main(){
    cout<< solution("()))((()")<<endl;
}
