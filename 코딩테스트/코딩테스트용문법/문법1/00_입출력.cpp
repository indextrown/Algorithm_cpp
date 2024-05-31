#include <iostream>
#include <thread>

using namespace std;
// https://yechoi.tistory.com/48
// endl이 입력되면 버퍼는 자동으로 비워진다
// \n을 입력하면 버퍼를 지우지 않는다. 
// 속도차이는 \n이 빠르다. 즉시 출력하는게 아니면 \n으로 모다웠다가 출력하는게 시간을 줄일 수 있다. 
// cout을 통해 출력하는 데이터가 즉시 콘솔에 나타나지 않고 버퍼에 저장되었다가 특정 조건에서 버퍼 내용이
// 콘솔로 플러시되는(전송되는) 방식이다
// 프로그램이 종료되면 표준 출력버퍼는 자동으로 플러시됨 
int main()
{
    cout <<"hello";
    this_thread::sleep_for(chrono::seconds(3));
    return 0;
}