#include<iostream>
using namespace std;

const long long mod = 1000000007;

int main(){
	int number = 0;
	cin>>number;
	int cnt = 0;
	long long **state = new long long *[number + 1];
	/*
	 *state总共有number+1行，用来表示当数字个数为0~number个时各自的情况个数
	 *每一行有六个数据，用来存当前数字个数下六种情况的个数，六种情况与对应的第二维下标分别是：
	 *0：有2，没有0、1、3
	 *1：有0、2，没有1、3
	 *2：有2、3，没有0、1
	 *3：有0、1、2，没有3
	 *4：有0、2、3，没有1
	 *5：有0、1、2、3
	*/
	for(; cnt < number + 1; cnt++)
		state[cnt] = new long long[6];
	for(cnt = 0; cnt < 6; cnt++)
		state[0][cnt] = 0;
	for(cnt = 1; cnt < number + 1; cnt++){
		state[cnt][0] = 1;	//全是2，只有一种情况，在上一行全是2的情况下加一个2
		state[cnt][1] = (state[cnt - 1][0] + state[cnt - 1][1]*2) % mod;//在上一行有2的情况下加一个0，或者在上一行有0和2的情况下加0或者2(要乘2)
		state[cnt][2] = (state[cnt - 1][0] + state[cnt - 1][2]) % mod;	//在上一行有2的情况下加一个3，或者在上一行有2和3的情况下加3(不能加2)
		state[cnt][3] = (state[cnt - 1][1] + state[cnt - 1][3]*2) % mod;//在上一行有0、2的情况下加一个1，或者在上一行有0、1、2的情况下加1或者2
		state[cnt][4] = (state[cnt - 1][1] + state[cnt - 1][2] + state[cnt - 1][4]*2) % mod;
		state[cnt][5] = (state[cnt - 1][3] + state[cnt - 1][4] + state[cnt - 1][5]*2) % mod;
	}
	cout<<state[number][5]<<endl;
	return 0;
}
