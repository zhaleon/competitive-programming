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

int t, n;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> t;

	while(t--) {
		cin >> n;
		ll ans = 0;
		int i;
		for (i = 1; i <= n; i++){
			if (i <= (n)/2-1) {
				ans += (1 << i);
			} else if (i < (n)) {
				ans -= (1 << i);
			} else {
				ans += (1 << i);
			}
		}
		if (ans < 0) ans *= -1;
		cout << ans << '\n';
	}

    
    return 0;
}








