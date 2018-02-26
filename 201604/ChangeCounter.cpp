#include<bits/stdc++.h>
using namespace std;

int main(){
	int number;
	cin>>number;
	int result = 0;
	int isUp = -1;
	int current, pre;
	for(int i = 0; i < number; i++){
		if(i == 0)
			cin>>pre;
		else{
			cin>>current;
			if(isUp == 0 && current > pre)
				result++;
			else if(isUp == 1 && current < pre)
				result++;
			isUp = pre < current ? 1 : 0;
			pre = current;
		}
	}
	cout<<result<<endl;
	return 0;
}
