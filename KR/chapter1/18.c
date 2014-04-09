#include <stdio.h>
#define MAX 1000
int removeT(char string[]);
int getLine(char string[],int max);
int main(){
	char str[MAX];
	while(getLine(str,MAX)>0){
		if(removeT(str)>0)
			printf("%s",str);
	}

	return 0;
}

int getLine(char string[],int max){
	int count;
	char ch;
	for(count=0;(ch=getchar())!=EOF && ch!='\n';count++){
		if(count<max-2)
			string[count]=ch;
	}
	if(ch=='\n'){
		string[count]=ch;
		count++;
	}
	string[count]='\0';
	return count;
}
int removeT(char string[]){
	int length;
	length=0;
	while(string[length]!='\n')
		length++;
	length--;
	while(length>0 && (string[length]==' ' || string[length]=='\t'))
		length--;
	if(length>0){
		length++;
		string[length]='\n';
		length++;
		string[length]='\0';
	}
	return length;
}
