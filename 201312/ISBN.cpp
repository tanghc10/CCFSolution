#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

int index[9] = {0,2,3,4,6,7,8,9,10};

int main(){
	string initiallyStr;
	int sumOfISBN = 0, strNumIndex = 0, checkNum = -1;
	cin>>initiallyStr;
	for(; strNumIndex < 9; strNumIndex++)
        sumOfISBN += (strNumIndex+1) * (initiallyStr[index[strNumIndex]] - '0');
	checkNum = initiallyStr[12];
	sumOfISBN = sumOfISBN % 11;
	if (checkNum == 'X')
        checkNum = 10;
	else
        checkNum = checkNum - '0';
	if(sumOfISBN == checkNum)
        cout<<"Right"<<endl;
    else{
        initiallyStr[12] = sumOfISBN == 10 ? 'X' : ('0' + sumOfISBN);
        cout<<initiallyStr<<endl;
    }
	return 0;
}
