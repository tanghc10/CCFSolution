#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int number = 0, intCnt = 0, least_distance = 2001;
	cin>>number;
	int *intArray = new int[number];
	for(; intCnt < number; intCnt++)
		cin>>intArray[intCnt];
	sort(intArray, intArray + number);
	for(intCnt = 0; intCnt < number - 1; intCnt++)
        least_distance = least_distance > (intArray[intCnt + 1] - intArray[intCnt]) ? (intArray[intCnt + 1] - intArray[intCnt]) : least_distance;
    cout<<least_distance<<endl;
	return 0;
}
