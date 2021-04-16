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
int after[100001];
int numFeeders[100001];

int main() {
	setIO("shuffle");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;
    rep(i,1,N+1) {
		cin >> after[i];
		numFeeders[after[i]]++;
	}
	
	queue<int> q;

	rep(i,1,N+1) {
		if (!numFeeders[i]) q.push(i);
	}

	int good = N;
	good -= q.size();

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		numFeeders[after[cur]]--;
		if (!numFeeders[after[cur]]) {
			q.push(after[cur]);
			good--;
		}
	}
	cout << good << endl;
    return 0;
}








