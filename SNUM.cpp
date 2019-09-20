#include <fstream>
using namespace std;

int main() {
	ifstream docFile;
	ofstream ghiFile;

	int n;
	docFile.open("SNUM.INP");
	docFile >> n;

	int temp = n;
	int sum = 0;
	while (temp != 0) {
		sum += temp % 10;
		temp /= 10;
	}

	ghiFile.open("SNUM.OUT");
	if (n % sum == 0) ghiFile << 1;
	else ghiFile << 0;

	return 0;
}