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
#include <stack>
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
int arr[100002];

int fir[100002];
int las[100002];

int main() {
	setIO("art2");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
	
	rep(i,1,N+1) cin >> arr[i];
	
	rep(i,1,N+1) {
		if (arr[i] == 0) continue;
		if (!fir[arr[i]]) fir[arr[i]] = i;
		las[arr[i]] = i;
	}
	
	stack<int> s;
	
	int ans = 0;
	
	rep(i,1,N+1) {
		if (!arr[i]) continue;
		if (i == fir[arr[i]]) {
			s.push(arr[i]);
			ans = max(ans, (int)s.size());
		}
		
		if (s.top() != arr[i]) { //multiple disjoint intervals bad
			cout << -1 << endl;
			return 0;
		}
		
		if (i == las[arr[i]]) {
			s.pop();
		}
	}
	
	cout << ans << endl;

    return 0;
}