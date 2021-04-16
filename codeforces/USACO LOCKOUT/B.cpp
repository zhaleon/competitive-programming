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
int n;
vi v[1001];
vi b[1001];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	int k;
	rep(i,1,n+1) {
		cin >> k;
		int a;
		rep(j,0,k) {
			cin >> a;
			b[i].PB(a);
			v[i].PB(a);
			if (i == 1) {
				v[n].PB(a);
			} else {
				v[i-1].PB(a);
			}
		}
	}
	int ans = 0;
   	rep(i,1,n+1) {
		sort(v[i], v[i]+n);
		sort(b[i], b[i]+n);
	}
	rep(j,2,n+1) {	
	rep(i,0,b[j].size()-1) {
		int l = b[j][i], h = b[j][i+1];
		int low = 0, high = v[i].size();
		int c, d;
		while (low+1 < high) {
			int mid = (low+high)/2;
			if (v[i][mid] < l) {
				low = mid;	
			} else {
				high = mid;
			}
		}
		c = high;
		low = 0, high = v[j].size();
		while (low+1 < high) {
			int mid = (low+high)/2;
			if (v[i][mid] > l) {
				high = mid;
			} else {
				low = mid;
			}
		}
		d = low;
		int tot = abs(c-d)-1;
		j--;
		int low = 0, high = v[j].size();
		int c, d;
		while (low+1 < high) {
			int mid = (low+high)/2;
			if (v[j][mid] < l) {
				low = mid;
			} else {
				high = mid;
			}
		}
		c = high;
		low = 0, high = v[i].size();
		while (low+1 < high) {
			int mid = (low+high)/2;
			if (v[j][mid] > l) {
				high = mid;
			} else {
				low = mid;
			}
		}
		d = low;
		if (tot != abs(c-d)-1) ans++;
		j++;
	}}
    rep(i,0,b[1].size()-1) {
		int l = b[1][i], h = b[1][i+1];
		int c, d;
		int low = 0, high = v[1].size();
		while (low+1 < high) {
			int mid = (low+high)/2;
			if (v[1][mid] < mid) {
				low = mid;
			} else {
				high = mid;
			}
		}
		c = high;
		low = 0, high = v[1].size();
		while(low+1 < high) {

		}
	}
	return 0;
}








