#include<stdio.h>
int t,n;
int a[1010];
int b[1010];
void func(int a_lo, int a_hi, int b_lo, int b_hi)
{
	if (a_lo > a_hi) return;
	int next = b[a[a_lo]]; // ���� preorder���� �����ִ� ������ȣ�� inorder���� ���°�� �ִ��� Ȯ��
	// inorder���� next �տ� �ε������� ���� left subtree�� ����
	func(a_lo + 1, a_lo + (next - b_lo), b_lo, next-1); // b_lo ~ next-1 ���� ���� subtree, ���� preorder ���� �����̹Ƿ� a_lo+1 ���ְ�, a_lo���� next-b_lo�� �����̹Ƿ� a_lo + next - b_lo
	func(a_lo + (next - b_lo)+1, a_hi, next + 1, b_hi); // next+1 ~ b_hi���� ������ subtree, ���� ����Ʈ�� ���� preorder���� a_lo ~ a_lo + next - b_lo ���� �����Ƿ�, a_lo + next-b_lo+1
	printf("%d ", a[a_lo]);
}
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		int temp;
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &temp);
			b[temp] = i; // �ش簪�� ���° �ε����� �ִ��� ����
		}

		func(0, n - 1, 0, n - 1);
		printf("\n");
	}


	return 0;
}