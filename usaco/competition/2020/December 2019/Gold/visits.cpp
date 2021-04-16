#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int> > vii;
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

vector<pair<pii, pii>> queries;
vpi ans;

vi adj[100001];
vi farm[100001];

int active[100001];
int bit[200002];

int fir[100001]; //range query
int last[100001];

int parent[100001][19];
int depth[100001];

bool comp(pair<pii, pii> a, pair<pii, pii> b) {return a.F.F < b.F.F;} // cow type,  index of the query, path
bool comp2(pii a, pii b) {return a.F < b.F;};

int t = 1;
void dfs(int cur) {
	fir[cur] = t++; //t++;
	for (auto edge : adj[cur]) if (!fir[edge]) dfs(edge);
	last[cur] = t++; //t++;
}

void lcaPre(int cur, int d) {
	depth[cur] = d;
	for (auto edge : adj[cur]) {
		if (!parent[edge][0]) {
			parent[edge][0] = cur; 
			lcaPre(edge, d+1);
		}	
	}
}
int lca(int i, int j) {
	if (i == j) return i;
	if (depth[i] < depth[j]) swap(i,j);
	
	int dif = abs(depth[i]-depth[j]);
	for (int a = 17; a >= 0; a--) {
		if (dif & (1 << a)) i = parent[i][a];
	}
	
	assert(depth[i] == depth[j]);
	
	int p = 17;
	while (i != j && p--) {
		if (depth[i] > (1 << p) && parent[i][p] != parent[j][p]) {
			i = parent[i][p];
			j = parent[j][p];
		}
	}
	if (i == j) return i;
	assert(parent[i][0] == parent[j][0]);
	return parent[i][0];
}

void upd(int pos, int delta, int size = 2*N+1) {
	while (pos < size) {
		bit[pos] += delta;
		pos += pos & -pos;
	}
}	

int sum(int i) {
	int res = 0;
	while (i > 0) {
		res += bit[i];
		i -= i & -i;
	}
	return res;
}

int main() {
	setIO("milkvisits");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
    
	int a, b, c;
	rep(i,1,N+1) {
		cin >> a;
		farm[a].PB(i);
	}

	rep(_,0,N-1) {
		cin >> a >> b;
		adj[a].PB(b);
		adj[b].PB(a);
	}

	rep(i,0,M) {
		cin >> a >> b >> c;
		queries.PB(MP(MP(c,i), MP(a,b)));
	}

	sort(queries.begin(), queries.end(), comp);
	dfs(1);
	parent[1][0] = 1;
	lcaPre(1, 1);
	
	rep(j,0,17) {
		rep(i,1,N+1) {
			parent[i][j+1] = parent[parent[i][j]][j];
		}
	}

	int curQuery = 0;
	rep(i,1,N+1) {
		rep(j,0,farm[i].size()) {
			upd(fir[farm[i][j]], 1);
			upd(last[farm[i][j]], -1);
			active[farm[i][j]] = 1;
		}

		int res;
		while (curQuery < queries.size() && queries[curQuery].F.F == i) {
			res = 0;
			auto q = queries[curQuery].S;
			int _lca = lca(q.F, q.S);
			res += sum(fir[q.F]) + sum(fir[q.S]) - 2*sum(fir[_lca]) + active[_lca];
			if (res > 0) ans.PB(MP(queries[curQuery].F.S, 1));
			else ans.PB(MP(queries[curQuery].F.S, 0));
			
			curQuery++;
		}
		
		rep(j,0,farm[i].size()) {
			upd(fir[farm[i][j]], -1);
			upd(last[farm[i][j]], 1);
			active[farm[i][j]] = 0;
		}	
	}

	sort(ans.begin(), ans.end(), comp2);

	for (auto x : ans) cout << x.S;
	cout << endl;

    return 0;
}








