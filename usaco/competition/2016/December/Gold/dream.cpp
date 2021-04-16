#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <fstream>
#include <assert.h>
#include <string>
#include <cstring>
#include <unordered_map>
#include <bitset>
#include <climits>
#include <time.h>
#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <deque>
#include <cmath>
#include <set>
#include <unordered_set>

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

int grid[1000][1000];

bool v[1000][1000][4][2];

auto comp = [](pair<pii, pii> a, pair<pii, pii> b) {return a.S.S > b.S.S;};

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool good(int a, int b) { return a >= 0 && a < N && b >= 0 && b < M; }

int main() {
	setIO("dream");
    ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N >> M;

	rep(i,0,N) {
		rep(j,0,M) {
			cin >> grid[i][j];
		}
	}
    
	priority_queue<pair<pii, pii>, vector<pair<pii, pii> >, decltype(comp)> pq(comp);
	pq.push(MP(MP(0,0), MP(0, 0)));
	rep(i,0,4) v[0][0][i][0] = 1;

	int ans = INF;

	while (!pq.empty()) {
		auto temp = pq.top(); pq.pop();
		pii cur = temp.F;
		bool smell = temp.S.F;
		int dist = temp.S.S;

		if (cur.F == N-1 && cur.S == M-1) ans = min(ans, dist);
		rep(i,0,4) {
			int a = cur.F + dx[i], b = cur.S + dy[i];
			if (!good(a,b)) continue;
			else if (!v[a][b][i][smell]) {
				if (grid[a][b] == 1) {
					pq.push(MP( MP(a,b), MP(smell, dist+1) ));
					v[a][b][i][smell] = 1;
				} else if (grid[a][b] == 2) {
					pq.push(MP( MP(a,b), MP(1, dist+1) ));	
					v[a][b][i][smell] = 1;
				} else if (grid[a][b] == 3 && smell) {
					pq.push(MP( MP(a,b), MP(1, dist+1) ));
					v[a][b][i][smell] = 1;
				} else if (grid[a][b] == 4) {
					int c = 0;
					while (good(a,b) && grid[a][b] == 4) {
						v[a][b][i][smell] = 1;
						a += dx[i]; b += dy[i];
						c++;
					}
					//a += dx[i]; b += dy[i];
					if (!good(a,b) || grid[a][b] == 0) {
						v[a-dx[i]][b-dy[i]][i][smell] = 1;
						pq.push(MP( MP(a-dx[i], b-dy[i]), MP(0, dist+c) ));
					} else {
						if (grid[a][b] == 3) {
							v[a-dx[i]][b-dy[i]][i][smell] = 1;
							pq.push(MP( MP(a-dx[i], b-dy[i]), MP(0, dist+c) ));	
						} else if (grid[a][b] == 2) {
							v[a][b][i][smell] = 1;
							pq.push(MP( MP(a,b), MP(1, dist+c+1) ));
						} else if (grid[a][b] == 1) {
							v[a][b][i][smell] = 1;
							pq.push(MP( MP(a,b), MP(0, dist+c+1) ));
						}
					}
				}
			}

		}
	}

	cout << ((ans == INF) ? -1 : ans) << endl;
	
    return 0;
}








