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

int n, m;
int c[100001];

bool comp(int a, int b) {
    return a > b;
}

int main() {
    cin >> n >> m;
    
    int sum = 0;
    int l = 0;
    
    loop(i,1,m+1) {
        cin >> c[i];
        sum += c[i];
    }
    
    //sort(c+1, c+100001, comp);
    
    l=sum-m;
    
    loop(i,1,m+1) {
        if (n-c[i]+1 < i) {
            cout << "-1\n";
            return 0;
        }
    }
    
    if (sum < n) {
        cout << "-1\n";
        return 0;
    }
    //cout << l << endl;

    int i = 1;
    int f = n-m;
    t = 1;
    while(i <= n-c[m]+1) {
        cout << i << ' ';
        if (f > 0) {
            if (f - c[t] + 1 <= 0) {
                if (f == c[i]-1) {
                    i += f;
                } else {
                    i += f;
                }
                f = 0;
            } else {
                f -= (c[t]-1);
                i += (c[t]-1);
            }
        } else {
            //i++;
        }
        i++;
        t++;
    } cout << '\n';
    
    return 0;
}



