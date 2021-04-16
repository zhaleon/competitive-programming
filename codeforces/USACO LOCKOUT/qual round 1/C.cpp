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
int arr[(int)1e5];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
    
	loop(i,0,n) cin >> arr[i];
	ll sum = 0;
	int last = INF;
	int maxNeg = -100000;
	loop(i,0,n) {
		if (arr[i] > 0 && arr[i] % 2 == 0) {
			sum += arr[i];
		}
		if (abs(arr[i]) % 2 == 1) {
			if (arr[i] > 0) {
				sum += arr[i];
				last = min(last, arr[i]);
			} else {
				maxNeg = max(maxNeg, arr[i]);	
			}
		}
	}
	if (sum % 2 == 0) {
		sum -= (min(last, -maxNeg));
	}	
	cout << sum << endl;

    return 0;
}








