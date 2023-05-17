#include<stdlib.h>
#include<stdio.h>

char **ft_split(char *str) {
	printf("%s\n", str);
	int i = 0;
	int a = 0;
	int b = 0;
	char ch;
	while (str[i] != ' ' && str[i] != '\n' && str[i] != '\t') {	i++;}
	a = i;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {	i++;}
	while (str[i + b] != '\0') {	b++;	}
	
	//static char **ans = { (char*) malloc(a+1),  (char*) malloc(b + 1)};
	char *A = (char*) malloc(a + 1);
	char *B = (char*) malloc(b + 1);
	
	int j = 0;
	while (str[i] != '\0') {
		if (j >= b) {
			printf("not enough A\n");
		}
		ch = str[i];
		B[j] = ch;
		i++; j++;
	}
	B[j] = '\0';
	i = 0;
	while (str[i] != ' ' && str[i] != '\n' && str[i] != '\t') {
		if (i >= a) {
			printf("not enough A\n");
		}
		ch = str[i];
		A[i] = ch;
		i++;
	}
	A[i] = '\0';
	
	//ans[0] = &str[0];
	
	
	//char *ans[] = {A, B};
	
	char ** ans = (char**) malloc(sizeof(char*) * 2);
	ans[0]=A;
	ans[1]=B;
	return ans;
}