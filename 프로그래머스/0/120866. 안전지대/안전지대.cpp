#include<iostream>
#include<vector>
#include<string>

using namespace std;

int dx[8] = { 1, 1, 1, 0, 0, -1, -1, -1 }; //상하좌우 대각선 방향
int dy[8] = { 1, 0, -1, 1, -1, 1, 0, -1 }; //상하좌우 대각선 방향

int solution(vector<vector<int>> board) {
    int answer = 0; //출력할 값
    int bomb = 0; //위험지대 체크 변수

    //n  * n배열
    int n = board.size();

    for (int x = 0; x < n; x++) { //x축 방향으로 가기
        for (int y = 0; y < n; y++) { //y축 방향으로 가기
            //만약 지뢰를 발견했다면
            if (board[x][y] == 1) {
                //값을 더해주기
                board[x][y] = 2;
                bomb++;

                //이제 주변은 위험 지대로 표시
                //상하좌우, 대각선 탐색 -> 8곳 확인 필요
                for (int k = 0; k < 8; k++) {
                    //살펴볼 방향
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    //x와 y가 board 안이면서, 지뢰가 없는 구역을 위험 지역으로 분류, 이미 위험 지역이면 표시 안함
                    if ((nx >= 0 && nx < n) && (ny >= 0 && ny < n) && (board[nx][ny] == 0)) {
                        //위험 지역 체크
                        board[nx][ny] = 2;
                        bomb++;
                    }

                }
            }
        }

    }

    answer = n * n - bomb;

    return answer;
}