#include <bits/stdc++.h>
using namespace std;
bool isNumber(string &st){
   if(st.empty())return false;
   for(auto i:st)if(!isdigit(i)) return false;
   return true;
}
int main(){
   string st, text="";
   while(cin >> st){
	text += st;
   }
   long long total_sum = 0;
   int i = 0;
   bool doit=true;
   while(i<text.size()){
	if("do()" == text.substr(i, 4)) doit=true;
	if("don't()" == text.substr(i, 7)) doit=false;
        if( doit && "mul(" == text.substr(i, 4)){
	   int j = i+4;
	   string num1 = "", num2 = "";
	   while( j < text.size() && isdigit(text[j])){
		   num1 += text[j++];
	   }
	   if(j<text.size() && text[j]!=','){
		   i++; continue;
	   }
	   j++;
	   while( j < text.size() && isdigit(text[j])){
		   num2 += text[j++];
	   }
	   if(isNumber(num1) && isNumber(num2) && j<text.size() && text[j]==')'){
		   total_sum += stoi(num1)*stoi(num2);
		   i=j;
	   }
	}
	i++;
   }
   cout << total_sum <<endl;
   return 0;
}
