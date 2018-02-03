#include<iostream>

using namespace std;

int main(){
	int number = 0, key = 0, intCnt = 0, counter = 0, kidsNum = 0;
	cin>>number>>key;
	int *kids = new int[number];
	for(; intCnt < number; intCnt++)
		kids[intCnt] = intCnt;
	intCnt = 0;
	kidsNum = number;
	while(kidsNum != 1){
		if(kids[intCnt] == intCnt){
			counter++;
			if((counter % key == 0) || (counter % 10 == key)){
				kids[intCnt] = kids[intCnt + 1];
				kidsNum--;
			}
		}else{
			kids[intCnt] = kids[intCnt + 1];
		}
		intCnt = (intCnt + 1) % number;
	}
	for(intCnt = 0; intCnt < number; intCnt++){
		if (intCnt == kids[intCnt]){
			cout<<intCnt+1<<endl;
			break;
		}
	}
	return 0;
}
