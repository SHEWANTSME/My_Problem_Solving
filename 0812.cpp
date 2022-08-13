 //�׸��� �Բ� �� ������ ������ ����غ���
#include<iostream>
#include<queue>
#include<vector>
#define endl "\n"
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define INF 1e9 // big enough to make infinte num ( int���϶�)
#define PP pair<int,int>
#define sc second
#define ff first
using namespace std;
int vertex, edge, start; // ���� , ����(so called as��� or ����ġ) , ������
int dis[20002]; // �ִܰŸ� �迭 (������ max �� ��ŭ �����迭ȭ ��Ŵ)
vector<PP>near[20002]; // ���� �������� �ٸ� ������ �� ���������� ����ġ�� �����ϴ� ����
// 3���� ���Ҹ� �־�� �ϴ� ���Ͱ��� ���°� �˰���?
int main() {
	fastio;
	cin >> vertex >> edge >> start;
	for (int i = 0; i <= 20001; i++) // �̰� ������ ���ϸ� indexing error��
		dis[i] = INF; // ������ distance �迭 �ʱ�ȭ �Ҷ� �迭�� ÷���� ������ �ϴ� INF�� �ʱ�ȭ ��Ű��!
	while (edge--) {// ���� �������� ������ edge(������ ����)�� �״��� ������ while--�� �������ѵ� ����
		int u, v, w; // u to v ����ġ w
		cin >> u >> v >> w;
		near[u].push_back({ v,w }); // ���� ������� u ,v ,w ����
	}
	//Using Mean heap
	priority_queue<PP, vector<PP>, greater<PP>>pq;
	// pq�� (�Ÿ�, ����)������ �ؾ���! �Ÿ� ������ �����ؾ��ϴϱ� �Ÿ��� first
	dis[start] = 0; // �������� �Ÿ� =0
	pq.push({ dis[start] , start }); // (�Ÿ� , ����) -> (����ġ , ����)���� ������ �� ������.
	while (not pq.empty()) {
		int weight = pq.top().ff; // pq�� ����ġ
		int point = pq.top().sc; // pq�� ����
		pq.pop();
		if (dis[point] != weight)continue;// �� �̷��� �ǳ���, �ּҰ���ġ�� ���� ���Ҷ� 
		// ���� pq�� ������ dis�� ���� ����ġ �ĺ��ε� weight�� �ٸ��� (�ٸ��ٴ°� ������ Ŭ������ �ֳĸ� �ּ� ���̴ϱ�)
		// �ٸ��ٴ°��� ������ ���� weight���� ũ�ٴ°Ŵϱ� �� �ʿ䵵 ��� continue�ѱ�°���
		/*
		�ټ��� ����(in ����)
		���⼭ ������ ���� �� ��մ� ������ �߻��ϴµ�, �켱���� ť���� ���� ���� ������ (5, 4)�� ���õƽ��ϴ�.
		�׷��� d[4] = 5�� �´��� Ȯ���غ��� d[4] = 4���� �� ���Ҵ� �߸��� �����Դϴ�.
		�� 5��� ���� ��� �Գ� ���� 1���� �ٷ� 4�� ���� ��θ� �߰��� �� ���ܳ� ��������
		1->3->4�� ���� �� ª�� ��ΰ� ���ͼ� ���� ������ �����Դϴ�.
		�׷��� ������ �ƹ� ó���� ���� �ʰ� �׳� �ǳʶݴϴ�.
		*/
		for (auto &next : near[point]) { // ������ ������ near�� ���Ҽ� ��ŭ for���� ����
			int next_point = next.ff; // �Ʊ� near������ near[u].push_back({v,w}) �� ������ �־���� ������ 
			// v�� �ش��ϴ� next_point�� next.first�̰�
			// w�� �ش��ϴ� ����ġ next_weight�� next.second����.
			int next_weight = next.sc;
			if (dis[next_point] <= dis[point] + next_weight)continue; // �̰͵� ���� ��Ȳ�� ����� �� �ʿ䵵 ���� ��Ȳ
			dis[next_point] = dis[point] + next_weight;
			pq.push({ dis[next_point] , next_point });
		}
	}
	for (int i = 1; i <= vertex; i++) {
		if (dis[i] == INF) cout << "INF" << endl;
		else cout << dis[i] << endl;
	}
	return 0;
}

// party 1238 �� ��Ƴߤ�..... �� �ٽôٽ�
# include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#define pp pair<int,int>
#define INF 1e9+10
#define ff first
#define sc second
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
using namespace std;
int n, m, x;
vector<pp>way[1001];
vector<int>dis;
int visited[1001];
void Dijkstra(int tt) {
	dis.clear();
	dis.resize(n + 1, INF);
	dis[tt] = 0;
	priority_queue<pp, vector<pp>, greater<pp>>pq;
	pq.push({ dis[tt], tt });
	while (not pq.empty()) {
		int cost = pq.top().ff;
		int now = pq.top().sc;
		pq.pop();
		if (cost > dis[now])continue;
		for (auto & next : way[now]) {
			int _next = next.sc;
			int _next_cost = next.ff+cost;
			if (_next_cost < dis[_next]) {
				dis[_next] = _next_cost;
				pq.push({ _next_cost, _next });
			}
		}
	}
}
int main() {
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		int st, end, time;
		cin >> st >> end >> time;
		way[st].push_back({ time, end }); // minheap�ε� time�� ���� ������ �켱������ �Ǿ���ϴϱ� time�� ���� ���°���
	}
	for (int i = 1; i <= n; i++) {
		Dijkstra(i);
		visited[i] = dis[x];
	}
	Dijkstra(x);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		visited[i] += dis[i];
		ans = max(ans, visited[i]);
	}
	cout << ans << endl;
}// ���ش� �Ǿ����� RE������ �ʿ��� �����̴�.