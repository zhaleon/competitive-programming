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
    
    for (ll i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        int dif = abs(a - b);
        if (dif > min(a, b) || dif*2 > max(a, b)) {
            cout << "NO\n";
        } else if (a == b && (a > 2 || a == 0) && a % 3 == 0) {
            cout << "YES" << "\n";
        } else if (a == 0 || b == 0) {
            cout << "NO\n";
        } else if (a > b) {
            int difference = (a-b);
            a -= difference*2;
            b -= difference;
            if ((a+b) % 3 == 0) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else if (b > a) {
            int difference = (b-a);
            b -= difference*2;
            a -= difference;
            if ((a+b) % 3 == 0) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}



