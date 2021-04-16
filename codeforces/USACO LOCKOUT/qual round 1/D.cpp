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
ll a[(int)5e5];
ll p[(int)5e5];
int x[(int) 5e5];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;

	ll sum = 0;
	loop(i,0,n) {
		cin >> a[i];
		sum += a[i];
	}
	ll target;
   	if (sum % 3 != 0) {
		cout << 0 << endl;
		return 0;
	} else {
		target = sum/3;
	}
	p[0] = a[0];
	int num = 0;
	if (a[0] == target) {
		++num;
		x[0] = num;
	}	
	loop(i,1,n) {
		p[i] = p[i-1] + a[i];
		if (p[i] == target) {
			num++;
			x[i] = num;
		} else {
			x[i] = num;
		}
	}
	ll ans = 0;
	loop(i,1,n-1) {
		if (p[i] == 2*target) {
			ans += x[i-1];
		}
	}
	cout << ans << endl;
    return 0;
}








