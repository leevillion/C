/**
 * delete comments
 */
#include <stdio.h>
int main(){
	char ch;
	int inQuote;
	int preStart;
	int start;
	int preEnd;
	inQuote=preStart=start=preEnd=0;
	while((ch=getchar())!=EOF){
		if(ch=='"'){
			putchar(ch);
			inQuote=1;
		}
		else if(ch=='/' && inQuote==0 && preEnd==0)
			preStart=1;
		else if(ch=='*' && preStart==1){
			start=1;
			preStart=0;
		}
		else if(inQuote==1 && ch=='"'){
			putchar(ch);
			inQuote=0;
		}
		else if(ch=='*' && start==1){
			preEnd=1;
		}
		else if(ch=='/' && preEnd==1){
			start=0;
			preEnd=0;
		}
		else if(start==1){
		
		}
		else
			putchar(ch);

	}

	return 0;
}
