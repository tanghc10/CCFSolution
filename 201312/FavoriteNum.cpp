#include <iostream>
#include <map>
using namespace std;

int main(){
	int number = 0, readCnt = 0, tempNum = 0;
	int result = 0, showTimes = -1;
	map<int, int> counter;
	cin>>number;
	for(; readCnt < number; readCnt++){
		cin>>tempNum;
		counter[tempNum]++;
	}
	map<int, int>::iterator travercer = counter.begin();
	while(travercer != counter.end()){
		if(travercer->second > showTimes){
			result = travercer->first;
			showTimes = travercer->second;
		}
		travercer++;
	}
	cout<<result<<endl;
	return 0;
}
