#include <bits/stdc++.h>
using namespace std;
/*
      0  1 2 3 4 5 6 7 81   
    0                   1
    1                         
    2
    3
    4
    n

 * */
bool canBeDone(long long testValue, vector<long long> &values){
    unordered_map<int, bool> marked;
    marked[values.front()]=true;
    for(int i = 1; i < values.size(); i++){
	    unordered_map<int, bool> newMarked;
	    for(auto ii:marked){
		    newMarked[ii.first*values[i]]=true;
		    newMarked[ii.first+values[i]]=true;
	    }
	    marked=newMarked;
    }
    return marked[testValue];
}
int main(){
   string line;
   long long res = 0;
   while(getline(cin, line)){
      long long testValue;
      char del;
      stringstream st(line);
      st>>testValue>>del;
      vector<long long> values;
      long long val;
      while(st>>val) values.push_back(val);
      if(canBeDone(testValue, values)) res+=testValue;
   }
   cout << res <<endl;
   return 0;
}
