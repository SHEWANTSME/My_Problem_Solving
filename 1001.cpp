//#include<iostream>
//#include<string>
//#include<queue>
//#include<vector>
//using namespace std;
//#define pp pair<int,pair<string,int>>
//#define ff first
//#define sc second
//int n;
//struct cmp {
//	bool operator()(pp x, pp y) {
//		if (x.first == y.first) {
//			bool now = x.second.second > y.second.second;
//			return now;
//		}
//		else {
//			bool nononow = x.first >y.first;
//			return nononow;
//		}
//	}
//};
//priority_queue<pp, vector<pp>,cmp >pq;
//
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		int age; string s;
//		cin >> age >> s;
//		pq.push({ age,{s,i} });
//	}
//	while (not pq.empty()) {
//		auto x = pq.top();
//		cout << x.first << " " << x.second.first << endl;
//		pq.pop();
//	}
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
////struct Node {
////	int data;
////	struct Node *next;
////};
////// insert a new node in an empty list
////struct Node *Insert_Empty(struct Node *last, int new_node) {
////	if (last != NULL)return last;
////	struct Node *temp = new Node;
////	
////}
//// 일단 나이순 정렬을 해보자 
//
////struct cmp {
////	bool operator()(pp x, pp y) {
////		if (x.first == y.first) return x.second < y.second;
////		else x.first < y.first;
////	}
////};
//
//
//
//
//
//#include<iostream>
//#include<string>
//using namespace std;
//#define ll long long 
//ll dp[3001][2][2];
//string s;
//// 65~90 : 대문자 알파벳
//// 97~122 : 소문자 알알파벳// '0' = 48
//int main() {
//	cin >> s;
//	for (int i = 0; i <= 3000; i++) {
//		dp[i][0][0] = 1e9;// [now_idx][캡스락][토글]
//		dp[i][1][1] = 1e9;
//		dp[i][0][1] = 1e9;
//		dp[i][1][0] = 1e9;
//
//	}
//	if (s[0] < 95) { // 대문자
//		dp[1][0][1] = 2;
//		dp[1][1][0] = 2;
//	}
//	else { // 소문자
//		dp[1][0][0] = 1;
//		dp[1][1][0] = 2; // j + 캡스락일땐 어쩔껀데?
//	}
//	for (int i = 1; i < s.size(); i++) {
//		if (s[i] - 95 < 0) {// 대문자
//			dp[i + 1][0][1] = min(dp[i][0][0] + 1, dp[i][1][0] + 2);
//			dp[i + 1][1][0] = min(dp[i])
//				dp[i + 1][0][0] =
//				dp[i + 1][1][1] =
//				//dp[i+1][0] = min(dp[i][0]+1 , dp[i][1]+2);
//				//dp[i+1][1] = min(dp[i][0]+2,dp[i][1]+2);
//		}
//		else {
//			dp[i + 1][0] = min()
//				dp[i + 1][1] = min()
//		}
//	}
//}


#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s;
int main() {
	cin >> s;
	int ans = 0;
	//string ap = "aaaa";
	//string k = "";
	//cout << s + k+ap << " "; cout << "fuck" << endl;
	while (1) {
		string front = "";
		string back = "";
		if (s == "1")cout << ans+1 << endl, exit(0);
		bool flag = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != '0'){flag = 1; break;}
		}
		if(flag==0)cout << ans << endl, exit(0);
		cout << s << endl;
		int idx = -1;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '1') { idx = i; break; }
		}
		if (idx == -1) {
			try {
				int now = stoi(s);
				now--;
				s = to_string(now);
				ans++;
			}
			catch(...){
				string new_s = "";
				for (int i = 0; i < s.size(); i++) {
					if (s[i] == '0')continue;
					else new_s.push_back(s[i]);
				}
				if (new_s == "") { cout << ans << endl; exit(0); }
				else { s = new_s; ans++; }
			}
		}
		else {
			for (int i = 0; i < idx; i++) front.push_back(s[i]);
			for (int j = idx + 1; j < s.size(); j++) back.push_back(s[j]);
			s = front + back;
			ans++;
			
		}
	}

}
