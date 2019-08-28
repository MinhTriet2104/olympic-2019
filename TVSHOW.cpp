#include <fstream>
#include <vector>
//#include <algorithm>
//#include <iostream>
using namespace std;

struct Time {
	int start;
	int end;
};

//bool compare(Time t1, Time t2) {
//	return t1.start < t2.start;
//}

int main() {
	ifstream docFile;
	docFile.open("TVSHOW.INP");

	int n;
	docFile >> n;

	vector<Time> arr(n);
	for (int i = 0; i < n; i++) {
		docFile >>  arr[i].start;
		docFile >> arr[i].end;
	}
	docFile.close();

	//sort(arr.begin(), arr.end(), compare);

	//for (int i = 0; i < n; i++) {
	//	cout <<  arr[i].start;
	//	cout << " ";
	//	cout << arr[i].end << endl;
	//}

	int count = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i].start > arr[j].start && arr[i].start < arr[j].end || arr[j].start > arr[i].start && arr[j].start < arr[i].end) {
				//cout << arr[i].start << " " << arr[i].end << " " << arr[j].start << " " << arr[j].end << endl;
				count++;
			}
		}
	}
	
	ofstream ghiFile;
	ghiFile.open("TVSHOW.OUT");
	ghiFile << count;
	ghiFile.close();

	//system("pause");
	return 0;
}