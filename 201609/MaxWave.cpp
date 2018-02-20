#include<bits/stdc++.h>
using namespace std;

int main(){
	int number;
	cin>>number;
	int result = -1;
	int pre, current;
	for(int i = 0; i < number; i++){
		if(i == 0){
			cin>>pre;
			i++;
		}
		cin>>current;
		if(current >= pre && result < current - pre)
			result = current - pre;
		else if(result < pre - current)
			result = pre - current;
        pre = current;
	}
	cout<<result<<endl;
	return 0;
}
