 //그림과 함께 잘 이해해 보도록 노력해보자
#include<iostream>
#include<queue>
#include<vector>
#define endl "\n"
#define fastio cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define INF 1e9 // big enough to make infinte num ( int형일때)
#define PP pair<int,int>
#define sc second
#define ff first
using namespace std;
int vertex, edge, start; // 정점 , 간선(so called as비용 or 가중치) , 시작점
int dis[20002]; // 최단거리 배열 (정점의 max 수 만큼 전역배열화 시킴)
vector<PP>near[20002]; // 현재 정점에서 다른 정점과 그 정점까지의 가중치를 저장하는 벡터
// 3개의 원소를 넣어야 하니 위와같이 쓰는거 알겠지?
int main() {
	fastio;
	cin >> vertex >> edge >> start;
	for (int i = 0; i <= 20001; i++) // 이거 끝까지 안하면 indexing error뜸
		dis[i] = INF; // 무조건 distance 배열 초기화 할때 배열의 첨부터 끝까지 일단 INF로 초기화 시키자!
	while (edge--) {// 지금 문제에선 어차피 edge(간선의 개수)는 그닥인 정보라서 while--로 소진시켜도 무방
		int u, v, w; // u to v 가중치 w
		cin >> u >> v >> w;
		near[u].push_back({ v,w }); // 위의 순서대로 u ,v ,w 순서
	}
	//Using Mean heap
	priority_queue<PP, vector<PP>, greater<PP>>pq;
	// pq는 (거리, 정점)순으로 해야함! 거리 순으로 정렬해야하니까 거리가 first
	dis[start] = 0; // 시작점의 거리 =0
	pq.push({ dis[start] , start }); // (거리 , 정점) -> (가중치 , 정점)으로 이해할 수 있지요.
	while (not pq.empty()) {
		int weight = pq.top().ff; // pq의 가중치
		int point = pq.top().sc; // pq의 정점
		pq.pop();
		if (dis[point] != weight)continue;// 왜 이렇게 되나면, 최소가중치의 합을 구할때 
		// 현재 pq의 정점의 dis가 현재 가중치 후보인데 weight랑 다르면 (다르다는게 무조건 클때겠지 왜냐면 최소 힙이니까)
		// 다르다는것은 무조건 현재 weight보다 크다는거니까 볼 필요도 없어서 continue넘기는거임
		/*
		바센세 설명(in 예제)
		여기서 이전엔 없던 좀 재밌는 현상이 발생하는데, 우선순위 큐에서 가장 작은 원소인 (5, 4)가 선택됐습니다.
		그런데 d[4] = 5가 맞는지 확인해보면 d[4] = 4여서 이 원소는 잘못된 원소입니다.
		이 5라는 값이 어디서 왔나 보면 1에서 바로 4로 가는 경로를 추가할 때 생겨난 값이지만
		1->3->4로 가는 더 짧은 경로가 나와서 쓸모가 없어진 원소입니다.
		그렇기 때문에 아무 처리도 하지 않고 그냥 건너뜁니다.
		*/
		for (auto &next : near[point]) { // 위에서 정의한 near의 원소수 만큼 for문을 돌림
			int next_point = next.ff; // 아까 near에서는 near[u].push_back({v,w}) 의 순서로 넣어놨기 때문에 
			// v에 해당하는 next_point가 next.first이고
			// w에 해당하는 가중치 next_weight가 next.second겠지.
			int next_weight = next.sc;
			if (dis[next_point] <= dis[point] + next_weight)continue; // 이것도 위의 상황과 비슷한 볼 필요도 없는 상황
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

// party 1238 아 어렵넹ㅇ..... 아 다시다시
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
		way[st].push_back({ time, end }); // minheap인데 time이 작은 순서가 우선순위가 되어야하니까 time이 먼저 오는거임
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
}// 이해는 되었으니 RE구현이 필요한 시점이다.