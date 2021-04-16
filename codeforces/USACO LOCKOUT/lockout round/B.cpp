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
int n;
string x[100];

bool comp(string a, string b) {
	if (a.length() != b.length()) return a.length() < b.length();
	return a < b;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	loop(i,0,n) cin >> x[i];
	
	sort(x, x+n, comp);

	loop(i,0,n-1) {
		if (x[i].length() == x[i+1].length()) {
			cout << "NO" << endl;
			return 0;
		} else {
			bool found = 0;
			for (int j = 0; j < x[i+1].length()-x[i].length(); j++) {
				if (x[i+1].substr(j,x[i].length()) == x[i]) {
					found = 1;
					break;
				}
			}
			if (!found) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;

    return 0;
}








