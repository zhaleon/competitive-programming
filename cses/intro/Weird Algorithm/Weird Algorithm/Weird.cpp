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
    
    long long x;
    cin >> x;
    if (x == 1) cout << "1\n";
    while (x != 1) {
        cout << x << " ";
        if (x % 2 == 0) {
            x/=2;
        } else {
            x *= 3;
            x++;
        }
        if (x == 1) {
            cout << "1\n";
        }
    }
    
    return 0;
}



