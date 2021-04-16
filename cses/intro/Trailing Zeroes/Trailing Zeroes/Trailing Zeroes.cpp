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
#include <math.h>


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
    
    int numTwo = 0, numFive = 0;
    for (int i = 1; i < 32; i++) {
        numTwo += (int)(n/(int)pow(2, i));
    }
    for (int i = 1; i < 32; i++) {
        int test = pow(5, i);
        if (test < 0) break;
        numFive += int(n/test);
    }
    
    cout << min(numFive, numTwo) << "\n";
    return 0;
}



