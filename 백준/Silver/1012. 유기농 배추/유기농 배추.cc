#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX =51; 

int m, n,k; //순서대로 가로, 세로, 위치의 개수
int tx, ty; //좌표

int map[MAX][MAX]; //밭 표현용 맵
bool isVisited[MAX][MAX]; //밭 방문 확인

//상하좌우 움직임용
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int result; //결과담을 변수


//BFS
void BFS(int start_x, int start_y){
    queue <pair<int,int>> q;
    q.push(make_pair(start_x, start_y));
    isVisited[start_x][start_y] = true; //방문했다 표시

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i =0; i< 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            //맵 안에 있는지, 방문한 적 없는지, 배추가 있는지
            if((nx >= 0 && nx < n) && (ny >=0 && ny < m)
            && !isVisited[nx][ny] && map[nx][ny] == 1){
                //방문한 좌표는 방문 표시 해두기
                isVisited[nx][ny] = true;
                //좌표 큐에 삽입
                q.push(make_pair(nx, ny));
            }
        }

    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력 후 맵 연결
    int T; //테스트 케이스

    cin >> T;

    //테스트 케이스 수만큼 반복
    for(int i =0; i< T; i++){
        cin >> m >> n>> k;

        //맵과 방문 배열 초기화
        for(int x = 0; x < n; x++){
            for(int y =0; y < m; y++){
                //맵을 0으로 초기화 
                map[x][y] = 0;
                //방문 배열 초기화
                isVisited[x][y] = false;

            }
        }

        //맵에다가 배추 심기
        for(int j =0; j < k; j++){
            //그다음 좌표에 1넣기
            cin >> ty >> tx; //ty, tx로 받아야 세로, 가로!!
            map[tx][ty] = 1;
        }

        //결과변수 초기화
        int result = 0;
        //맵 순회하기
        for(int x = 0; x < n; x++){ //n은 세로
            for(int y =0; y <m; y++){ //m은 가로
                //배추가 있고, 방문이 되지 않은 곳을 체크
                if(map[x][y] ==1 && !isVisited[x][y]){
                    BFS(x,y); //BFS로 방문확인 후
                    //BFS가 돌아간 만큼 1더하기
                    result++;
                }
            }
        }
        //결과 값 출력
        cout << result << "\n";
        
    } 
    return 0;
}