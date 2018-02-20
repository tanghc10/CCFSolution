#include<bits/stdc++.h>
using namespace std;

typedef struct{
	int endPoint, duration;
}edge;

vector<edge> edgeArray[100001];
const int INF = 1<<30;
bool *isInQueue;
int *Distance;
int n, m;

int max(int a, int b){
	return a > b ? a : b;
}

void spfa(int s){
	queue<int> Queue;
	isInQueue = new bool[n + 1];
	Distance = new int[n + 1];
	for(int i = 0; i <= n; i++){
        Distance[i] = INF;
        isInQueue[i] = false;
	}
	Queue.push(s);
	isInQueue[s] = true;
	Distance[s] = 0;
	while(!Queue.empty()){
		int currentIndex = Queue.front();
		Queue.pop();
		isInQueue[currentIndex] = false;
		int currentSize = edgeArray[currentIndex].size();
		int Max = INF;
		for(int i = 0; i < currentSize; i++){
			if(Distance[edgeArray[currentIndex][i].endPoint] > (Max = max(Distance[currentIndex], edgeArray[currentIndex][i].duration))){
                Distance[edgeArray[currentIndex][i].endPoint] = Max;
                if(isInQueue[edgeArray[currentIndex][i].endPoint] == false){
                    Queue.push(edgeArray[currentIndex][i].endPoint);
                    isInQueue[edgeArray[currentIndex][i].endPoint] = true;
                }
			}
		}
	}
}

int main(){
	cin>>n>>m;
	while(m--){
		int from;
		edge tempEdge;
		cin>>from>>tempEdge.endPoint>>tempEdge.duration;
		edgeArray[from].push_back(tempEdge);
		int temp = from;
		from = tempEdge.endPoint;
		tempEdge.endPoint = temp;
		edgeArray[from].push_back(tempEdge);
	}
	spfa(1);
	cout<<Distance[n]<<endl;
	return 0;
}
