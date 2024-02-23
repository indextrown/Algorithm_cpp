#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tc, n;
    string wear, weartype;

    // 표준 입력으로부터 테스트 케이스 수를 읽음
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        cin >> n; // 혜빈이가 가진 의상의 수
        unordered_map<string, int> weartypeCount; // weartype을 키로 하고, 해당 weartype의 의상 수를 값으로 하는 해시맵

        for (int j = 0; j < n; j++) {
            cin >> wear >> weartype; // 의상 이름과 의상 종류를 읽음
            weartypeCount[weartype]++; // 해당 의상 종류의 카운트를 1 증가
        }

        // 모든 조합의 수를 계산
        int combinations = 1;
        for (const auto& pair : weartypeCount) {
            combinations *= (pair.second + 1); // 각 weartype에서 선택할 수 있는 경우의 수는 (의상 수 + 1) (선택하지 않는 경우 포함)
        }
        
        // 모든 의상을 선택하지 않는 경우를 제외
        combinations -= 1;

        cout << combinations << "\n"; // 가능한 모든 의상 조합의 수 출력
    }

    return 0;
}
