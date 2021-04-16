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

ll N, M;

ll f[100001];
ll s[100001];

ll small[100001][20];

ll query(int l, int r) {
	int p = (int)log2(r-l);
	return max(small[l][p], small[r-(1<<p)][p]);
}

int main() {
    setIO("hayfeast");
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> N >> M;

	rep(i,0,N) cin >> f[i] >> s[i]; 
	
	rep(i,0,N) small[i][0] = s[i];

	rep(i,1,18) {
		int cur = 1 << (i-1);
		for (int j = 0; j + cur < N; j++) {
			small[j][i] = max(small[j][i-1], small[j+cur][i-1]);
		}
	}
	int left = 0;
    ll sum = 0, best = (1ll << 62), cur = 0;
	
	rep(i,0,N) {
		sum += f[i];
		cur = query(left, i+1);
		while (left < i && sum - f[left] >= M) {
			sum -= f[left];
			left++;
			best = min(best, query(left, i+1));
		}

		if (sum >=  M) best = min(cur, best);
	}

	cout << best << endl;

    return 0;
}








