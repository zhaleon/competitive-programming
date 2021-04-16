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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
   	int n;
	cin >> n;
	string s;
	cin >> s;
	int l = 0, r = 0, u = 0, d = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'L') l++;
		if (s[i] == 'R') r++;
		if (s[i] == 'U') u++;
		if (s[i] == 'D') d++;
	}

	cout << (s.length() - abs(l - r) - abs(d - u)) << endl;
    return 0;
}








