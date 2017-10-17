#include <cassert>
#include <iostream>
#include <vector>
 
using namespace std;

template <class T>
class Merge {
public:
    Merge(int a[], int s, int m, int e);
    static void msort(int a[], int from, int to);
    static bool sorted (int a[], int n);
};

// s = start 
// m = middle
// e = end 


template <class T>
Merge::Merge(int a[], int s, int m, int e) {
    int n = e - s + 1;
    vector<T> b(n);
    int i1 = s;
    int i2 = m + 1;
    int j = 0;

    while (i1 <= m && i2 <= e) {
        if (a[i1] < a[i2]) {
            b[j] = a[i1];
            i1++;
        }
        else {
            b[j] = a[i2];
            i2++;
        }
        j++;
    }

    while (i1 <= m) {
        b[j] = a[i1];
        i1++;
        j++;
    }
    while (i2 <= e) {
        b[j] = a[i2];
        i2++;
        j++;
    }
    for (j = 0; j < n; j++)
        a[s + j] = b[j];
}

template <class T>
void Merge::msort(int a[], int from, int to) {
    if (from == to) return;
    int m = (from + to) / 2;
    msort(a, from, m);
    msort(a, m + 1, to);
    Merge(a, from, m, to);
}

template <class T>
bool Merge::sorted(int a[], int n) {
    for (int i = 0; i < n -1; ++i) {
        if (a[i] > a[i + 1])
            return false;
    }
    return true;
}

int main (int argc, char * args[]) {
    int a[1000];
    for (int i = 0; i < 1000; ++i) a[i] = -50 + rand() % 100;
    Merge::msort(a, 0, 999);
    assert(Merge::sorted(a, 1000));
    int b[1001];
    for (int i = 0; i < 1001; ++i) b[i] = -50 + rand() % 100;
    Merge::msort(b, 0, 1000);
    assert(Merge::sorted(b, 1001));
    int c[] = { 7 };
    Merge::msort(c, 0, 6);
    assert(Merge::sorted(c, 6));
    int d[] = { 43, 7, -46, 57, 11 };
    Merge::msort(d, 0, 4);
    assert(Merge::sorted(d, 5));
	
    cout << "All tests passed." << endl;
}
