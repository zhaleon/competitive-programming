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

bool v[100001];
bool active[100001];

stack<int> s;

bool dfs(int cur = 1) {
	v[cur] = 1;
	active[cur] = 1;
	s.push(cur);

	for (auto &edge : adj[cur]) {
		if (!v[edge]) 
			if (dfs(edge))
				return true;
		if (active[edge]) {
			s.push(edge);
			return true;
		}	
	}

	s.pop();
	active[cur] = 0;
	return 0;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	rep(i,1,M) {
		int a, b; 
		cin >> a >> b;
		adj[a].PB(b);
	}
   
	rep(i,1,N) {
		if (!v[i]) {
			if (dfs(i)) {
				vi cycle;
				int f = s.top(); 
				while (s.size()) {
					cycle.PB(s.top()); s.pop();
					if (cycle.back() == f && cycle.size() > 1)
						break;
					
				}
				cout << cycle.size() << endl;
				reverse(cycle.begin(), cycle.end());
				for (auto e : cycle) cout << e << ' ';
				return 0;
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;

	return 0;
}








