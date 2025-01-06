#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> grid;
bool checkRow(vector<int> &row){
     bool isSafeInc=true, isSafeDec=true;
     for(int j = 1; j<row.size(); j++){
	      auto diffDec = row[j-1]-row[j];
	      auto diffInc = row[j]-row[j-1];
	      isSafeDec &= diffDec<=3 && diffDec>0;
	      isSafeInc &= diffInc<=3 && diffInc>0;
      }
     return isSafeInc || isSafeDec;
}
int main(){
   int n=1000;
   cin >> n;
   int res = 0;
   string line;
   while(getline(cin, line)){
	   stringstream ss(line);
	   vector<int>level;
	   int prev = -1, point;
	   ss>>prev;
	   level.push_back(prev);
	   while(ss>>point){
		   level.push_back(point);
	   }
	   grid.push_back(level);
   }
   for(int i = 0 ; i < grid.size(); i++){
      bool isSafe=false;
      for(int skip = 0 ;skip < grid[i].size(); skip++){
	  vector<int>row;
	  for(int j = 0; j < grid[i].size(); j++){
		  if(j==skip) continue;
		  row.push_back(grid[i][j]);
	  }
	  isSafe = checkRow(row);
	  if(isSafe)break;
      }
       res+=isSafe;
   }

   cout <<res<<endl;
   return 0;
}
