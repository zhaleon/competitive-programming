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

int num[100001];
int bit[100001];

int fir[50001];

void upd(int pos, int delta) {
	while (pos < 2*N+1) {
		bit[pos] += delta;
		pos += pos & -pos;
	}
}

int sums(int i) {
	int res = 0;
	while (i > 0) {
		res += bit[i];
		i -= i & -i;
	}
	return res;
}

int sum(int i, int j) {
	return sums(j) - sums(i-1);
}

int main() {
	setIO("circlecross");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	
	rep(i,1,2*N+1) cin >> num[i];
	
	int ans = 0;
	
	rep(i,1,2*N+1) {
		if (!fir[num[i]]) {
			fir[num[i]] = i;
			upd(fir[num[i]], 1);
		} else {
			upd(fir[num[i]], -1);
			ans += sum(fir[num[i]], i);
		}
	}

	cout << ans << endl;

    return 0;
}