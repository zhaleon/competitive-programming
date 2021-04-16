#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;

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

int N, M;

vi tree_adj[100001];
vi adj[100001];

int fir[100001];
int las[100001];

int t = 1;
void dfs(int cur, int par = -1) {
	fir[cur] = t++;
	for (auto edge : tree_adj[cur]) if (edge != par) dfs(edge, cur);
	las[cur] = t++;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	
	rep(i,0,M) {
		int a, b;
		cin >> a >>  b;
		if (i < N-1) {
			tree_adj[a].PB(b);
			tree_adj[b].PB(a);
		} else {
			adj[a].PB(b);
			adj[b].PB(a);
		}
	}
	
	

    return 0;
}