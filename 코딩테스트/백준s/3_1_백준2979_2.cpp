#include <iostream>
#include <algorithm>
using namespace std;

int A, B, C;
int arr[6];
int v[100];
int sum;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> C;
    for (int i=0; i<6; i++)
    {
        cin >> arr[i];
    }

    int max_time = 0;
    for (int i=0; i<3; i++)
    {
        for (int j=arr[i*2]; j<arr[i*2+1]; j++) v[j]++;
        max_time = max(max_time, arr[i*2+1]);
    }


    for (int i=0; i<max_time; i++)
    {
        if (v[i]==1) sum += A;
        else if (v[i]==2) sum += B*2;
        else if (v[i]==3) sum += C*3;
    }
    cout << sum << "\n";

    return 0;
}






    // for (int i=arr[0]; i < arr[1]; i++) v[i] ++;

    // for (int i=arr[2]; i < arr[3]; i++) v[i] ++;
    
    // for (int i=arr[4]; i < arr[5]; i++) v[i] ++;

    


    /*
    #include <bits/stdc++.h>
using namespace std;

int a, b, c;
int t[100];

int main() {
	cin >> a;
	cin >> b;
	cin >> c;
	
	for(int i = 0; i<3; i++) {
		int s, e;
		cin >> s;
		cin >> e;
		
		for(int j = s; j < e; j++) {
			t[j-1]++;
		}
	}
	
	int sum = 0;
	for(int i = 0; i < 100; i++) {
		if(t[i] == 1) sum+=t[i]*a;
		if(t[i] == 2) sum+=t[i]*b;
		if(t[i] == 3) sum+=t[i]*c;
	}
	
	cout << sum;
	
	return 0;
}
    
    */