#include<stdio.h>
struct Trie
{
	Trie* trie[10];
	bool finish;
	Trie()
	{
		finish = 0;
		for (int i = 0; i < 10; i++)
			trie[i] = 0;
	}
	~Trie()
	{
		for (int i = 0; i < 10; i++)
			delete trie[i];
	}
	bool find(const char* pos)
	{
		if (*pos != '\0' && finish) return true;
		if (*pos == '\0' && finish) return false;
		if (trie[*pos - '0'] != NULL)
			return trie[*pos - '0']->find(pos + 1);
	}
	void insert(const char* pos)
	{
		if (*pos == '\0')
		{
			finish = 1;
			return;
		}
		else
		{
			if (trie[*pos - '0'] == NULL)
				trie[*pos - '0'] = new Trie();
			trie[*pos - '0']->insert(pos + 1);
		}
	}
};
int t, n;
char input[10000][11];
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		Trie res;
		scanf("%d", &n);
		bool flag = 0;
		for (int i = 0; i < n; i++)
		{
			scanf(" %s", &input[i]);
			res.insert(input[i]);
		}
		for (int i = 0; i < n; i++)
		{
			if (res.find(input[i])) flag = 1;
		}
		if (flag) printf("NO\n");
		else printf("YES\n");
	}

	return 0;
}