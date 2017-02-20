#include<iostream>
#include <algorithm>   

using namespace std;

int time[100];
int record[100];


bool ifGreen(int time,int length,int t[]) {
	for (int i = 0; i < length; i++) {
		if ((time / t[i] + 1) % 2 == 0)
			return false;
		if (((time/t[i])%2==0 &&(time + 5) / t[i] + 1) % 2 == 0)
			return false;
	}
	return true;
}

void countTime(int length,int t[]) {
	int m = t[0];

	for (int i = 1; i < length; i++) {
		m = min(t[i - 1], t[i]);
	}
	
	for (int i = m-5; i < 18000;i++) {
		if (ifGreen(i, length, t)) {
			cout << "ok" << i << endl;
			break;
		}
		
	
	}
	cout << "fail" << endl;
	
}

int main() {
	int temp=0;// count for total lights
	int count0 = 0; 
	
	while (true) {
		for (int i = 0; i < 100; i++) {
			cin >> time[i];
			
			if (time[i] == 0) {
				count0++;
				countTime(i,time);
				cout << "time0"<<endl;
				break;
			}
			
		}
		if (count0 == 4){
			cout << "time0*4" << endl;
			break;
		}
		else 
			count0 = 0;
		temp = 0;
			

	}
	
	return 0;
}
