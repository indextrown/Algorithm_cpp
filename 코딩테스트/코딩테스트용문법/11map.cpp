#include <iostream>
#include <map>
#include <vector>
using namespace std;  
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);  
	vector<int> v{1,1,2,2,3,3}; 
	map<int, int> mp;
	for(int i : v){ 
		if(mp[i]){
			// cout << "엇 이미 맵에 있어!! : " << i << "\n";
			continue;
		}else{
			mp[i] =i;
			// cout << "자 이제 맵에 넣을꺼야!!" << i << "\n"; 
		}			
	}
    for (auto i : mp)
        cout << i.first << " : " << i.second <<"\n";

	return 0;
} 