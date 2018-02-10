#include <iostream>
#include <vector>
using namespace std;

int n = 0, m = 0;
const int INF = 1<<20;
int min_cost = INF;

class Road{
public:
	int t, a, b, c;
};

vector< vector<int> > road;
vector< vector<int> > trail;
bool *visited = NULL;

void DFS(int currentIndex, int current_cost, int trailLength){
	if(current_cost + trailLength*trailLength > min_cost)
		return;
	if(currentIndex == n){
		if (current_cost + trailLength*trailLength < min_cost)
			min_cost = current_cost + trailLength*trailLength;
		return;
	}
	int intCnt = 1;
	for(; intCnt < n + 1; intCnt++){
		if(visited[intCnt] == false){
			visited[intCnt] = true;
			if(trail[currentIndex][intCnt] != INF)
				DFS(intCnt, current_cost, trailLength + trail[currentIndex][intCnt]);
			if(road[currentIndex][intCnt] != INF)
				DFS(intCnt, current_cost + road[currentIndex][intCnt] + trailLength*trailLength, 0);
			visited[intCnt] = false;
		}
	}
}

int main(){
	cin>>n>>m;
	int intCnt = 0;
	visited = new bool[n + 1];
	Road tempRoad;
	for(; intCnt <= n; intCnt++){
		road.push_back(vector<int>(n + 1, INF));
		trail.push_back(vector<int>(n + 1, INF));
	}
	for(intCnt = 0; intCnt < m; intCnt++){
		cin>>tempRoad.t>>tempRoad.a>>tempRoad.b>>tempRoad.c;
		if(tempRoad.t == 0){
			if (tempRoad.c < road[tempRoad.a][tempRoad.b])
				road[tempRoad.a][tempRoad.b] = tempRoad.c;
			if (tempRoad.c < road[tempRoad.b][tempRoad.a])
				road[tempRoad.b][tempRoad.a] = tempRoad.c;
		}else if(tempRoad.t == 1){
			if (tempRoad.c < trail[tempRoad.a][tempRoad.b])
				trail[tempRoad.a][tempRoad.b] = tempRoad.c;
			if (tempRoad.c < trail[tempRoad.b][tempRoad.a])
				trail[tempRoad.b][tempRoad.a] = tempRoad.c;
		}
	}
	for(intCnt = 1; intCnt <= n; intCnt++)
		visited[intCnt] = false;
    visited[1] = true;
	DFS(1,0,0);
	cout<<min_cost<<endl;
	road.clear();
	return 0;
}
