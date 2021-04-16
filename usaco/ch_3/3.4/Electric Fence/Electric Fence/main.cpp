/*
ID: lionz202
TASK: fence9
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

ifstream fin ("fence9.in");
ofstream fout ("fence9.out");

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int N, M, P;



int main() {
    fin >> N >> M >> P;
    int area = M*P/2;
    
    int y = N/gcd(M,N);
    if (N!=0 && M%N == 0) {
        y = 1;
        //fout << "u" << endl;
    }
    int i = N/y;
    //fout << N << ' '<< y << endl;
    if (N == 0) {
        i = M;
    }

    
    int x = P-N;
    int j;
    if (x < 0) {
        x = -1*x;
        j = (x)/((x)/gcd(x, M));
        if (M % x == 0) {
            j = x;
            //fout << "hi" << endl;
        }
    } else if (x > 0) {
        //fout << "hi" << endl;
        j = (x)/(x/gcd(x, M));
        if (M % x == 0) {
            j = x;
            //fout << "hi" << endl;
        }
    } else {
        j = M;
    }
    
   // fout << i << ' ' << j << ' ' << P << endl;
//    fout << i + j + P << endl;
//    fout << area << endl;
    //fout << i << ' ' << j << endl;
    fout << area + 1 - (i+j+P)/2 << endl;
    
    //fout << gcd(3, 6) << endl;
    
    return 0;
}



