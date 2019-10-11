#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int len = 0;
typedef struct node {
	int data;
	node* next;
}node; 

typedef struct stack {
	node* top;
}Stack;

int empty(Stack* s) {
	if (s->top == NULL)
		return 1;
	else
		return 0;
}
void push(Stack *s,int number) {
	node* newstack = (node*)malloc(sizeof(node));
	if (newstack == NULL) {
		printf("�������� �����Ͽ����ϴ�.\n");
		return;
	}
	newstack->data = number;
	if (empty(s))
		newstack->next = NULL;
	else
		newstack->next = s->top;
	s->top = newstack;//�� ��带 �������� ���� ����
	len++;
}
int pop(Stack *s) {
	node *newstack;
	int pop;
	if (empty(s))
		return -1;
	else {
		newstack = s->top;
		pop = newstack->data;
		s->top = newstack->next;
	}
	len--;
	free(newstack);
	return pop;
}
int topnum(Stack *s) {
	if (empty(s) == 1)
		return -1;
	else
		return s->top->data;
}
void Initstack(Stack* s) {
	s->top = NULL;
}
int size() {
	return len;
}
void allprint(Stack* S) {
	printf("���� �Էµ� ���� : ");
	node* all = S->top;
	while (all != NULL) {
		printf("%3d", all->data);
		all = all->next;
	}
	printf("\n");
}
int main() {
	Stack *s = (Stack *)malloc(sizeof(stack));
	char a[80];
	const char* b[80] = { "push","pop","size","empty","top","exit" };
	int num;
	Initstack(s);
	do {
		printf("��ɾ �Է��� �ּ���(push, pop, size, empty, top, exit)\n");
		scanf("%s", a);
		if (strcmp(a, b[0]) == 0) {
			printf("������ �Է��� �ּ���\n");
			scanf("%d", &num);
			push(s, num);
			allprint(s);
		}
		else if (strcmp(a, b[1]) == 0) {
			printf("%d\n", pop(s));
			allprint(s);
		}
		else if (strcmp(a, b[2]) == 0) {
			printf("���ÿ� ����ִ� ������ ���� : %d\n", size());
			allprint(s);
		}
		else if (strcmp(a, b[3]) == 0) {
			printf("%d\n", empty(s));
			allprint(s);
		}
		else if (strcmp(a, b[4]) == 0) {
			printf("������ ���� ���� �ִ� ���� : %d\n", topnum(s));
			allprint(s);
			if (topnum(s) == -1)
				printf("������ ������ϴ� %d\n", topnum(s));
		}
		else if (strcmp(a, b[5]) == 0)
			break;
	} while (1);
	free(s);
	return 0;
}