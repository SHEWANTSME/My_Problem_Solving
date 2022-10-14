#include<iostream>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;
int n;
int arr[1001];
ll dp1[1001][2];
ll dp2[1001][2];
ll dp[1001];
ll cnt[1001];
priority_queue<ll>pq;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[1] = arr[1];
	cnt[1] = 1;
	for (int i =2; i <= n; i++) {
		// now 랑 dp[i-1]로 비교해야하지 않나?
		int now = arr[i];
		if (now <= dp[i - 1]) {
			dp[i] = dp[i - 1] + now;
			cnt[i] = cnt[i - 1] + 1;
		}
		else {
			pq.push(cnt[i - 1]);
			dp[i] = now;
			cnt[i] = 1;
		}
	}
	if (not pq.empty()) { cout << max(pq.top(),cnt[n]) << endl; }
	else cout << cnt[n] << endl;
}

//  아 문제 이해 잘못..

#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define ll long long
using namespace std;
int n;
int arr[1001];
ll dp[1001];
ll cnt[1001];
bool exclude[1001];
priority_queue<ll>pq;
// 제거할 놈부터 
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	dp[1] = arr[1];	cnt[1] = 1;

	vector<int>nn;
	for (int i = 1; i <= n; i++) {
		nn.push_back(i);
	}
	for (int k = 1; k <= n; k++) {
		vector<int>ind;
		for (int i = 0; i < k; i++) {
			ind.push_back(1);
		}
		for (int j = 0; j < nn.size() - k; j++) {
			ind.push_back(0);
		}
		sort(ind.begin(), ind.end());
		do {
			for (int i = 0; i < ind.size(); i++) {
				if (ind[i] == 1) {
					exclude[nn[i]] = 1;
					//cout << nn[i] << " ";
				}//cout << endl;
			}
			int ssum = 0;
			int flag = 0;
			for (int i = 1; i <= n; i++) {
				if (exclude[i] == 1)continue;
				else {
					flag = i; break;
				}
			}
			int ccnt = 1;
			if (flag != 0) {
				ssum= arr[flag];
				for (int i = flag+1; i <= n; i++) {
					if (exclude[i] == 1)continue;
					else {
						if (ssum >= arr[i]) {
							ssum += arr[i]; ccnt++;
						}
						else {
							ssum = arr[i];
							ccnt = 1;
						}
					}
				}
				pq.push(ccnt);
			}
			for (int i = 1; i <= 1000; i++)exclude[i] = 0;
		} while (next_permutation(ind.begin(), ind.end()));
	}
	int new_sum = arr[1];
	bool real = 0;
	for (int i = 2; i <= n; i++) {
		if (new_sum >= arr[i])new_sum += arr[i];
		else {
			real = 1; break;
		}
	}
	if(real==1)	cout << pq.top() << endl;
	else cout << n << endl;
}