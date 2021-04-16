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

struct edge {
	int a, b, id;
	edge() {};
	edge(int a, int b, int id) : a(a), b(b), id(id) {};	
};

int N, M;
vector<edge> adj[100001];

bool  vis[200001];
edge edges[200001];
int depth[100001];


void dfs(int cur, int d = 1) {
	vis[cur] = 1;
	depth[cur] = d;
	
	for (edge E : adj[cur]) {
		
		if (!vis[E.b]) {
			//used[E.id] = 1;
			dfs(E.b, d+1);
		}	
		
	}
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	
	rep(i,1,M) {
		int a, b;
		cin >> a >> b;
		adj[a].PB(edge(a,b,i));
		edges[i] = edge(a,b,i);
	}

	dfs(1);
	
	rep(i,1,M) {
		int a = edges[i].a, b = edges[i].b;
		if (depth[a] < depth[b]) swap(a,b); 
		if (depth[a] == depth[b] && a < b) swap(a,b);
		
		cout << a << ' ' << b << endl;
	}
	
    return 0;
}








