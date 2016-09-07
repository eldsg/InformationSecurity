#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

int main(){
	int num;
	string ret;
	printf("input num of string : \n");
	scanf("%d", &num);
	for(int i = 0; i<num; i++){
		char temp[1000];
		scanf("%s", temp);
		ret += "\"";
		ret += temp;
		ret += "\"";
		if(i!=num-1) ret += ",";
	}
	cout << ret << endl;
}
