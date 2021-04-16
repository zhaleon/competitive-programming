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

int low_link[100001];
int id[100001];
bool v[100001]; //still processing
bool seen[100001];

int num_cc = 0;
int num_v = 0;

void dfs(int cur = 1) {
	static int t = 0;
	static stack<int> s;
	
	++num_v;
	v[cur] = seen[cur] = 1;
	low_link[cur] = ++t;
	id[cur] = t;

	s.push(cur);

	for (auto &edge : adj[cur]) {
		if (!seen[edge])
			dfs(edge);
		low_link[cur] = min(low_link[cur], low_link[edge]);
	}
	
	if (!s.empty()) {
		num_cc++;
		while (s.size() && low_link[s.top()] != id[s.top()]) {
			low_link[s.top()] = INF;
			s.pop();
		}
		low_link[s.top()] = INF;
		s.pop();
	}

	v[cur] = 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	rep(i,1,M) {
		int a, b;
		cin >> a >> b;
		adj[a].PB(b);
	}
    
	dfs();

	if (num_v < N || num_cc > 1) {
		cout << "NO" << endl;	
	} else {
		cout << "YES" << endl;
	}

    return 0;
}








