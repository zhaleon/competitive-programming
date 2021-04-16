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
#define loop(i,a,b) for(int i = a; i < b; i++)


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string n;
    cin >> n;
    int best = 0, currentSum = 1;
    char currentChar = n[0];
    for (int i = 1; i < n.length(); i++) {
        if (n[i] == currentChar) {
            currentSum++;
        } else {
            currentChar = n[i];
            best = max(best, currentSum);
            currentSum = 1;
        }
    }
    best = max(best, currentSum);
    cout << best << "\n";
    
    return 0;
}



