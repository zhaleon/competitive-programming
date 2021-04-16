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

const int mod = 1e9+7;

int N;

pii p[100000];
int active = 0;

int t[100001];

int main() {
	setIO("help");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	rep(i,0,N) cin >> p[i].F >> p[i].S;

	sort(p, p+N);

	t[0] = 1;
	rep(i,1,N+1) t[i] = (2*t[i-1])%mod;

	priority_queue<int, vi, greater<int>> q;

	int ans = 0;
	rep(i,0,N) {
		if (q.size() && q.top() < p[i].F) {
			while (q.size() && q.top() < p[i].F) {
				active--;
				q.pop();
			}
		} 
		active++;
		q.push(p[i].S);
		ans += t[N-active];
		ans %= mod;
	}

	cout << ans << endl;
    return 0;
}








