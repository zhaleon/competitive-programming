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

int N, Q;
vi adj[200001];

int t = 0;
int fir[200001];
int las[200001];

void dfs(int cur = 1, int p = -1) {
	fir[cur] = ++t;
	for (auto &edge : adj[cur]) 
		if (edge != p)
			dfs(edge, cur);
	las[cur] = t;
}

int tree[200001];
ll bit[200001];

void update(int pos, int delta) {
	while (pos < N+1) {
		bit[pos] += delta;
		pos += pos & -pos;
	}
}

ll sum(int i) {
	ll res = 0;
	while (i) {
		res += bit[i];
		i -= i & -i;
	}
	return res;
}

ll sum(int i, int j) {
	return sum(j) - sum(i-1);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> Q;

	rep(i,1,N+1) cin >> tree[i];
	
	rep(i,1,N) {
		int a, b;
		cin >> a >> b;
		adj[a].PB(b);
		adj[b].PB(a);
	}
   
	dfs();

	rep(i,1,N+1) update(fir[i], tree[i]);

	rep(i,0,Q) {
		int a, b, c;
		cin >> a;
		
		if (a == 1) {
			cin >> b >> c;
			update(fir[b], -tree[b]);
			update(fir[b], c);
			tree[b] = c;
		} else {
			cin >> b;
			cout << sum(fir[b], las[b]) << endl;
		}
	}

    return 0;
}








