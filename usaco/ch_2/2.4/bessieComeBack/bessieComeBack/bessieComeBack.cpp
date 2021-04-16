/*
 ID: lionz202
 TASK: comehome
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <assert.h>
#include <utility>
#include <queue>
#include <string.h>
#include <cstring>

using namespace std;

//FILE *fin=fopen("comehome.in","r");
//FILE *fout = fopen("comehome.out", "w");
ofstream fout ("comehome.out");
ifstream fin ("comehome.in");

int charToInt(char x) {
    if (tolower(x) != x) {
        return int(x - 'A') + 26;
    }
    return int(x - 'a');
}



int p, current;
int adj[53][53];
int distances[53], visited[53];

auto comparator = [](const int& a, const int& b)
{ return adj[current][a] > adj[current][b];};

struct comp {
    bool operator()(const int& a, const int& b) {
        return adj[current][a] == adj[current][b];
    }
};

priority_queue<int, vector<int>, decltype(comparator)> nextPath(comparator);



int main()
{
    fin >> p;
    for (int i = 0; i < 52; i++) {
        for (int j = 0; j < 52; j++) {
            adj[i][j] = 1000000;
        }
    }
    for (int i = 0; i < p; i++) {
        char a, b;
        int c, d, e;
        fin >> a >> b >> c;
        d = charToInt(a);
        e = charToInt(b);
        adj[d][e] = adj[e][d] = min(adj[d][e], c);
    }
    memset(distances, 1000000, sizeof(distances));

    distances[51] = 0;
    nextPath.push(51);

    while(!nextPath.empty()) {
        current = nextPath.top();
        nextPath.pop();

        if (visited[current]) continue;
        visited[current] = 1;

        for (int i = 0; i < 51; i++) {
            if (adj[current][i] != 1000000) {
                nextPath.push(i);
                if (distances[current] + adj[current][i] < distances[i]) {
                    distances[i] = distances[current] + adj[current][i];
                }
            }
        }
    }
    
    int best = 100000000, cow = -1;
    for (int i = 26; i < 51; i++) {
        if (distances[i] < best) {
            best = distances[i];
            cow = i;
        }
       //fout << distances[i] << endl;
    }
    
    fout << char(cow+'A'-26) << ' ' << best << endl;
    return 0;
}
