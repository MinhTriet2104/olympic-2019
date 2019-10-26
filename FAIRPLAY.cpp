#include <fstream>
#include <algorithm>
using namespace std;

int compare (const void * a, const void * b) {
  return ( *(int*)a - *(int*)b );
}

int main() {
	ifstream docFile;
	ofstream ghiFile;

	// doc file
	docFile.open("FAIRPLAY.INP");
	int n;
	docFile >> n;
	// Tao 2 mang a va b
	int *arrA = new int[n]; // Doi khach	
	int *arrB = new int[n]; // Doi nha
	// doc 2 mang
	for (int i = 0; i < n; i++) {
		docFile >> arrA[i];
	}
	for (int i = 0; i < n; i++) {
		docFile >> arrB[i];
	}
	// sap xep 2 mang
	qsort(arrA, n, sizeof(int), compare);
	qsort(arrB, n, sizeof(int), compare);

	int point = 0;
	for (int i = 0; i < n; i++) {
		if (arrA[i] < arrB[i]) point++;
		else {
			int j = i - 1;
			int cur = arrB[i];
			while (arrB[j] == 0) {
				if (cur > arrA[j]) {
					point++;
					break;
				}
				j--;
			}
			arrB[i] = 0;
		}
	}
	
	// Ghi file
	ghiFile.open("FAIRPLAY.OUT");
	ghiFile << point;

	delete[] arrA;
	delete[] arrB;

	return 0;
}