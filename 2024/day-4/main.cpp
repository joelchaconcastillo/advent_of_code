#include <bits/stdc++.h>
using namespace std;
int n, m;
long long counter(int i, int j, vector<string> &A, string &word, int rowDir, int colDir){
    long long res  = 0 ;
    bool found=true;
    int pos = 0;
    while(pos < word.size() && i>=0 && i < n && j>=0 && j<m && word[pos]==A[i][j]){
	 pos++;
	 i+=rowDir;
	 j+=colDir;
    }
    if(pos == word.size()) return 1;
    return 0;
}
int main(){
   string line, word="XMAS";
   vector<string> data;
   while(cin>>line){
      data.push_back(line);
   }
   n = data.size(), m = data.front().size();
   long long res = 0;
   for(int i = 0 ; i < n; i++){
      for(int j = 0 ; j < m; j++){
	 res += counter(i, j, data, word, -1, 0);
	 res += counter(i, j, data, word, 1, 0);
	 res += counter(i, j, data, word, 0, -1);
	 res += counter(i, j, data, word, 0, 1);
	 res += counter(i, j, data, word, 1, 1);
	 res += counter(i, j, data, word, -1, -1);
	 res += counter(i, j, data, word, -1, 1);
	 res += counter(i, j, data, word, 1, -1);
      }
   }
   cout << res<<endl;
   return 0;
}
