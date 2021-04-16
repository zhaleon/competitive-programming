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
int a[2005];
int n;

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int v[2005];
		memset(v, 0, sizeof(v));
		cin >> n;
		int counter = 0;
		loop(i,1,2*n+1) cin >> a[i];
		for (int i = 2*n; i > 0 && counter < n-1; i--) {
			if (v[i]) continue;
			string cur = "";
			if (a[i] % 2 == 0) {
				cur += to_string(i) + " ";
				bool found = 0;
				for (int j = i-1; j > 1; j--) {
					if (a[j] % 2 == 0) {
						cur += to_string(j) + "\n";
						found = 1;
						v[j] = 1;
						break;
					}
				}
				if (found) {
					cout << cur;
					counter++;
				}
			} else {
				cur += to_string(i) + " ";
				bool found = 0;
				for (int j = i-1; j > 1; j--) {
					if (a[j] % 2 == 1) {
						found = 1;
						cur += to_string(j) + "\n";
						v[j] = 1;
						break;
					}
				}
				if (found) { 
					cout << cur;
					counter++;
				}
			}
		}	
	}
    
    return 0;
}








