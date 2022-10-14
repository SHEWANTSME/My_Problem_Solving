//#include<iostream>
//#include<queue>
//#include<vector>
//#include<algorithm>
//#define ll long long
//#define fastio cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
//#define pp pair<ll,pair<ll,int>>
//#define ff first
//#define sc second
//using namespace std;
//int n;
//struct cmp {
//	bool operator()(pp a, pp b) {
//		if (a.ff == b.ff) {
//			return a.sc < b.sc;
//		}
//		else return a.ff > b.ff;
//
//		//	if (x.sc == y.sc) return idx[x.ff] < idx[y.ff];// idx가 작은애부터 출력
//		//	else return x.sc > y.sc;
//	}
//};
//priority_queue<pp,vector<pp> , cmp>pq;
//priority_queue<ll,vector<ll>, greater<ll>>pq2;
//int main() {
//	fastio; cin >> n;
//	for (int i = 1; i <= n; i++) {
//		int classnum;
//		ll st_time, end_time;
//		cin >> classnum >> st_time >> end_time;
//		pq.push({ st_time,{end_time , classnum} });
//	}
//	pq2.push(pq.top().sc.ff);
//	pq.pop();
//	while (not pq.empty()) {
//	//	cout << pq2.size() << endl;
//		auto now = pq.top();
//	//	cout << now.ff << " " << pq2.top()<<" "<<now.sc.ff << endl;
//		if (now.ff >= pq2.top()) { pq2.push(now.sc.ff); pq2.pop(); }
//		else pq2.push(now.sc.ff);
//		pq.pop();
//	}
//	while (not pq2.empty()) {
//		auto now = pq2.top();
//		cout << now << endl;
//		pq2.pop();
//	}
////	cout <<"at last : "<< pq2.size() << endl;
//	/*while (not pq.empty()) {
//		auto now = pq.top();
//		cout << now.sc.sc<< " " << now.ff<< " " << now.sc.ff << endl;
//		pq.pop();
//	}*/
//
//}

//#include<iostream>
//#include<queue>
//#include<algorithm>
//#define pp pair<int,int>
//using namespace std;
//int n;
//priority_queue<int, vector<int>, greater<int>>pq;
////priority_queue<pp,vector<pp>,greater<pp>>pq;
//int main() {
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		int t; cin >> t; pq.push(t);
//		//pq.push({ t,i });
//	}
//	int ans = 0;
//	int realans = 0;
//	while (not pq.empty()) {
//		int now=pq.top();
//		pq.pop();
//		ans += now;
//		realans += ans;
//	}
//	cout << realans << endl;
//}


// 이문제가 강의실문제일거임! 1374번
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#define ll long long
#define fastio cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define pp pair<int,int>
#define pq priority_queue
#define ff first
#define sc second
using namespace std;
int n;
pq<pp, vector<pp>, greater<pp>>PQ;
pq<int, vector<int>, greater<int>>PQ2;
int main() {
	fastio; cin >> n;
	for (int i = 1; i <= n; i++) {
		int st_time, end_time;
		cin >> st_time >> end_time;
		PQ.push({  end_time,st_time });
	}
	int now_end_time = PQ.top().ff;
	int now_st_time = PQ.top().sc;
	PQ.pop();
	while (not PQ.empty()) {
		auto now = PQ.top();
		PQ.pop();
		if(now_end_time<now.sc)
		cout << PQ.top().sc<< " " << PQ.top().ff<< endl;
		PQ.pop();
	}
}
//struct cmp {
//	bool operator()(pp a, pp b) {
//		if (a.ff == b.ff) {
//			return a.sc < b.sc;
//		}
//		else return a.ff > b.ff;
//	}
//};
////priority_queue<pp, vector<pp>, cmp>pq;
////priority_queue<ll, vector<ll>, greater<ll>>pq2;
//int main() {
//	fastio; cin >> n;
//	for (int i = 1; i <= n; i++) {
//		int classnum;
//		ll st_time, end_time;
//		cin >>st_time >> end_time;
//		pq.push({ st_time,{end_time , classnum} });
//	}
//	pq2.push(pq.top().sc.ff);
//	pq.pop();
//	while (not pq.empty()) {
//		//	cout << pq2.size() << endl;
//		auto now = pq.top();
//		//	cout << now.ff << " " << pq2.top()<<" "<<now.sc.ff << endl;
//		if (now.ff >= pq2.top()) { pq2.push(now.sc.ff); pq2.pop(); }
//		else pq2.push(now.sc.ff);
//		pq.pop();
//	}
//	while (not pq2.empty()) {
//		auto now = pq2.top();
//		cout << now << endl;
//		pq2.pop();
//	}
//	//	cout <<"at last : "<< pq2.size() << endl;
//		/*while (not pq.empty()) {
//			auto now = pq.top();
//			cout << now.sc.sc<< " " << now.ff<< " " << now.sc.ff << endl;
//			pq.pop();
//		}*/
//
//}