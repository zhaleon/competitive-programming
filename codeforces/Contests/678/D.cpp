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
#define rep(i,a,b) for (int i = a; i < b; i++)

void setIO(string name) {
	freopen((name+".in").c_str(), "r", stdin); 
	freopen((name+".out").c_str(), "w", stdout);
}

int N;

vi adj[200001];

ll arr[200001];
ll best[200001];

void get_size(int cur) {
	best[cur] = 0;
	for (auto edge : adj[cur]) {
		get_size(edge);
		best[cur] = max(best[cur] ,best[edge]);
	}
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	rep(i,1,N) {
		int a; cin >> a;
		adj[a].PB(i);
	}

	rep(i,1,N+1) cin >> arr[i];
    
	get_size(1);

	int cur = 1;

	while (adj[cur].size()) {
		int nxt = 0, score = INF;

		for (auto edge : adj[cur]) {
			if (score > best[edge]) {
				score = best[edge];
				nxt = edge;
			}
		}

		cur = 3;
	}

    return 0;
}








