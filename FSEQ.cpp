#include <fstream>
#include <vector>
using namespace std;

int main() {
	ifstream docFile;
	ofstream ghiFile;

	int n;
	docFile.open("FSEQ.INP");
	docFile >> n;

	vector<int> a1(n);
	vector<int> a2(n, 0);
	for (int i = 0; i < n; i++) {
		docFile >> a1[i];
	}
	
	for (int i = 2; i < n; i++) {
		if (a1[i] == a1[i - 1] + a1[i - 2]) {
			if (a2[i - 1] == 0) {
				a2[i] = 3;
			} else {
				a2[i] = a2[i - 1] + 1;
			}
		}
	}

	int max = a2[2];
	for (int i = 3; i < n; i++) {
		if (a2[i] > max) max = a2[i];
	}

	ghiFile.open("FSEQ.OUT");
	if (max == 0) ghiFile << -1;
	else ghiFile << max;

	return 0;
}