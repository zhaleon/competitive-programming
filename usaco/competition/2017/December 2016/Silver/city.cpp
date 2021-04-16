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

map<string, int> num; 
vector<string> places;

int main() {
	setIO("citystate");
    ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> N;
    
	string a, b;

	rep(i,0,N) {
		cin >> a >> b;
		string c = a.substr(0,2) + b;
		num[c]++;
		if (a.substr(0,2) == b) num[c]--;
		places.PB(c);
	}

	int ans = 0;

	for (string p : places) {
		ans += num[p.substr(2,2) + p.substr(0,2)];
	}

	cout << ans/2 << endl;

    return 0;
}








