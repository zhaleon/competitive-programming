/*
 ID: lionz202
 TASK: beads
 LANG: C++
 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int right(string a, int b) {
    int c = 1, current = (b+2) % a.length();
    char first = a[(b+1) % a.length()];
    if (first == 'w') first = a[(b+1)%a.length()];
    while(true) {
        if (first == a[current]) {
            c++;
            current++;
        } else if (a[current] == 'w') {
            c++;
            current++;
        } else {
            break;
        }
        if (current == a.length()) current = 0;
        if (c == a.length()) break;
    }
    return c;
};

int left(string a, int b) {
    int c = 1;
    char first = a[b];
    int current = (b == 0) ? (int)a.length() - 1 : b-1;
    if (first == 'w') first = (b == 0) ? (int)a.length() - 1 : a[b - 1];
    while(true) {
        if (first == a[current]) {
            c++;
            current--;
        } else if (a[current] == 'w') {
            c++;
            current--;
        } else {
            break;
        }
        if (current < 0) current= (int)a.length() - 1;
        if (c == a.length()) break;
    }
    return c;
};


int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    string necklace;
    int length, count = 0, max = 0;
    fin >> length >> necklace;
    for (int current = 0; current < length; current++) {
        count += left(necklace, current);
        count += right(necklace, current);
        if (count > max) max = count;
        count = 0;
    }
    if (max > length || length < 3) {
        fout << length << endl;
    } else {
        fout << max << endl;
    }
    return 0;
}
