#include <iostream>
using namespace std;

int main()
{
   freopen("input.txt", "r", stdin);
   
   int a, b;
   char inp;
   cin >> a >> b;
   vector<vector<int> > arr(a, vector<int>(b));
   
   for (int i=0; i<a; i++)
   {
      for (int j=0; j<b; j++)
      {
         cin >> inp;
         arr[i][j] = inp - '0'; // 문자 -> 정수
      }
   }

   return 0;
}