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
#include <chrono>
#include <time.h>
#include <stdio.h>
#include <cstdlib>


using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
typedef vector<int> vi;

#define INF 1000000000
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define loop(i,a,b) for (int i = a; i < b; i++)




int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n;
    cin >> n;
    
    ll dp[10001];
    dp[1] = 0;
    dp[2] = 6;
    dp[3] = 28;
    for (ll i = 4; i <= n; i++) {
        dp[i] = dp[i-1] + (long long)3 * (i*i-3) + (long long)4*(i*i-4) + (long long)(2*i-8)*(i*i-5) + 2 - (2*i-1)*(2*i-2)/2;
    }
    for (int i = 1; i <= n; i++) {
        cout << dp[i] << "\n";
    }
    
    return 0;
}



