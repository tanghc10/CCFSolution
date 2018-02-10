#include<iostream>
using namespace std;

int N, M, a[100010];
long long tree[100010];

int lowbit(int i){
	return -i&i;
}

/*第i个数加上value*/
void update(int i, int value){
	while(i <= N){
		tree[i] += value;
		i = i + lowbit(i);
	}
}

/*第一个数到第i个数的和*/
long long sum(int i){
	long long sum = 0;
	while(i > 0){
		sum += tree[i];
		i = i - lowbit(i);
	}
	return sum;
}

int main(){
	cin>>N>>M;
	int numberCnt = 1, opCnt = 0, tempCnt = 0;
	int option = 0, left = 0, right = 0, divNum = 1;
	for(; numberCnt <= N; numberCnt++){
		cin>>a[numberCnt];
		update(numberCnt, a[numberCnt]);
	}
	for(; opCnt < M; opCnt++){
		cin>>option>>left>>right;
		if(option == 1){
			cin>>divNum;
			if(divNum == 1)
                continue;
			for(tempCnt = left; tempCnt <= right; tempCnt++){
				if(a[tempCnt] >= divNum && a[tempCnt] % divNum == 0){
					update(tempCnt, a[tempCnt]/divNum - a[tempCnt]);
					a[tempCnt] = a[tempCnt] / divNum;
				}
			}
		}else if(option == 2){
			cout<<sum(right) - sum(left - 1)<<endl;
		}
	}
	return 0;
}
