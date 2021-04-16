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

void setIO(string name) {
	freopen((name+".in").c_str(), "r", stdin); 
	freopen((name+".out").c_str(), "w", stdout);
}

int N, M;
vi adj[100001];
int parent[100001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
	rep(i,1,M) {
		int a, b;
		cin >> a >> b;
		adj[a].PB(b);
		adj[b].PB(a);
	}

	parent[1] = 1;

	queue<int> q;
	q.push(1);

	while(q.size()) {
		int cur = q.front(); q.pop();

		for (auto &edge : adj[cur]) {
			if (!parent[edge]) {
				parent[edge] = cur;
				q.push(edge);
			}
		}
	}

	int cur = N;
	if (!parent[cur]) {
		cout << "IMPOSSIBLE\n";	
	} else {
		vi path;
		path.PB(N);
		while (N != 1) {
			path.PB(parent[N]);
			N = parent[N];
		}

		cout << path.size() << endl;

		reverse(path.begin(), path.end());
		for (auto e : path) cout << e << ' ';
	}

    return 0;
}








