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
int id[50000];

int pref[50000];

int f[7] = {-1, -1, -1, -1, -1, -1, -1};
int s[7] = {-1, -1, -1, -1, -1, -1, -1};

int main() {
	setIO("div7");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	rep(i,0,N) cin >> id[i];

	pref[0] = id[0] % 7;

	rep(i,1,N) pref[i] = (id[i] + pref[i-1]) % 7;
	//rep(i,0,N) cout << pref[i] << ' '; cout << endl;
    rep(i,0,N) {
		if (f[pref[i]] < 0) f[pref[i]] = i;
		else s[pref[i]] = i;
	}
	//rep(i,0,7) cout << f[i] << ' '; cout << endl;
	//rep(i,0,7) cout << s[i] << ' '; cout << endl;
	int ans = 0;
	rep(i,0,7) ans = max(ans, s[i]-f[i]);

	cout << ans << endl;

    return 0;
}








