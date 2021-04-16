/*
ID: lionz202
TASK: nuggets
LANG: C++
*/
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

ifstream fin ("nuggets.in");
ofstream fout ("nuggets.out");

int N;
int nugs[10];
int works[256*256];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}
int main() {
    fin >> N;
    int smallest = INF;
    int g = 0;
    loop(i,0,N) {
        fin >> nugs[i];
        smallest = min(nugs[i], smallest);
    }
    
    if (N == 1) {
        fout << "0" << endl;
        return 0;
    } else {
        g = gcd(nugs[0],nugs[1]);
        loop(i,2,N) {
            g = gcd(g,nugs[i]);
        }
        if (g != 1) {
            fout << "0" << endl;
            return 0;
        }
    }
    
    works[0] = 1;
    int biggest = 0;
    for(int i = 0; i < 255*255-255*2; i++) {
        for (int j = 0; j < N; j++) {
            if (i+nugs[j] < 256*256 && works[i]) {
                works[i+nugs[j]] = 1;
            }
        }
        if (!works[i]) {
            biggest = max(biggest, i);
        }
    }
    
    fout << biggest << endl;
    
    fin.close();
    fout.close();
    return 0;
}



