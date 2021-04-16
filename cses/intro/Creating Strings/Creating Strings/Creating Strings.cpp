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

vector<int> arr;
int distinct = 0;
map<char, int> used;
vector<int> usedLetters;

ll factorial(int n) {
    if (n == 1) return 1;
    return factorial(n-1)*n;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string n;
    cin >> n;
    
    for (int i = 0; i < n.length(); i++) {
        arr.PB((int)(n[i]));
        if (used[n[i]] == 0) {
            usedLetters.push_back(n[i]);
        }
        used[n[i]]++;
    }
    
    ll answer = factorial(n.length());
    for (int i = 0; i < usedLetters.size(); i++) {
        answer/=factorial(used[usedLetters[i]]);
    }
    
    sort(arr.begin(), arr.end());
    cout << answer << "\n";
    do {
        for (int i = 0; i < n.length(); i++) {
            cout << (char)arr[i];
        }
        cout << "\n";
    } while (next_permutation(arr.begin(), arr.end()));

    
    return 0;
}



