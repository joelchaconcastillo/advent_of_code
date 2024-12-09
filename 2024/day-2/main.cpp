#include <bits/stdc++.h>
using namespace std;
int main(){
   int n=1000;
   cin >> n;
   int res = 0;
   string line;
   while(getline(cin, line)){
	   stringstream ss(line);
	   bool isSafeInc=true, isSafeDec=true;
	   int prev = -1, point;
	   ss>>prev;
	   while(ss>>point){
	      auto diffDec = prev-point;
	      auto diffInc = point-prev;
	      isSafeDec &= diffDec<=3 && diffDec>0;
	      isSafeInc &= diffInc<=3 && diffInc>0;
	      prev = point;
	   }
      res+=isSafeInc;
      res+=isSafeDec;
   }
   cout <<res<<endl;
   return 0;
}
