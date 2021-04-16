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

int N, K;

int d[50000];

int le[50000];

int ri[50000]; //most in a box with at biggest as d[i]

int main() {
	setIO("diamond");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> K;
    
	rep(i,0,N) cin >> d[i];

	sort(d, d+N);
	
	int p1 = 0, p2 = N-1;
	
	ri[0] = 1;
	le[N-1] = 1;

	rep(i,1,N) {
		while (p1 < N && d[p1] + K < d[i]) p1++;
		while (p2 >= 0 && d[p2] - K > d[N-1-i]) p2--;
		ri[i] = i - p1 + 1;
		ri[i] = max(ri[i], ri[i-1]);
		le[N-1-i] = p2 - (N-1-i) + 1; 
		le[N-1-i] = max(le[N-1-i], le[N-i]);
	}
	int ans = 0;
	rep(i,0,N) {
		ans = max(le[i] + ri[i], ans);
	}

	//rep(i,0,N) cout << le[i] << ' '; cout << endl;
	//rep(i,0,N) cout << ri[i] << ' '; cout << endl;
	if (ans > N) ans = N;
	cout << ans << endl;
    return 0;
}








