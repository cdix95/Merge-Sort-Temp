#include <iostream>
#include <cassert>

using namespace std;

template <class T>
void msort(T a[], T x[], int s, int e) {
	if(e - s > 1){
		int m = (s+ (e - 1))/2;
		msort(a, x, s, m+1);
		msort(a, x, m+1, e);
		int j = s;
		int c = m+1;
		int t = s;
	    	while(j < m + 1 && c < e){
			if(a[j] >= a[c]) x[t++] = a[c++];
			else x[t++] = a[j++];
	   	 }
	   	while(j < m+1) x[t++] = a[j++];
	    	while(c < e) x[t++] = a[c++];
	    	for(int q=s; q < e; q++) a[q] = x[q];
	}
}

template <class T>
void mergesort(T a[], int n) {
	T *x = new T[n];
	msort(a, x, 0, n);
	delete []x;
}

template <class T>
bool sorted(T a[], int n) {
	for (int x = 0; x < n-1; x++)
		if (a[x] > a[x+1]) return false;
		return true;
}

int main(int argc, char * args[]) {
	int a[1000];
	for (int i = 0; i < 1000; ++i) a[i] = -50 + rand() % 100;
	mergesort(a, 1000);
	assert(sorted(a, 1000));
	
	int b[1001];
	for (int i = 0; i < 1001; ++i) b[i] = -50 + rand() % 100;
	mergesort(b, 1001);
	assert(sorted(b, 1001));
	
	int c[] = { 2 };
	mergesort(c, 1);
	assert(sorted(c, 1));
	
	int d[] = {78, 43, 2, 10, 27};
	mergesort(d, 5);
	assert(sorted(d, 5));
	
	int z [0];
	mergesort (z, 0);
	assert (sorted (z, 0));
	
	double y []={5.8, 3.6, -6.9, 50.6, 4.7, -21.4, 6.12};
	mergesort<double>(y, 7);
	assert (sorted (y, 7));

  
	cout << "All tests passed." << endl;    
}
