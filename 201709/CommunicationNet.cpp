#include<bits/stdc++.h>
using namespace std;

vector<int> toMatrix[1010];
int isConnect[1010][1010];

void dfs(int start, int current, int isVisited[]){
	size_t i = 0;
	isVisited[current] = 1;
	isConnect[start][current] = 1;
	isConnect[current][start] = 1;
	for(; i < toMatrix[current].size(); i++){
		if(isVisited[toMatrix[current][i]] == 0)
			dfs(start, toMatrix[current][i], isVisited);
	}
}


int main(){
	int N = 0, M = 0;
	int tempCnt = 0, i = 0;
	int result = 0;
	cin>>N>>M;
	for(tempCnt = 0; tempCnt < M; tempCnt++){
        int from, to;
		cin>>from>>to;
		toMatrix[from].push_back(to);
	}
	for(tempCnt = 1; tempCnt <= N; tempCnt++){
		int isVisited[1010] = {0};
		dfs(tempCnt, tempCnt, isVisited);
	}
	for(tempCnt = 1; tempCnt <= N; tempCnt++){
        for(i = 1; i <= N; i++){
            if(isConnect[tempCnt][i] == 0)
                break;
        }
        if(i == N+1)
            result++;
	}
	cout<<result<<endl;
	return 0;
}
