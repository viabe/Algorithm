#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, v; //정점의 개수, 간선의 개수, 탐색을 시작할 정점의 번호
int s, e; //연결할 정점, 테스트 케이스에서 입력 받을 것들

vector<vector<int>>graph; //그래프
vector<bool> isVisited; //방문 확인용

void input(){
	cin >> n >> m >> v;

	graph.assign(n+1, vector<int>()); //정점의 개수만틈 공간 할당 및 빈 객체 생성
	isVisited.assign(n+1, false); // 정점의 개수만큼 false로 초기화

	for(int i = 0; i < m; i++){
		cin >> s >> e;

		graph[s].emplace_back(e);
		graph[e].emplace_back(s);
	}

	//다만 조건 중에 정점 번호가 작은 것부터 먼저 방문하는 조건이 있기 때문에 이를 정렬해준다.
	//graph[0]은 더미이기 때문에 1부터 시작해야함
	for(int i = 1; i <= n; i++){
		sort(graph[i].begin(), graph[i].end()); 
	}
}
//탐색을 할때 스택으로 노드를 탐색하고 방문처리를 한다.
void DFS(int cur){
	isVisited[cur] = true; //현재 방문한 정점에 왔다고 방문 표시
	cout << cur << " "; // ✅ 방문한 정점 출력
	
	//현재 정점과 간선에 연결되어 있는 모든 정점들을 둘러보기
	for(int i =0; i< graph[cur].size(); i++){
		int next = graph[cur][i];
		if(!isVisited[next])
			DFS(next); //만약 next를 둘러보지 않았다면 재귀로 호출
	}

}

//탐색을 할때 큐로 노드를 탐색하고 방문처리를 한다.
void BFS(int start){
	queue <int> q;
	q.push(start);
	isVisited[start] = true;

	while(!q.empty()){
		int cur = q.front(); //노드 검사가 끝나면 나가고 cur+1이 됨 그게 다시 넣어짐
		q.pop();

		cout << cur << " "; // ✅ 방문한 정점 출력

		//한 노드에 연결된 정점 계속해서 탐색하는 반복문 부분
		for(int i = 0; i<graph[cur].size(); i++){
			int next = graph[cur][i];
			if(!isVisited[next]){
				q.push(next);
				isVisited[next] = true;
			}
		}
	}
}

int main() {
	input();

	DFS(v);
	cout << "\n";

	fill(isVisited.begin(), isVisited.end(), false); //초기화
	BFS(v);
	

	return 0;
}