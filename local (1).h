#include <stdio.h>
#include <unistd.h>
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))
#define COMPARE(x,y) (((x)<(y)) ? -1 : ((x)==(y)) ? 0 : 1)
#define MALLOC(p,s) if (!((p)=malloc((s)))) { \
		fprintf(stderr, "Insuffient Memory"); }

#define ANSI_RESET    		"\x1b[0m"	// 출력 속성 리셋
#define ANSI_BOLD		    "\x1b[1m"
#define ANSI_UNDERSCORE	    "\x1b[4m"	
#define ANSI_BLINK		    "\x1b[5m"	// mono display only
#define ANSI_REVERT		    "\x1b[7m"
#define ANSI_FG_BLACK      	"\x1b[30m"	// 이하 글자색
#define ANSI_FG_RED      	"\x1b[31m"
#define ANSI_FG_GREEN    	"\x1b[32m"
#define ANSI_FG_YELLOW   	"\x1b[33m"
#define ANSI_FG_BLUE     	"\x1b[34m"
#define ANSI_FG_MAGENTA  	"\x1b[35m"
#define ANSI_FG_CYAN     	"\x1b[36m"
#define ANSI_BG_BLACK      	"\x1b[40m"	// 이하 배경색

#define ClearTERM()				printf("\033c")
#define ClearLINE(n)			printf("%*c", (n), ' ')
// #define MoveCURSOR(row, col) 	printf("\033[%dd\033[%dG", (row), (col))
#define MoveCURSOR(row, col) 	printf("\033[%d;%df", (row), (col))

int wait(int opt)
{	// opt==0 wait for Enter key, otherwise sleep for opt seconds.
	static char c = '\n';
	if (c == '.') opt = 1; 
	if (opt)
	{
		printf("\n");
		sleep(opt);
	}
	else
	{
		for (c = getchar(); c != '\n' && c != '.' && c != ','; c = getchar()) ;
		if (c == '.' || c == ',') getchar();
	}// if '.' is pressed once, waiting for Enter key is not applied any longer.
	return(opt);
}

char prompt(char *msg, char *opt)
{
	char gc, oc, *s;
	while (1)
	{
		s = opt;
		printf("%s", msg);
		for (oc=*s, gc=getchar(); oc && oc != gc; oc=*(++s))	; 
		if (oc) return(oc);
		if (gc != '\n') getchar();
	}
}


/*
[0m  : 모든 색과 스타일 초기화
[1m  : 굵게(bold) / 밝게
[3m  : 이탤릭체(italic)
[4m  : 밑줄(underline)
[7m  : 반전(글자색/배경색을 거꾸로)
[9m  : 가로줄 치기
[22m : 굵게(bold) 제거
[23m : 이탤릭체(italic)제거
[24m : 밑줄(underline)제거
[27m : 반전 제거
[29m : 가로줄 제거
[30m : 글자색:검정
[31m : 글자색:빨강
[32m : 글자색:초록
[33m : 글자색:노랑
[34m : 글자색:파랑
[35m : 글자색:마젠트(분홍)
[36m : 글자색:시안(청록)
[37m : 글자색:백색
[39m : 글자색으로 기본값으로
[40m : 바탕색:흑색
[41m : 바탕색:적색
[42m : 바탕색:녹색
[43m : 바탕색:황색
[44m : 바탕색:청색
[45m : 바탕색:분홍색
[46m : 바탕색:청록색
[47m : 바탕색:흰색
[49m : 바탕색을 기본값으로

---------- 커서 이동 --------------
ESC[pr;pcH    –   좌표 (pr, pc)로 이동할때
ESC[pr;pcf    –   ”

ESC[pnA       –   pn줄 만큼 위로
ESC[pnB       –   pn줄 만큼 아래로
ESC[pcC       –   pc칸 만큼 오른쪽으로               
ESC[pcD       –   pc칸 만큼 왼쪽으로
*/