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

int N;
int arr[200001];
vi adj[200001];

int tin[200001];
int tout[200001];

vi times[200001];

void dfs(int cur, int p = -1) {
	static int t = 0;

	tin[cur] = ++t;
	times[arr[cur]].PB(t);	

	for (auto &e : adj[cur]) 
		if (e != p)
			dfs(e, cur);

	tout[cur] = t;
}

void compress(int a[]) {
	map<int, int> m;
	rep(i,1,N) 
		m[a[i]];

	int ind = 0;
	for (auto &p : m) p.S = ++ind;

	rep(i,1,N)
		a[i] = m[a[i]];
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	rep(i,1,N) cin >> arr[i];
	compress(arr);

	rep(i,1,N-1) {
		int a, b;
		cin >> a >> b;
		adj[a].PB(b);
		adj[b].PB(a);
	}



    return 0;
}








