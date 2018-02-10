#include<iostream>
using namespace std;

int main(){
	int number = 0, result = 0;
	cin>>number;
	number = number / 10;
	result = number;
	while(number >= 3){
		if (number >= 5){
			number -= 5;
			result += 2;
		}else if(number >= 3){
			number -= 3;
			result += 1;
		}
	}
	cout<<result<<endl;
	return 0;
}
