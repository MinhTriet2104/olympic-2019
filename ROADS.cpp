#include <fstream>
#include <vector>
using namespace std;

int main() {
	ifstream docFile;
	ofstream ghiFile;

	docFile.open("ROADS.INP");
	int n, m, k;
	docFile >> n >> m >> k;
	n++;
	m++;

	vector<int> H(n);
	vector<int> V(m);
	char c;
	int x;
	for (int i = 0; i < k; i++) {
		docFile >> c;
		docFile >> x;
		if (c == 'H') {
			H[x] = 1;
		} else {
			V[x] = 1;
		}
	}
	docFile.close();

	int h0 = 0, h1 = 0, h2 = 0;
	int v0 = 0, v1 = 0, v2 = 0;

	for (int i = 0; i < n - 1; i++) {
		if (H[i] == 0 && H[i + 1] == 0) {
			h0++;
		} else if (H[i] == 1 && H[i + 1] == 1) {
			h2++;
		} else {
			h1++;
		}
	}
	for (int i = 0; i < m - 1; i++) {
		if (V[i] == 0 && V[i + 1] == 0) {
			v0++;
		} else if (V[i] == 1 && V[i + 1] == 1) {
			v2++;
		} else {
			v1++;
		}
	}

	ghiFile.open("ROADS.OUT");
	ghiFile << h0 * v0 << " ";
	ghiFile << h1 * v0 + h0 * v1 << " ";
	ghiFile << h1 * v1 + h2 * v0 + h0 * v2 << " ";
	ghiFile << h1 * v2 + h2 * v1 << " ";
	ghiFile << h2 * v2;
	ghiFile.close();

	return 0;
}