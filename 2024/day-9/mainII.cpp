#include <bits/stdc++.h>
using namespace std;
string message;
vector<tuple<int, bool, int>> encoded, compact_message;//val, dot, index

void compact(){
   int n = message.size();
   compact_message = encoded;
   for(int r = compact_message.size()-1; r>=0; r--){
       auto &[valR, isDotR, indexR] = compact_message[r];
       if(isDotR)continue;
       int l = 0;
       while( l < r){
	   auto &[valL, isDotL, indexL] = compact_message[l];
	   if(isDotL && valL >= valR ) break;
	   l++;
       }
       if(l==r)continue;
       auto &[valL, isDotL, indexL] = compact_message[l];
       if( valL == valR){
	    isDotL = false;
	    isDotR = true;
	    swap(indexR, indexL);
	    continue;
       }
       isDotR = true;
       valL -= valR;
       compact_message.insert(compact_message.begin() + l, {valR, false, indexR});
   }
}
void read_message(){
   cin >> message;
   for(int i = 0 ; i < message.size(); i++){
      int val = 0;
      if(i%2==0)val=i/2;
      encoded.push_back({message[i]-'0', (i%2)==1, val});
   }
}
vector<int> encoded_message(){
   vector<int>encoded;
   int index = 0;
   for(auto i = 0; i < compact_message.size(); i++){
      auto [_size,isDot, val] = compact_message[i];
      for(int j = 0; j < _size; j++) encoded.push_back(isDot?0:val);
   }
   return encoded;
}
int main(){
   read_message();
   compact();
   auto encoded = encoded_message();
   long long res = 0;
   for(int i = 0 ; i < encoded.size(); i++){
      res += encoded[i]*i;
   }
   cout << res <<endl;
   return 0;
 
}
/*
  *   *   *   *   *   *   *   *   *
2 3 3 3 1 3 3 1 2 1 4 1 4 1 3 1 4 0 2

2 2 1 3 3 1 3 4 4 4


2 3 2
1 0 1 1 1 1 1 1 0


 * */
