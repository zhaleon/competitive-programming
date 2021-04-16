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
int team[100001];

bool possible = 1;

void search(int cur = 1, int dist = 0) {
	if (dist & 1) team[cur] = 1;
	else team[cur] = 2;

	for (auto &edge : adj[cur]) {
		if (!team[edge])
			search(edge, dist+1);
		else
			possible = min(possible, team[edge] != team[cur]);
	}
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	rep(i,1,M) {
		int a, b;
		cin >> a >> b;
		adj[a].PB(b);
		adj[b].PB(a);
	}

	rep(i,1,N)
		if (!team[i])
			search(i);


	if (possible)
		rep(i,1,N) cout << team[i] << ' ';
	else
		cout << "IMPOSSIBLE\n";
    return 0;
}








