#include<iostream>
#include <algorithm> 
#include <string> 

using namespace std;



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
		m = min(m, t[i]);// to pick up the smallest number, make sure at least one light turns orange
	}

	for (int i = m - 5; i < 18000; i++) {
		if (ifGreen(i, length, t) == true) {
			record[countR] = i;
			countR++;
			break;
		}
		if (i == 17999) {
			record[countR] = -1;
			countR++;
			break;
		}
			
	}


}

void printTime(int time) {
	
	int sec=0;
	string ssec;
	int min=0;
	string smin;
	int hour=0;
	string shour;

	if (time <0)
		cout << "Signals fail to synchronise in 5 hours" << endl;// timeout
	else {
		hour = time / 3600;
		min = (time - hour * 3600) / 60;
		sec = time - hour * 3600 - min * 60;
		if (sec < 10)
			ssec = "0" + to_string(sec);
		else
			ssec = to_string(sec);
		if (min < 10)
			smin = "0" + to_string(min);
		else
			smin = to_string(min);
		
		shour = "0" + to_string(hour);
		
		
		cout << shour << ":" << smin << ":" << ssec << endl;
	}
}

int main() {
	int times[100];
	int temp = 0;// count for total lights
	int count0 = 0;


	while (true) {
		for (int i = 0; i < 100; i++) {
			cin >> times[i];

			if (times[i] == 0) {
				count0++;
				if (count0 == 1)
					countTime(i, times);
				

				break;
			}
			if (times[i] != 0)
				count0 = 0;

		}
		if (count0 == 4) {
			
			break;
		}


	}

	for (int i = 0; i < countR; i++) {
		printTime(record[i]);
	}
	return 0;
}
