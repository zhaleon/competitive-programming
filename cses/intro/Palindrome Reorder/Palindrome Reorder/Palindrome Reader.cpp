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
    
    string input;
    cin >> input;
    
    unordered_map<char, int> used;
    int letters[26];
    memset(letters, 0, sizeof(letters));
    for (int i = 0; i < input.length(); i++) {
        letters[(int)(input[i])-65]++;
    }
    
    int badCount = (input.length() % 2 == 0) ? 1 : 0;
    int middleLetters = -1;
    for (int i = 0; i < 26; i++) {
        if (letters[i] % 2 == 1) {
            middleLetters = i;
            badCount++;
        }
        if (badCount > 1) {
            cout << "NO SOLUTION\n";
            return 0;
        }
    }
    
    for (int i = 0; i < 26; i++) {
        if (i == middleLetters) continue;
        if (letters[i] > 0) {
            for (int j = 0; j < letters[i]/2; j++) {
                cout << (char)(i+65);
            }
        }
    }
    for (int i = 0; i < letters[middleLetters] && middleLetters != -1; i++) {
        cout << (char)(middleLetters+65);
    }
    for (int i = 25; i >= 0; i--) {
        if (i == middleLetters) continue;
        if (letters[i] > 0) {
            for (int j = 0; j < letters[i]/2; j++) {
                cout << (char)(i+65);
            }
        }
    }
    cout << "\n";
    return 0;
}



