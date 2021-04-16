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

int t, n;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n;
		if (n % 2 == 1) {
			if (n == 1) cout << "FastestFinger\n";
			else cout << "Ashishgup\n";
		} else {
			if (n == 2) {
				cout << "Ashishgup\n";
				continue;
			}
			if (n % 2 == 0 && n % 4 > 0) {
				bool prime = 1;
				n/=2;
				for (int j = 3; j <= (int)sqrt(n); j+=2) {
					if (n % j == 0) {
						prime = 0;
						break;
					}
				}
				if (prime) {
					cout << "FastestFinger\n";
				} else {
					cout << "Ashishgup\n";
				}
				continue;
			}
			if (__builtin_popcount(n) > 1) cout << "Ashishgup\n";
			else cout << "FastestFinger\n";
		}
	}
    
    return 0;
}








