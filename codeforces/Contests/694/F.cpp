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

int T, N, M;

vi adj[300001];
bool used[300001];
bool red[300001];
bool v[300001];
int num_v = 0;

void dfs(int cur = 1) {
	++num_v;
	v[cur] = 1;
	for (auto &edge : adj[cur])
		if (!v[edge])	
			dfs(edge);
}

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> T;
	while(T--) {
		cin >> N >> M;
		rep(i,1,M) {
			int a, b;
			cin >> a >> b;
			adj[a].PB(b);
			adj[b].PB(a);
		}

		mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
		uniform_int_distribution<int> start(1, N);
	
		dfs();

		if (num_v != N) {
			cout << "NO\n";
		} else {
			cout << "YES\n";

			int num_used = 0, num_edges = 0;
			vi ans;
			vi perm;
			rep(i,0,N-1) perm.PB(i+1);

			while (num_used != N && num_edges != N-1) {
				num_used = num_edges = 0;
				rep(i,1,N) used[i] = red[i] = 0;
				shuffle(perm.begin(), perm.end(), rng);
				ans.clear();
				
				rep(j,0,N-1) {
					int i = perm[j];
					if (!used[i]) {
						used[i] = 1;
						++num_used;

						ans.PB(i);
						
						for (auto &edge : adj[i]) 
							num_used += !used[edge], num_edges += !used[edge], used[edge] = 1;
					}
				}
			}

			cout << ans.size() << '\n';
			rep(i,0,int(ans.size())-1) cout << ans[i] << ' '; cout << '\n'; 
		}

		rep(i,1,N) used[i] = red[i] = v[i] = 0;
		rep(i,1,N) adj[i].clear();
		num_v = 0;
	}
    
    return 0;
}








