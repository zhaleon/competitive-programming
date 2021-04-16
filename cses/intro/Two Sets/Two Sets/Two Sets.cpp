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
    
    ll target = n*(n+1);
    vi first;
    int used[1000001];
    if (target % 4 != 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        if (target/4 % n == 0) {
            // need n+1/4 groupings of n
            ll amt = (n+1)/4;
            first.PB((int)n);
            for (int i = 1; i < amt; i++) {
                first.PB(i);
                first.PB((int)n-i);
            }
        } else {
            ll amt = (n/4);
            for (int i = 1; i <= amt; i++) {
                first.PB(i);
                first.PB((int)n+1-i);
            }
        }
    }
    
    sort(first.begin(), first.end());
    cout << first.size() << "\n";
    
    for (int i = 0; i < first.size(); i++) {
        used[first[i]] = 1;
        cout << first[i] << ' ';
    } cout << "\n";
    
    cout << (n - first.size()) << "\n";
    
    for (int i = 1; i <= n; i++) {
        if (used[i] != 1) {
            cout << i << " ";
        }
    } cout << "\n";
    
    return 0;
}



