#include <bits/stdc++.h>
using namespace std;
int n, m;
long long counter1(int i, int j, vector<string> &A, int rowDir, int colDir){
    return A[i-rowDir][j-colDir] == 'M' 
	    && A[i+rowDir][j-colDir] == 'M'
	    && A[i-rowDir][j+colDir] == 'S'
	    && A[i+rowDir][j+colDir] == 'S'
	    && A[i][j] == 'A';
}
long long counter2(int i, int j, vector<string> &A, int rowDir, int colDir){
    return A[i-rowDir][j-colDir] == 'M' 
	    && A[i+rowDir][j-colDir] == 'S'
	    && A[i-rowDir][j+colDir] == 'M'
	    && A[i+rowDir][j+colDir] == 'S'
	    && A[i][j] == 'A';
}
int main(){
   string line;
   vector<string> data;
   while(cin>>line){
      data.push_back(line);
   }
   n = data.size(), m = data.front().size();
   long long res = 0;
   for(int i = 1 ; i+1 < n; i++){
      for(int j = 1 ; j+1 < m; j++){
	 res += counter1(i, j, data, 1, 1); // -->  M   S
					    //        A
					    //      M   S
	 res += counter1(i, j, data, -1, -1);//-->  S   M
					     //       A
					     //     S   M
	 res += counter2(i, j, data, 1, 1); //-->  M   M
					    //       A 
					    //         M
	 res += counter2(i, j, data, -1, -1);
      }
   }
   cout << res<<endl;
   return 0;
}
