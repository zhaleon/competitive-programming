#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;

#define INF 1000000000
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define all(x, ...) next(begin(x), ##__VA_ARGS__), end(x)
#define rep(i,a,b) for (int i = a; i <= b; ++i)

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    string N;
    cin >> N;
    
    int ans = N.back() - '0';
    int nums = N.back() - '0';
    int low = nums;
    int hi = nums;
    
    for (int i = N.length() - 2; i >= 0; --i) {
        int cur_digit = N[i] - '0';
    }
    
    return 0;
}








