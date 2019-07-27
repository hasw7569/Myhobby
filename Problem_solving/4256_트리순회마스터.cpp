#include<stdio.h>
int t,n;
int a[1010];
int b[1010];
void func(int a_lo, int a_hi, int b_lo, int b_hi)
{
	if (a_lo > a_hi) return;
	int next = b[a[a_lo]]; // 현재 preorder에서 보고있는 정점번호가 inorder에서 몇번째에 있는지 확인
	// inorder에서 next 앞에 인덱스들은 전부 left subtree에 속함
	func(a_lo + 1, a_lo + (next - b_lo), b_lo, next-1); // b_lo ~ next-1 까지 왼쪽 subtree, 다음 preorder 순서 볼것이므로 a_lo+1 해주고, a_lo부터 next-b_lo개 볼것이므로 a_lo + next - b_lo
	func(a_lo + (next - b_lo)+1, a_hi, next + 1, b_hi); // next+1 ~ b_hi까지 오른쪽 subtree, 왼쪽 서브트리 볼떄 preorder에서 a_lo ~ a_lo + next - b_lo 까지 봤으므로, a_lo + next-b_lo+1
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
			b[temp] = i; // 해당값이 몇번째 인덱스에 있는지 저장
		}

		func(0, n - 1, 0, n - 1);
		printf("\n");
	}


	return 0;
}