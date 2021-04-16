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
int hw[100001];

int worst[100001];
int sum[100001];

int main() {
	setIO("homework");
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;

	rep(i,1,N+1) {
		cin >> hw[i];
	}

	worst[N] = sum[N] = hw[N];

	for (int i = N-1; i > 0; i--) {
		worst[i] = min(hw[i], worst[i+1]);
		sum[i] = hw[i] + sum[i+1];
	}

	vector<pair<double, int> > ans;

	double best = 0;
	for (int k = 1; k < N-1; k++) {
		double avg = (double)(sum[k+1]-worst[k+1])/(N-k-1);
		best = max(avg, best);
		ans.PB(MP(avg, k));	
	}

	double eps = 1e-5;

	rep(i,0,ans.size()) {
		if (best - ans[i].F < eps) {
			cout << ans[i].S << endl;
		}
	}

    return 0;
}








