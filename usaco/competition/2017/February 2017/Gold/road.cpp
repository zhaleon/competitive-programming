#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int> > vii;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for (int i = a; i < b; i++)

void setIO(string name) {
	freopen((name+".in").c_str(), "r", stdin); 
	freopen((name+".out").c_str(), "w", stdout);
}

ll INF = (1ll << 50);

ll N, T;

ll farm[100][100];
ll dist[100][100][3];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool good(int x, int y) {
	//if (!(x >= 0 && x < N && y >= 0 && y < N)) cout << "WHAT " << x << ' ' << y << endl;
	return x >= 0 && x < N && y >= 0 && y < N;
}

auto comp = [](pair<pii, int> a, pair<pii, int> b) {return dist[a.F.F][a.F.S][a.S % 3] > dist[b.F.F][b.F.S][b.S % 3];};

int main() {
	setIO("visitfj");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> T;
	
	rep(i,0,N) {
		rep(j,0,N) {
			cin >> farm[i][j];
		}
	}

	memset(dist, 0x3f, sizeof(dist));
		
	priority_queue<pair<pii, int>, vector<pair<pii, int>>, decltype(comp)> pq(comp);

	pq.push(MP(MP(0,0), 0));
	
	dist[0][0][0] = 0;

	while (!pq.empty()) {
		pii cur = pq.top().F;
		int m = pq.top().S;
		pq.pop();
		
		
		if (cur.F == N-1 && cur.S == N-1) {
			cout << dist[cur.F][cur.S][m%3] << endl;
			return 0;
		}
	
		rep(i,0,4) {
			int x = cur.F + dx[i], y = cur.S + dy[i];
			int add = ((m+1)%3 == 0) ? farm[x][y] : 0;
			if (good(x, y) && dist[x][y][(m+1)%3] > dist[cur.F][cur.S][m%3] + T + add) { 
				
				pq.push(MP(MP(x,y), m+1));
				dist[x][y][(m+1)%3] = min(dist[cur.F][cur.S][m%3] + T + add, dist[x][y][(m+1)%3]);
			}
		}
	}
	
	cout << min({dist[N-1][N-1][0], dist[N-1][N-1][1], dist[N-1][N-1][2]}) << endl;
	

    return 0;
}