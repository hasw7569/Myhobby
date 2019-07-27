#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int N, indegree[26];
vector<int> vt[26];
bool check[26];
int main() 
{
 	char input[100][11];
  	scanf("%d", &N);
  	for (int i = 0; i<N; i++) {
 		scanf("%s", input[i]);
 		for (int j = 0; input[i][j]; j++)
  			check[input[i][j] - 'a'] = true;
	}

  	for (int i = 0; i<N - 1; i++) {
  		for (int j = 0; input[i][j] && input[i + 1][j]; j++) {
  			if (input[i][j] != input[i + 1][j]) {
  				vt[input[i][j] - 'a'].push_back(input[i + 1][j] - 'a');
  				indegree[input[i + 1][j] - 'a']++;
  				break;
			}
		}
	}

  	int cnt = 0;
 	queue<int> Q;
 	for (int i = 0; i<26; i++) {
  		if (check[i]) {
  			cnt++;
  			if (indegree[i] == 0) Q.push(i);
		}
	}
 	char res[27] = { 0 };
  	bool multi = false;
  	for (int i = 0; i<cnt; i++) {
  		if (Q.empty()) {
  			puts("!");
  			return 0;
		}
  		if (Q.size() > 1) multi = true;

 		int curr = Q.front();
 		Q.pop();
  		res[i] = 'a' + curr;
  		for(int i = 0; i<vt[curr].size(); i++)
  			if (--indegree[vt[curr][i]] == 0) Q.push(vt[curr][i]);
	}
 	puts(multi ? "?" : res);
}
