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

void search(int cur) {
	v[cur] = 1;
	for (auto &edge : adj[cur]) 
		if (!v[edge])
			search(edge);
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
   
	vi comp;

	rep(i,1,N) {
		if (!v[i]) {
			search(i);
			comp.PB(i);
		}
	}
	
	cout << max(0, (int)comp.size()-1) << endl;

	rep(i,1,(int)comp.size()-1)
		cout << comp[i] << ' ' << comp[i-1] << endl;

	return 0;
}








