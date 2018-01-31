#include<iostream>
using namespace std;

const int INF = 1<<30;
int *h = NULL;

int main(){
	int number = 0, intCnt = 0, startIndex = 0;
	int result = 0, current_max = -1, current_area = -1, min_length = INF;
	cin>>number;
	h = new int[number];
	for(; intCnt < number; intCnt++)
		cin>>h[intCnt];
	for(startIndex = 0; startIndex < number; startIndex++){
		min_length = INF;
		current_area = -1;
		for(intCnt = 0; startIndex + intCnt < number; intCnt++){
			if(h[startIndex + intCnt] < min_length)
				min_length = h[startIndex + intCnt];
			current_area = min_length * (intCnt + 1);
			if (current_area > current_max)
				current_max = current_area;
		}
	}
	cout<<current_max<<endl;
	return 0;
}
