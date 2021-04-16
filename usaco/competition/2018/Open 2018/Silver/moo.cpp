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

int N;
int board[255][255];

int group[255][255];

int ans1 = 0, ans2 = 0, size = 0;

map<int, int> m; //group -> num on board
map<int, int> s; //group -> size
map<pii, pair<map<int, bool>, int> > g; //pair -> size of region && if a specific pair has been considered already
map<pii, map<int, bool> > u; //check pairs already considered

//answer part 1
void flood(int a, int b, int groupNum) {
	group[a][b] = groupNum;
	size++;
	if (!group[a][b+1] && board[a][b] == board[a][b+1]) flood(a, b+1, groupNum);
	if (!group[a][b-1] && board[a][b] == board[a][b-1]) flood(a, b-1, groupNum);
	if (!group[a+1][b] && board[a][b] == board[a+1][b]) flood(a+1, b, groupNum);
	if (!group[a-1][b] && board[a][b] == board[a-1][b]) flood(a-1, b, groupNum);
}

void checkPairs() {
	rep(i,1,N+1) {
		rep(j,1,N+1) {
			int cur = board[i][j];
			
			if (j < N) {
				pii p;
				if (cur > board[i][j+1]) p = MP(cur, board[i][j+1]);	
				else p = MP(board[i][j+1], cur);		
				if (!g[p].F[group[i][j]]) {
					g[p].S += s[group[i][j]];
					g[p].F[group[i][j]] = 1;
				}
				if (!g[p].F[group[i][j+1]]) {
					g[p].S += s[group[i][j+1]];
					g[p].F[group[i][j+1]] = 1;
				}
			}
			if (i < N) {
				pii p;
				if (cur > board[i+1][j]) p = MP(cur, board[i+1][j]);
				else p = MP(board[i+1][j], cur);			
				if (!g[p].F[group[i][j]]) {
					g[p].S += s[group[i][j]];
					g[p].F[group[i][j]] = 1;
				}
				if (!g[p].F[group[i+1][j]]) {
					g[p].S += s[group[i+1][j]];
					g[p].F[group[i+1][j]] = 1;
				}
			}
			
		}
	}
}

int main() {
	setIO("multimoo");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	
	rep(i,1,N+1) {
		rep (j,1,N+1) {
			cin >> board[i][j];
			board[i][j]++;
		}
	}
	
   	int groupNo = 1;
	rep(i,1,N+1) {
		rep(j,1,N+1) {
			if (!group[i][j]) {
				flood(i, j, groupNo);
			
				m[groupNo] = board[i][j];
				s[groupNo] = size;	
				
				ans1 = max(ans1, size);
				size = 0;
				groupNo++;
			}
		}
	}
	checkPairs();
	
	for (auto x : g) ans2 = max(ans2, x.S.S);
	//for (auto x : g) cout << x.F.F << ' ' << x.F.S << ' ' << x.S.S <<  endl;
	//cout << g.size() << endl;
	cout << ans1 << endl << ans2 << endl;
   
	return 0;
}








