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

int n, x;
int price[1001];
int pages[1001];
int dp[100001];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> n >> x;

	loop(i,1,n+1) {
		cin >> price[i];
	}
	loop(i,1,n+1) {
		cin >> pages[i];
	}	
	
   	for (int i = 1; i <= N; i++) {
		for (int j = x; j >= price[i]; j--) {
			dp[j] = max(dp[j], dp[j-price[i]] + pages[i]);
		}

	}
	cout << dp[x] << endl;
    return 0;
}








