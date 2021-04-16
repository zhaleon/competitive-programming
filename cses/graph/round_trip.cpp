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

int last = 0;
void search(int cur = 1) {
	for (auto &edge : adj[cur]) {
		if (!last && !parent[edge]) {
			parent[edge] = cur;
			search(edge);
		} else if (!last && parent[cur] != edge) { 
			vi path;
			path.PB(edge);

			while (cur != edge) {
				path.PB(cur);
				cur = parent[cur];
			}
			path.PB(edge);

			cout << path.size() << endl;
			for (auto e : path) cout << e << ' ';	
			
			last = 1;
			return;
		}
	}
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	rep(i,1,M) {
		int a, b;
		cin >> a >> b;
		adj[a].PB(b);
		adj[b].PB(a);
	}

	rep(i,1,N) {
		if (!parent[i] && !last) {
			search(i);
		}
	}

	if (!last) cout << "IMPOSSIBLE\n";

   	
	return 0;
}








