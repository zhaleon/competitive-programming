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
int K;
int n[100];

bool works(int a, int b) {
	if (a == 0 || b == 0) return true;
	for (int x = 0; x < 3; x++ ) {
		if (a % 10 != 0 && b % 10 != 0) {
			return false;	
		}
		a/=10;
		b/=10;
	}
	return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> K;
	int zero = 0;
	loop(i,0,K) {
		cin >> n[i];
		if (n[i] == 0) zero = i;
	}
	if (zero) {
		loop(a,0,K) {
			if (a == zero) continue;
			loop(b,a+1,K) {
				if (b == 0) continue;
				loop(c,b+1,K) {
					if (c == 0) continue;
					if (works(n[a], n[b]) && works(n[b], n[c]) && works(n[a], n[c])) {
						cout << 4 << endl << 0 << ' ' << n[a] << ' ' << n[b] << ' ' << n[c] << endl;
						return 0;
					}				
				}
			}
		}

		loop(a,0,K) {
			if (a == zero) continue;
			loop(b,a+1,K) {
				if (b == zero) continue;
				if (works(n[a], n[b]) {
					cout << 3 << endl << 0 << ' ' << n[a] << ' ' << n[b] << endl;
					return 0;
				}
			}
		}
		loop(a,0,K) {
			if (a==zero) continue;
			if (n[a] > 0) {
				cout << 2 << endl << 0 << n[a] << endl;
			}
		}
	} else {
		loop(a,0,K) {
			loop(b,a+1,K) {
				loop(c,b+1,K) {
					if (works(n[a], n[b]) && works(n[b], n[c]) && works(n[a], n[c])) {
						cout << 4 << endl << 0 << ' ' << n[a] << ' ' << n[b] << ' ' << n[c] << endl;
						return 0;
					}				
				}
			}
		}

		loop(a,0,K) {
			loop(b,a+1,K) {
				if (works(n[a], n[b]) {
					cout << 3 << endl << 0 << ' ' << n[a] << ' ' << n[b] << endl;
					return 0;
				}
			}
		}
		loop(a,0,K) {
			if (n[a] > 0) {
				cout << 2 << endl << 0 << n[a] << endl;
			}
		}

	}


    return 0;
}








