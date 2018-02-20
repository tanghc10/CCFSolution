#include<bits/stdc++.h>
using namespace std;

int main(){
	int ticketsArray[20];
	for(int i = 0; i < 20; i++)
		ticketsArray[i] = 5;
	int n, number;
	cin>>n;
	while(n--){
		cin>>number;
		int i = 0;
		for(; i < 20; i++){
			if(ticketsArray[i] >= number){
				for(int j = 0; j < number; j++)
					cout<<i*5 + 6 - ticketsArray[i] + j<<" ";
				ticketsArray[i] -= number;
				cout<<endl;
				break;
			}
		}
		if(i == 20){
			for(i = 0; i < 20; i++){
				if(number == 0)
					break;
				while(ticketsArray[i] > 0){
					cout<<i*5 + 6 - ticketsArray[i]<<" ";
					number--;
					ticketsArray[i]--;
					if(number == 0) break;
				}
			}
		}
	}
	return 0;
}
