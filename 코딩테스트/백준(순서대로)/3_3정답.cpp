#include <iostream>
using namespace std;

int A, B, C;
int a, b, ret;
int cnt[104]; // 배열의 경우 조금 더 넓게

int main()
{
    cin >> A >> B >> C;

    // counting array
    for (int i=0; i<3; i++)
    {
        cin >> a >> b;
        for (int j=a; j<b; j++) cnt[j]++; // 이상 미만 
    }

    for (int j=0; j<100; j++)
    {
        if (cnt[j])
        {
            if (cnt[j]==1) ret += A;
            else if (cnt[j]==2) ret +=B*2;
            else if (cnt[j]==3) ret +=C*3;
        }
    }
    cout << ret << "\n";
    
}













/*
누적합 방식
#include <bits/stdc++.h>
using namespace std;

int fee[4], a[101], ans = 0;

int main() {
    for (int i = 1; i <= 3; ++i) {
        cin >> fee[i];
    }

    for (int i = 0; i < 3; ++i) {
        int s, e;
        cin >> s >> e;
        ++a[s], --a[e];
    }

    int car = 0;
    for (int i = 1; i <= 100; ++i) {
        car += a[i];
        ans += car * fee[car];
    }
    cout << ans;
    return 0;
}



*/