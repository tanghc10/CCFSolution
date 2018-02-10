#include<iostream>
using namespace std;

int main(){
	int n = 0, k = 0;
	int result = 0, currentNum = 0, tempNum = 0;
	int numberCnt = 0;
	cin>>n>>k;
	for(; numberCnt < n; numberCnt++){
		cin>>tempNum;
		currentNum += tempNum;
		if(currentNum >= k){
			result++;
			currentNum = 0;
		}
	}
	if(currentNum != 0)
        result++;
	cout<<result<<endl;
	return 0;
}
