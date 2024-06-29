#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(int n) {
    //결과값을 출력할 벡터 배열, n의 크기로 할당하고 0으로 초기화한다.
    vector<vector<int>> answer(n, vector<int>(n, 0)); 
    
    int dx[4] = { 0,1,0,-1 }; //x축 증가를 위한 방향 벡터
    int dy[4] = { 1,0,-1,0 }; //y추 증가를 위한 방향 벡터
    int x = 0; //시작 좌표
    int y = 0;
    
    int direction = 0; //초기 방향은 오른쪽
    int num =1;
    
    while (num <= n*n)
    {
        answer[x][y] = num++; // 값넣기

        int nx = x + dx[direction]; //다음 x 좌표
        int ny = y + dy[direction]; //다음 y 좌표

        //범위를 벗어나거나 이미 채워진 셀을 만났을 때 방향을 바꾼다.
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || answer[nx][ny] != 0) {
            direction = (direction + 1) % 4; //방향을 바꾼다
            nx = x + dx[direction];
            ny = y + dy[direction];
        }

        x = nx;
        y = ny;
    }


    return answer;
}