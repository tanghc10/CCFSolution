#include<iostream>
using namespace std;
const int INF = 1 << 30;
int dp[1001][1001], a[1001], sum[1001];

int main(){
	int number = 0, numberCnt = 0;
	int i = 0, j = 0, k = 0, t = 0;
	cin>>number;
	for(; numberCnt < number; numberCnt++){
		cin>>a[numberCnt];
		sum[numberCnt] = sum[numberCnt - 1] + a[numberCnt];
	}
	for(j = 1; j < number; j++){
		for(i = 0, k = j; i < number - j + 1; i++, k++){
			dp[i][k] = INF;
			for(t = i; t < k; t++)
				if(dp[i][k] > dp[i][t] + dp[t+1][k] + sum[k] - sum[i-1])
					dp[i][k] = dp[i][t] + dp[t+1][k] + sum[k] - sum[i-1];
		}
	}
	cout<<dp[0][number-1]<<endl;
	return 0;
}
