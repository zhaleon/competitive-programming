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
ll dist[2501];
int p[2501];

struct edge {
	ll a, b, w;
	edge() {};
	edge(int a, int b, int w) : a(a), b(b), w(w) {};
};

edge edges[5001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	rep(i,1,M) {
		int a, b, w;
		cin >> a >> b >> w;
		edges[i] = edge(a,b,w);
	}
	int x;

	memset(dist, 0x3f, sizeof(dist));
	dist[1] = 0;

	rep(i,1,N) {
		x = -1;
		rep(j,1,M) {
			ll a = edges[j].a, b = edges[j].b, w = edges[j].w;
			if (dist[a] + w < dist[b]) {
				p[b] = a;
				dist[b] = dist[a] + w;
				x = b;
			}
		}
	}


	if (x == -1) {
		cout << "NO" << endl;
	} else {
		rep(i,1,N) x = p[x];
		vi cycle;

		for (int v = x;; v = p[v]) {
			cycle.PB(v);
			if (v == x && cycle.size() > 1)
				break;
		}
		reverse(cycle.begin(), cycle.end());
		cout << "YES" << endl;
		for (auto e : cycle) cout << e << ' ';
	}
    return 0;
}








