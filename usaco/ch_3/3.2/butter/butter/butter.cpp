/*
 ID: lionz202
 TASK: butter
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <assert.h>
#include <queue>
#include <unordered_map>
#include <cstring>
#include <climits>
#include <bitset>
#include <map>

using namespace std;

ifstream fin("butter.in");
ofstream fout("butter.out");

int N, P, C;
int adj[801][801];
int visited[801][801];
int distances[801][801];
int location[801];
int currentPasture;

auto comparator = [](const int& a, const int& b)
{ return adj[currentPasture][a] > adj[currentPasture][b];};

int main()
{
    fin >> N >> P >> C;
    
    for (int i = 1; i <= N; i++) {
        int temp;
        fin >> temp;
        location[temp]++;
    }
    for (int i = 1; i <= P; i++) {
        fill(distances[i], distances[i]+801, 10000000);
        distances[i][i] = 0;
    }
    for (int i = 0; i < C; i++) {
        int a, b, c;
        fin >> a >> b >> c;
        adj[a][b] = adj[b][a] = c;
    }
    
//    for (int i = 1; i <= P; i++) {
//        fout << i << ":  ";
//        for (int j = 1; j <= P; j++) {
//            fout << distances[i][j] << ' ';
//        }
//        fout << endl;
//    } fout << endl;
    for (int i = 1; i <= P; i++) {
        fout << i << ":  " << location[i] << endl;
    } fout << "\n\n\n";
    
    int best = 10000000;
    priority_queue<int, vector<int>, decltype(comparator)> dijkstras(comparator);
    for (int i = 1; i <= P; i++) {
        dijkstras.push(i);
        while (!dijkstras.empty()) {
            currentPasture = dijkstras.top();
            dijkstras.pop();
            
            if (visited[i][currentPasture]) continue;
            visited[i][currentPasture] = 1;
            
            for (int j = 1; j <= P; j++) {
                if (adj[currentPasture][j] != 0 && currentPasture != j) {
                    if (distances[i][currentPasture] + adj[currentPasture][j] < distances[i][j]) {
                        distances[i][j] = distances[i][currentPasture] + adj[currentPasture][j];
                    }
                    dijkstras.push(j);
                }
            }
        }
        int sum = 0;
        for (int j = 1; j <= P; j++) {
            if (location[j] != 0 && i != j) {
                sum += distances[i][j]*location[j];
            }
        }
        fout << sum << ' ' << i << ":   ";// << endl;
        for (int j = 1; j <= P; j++) {
            if (location[j] > 0) {
                fout << j << ": " << distances[i][j] << "   ";
            }
        } fout << "\n";
        best = min(best, sum);
    }

    fout << best << endl;// << endl;
    
//    for (int i = 1; i <= P; i++) {
//        fout << i << ":  ";
//        int sum = 0;
//        for (int j = 1; j <= P; j++) {
//            fout << distances[i][j] << ' ';
//            if (location[j]) {
//                sum += distances[i][j];
//            }
//        } fout << sum;
//        fout << endl;
//    } fout << endl;
//
//    for (int i = 1; i <= P; i++) {
//        fout << i << ":  ";
//        for (int j = 1; j <= P; j++) {
//            fout << adj[i][j] << ' ';
//        }
//        fout << endl;
//    } fout << endl;
//
//    for (int i = 1; i <= P; i++) {
//        fout << i << ' ' << location[i] << endl;
//    }
    fin.close();
    fout.close();
    return 0;
}

