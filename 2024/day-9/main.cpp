#include <bits/stdc++.h>
using namespace std;
int main(){
   string message;
   vector<int> uncompressed;
   cin >> message;
   int i = 0;
   while(i < message.size()){
	string dig = to_string(i/2);
	for(int ii = 0 ; ii <message[i]-'0'; ii++) uncompressed.push_back(i/2);
	i++;
	if(i>=message.size())break;
	for(int ii = 0 ; ii <message[i]-'0'; ii++) uncompressed.push_back(-1);
	i++;
   }
   i = 0; int j = uncompressed.size()-1;
   while(i<j){
      while(i<j && uncompressed[i]!=-1)i++;
      while(i<j && uncompressed[j]==-1)j--;
      if(i>j)break;
      swap(uncompressed[i], uncompressed[j]);
      i++,j--;
   }
   unsigned long long res = 0;
   for(int i = 0 ; i< uncompressed.size(); i++){
	   if(uncompressed[i]==-1)break;
	   res+= i*(uncompressed[i]);
   }
   cout <<res <<endl;
   return 0;
}
