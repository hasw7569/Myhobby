#include<stdio.h>
int n;
int graph[26][2];
void preorder(int curr)
{
	printf("%c", 'A' + curr);
	if (graph[curr][0] != 0) preorder(graph[curr][0]);
	if (graph[curr][1] != 0) preorder(graph[curr][1]);
}
void inorder(int curr)
{
	if (graph[curr][0] != 0) inorder(graph[curr][0]);
	printf("%c", 'A' + curr);
	if (graph[curr][1] != 0) inorder(graph[curr][1]);
}
void postorder(int curr)
{
	if (graph[curr][0] != 0) postorder(graph[curr][0]);
	if (graph[curr][1] != 0) postorder(graph[curr][1]);
	printf("%c", 'A' + curr);
}
int main()
{
	scanf("%d", &n);
	char par, l, r;
	for (int i = 0; i < n; i++)
	{
		scanf(" %c %c %c", &par, &l, &r);
		if (l != '.')
			graph[par - 'A'][0] = l - 'A';
		if (r != '.')
			graph[par - 'A'][1] = r - 'A';
	}
	preorder(0);
	printf("\n");
	inorder(0);
	printf("\n");
	postorder(0);
	printf("\n");
	return 0;
}