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
#define loop(i,a,b) for (int i = a; i < b; i++)

void setIO(string name) {
	freopen((name+".in").c_str(), "r", stdin); 
	freopen((name+".out").c_str(), "w", stdout);
}
const int MOD = 998244353;

ll dp[3001][3001];
int counter = 0;
int A,B,C,D;
ll ans(int x, int y) {
	if (dp[x][y]) return dp[x][y];
	if (x < A || y < B) return dp[x][y] = 0;
	if (x == 1 || y == 1 || (x == A && y == B)) return dp[x][y] = 1;
	ll a = (ans(x-1,y)*y) % MOD;
	ll b = (ans(x,y-1)*x) % MOD;
	ll c = ((x-1)*(y-1)*ans(x-1,y-1)) % MOD;
	return dp[x][y] = ((a + b - c + MOD) % MOD);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> A >> B >> C >> D;

  	cout << ans(C, D) << endl;
	return 0;
}








