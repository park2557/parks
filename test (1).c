#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct test * testP;
typedef struct test {
	int 	i;
	int		j;
	testP	l;
} test;

testP 	queue[10];
int		front = -1, rear = -1;

void addq(int *rear, test t)
{
	test *tmp = (test *)malloc(sizeof(test));
	tmp->i = t.i;
	tmp->j = t.j;
	queue[++(*rear)] = tmp;
}

test deleteq(int *front)
{
	test	t, *tmp;
	tmp = queue[++(*front)];
	t.i = tmp->i;
	t.j = tmp->j;
	return t;
}

#define MALLOC(p,s) \
	if (!((p)=malloc((s)))) { \
		fprintf(stderr, "Insuffient Memory"); \
	}

void main()
{
	int idx;
	test t;
	testP t1, t2;
	char string[] = "Hi students, 	 2 students of all students study hard.";
	char *token;
	char delim[] = " ,.\t";
	
	MALLOC(t1, sizeof(*t1));
	t2 = (testP)malloc(sizeof(*t1));
	t1->i = 1;
	t1->j = 2;
	t2->i = 3;
	t2->j = 4;
	
	t.i = 1;
	t.j = 1;
	
	addq(&rear, t);
	
	t.i = 2;
	t.j = 2;
	addq(&rear, t);
	
	while (front != rear)
	{
		t = deleteq(&front);
		printf("i: %d j: %d\n", t.i, t.j);
	}
	printf("i: %d j: %d\n", t1->i, t1->j);
	printf("i: %d j: %d\n", t2->i, t2->j);
	
	// token = strtok(string, delim);
	// while(token)
	// {
	// 	printf("%s\n", token);
	// 	token = strtok(NULL, delim); 
	// }
	idx = 4;
	printf("string[%d] : %c\n", idx, string[idx]); // string[idx] == *(string+idx) == *(idx+string) == idx[string]
	printf("string[%d] : %c\n", idx, *(string+idx)); // string[idx] == *(string+idx) == *(idx+string) == idx[string]
	printf("string[%d] : %c\n", idx, idx[string]); // string[idx] == *(string+idx) == *(idx+string) == idx[string]
}