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
    
    for (int i = 0; i < n; i++) {
        unsigned long long a, b;
        cin >> a >> b;
        
        if (a > b) {
            if (a % 2 == 0) {
                long long output = ((a)*(a)) - b + 1;
                cout << output << "\n";
            } else {
                long long output = ((a-1)*(a-1)) + b;
                cout << output << "\n";
            }
        } else {
            if (b % 2 == 1) {
                long long output = ((b)*(b)) - a + 1;
                cout << output << "\n";
            } else {
                long long output = ((b-1)*(b-1)) + a;
                cout << output << "\n";
            }
        }
    }
    
    return 0;
}



