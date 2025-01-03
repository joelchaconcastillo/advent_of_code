#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>keys, locks;
void parseInput(){
  string line;
  bool isLock=true, firstLine=true;
  vector<int> freq;
  while(getline(cin, line)){
    if(line.empty()){
	  firstLine=true;
	  if(isLock) locks.push_back(freq);
	  else keys.push_back(freq);
	  continue;
    }
    if(firstLine && line[0] =='#'){
	    isLock=true;
	    freq.assign(line.size(), 0);
    }else if(firstLine && line[0]=='.'){
	    isLock=false;
	    freq.assign(line.size(), 0);
    }else{
	  for(int i = 0 ; i < freq.size(); i++){
		freq[i] += line[i]=='#';
	  }
    }
    firstLine=false;
  }	  
    if(isLock) locks.push_back(freq);
    else keys.push_back(freq);
    //take the complement for each key
    for(auto &key:keys){
	 for(auto &pin:key){
		pin--; 
	 }
    }

}
long long solve(){
 parseInput();
 long long res = 0;
 for(auto key:keys){
    for(auto lock:locks){
	bool hasOverlap = false;
	for(int i = 0 ;i < key.size(); i++){
	    if(key[i]+lock[i]>5){
		    hasOverlap=true;
		    break;
	    }
	}
	if(!hasOverlap)res++;
    }
 }
 return res;
}
int main(){
    cout << solve() <<endl;
  return 0;
}
