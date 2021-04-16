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


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin >> t;
	int n;
	while(t--) {
		cin >> n;
		int ans = 0;
		//n--;
		for (int i = 30; i >= 0; i--) {
			if (n & (1 << i)) {
				ans = i;
				break;
			}
		}
		bool on = 0;
		int shift = 0;
		cout << ans << '\n';
		n--;
		int msb;	
		for (int i = 30; i >= 0; i--) {
			if (n & (1 << i)) {
				msb = i;
				break;
			}
		}
		cout << "HI" << ' ' << msb << endl;
		loop(i,0,ans) {
			if (i == 0 && (1 << (i))) {
				cout << 0 << ' ';
				shift++;
				continue;
			}

			if (n & (1 << (i+1))) {
				cout << (1 << (shift)) << ' ';
				shift++;
			} else {
				if (i == msb) {
					cout << 0 << ' ';
					continue;
				}

				int j;
				for (j = i; !(n & (1 << j)); j++) {
					
				}
				//cout << j << "HI" << endl;
				int k = j-i;
				if (k == 1) {
					cout << (1 << shift) << ' ';
					shift++;
				}

				int x = i+1;
				for (; i < j; i++) {
					if (i == x) {
						cout << 0 << ' ';
					} else {
						cout << (1 << shift) << ' ';
						shift++;
					}
				}
			}
		}
		cout << '\n';

	}

    
    return 0;
}








