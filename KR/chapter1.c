#include <stdio.h>
int main(){
	void printHistfram();
	printHistfram();
	return 0;
}
//1-6 verify that getchar()!=EOF is 0 or 1
void verifyEOF(){
	int c;
	while(c=(getchar()!=EOF))
		printf("getchar()!=EOF is %d\n",c);
	printf("getchar()==EOF is %d\n",c);
}
//1-7 print EOF
void printEOF(){
	printf("EOF is %d\n",EOF);
}

//1-8 count blank,tab and newline
void countBTN(){
	int c,iBlank,iTab,iNewline;
	iBlank=0;iTab=0;iNewline=0;
	while((c=getchar())!=EOF){
		if(c=='\n')
			iNewline++;
		else if(c=='\t')
			iTab++;
		else if(c==32)
			iBlank++;
	}
	printf("newline=%d,tab=%d,blank=%d",iNewline,iTab,iBlank);

}


//1-9 replace string with single blank
void replaceWithSingleBlank(){
	int c,preBlank;
	preBlank=0;
	while((c=getchar())!=EOF){
		if(c==32&&preBlank==0){
			putchar(c);
			preBlank=1;
		}else if(c!=32){
			putchar(c);
			preBlank=0;
		}else if(c==32&&preBlank==1){
			
		}
	}
	
}
//1-12 print word per line
void printWordPreLine(){
	int ch,state;
	state=0;
	while((ch=getchar())!=EOF){
		if(ch==32||ch=='\n'||ch=='\t'){
			state=0;
		}else if(state==0){
			state=1;
			putchar('\n');
		}
		if(state==1)
			putchar(ch);
	}
}

//1-13 print a histofram of the lengths of words
void printHistfram(){
	int wordsArry[10],i,y,x,ch,state,lengthCount,wordCount;
	state=wordCount=0;
	for(i=0;i<=9;i++)
		wordsArry[i]=0;
	while((ch=getchar())!=EOF){
		if(ch==32||ch=='\n'||ch=='\t'){
			state=0;
		}else if(state==0){
			state=1;
			wordCount++;
		}
		if(state==1){
			wordsArry[wordCount]++;
		}
	}
	printf("\n");
	for(i=1;i<=9;i++){
		if(wordsArry[i]==0)
			break;
		printf("%d",i);
		for(lengthCount=1;lengthCount<=wordsArry[i];lengthCount++){
			printf("*");
		}
		printf("\n");
	}
	for(y=9;y>=1;y--){
		printf("%d",y);
		for(x=1;x<=i;x++){
			if(wordsArry[x]>=y)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}

}
