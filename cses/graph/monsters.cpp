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

int N, M, sx, sy;
int grid[1001][1001];
bool v[1001][1001];
int dist[1001][1001];
int dist2[1001][1001];
int dir[1001][1001];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool ok(int i, int j, int k) {
	return i + dx[k] > 0 && i + dx[k] <= N && j + dy[k] > 0 && j + dy[k] <= M;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;
	queue<pii> bfs;
	memset(dist, 0x3f, sizeof(dist));

	rep(i,1,N) {
		rep(j,1,M) {
			char a; cin >> a;
			if (a == '.')
				grid[i][j] = 1;
			else if (a == 'A')
				sx = i, sy = j, grid[i][j] = 1;
			else if (a == 'M')
				v[i][j] = 1, dist[i][j] = 0, bfs.push(MP(i,j));
		}
	}
	
	if (sx == 1 || sx == N || sy == 1 || sy == M) {
		cout << "YES" << endl << 0 << endl;
		return 0;
	}
	
	while (bfs.size()) {
		pii cur = bfs.front(); bfs.pop();
		v[cur.F][cur.S] = 1;
		rep(i,0,3) {
			if (ok(cur.F, cur.S, i) && grid[cur.F + dx[i]][cur.S + dy[i]] == 1 && !v[cur.F+dx[i]][cur.S+dy[i]]) {
				dist[cur.F+dx[i]][cur.S+dy[i]] = min(dist[cur.F+dx[i]][cur.S+dy[i]], dist[cur.F][cur.S] + 1);
				bfs.push(MP(cur.F+dx[i], cur.S+dy[i]));
			}
		}
	}

	bfs.push(MP(sx, sy));
	dist2[sx][sy] = 1;
	
	while (bfs.size()) {
		auto cur = bfs.front(); bfs.pop();
		//cerr << "CUR: " << cur.F << ' ' << cur.S << endl;	
		rep(i,0,3) {
			if (ok(cur.F,cur.S,i) && grid[cur.F+dx[i]][cur.S+dy[i]] == 1 && !dist2[cur.F+dx[i]][cur.S+dy[i]]) {
				//cout << "WHAT " << ' ' << cur.F << ' ' << cur.S << ' ' << i << endl;
				if (dist2[cur.F][cur.S] < dist[cur.F + dx[i]][cur.S + dy[i]]) {
					//cout << "TEST: " << endl;
					dist2[cur.F+dx[i]][cur.S+dy[i]] = dist2[cur.F][cur.S]+1;
					dir[cur.F+dx[i]][cur.S+dy[i]] = i;
					bfs.push(MP(cur.F+dx[i], cur.S+dy[i]));
				}
			}
			if (ok(cur.F,cur.S,i) && dist2[cur.F+dx[i]][cur.S+dy[i]] && grid[cur.F+dx[i]][cur.S+dy[i]] == 1) {
				//cout << "WHAT " << endl;
				if (cur.F + dx[i] == 1 || cur.F + dx[i] == N || cur.S + dy[i] == 1 || cur.S + dy[i] == M) {
					cur.F += dx[i], cur.S += dy[i];
					//cout << cur.F << ' ' << cur.S  << ' ' << i << endl;

					string ans = "";
					//cerr << "START: " << sx << ' ' << sy << endl;	
					while (cur.F != sx || cur.S != sy) {
						int k = dir[cur.F][cur.S];
						if (k == 0)
							ans += "D";
						else if (k == 1)
							ans += "U";
						else if (k == 2)
							ans += "R";
						else 
							ans += "L";
						cur.F -= dx[k], cur.S -= dy[k];
						//cout << "NOW: " << cur.F << ' ' << cur.S << endl;
					}
					
					reverse(ans.begin(), ans.end());
					cout << "YES" << endl;
					cout << ans.length() << endl;
					cout << ans << endl;
					return 0;
				}
			}
		}
	}

	cout << "NO\n";

    return 0;
}
