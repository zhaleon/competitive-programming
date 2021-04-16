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
#define loop(i,a,b) for (long long i = a; i < b; i++)

int t;

ll p[200001];
ll s[200001];
ll x[200001];


int main() {
    cin >> t;
    ll n;
    loop(i,0,t) {
//        memset(s,0,sizeof(s));
//        memset(p,0,sizeof(p));
        cin >> n;
        loop(j,1,n+1) {
            cin >> p[j];
        }
        
        s[1] = p[1];
        x[1] = p[1]*p[1];
        loop(j,2,n+1) {
            s[j] = s[j-1] + p[j];
            x[j] = p[j]*p[j] + x[j-1];
        }
        
        int count = 0;
        loop(j,1,n+1) {
            if (s[j] == (j+1)*j/2 && s[n]-s[j] == (n-j+1)*(n-j)/2) {
                if (x[j] == j*(j+1)*(2*j+1)/6 && x[n]-x[j] == (n-j)*(n-j+1)*(2*(n-j)+1)/6) {
                    count++;
                }
            }
        }
        cout << count << endl;
        loop(j,1,n+1) {
            if (s[j] == (j+1)*j/2 && s[n]-s[j] == (n-j+1)*(n-j)/2) {
                if (x[j] == j*(j+1)*(2*j+1)/6 && x[n]-x[j] == (n-j)*(n-j+1)*(2*(n-j)+1)/6) {
                    cout << j << ' ' << n-j << endl;
                }
            }
        }
    }
    return 0;
}



