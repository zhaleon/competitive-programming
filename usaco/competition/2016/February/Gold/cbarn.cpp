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
ll c[100000];

auto comp = [](int a, int b) {return a > b;};

int main() {
	setIO("cbarn");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	ll curMost = 0;
	rep(i,0,N) {
		cin >> c[i];
		curMost = max((ll)0, curMost - 1 + c[i]);
	} //find carry over, will push continue until the ideal starting point, just after we run out on second pass	

	int idx = 0;
	rep(i,0,N) {
		if (!curMost) {
			rotate(c, c+i, c+N);
			break;
		}
		curMost = max(0ll, curMost + c[i] - 1);
	}
	
	priority_queue<ll, vector<ll>, greater<ll>> q;		

	ll ans = 0;
	rep(i,0,N) {
		rep(j,0,c[i]) q.push((ll)i);
		ll a = q.top(); q.pop();
		ans += (i-a)*(i-a); 
		//curMost = max(0ll, curMost - 1 + c[i]);	
	}
	cout << ans << endl;

    return 0;
}








