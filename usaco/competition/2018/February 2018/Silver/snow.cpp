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

int N, B;

int ans = INF;

int snow[251];

int d[251]; //boot depth and stride
int s[251];

int v[251][251]; //boot and pos

void dfs(int boot, int location) {
	v[boot][location] = 1;
	if (boot > N) return;
	if (location == N) { 
	   	ans = min(ans, boot-1);
		return;
	}
	if (d[boot] >= snow[location]) { 
		for (int i = location+1; i <= location+s[boot] && i <= N; i++) {
			if (d[boot] >= snow[i] && !v[boot][i]) dfs(boot, i);
		}
	}
	if (!v[boot+1][location]) dfs(boot+1, location);
}

int main() {
	setIO("snowboots");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> B;

	rep(i,1,N+1) cin >> snow[i];
    rep(i,1,B+1) cin >> d[i] >> s[i];

	dfs(1, 1);

	cout << ans << endl;
    return 0;
}








