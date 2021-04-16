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
typedef pair<pair<int, int>, int> piii;
typedef vector<vector<int> > vii;
typedef vector<pair<int, int> > vpi;
typedef vector<int> vi;

#define INF 1000000000
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define loop(i,a,b) for (int i = a; i < b; i++)

int t;
int car[200001];

unordered_map<int, int> m;

int main() {
    cin >> t;
    
    int n;
    
    loop(i,0,t) {
        m.clear();
        cin >> n;
        loop(i,0,n) {
            cin >> car[i];

        }
        
        loop(i,0,n) {
            if (i == 0) {
                cout << "1";
                m[car[i]] = 1;
            } else {
                if (m[car[i-1]] == 1 && m[car[i+1]] == 1) {
                    cout << "2";
                    m[car[i]] = 2;
                } else if (m[car[i-1]] == 1) {
                    
                }
            }
            
            if (i == n-1) {
                cout << '\n';
            } else {
                cout << " ";
            }
        }
    }

    return 0;
}



