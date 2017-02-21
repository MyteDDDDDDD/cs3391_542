#include<iostream>
#include <algorithm>   

using namespace std;

int time[100];

int record[100];
int countR = 0;

bool ifGreen(int time, int length, int t[]) {
	
	for (int i = 0; i < length; i++) {
		int temp = time % (2 * t[i]);
		if (temp >= t[i] - 5)
			return false;
	}
	return true;
	
}

void countTime(int length, int t[]) {
	int m = t[0];

	for (int i = 1; i < length; i++) {
		m = min(t[i - 1], t[i]);
	}

	for (int i = m-4; i < 18000; i++) {
		if (ifGreen(i, length, t)==true) {
			record[countR] = i;
			countR++;
			break;
		}
	}
	

}

int main() {
	int temp = 0;// count for total lights
	int count0 = 0;
	

	while (true) {
		for (int i = 0; i < 100; i++) {
			cin >> time[i];

			if (time[i] == 0 ) {
				count0++;
				if(count0==1)
					countTime(i, time);
				cout << "time0" << endl;
				
				break;
			}
			if(time[i]!=0)
				count0 = 0;

		}
		if (count0 == 4) {
			cout << "time0*4" << endl;
			break;
		}
		

	}

	for (int i = 0; i < countR; i++) {
		cout << record[i] << endl;
	}
	return 0;
}
