#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int> sum; // records all the result of trafic lights, unit is second
	
	for(int i=0;i<sum.size;i++){
		int h,m,s,t;
		t=sum.at(i);
		h=t/3600;
		if(h>5)
			cout<<"Signals fail to synchronsize in 5 hours";
		else{
			m=(t-h*3600)/60;
			s=t%60;
			cout<<":"<<":"<<endl;
		}

	}
	return 0;
}