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

ll N, L, A, B;

pair<ll, ll> stops[100000];
ll best[100001];

int main() {
	setIO("reststops");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> L >> N >> A >> B;
    
	rep(i,0,N) {
		cin >> stops[i].F >> stops[i].S;
	}

	sort(stops, stops+N);

	best[N-1] = N-1;
	for (int i = N-2; i >= 0; i--) {
		if (stops[i].S > stops[best[i+1]].S) best[i] = i;
		else best[i] = best[i+1];
	}

	ll ans = 0;
	ll pos = 0;
	rep(i,0,N) {
		ll tasty = best[i];
		ll b = (stops[tasty].F-pos)*B; 
		ll f = (stops[tasty].F-pos)*A;
		ans += abs(f-b)*stops[tasty].S;
		i = tasty;
		pos = stops[i].F;
	}
	cout << ans << endl;
    return 0;
}








