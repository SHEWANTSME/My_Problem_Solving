//// 3165번
//#include<iostream>
//#include<string>
//#define ll long long
//using namespace std;
////ll n, k;
//string n; 
//ll k;
//int main() {
//	cin >> n >> k;
//	int now = -1;
//	int mmax = n.size();
//	while (1) {
//		for (auto &e : n) {
//			if(e)
//		}
//	}
//
//}
//
//N, K = map(int, input().split())
//N += 1
//N_list = list(str(N))
//cur_idx = -1
//max_idx = len(N_list)
//while True:
//if N_list.count('5') >= K :
//	break
//	while N_list[cur_idx] == '5' and abs(cur_idx) < max_idx :
//		cur_idx -= 1
//
//		cur_value = int(''.join(N_list))
//		cur_value = cur_value + 10 * *(abs(cur_idx) - 1)
//		N_list = list(str(cur_value))
//		max_idx = len(N_list)
//
//
//
//		print(''.join(N_list))

//#include<iostream>
//#include<vector>
//#include<algorithm>
//#define pp pair<int,int>
//#define endl "\n"
//using namespace std;
//
//int n;
//int arr[100][100];
//int ans = 1e9;
//int f;
//int main() {
//	pp ff;
//	bool cnt; cin >> n;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cin >> arr[i][j];
//			if (arr[i][j] & 4) { ff = { i,j }, cnt = (i + j) & 1; cout << i << " " << j << " " << cnt << endl; }
//		}
//	}
//	//for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
//	//	if (i & 1)f = i, cnt = (i + j) & 2, cout << f << " " << cnt << endl;
//	//}
//	
//
//}




//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int chk[100][100], n, ans = 1e9, f;
//vector<pair<int, int>> doit;
//
//int main() {
//	ios::sync_with_stdio(0); cin.tie(0);
//	pair<int, int> jr;
//	bool cnt; cin >> n;
//	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
//		cin >> chk[i][j];
//		if (chk[i][j] & 2) jr = { i,j }, cnt = (i + j) & 1;
//	}
//
//	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
//		if (chk[i][j] & 1) {
//			doit.push_back({ i,j }); f++;
//			if ((cnt + i + j) & 1) { cout << "Shorei"; return 0; }
//		}
//	}
//	cout << "Undertaker\n";
//	sort(doit.begin(), doit.end());
//	do {
//		pair<int, int>tmp = jr;
//		int mun = 0;
//		cout << "TMP_first" << tmp.first << " " << "T_s" << tmp.second << endl;
//		for (int i = 0; i < f; i++) {
//			mun += max(abs(tmp.first - doit[i].first), abs(tmp.second - doit[i].second));
//			tmp = doit[i];
//			cout << mun << " " << tmp.first<<" " << tmp.second << endl;
//		}
//		ans = min(ans, mun);
//		cout << "ansans"<<ans << endl;
//	} while (next_permutation(doit.begin(), doit.end()));
//	cout << ans; // 와 ㅅㅂ 이해했다 ㅠㅠ ㅈ같은 문제넹 
//	// 무지성 넥퍼뮤말곤 없나 ㅇㅅㅇ?
//}


#include<iostream>
#include<string>
#include<algorithm>
#include<deque>
#define ll long long
using namespace std;
ll n, k;
string nn;
deque<char>ans;
void Back(string nn ,)
//void Back(string nn, ll k,ll idx) {
//	if (idx == k) {
//		for (auto &e : ans) {
//			cout << e << " ";
//		}cout << endl;	 return;
//	}
//	else {
//		if (nn[nn.size() - idx] < '5') {
//			nn[nn.size() - idx] == '5';
//			Back(nn, k, idx + 1);
//		}
//		else if (nn[nn.size() - idx] > '5') {
//			
//		}
//		else Back(nn, k, idx + 1);
//	}
//	/*k==1이면
//	12346 -> 12350
//	12376 -> 12385
//
//	12342
//
//	k==2이면
//	12346-> 12350 -> 12355
//	12376 -> 12385 -> 12455가 되겠군
//
//	999-> 1005
//	*/
//	
//
//	//for (int i = 0; i < nn.size(); i++) {
//	//	if (nn[i] == '5')cnt++;
//	//}
//	//if (k <= cnt) {
//	//	cout << nn << endl; return;
//	//}
//	//123456789012345 3
//
//	}
int main() {
	cin >> n >> k;
	n += 1;
	nn=	to_string(n);
	// 595 2 -> 595보다 크면서 5 가 두개있는 가장 작은수
	ll cnt = 0;
	for (int i = 0; i < nn.size(); i++) {
		ans.push_back(' ');
		if (nn[i] == '5')cnt++;
	}	
	if (cnt >= k)cout << nn << endl, exit(0);
	Back(nn, k , 1);
}