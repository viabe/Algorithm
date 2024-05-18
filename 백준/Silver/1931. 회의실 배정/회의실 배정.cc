#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Meeting
{
	int firstTime; //시작시간
	int lastTime; //종료시간
};

//오름차순으로 종료시간을 기준으로 해야함
bool compare(Meeting a, Meeting b) {
	if (a.lastTime == b.lastTime) {
		return a.firstTime < b.firstTime;
	}
	return a.lastTime < b.lastTime;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//회의의 개수
	int n;
	cin >> n;

	//회의 시간 넣을 배열
	vector <Meeting> t(n);

	for (int i = 0; i < n; i++) {
		cin >> t[i].firstTime >> t[i].lastTime;
	}

	//정렬쓰기 첫번째수를 기준으로 
	sort(t.begin(), t.end(), compare);

	//최대 사용할 수 있는 회의의 개수 일단은 처음꺼는 있기 때문에 1을 기본으로
	int result = 1;

	//마지막 시간은 계속해서 변경되어야하기 때문에 변수 필요
	int endTime = t[0].lastTime;

	//이제 lasttime이 작은 순번을 골라서 카운팅
	//근데 1부터 시작해야함 이미 result를 1했으니까
	for (int i = 1; i < n; i++) {
		//가장 처음 배열 즉 t[0]을 시작으로 t[i].fistTime 의 수를 찾아야함. 가장 작은 걸 빨리 찾아야함
		if(t[i].firstTime >= endTime) {
			result++;
			endTime = t[i].lastTime;
		}
	}

	cout << result;
	return 0;
}