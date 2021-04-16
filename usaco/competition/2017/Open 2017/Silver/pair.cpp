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
vpi milk;

int main() {
	setIO("pairup");
    ios::sync_with_stdio(0); cin.tie(0);

	cin >> N;

	int a, b; 

	rep(i,0,N) {
		cin >> a >> b;
		milk.PB(MP(b,a));
	}

	sort(milk.begin(), milk.end());

	int left = 0, right = milk.size()-1;

	int ans = 0; 
	while (left + 1 < right) {
		if (milk[left].F + milk[right].F > ans) ans = milk[left].F + milk[right].F;

		if (milk[left].S < milk[right].S) {
			milk[right].S -= milk[left].S;
			left++;
		} else if (milk[left].S > milk[right].S) {
			milk[left].S -= milk[right].S;
			right--;
		} else {
			left++;
			right--;
		}
	}
    
	if (milk[left].S == milk[right].S) {
		ans = max(ans, milk[left].F + milk[right].F);
	} else if (milk[left].S < milk[right].S) {
		ans = max(ans, milk[right].F + max(milk[left].F, milk[right].F));
	} else {
		ans = max(ans, milk[left].F + max(milk[left].F, milk[right].F));
	}
	
	cout << ans << endl;

    return 0;
}








