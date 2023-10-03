#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MALLOC(p,s) \
	if (!((p)=malloc((s)))) { \
		fprintf(stderr, "Insuffient Memory"); \
	}

void arr_ptr_byCases()
{
    int a[3][4] = {{11, 12, 13, 14}, 
				   {21, 22, 23, 24},
				   {31, 32, 33, 34}};
	int *p = &a[0][0];  // a[0][0]; 
	
	int (*q)[4] = &a[0]; // &a a[0] &a[0]
	printf("%d\n", **(q+1));
	
	//int *q=&a;
	char *fmt1 = "%11s: %16ld => %s\n";	
    printf("----------------------------------------------------------------\n");
    printf(fmt1, "a", (long int)a, "배열 a의 값(주소상수): 첫 요소의 주소값"); // 배열명의 값
    printf(fmt1, "&a", (long int)&a, "배열 a의 주소값");  // 배열의 주소값
    printf(fmt1, "&a[0][0]", (long int)&a[0][0], "배열 a의 첫행, 첫열 공간의 주소");
    printf(fmt1, "a[0]", (long int)a[0], "배열 a의 첫행 배열의 값(배열주소상수)");
    printf(fmt1, "&a[0]", (long int)&a[0], "배열 a의 첫행 배열의 주소값");
    printf("----------------------------------------------------------------\n");
    printf(fmt1, "a+1", (long int)(a+1), "배열 a의 첫행의 다음 행 배열명 값");
    printf(fmt1, "&a[0][0]+1", (long int)(&a[0][0]+1), "배열 a의 첫행의 두번째열 주소 값");
    printf(fmt1, "a[0]+1", (long int)(a[0]+1), "배열 a의 첫행 배열의 두번째열 주소 값");
    printf(fmt1, "&a[0]+1", (long int)(&a[0]+1), "배열 a의 첫행 배열 주소값에 대한 다음 요소 주소 값");
    printf("----------------------------------------------------------------\n");
    printf(fmt1, "a", (long int)a, "배열 a의 값(주소상수): 첫 요소의 주소값"); // 배열명의 값
    printf(fmt1, "*a", (long int)*a, "배열 a주소를 역참조한 위치요소(첫행배열)의 첫공간 주소"); // 배열명의 값
    printf(fmt1, "*a+1", (long int)(*a+1), "배열 a주소를 역참조한 위치요소(첫행배열)의 주소를 한 단위 이동"); // 배열명의 값
    printf(fmt1, "**a", (long int)**a, "배열 a주소를 역참조한 위치요소(첫행배열)의 주소를 다시 역참조 값"); // 배열명의 값
    printf(fmt1, "&a+1", (long int)(&a+1), "배열 a의 주소(a 자체)를 한 단위 증가"); // 배열명의 값
    printf(fmt1, "***(&a)", (long int)***(&a), "배열 a의 주소(a 자체)를 역참조>역참조>역참조"); // 배열명의 값
    printf(fmt1, "***(&a+1)", (long int)***(&a+1), "배열 a의 주소(a 자체)를 한 단위 증가 후 역참조 3번"); // 배열명의 값
    printf("----------------------------------------------------------------\n");
    printf(fmt1, "&a[2][3]", (long int)&a[2][3], "a[2][3]의 주소값"); 
    printf(fmt1, "a[2]", (long int)a[2], "a의 세번째 행 배열 의미, 3행 배열 첫 공간 주소값"); 
    printf(fmt1, "a[2]+3", (long int)(a[2]+3), "a의 세번째 행 배열의 3번 열이동, a[2][3] 주소값");
    printf(fmt1, "a+2", (long int)(a+2), "a의 행 배열을 2번 열이동, a의 세번째 행배열 주소값");
    printf(fmt1, "a+2+3", (long int)(a+2+3), "a의 행 배열을 2번 행 이동 후 또 3번 행 이동, a[5]의 주소");
    printf(fmt1, "*(a+2)+3", (long int)(*(a+2)+3), "a의 행 배열을 2번 행 이동 후 역참조(3번 행배열) 후, 열 3번 이동한 주소");
    printf(fmt1, "a[2][3]", (long int)a[2][3], "a[2][3]의 값"); 
    printf(fmt1, "*(*(a+2)+3)", (long int)*(*(a+2)+3), "a[2][3]의 값");
    printf(fmt1, "*(a[2]+3)", (long int)*(a[2]+3), "a[2][3]의 값");
}

void make1dArray()
{
	int i, n, *list;
	
	printf("Enter the size of 1-Dim array: ");
	scanf("%d", &n);
	
	MALLOC(list, n*sizeof(int));
	for (i = 0; i < n; i++)
		list[i] = rand()%1000;
	for (i = 0; i < n; i++)
		printf("%d ", *(list+i));
	printf("\n");
}

void make2dArray()
{
	int i, j, val=0, rows, cols, **list;
	
	printf("Enter the row-size of 2-Dim array: ");
	scanf("%d", &rows);
	printf("Enter the column-size of 2-Dim array: ");
	scanf("%d", &cols);
	
	// get memory for row pointers
	MALLOC(list, rows*sizeof(*list));
	for (i = 0; i < rows; i++)
		MALLOC(list[i], cols*sizeof(**list));
	
	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++)
			list[i][j] = val++; // rand()%1000;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
			printf("%d ", *(*(list+i)+j)); // rand()%1000;
		printf("\n");
	}
	printf("\n");
}

void main() {
	arr_ptr_byCases();
	// make1dArray();
	// make2dArray();
}