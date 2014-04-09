#include <stdio.h>
#define LONG 10
#define MAX 1000
int getLIne(char string[],int max);
int main(){
	char inputLine[MAX];
	int count;
	while((count=getLine(inputLine,MAX))>0){
		if(count>LONG)	
			printf("%s",inputLine);
	}
	return 0;
}

int getLine(char string[],int max){
	int count;
	char ch;
	for(count=0;(ch=getchar())!=EOF && ch!='\n';count++)
	{  if(count<max-2)
			string[count]=ch;
		
	}
	if(ch=='\n'){
		string[count]=ch;
		count++;
	}
	//this sentence is very important
	//if not this sentence,can not judge the end position of string
	string[count]='\0';
	return count;
}
