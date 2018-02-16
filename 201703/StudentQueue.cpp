#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin>>n>>m;
	int *student2Position = new int[n+1];
	int *position2Student = new int[n+1];
	for(int i = 0; i <= n; i++){
		student2Position[i] = i;
		position2Student[i] = i;
	}
	for(int i = 0; i < m; i++){
		int studentId, moveNum;
		cin>>studentId>>moveNum;
		int endIndex = student2Position[studentId] + moveNum;
		int tempIndex = student2Position[studentId];
		if(moveNum < 0){
			while(tempIndex != endIndex){
				position2Student[tempIndex] = position2Student[tempIndex-1];
				student2Position[position2Student[tempIndex]] = tempIndex;
				tempIndex--;
			}
		}else{
			while(tempIndex != endIndex){
				position2Student[tempIndex] = position2Student[tempIndex+1];
				student2Position[position2Student[tempIndex]] = tempIndex;
				tempIndex++;
			}
		}
        position2Student[tempIndex] = studentId;
        student2Position[studentId] = endIndex;
	}
	cout<<position2Student[1];
	for(int i = 2; i <= n; i++)
		cout<<" "<<position2Student[i];
	cout<<endl;
	return 0;
}
