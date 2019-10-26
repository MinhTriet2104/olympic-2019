#include <fstream>
#include <iostream>
using namespace std;

int main() {
	ifstream docFile;
	ofstream ghiFile;

	docFile.open("SEQ.INP");

	int n;
	docFile >> n;

	int *arr = new int[n];
	int *arr3 = new int[n];
	int *arrTemp = new int[n];

	for (int i = 0; i < n; i++) {
		docFile >> arr[i];
	}
	docFile.close();

	int max = arr[0] + arr[1] + arr[2];
	arr3[0] = max;
	arrTemp[0] = max;
	for (int i = 1; i < n - 2; i++) {
		arr3[i] = arr[i] + arr[i + 1] + arr[i + 2];
		arrTemp[i] = arr3[i];
		if (arr3[i] > max) max = arr3[i];
	}

	int l = 6;
	while (l <= n) {
		for (int i = 0; i <= n - l; i++) {
			arrTemp[i] = arrTemp[i] + arr3[i + l - 3];
			if (arrTemp[i] > max) max = arrTemp[i];
		}
		l += 3;
	}

	ghiFile.open("SEQ.OUT");
	ghiFile << max;
	ghiFile.close();

	return 0;
}