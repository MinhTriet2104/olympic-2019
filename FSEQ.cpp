#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ifstream docFile;
	ofstream ghiFile;

	int n;
	docFile.open("FSEQ.INP");
	docFile >> n;

	vector<int> a1(n);
	for (int i = 0; i < n; i++) {
		docFile >> a1[i];
	}

	int count = 0;
	int max = 0;
	for (int i = 2; i < n; i++) {
		if (a1[i] == a1[i - 1] + a1[i - 2]) {
			count++;
		}
		else {
			if (count > max) {
				max = count;
			}
			count = 0;
		}
	}
	if (count > max) {
		max = count;
	}
	ghiFile.open("FSEQ.OUT");
	if (max == 0) ghiFile << -1;
	else ghiFile << max + 2;

	return 0;
}