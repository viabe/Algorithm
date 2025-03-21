#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

	//문제 풀이 : 한개의 회의실 이를 사용하고자 하는 N개의 회의에 대하여 회의실 사용표를 만들어야함
	//다만 각 회의는 시작 시간과 끝나는 시간이 주어져 있고 각 회의가 겹치지 않으면서도
	//회의를 최대한 많이 할 수 있는 개수를 세어야한다.
	//일단 시작시간과 마지막 시간이 별로 차이나지 않는 회의를 골라야한다.
	//즉, 마지막 시간이 가장 작은 회의를 골라야한다는 뜻이다.
	//우선 내부의 배열을 정렬하고, 시작 시간 순이지만 마지막 시간도 적게 정렬해야한다.

struct Meeting{
	int StartTime;
	int EndTime;
};

bool compare(Meeting a, Meeting b){
	if(a.EndTime == b.EndTime){
		return a.StartTime < b.StartTime;
	}
	return a.EndTime < b.EndTime;
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	
	int n; //회의의 총 개수
	cin >> n;

	vector<Meeting> m(n);
	for(int i =0 ; i<n; i++){
		cin >> m[i].StartTime >> m[i].EndTime;	
	}

	sort(m.begin(), m.end(), compare); //정렬

	int result = 1; //회의의 최대 개수, 하나는 무조건 있기 때문에
	int endTime = m[0].EndTime; //끝나는 시간을 맞춰서 넣기

	//끝나는 시간을 기점으로 골라야함
	for(int i = 1; i<n; i++){
		//첫번째 시간이 endTime에 가장 근접한 수를 찾아야함 이미 정렬을 했기 때문에 수만 찾으면 끝
		if(m[i].StartTime >= endTime){
			endTime = m[i].EndTime;
			result++;
		}
	}

	cout << result;
	return 0;
}