#include <fstream>
using namespace std;

int main() {
	ifstream docFile;
	docFile.open("ROBOT.INP");

	int n;
	docFile >> n;

	int count = 0;
	int x;
	docFile >> x; // Lay x dau tien de so sanh voi nhung x sau
	docFile.ignore(1);
	int x2;
	for (int i = 1; i < n; i++) {
		docFile >> x2;
		docFile.ignore(1);
		// Cu moi lan x tang la queo phai 1 lan
		if (x2 > x) {
			count++;
		}
		x = x2;
	}
	docFile.close();

	ofstream ghiFile;
	ghiFile.open("ROBOT.OUT");
	ghiFile << count;
	ghiFile.close();

	return 0;
}