/*
	갑옷은 두가지 재료로 만들 수 있고

	두가지 재료의 합이 M(1~10,000,000)면 갑옷을 만들 수 있다
	
	최대 15000개의 재료와 M 이주어질 때 갑옷을 몇개나 
	만들 수 있는지 구해라
	
	우선 수의 범위를 보니 int로 해결 가능하니
	long long을 고려하지는 않음
	
	
	그냥 NC2 의 합이 M인지 아닌지로 풀면 될 거같다고 생각함
	
	근데 NC2 = 15000*15000 /2 정도 될거임 
	대충 2억 /2 = 1억번 넘는 연산이 일어남 

	제한시간이 2초이기 때문에 그냥 통과할테니 
	이방식으로 풀어도 될 듯 
	
	만약 N의 범위를 훨씬 크게 줬으면
	
	어려운 문제가 될듯 
*/

// https://www.acmicpc.net/status?user_id=newbie12034&result_id=4
#include <iostream>
using namespace std;

int N, M;
int cnt = 0;

int main()
{
    // freopen("input.txt", "r", stdin);
    int arr[15000];
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    cin >> M;

    for (int i=0; i<N; i++)
    {
        cin >> arr[i];
    }

     for (int i=0; i<N; i++)
    {
        for (int j=i+1; j<N; j++)
        {
            if (arr[i] + arr[j] == M)
            {
                cnt++;
            } 
        }
    }
    cout << cnt << "\n";
    return 0;
}




















    // for (int i=3; i<=N; i++)
    // {
    //     // cout << psum[i] - psum[i-2] << "\n";
    //     // cout << psum[i] - psum[i-1] + psum[i-2] - psum[i-3] << "\n";
    // }


