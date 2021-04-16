#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;

#define INF 1000000000
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)

int T, N, M;

int best[200001][2];
int dist[200001];
bool v[200001];
vi adj[200001];

vi radj[200001];

void search(int s) {

	queue<int> bfs;
	bfs.push(1);
	dist[1] = 0;

	while (bfs.size()) {
		int cur = bfs.front(); bfs.pop();
		v[cur] = 1;

		for (auto &e : adj[cur]) {
			if (!v[e]) {
				dist[e] = dist[cur] + 1;
				bfs.push(e);
			}
		}
	}
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T >> N >> M;

	while (T--) {
		cin >> N >> M;
		rep(i,1,N) best[i][0] = best[i][1] = dist[i] = INF;

		rep(i,1,M) {
			int a, b;
			cin >> a >> b;
			adj[a].PB(b);
			adj[b].PB(a);
		}
		
		search(1);



		rep(i,1,N) adj[i].clear();
	}
    
    return 0;
}








