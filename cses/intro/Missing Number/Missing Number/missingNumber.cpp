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
    
    long long n, holder, sum = 0;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> holder;
        sum += holder;
    }
    cout << n*(n+1)/2 - sum << "\n";
    
    return 0;
}



