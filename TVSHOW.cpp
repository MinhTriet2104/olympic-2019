#include <fstream>
#include <time.h>
//#include <iostream>
using namespace std;

struct Time {
	int start;
	int end;
};

int compare(const void * a, const void * b) {
	Time *a1 = (Time*)a;
	Time *b1 = (Time*)b;
	return a1->start < b1->start;
}

int main() {
	clock_t start = clock();
	ifstream docFile;
	docFile.open("TVSHOW.INP");

	int n;
	docFile >> n;

	Time arr[50000];
	for (int i = 0; i < n; i++) {
		docFile >>  arr[i].start;
		docFile >> arr[i].end;
	}
	docFile.close();


	//for (int i = 0; i < n; i++) {
	//	cout <<  arr[i].start;
	//	cout << " ";
	//	cout << arr[i].end << endl;
	//}

	qsort(arr, n, sizeof(Time), compare);
	int count = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[j].start <= arr[i].end) {
				/*cout << arr[i].start << " " << arr[i].end << " " << arr[j].start << " " << arr[j].end << endl;*/
				count++;
			}
		}
	}
	
	//int count = 0;
	//for (int i = 0; i < n - 1; i++) {
	//	for (int j = i + 1; j < n; j++) {
	//		if (arr[i].start >= arr[j].start && arr[i].start <= arr[j].end || arr[j].start >= arr[i].start && arr[j].start <= arr[i].end) {
	//			//cout << arr[i].start << " " << arr[i].end << " " << arr[j].start << " " << arr[j].end << endl;
	//			count++;
	//		}
	//	}
	//}

	ofstream ghiFile;
	ghiFile.open("TVSHOW.OUT");
	ghiFile << count;
	ghiFile.close();

	printf("Time: %.2fs\n", (double)(clock() - start)/CLOCKS_PER_SEC);
	system("pause");
	return 0;
}