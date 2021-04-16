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

int N;
int ranks[100001];
int idx[100001];

vi adj[100001];

int bit[200001];
int fir[200001];
int las[200001];

void upd(int pos) {
	while (pos < 2*N+1) {
		bit[pos]++;
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

int sum(int i, int j) {
	return sum(j)-sum(i-1);
}

int t = 1;
void dfs(int cur, int p = -1) {
	fir[cur] = t++;
	for (auto edge : adj[cur]) {
		if (edge != p) dfs(edge, cur);
	}
	las[cur] = t++;
}

bool comp(int a, int b) {
	return ranks[a] > ranks[b];
}

int main() {
	setIO("promote");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	rep(i,1,N+1) {
		cin >> ranks[i];
		idx[i] = i;
	}
	
	rep(i,2,N+1) {
		int a; cin >> a;
		adj[i].PB(a);
		adj[a].PB(i);
	}
	
	dfs(1);
	
	sort(idx+1, idx+1+N, comp);

	vi ans(N+1);

	rep(i,1,N+1) {
		ans[idx[i]] = sum(fir[idx[i]], las[idx[i]]);
		upd(fir[idx[i]]);
	}
	
	rep(i,1,N+1) cout << ans[i] << endl;

    return 0;
}