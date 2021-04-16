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

ll hair[100001];
ll bit[100002];

ll invs[100002];

void upd(int pos) {
	while (pos < N+2) {
		bit[pos]++;
		pos += pos & -pos;
	}
}

ll sum(int i) {
	ll res = 0;
	while (i > 0) {
		res += bit[i];
		i -= i & -i;
	}
	return res;
}

ll sum(int i, int j) {return sum(j)-sum(i-1);}

int main() {
	setIO("haircut");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	
	ll inversions = 0;
	
	rep(i,1,N+1) {
		cin >> hair[i];
		hair[i]++;
		upd(hair[i]);
		inversions += sum(hair[i]+1, N+1);
		invs[hair[i]] += sum(hair[i]+1, N+1);
	}

	vector<ll> ans;

	for (int i = N; i > 0; i--) {
		inversions -= invs[i];
		ans.PB(inversions);
	}
	
	
	reverse(ans.begin(), ans.end());
	
	rep(i,0,N) cout << ans[i] << '\n';
	
	
    return 0;
}