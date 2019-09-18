#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
vector<int> G[1005];
bool vis[1005];
int delpoint;
void dfs(int a)
{
	if (a == delpoint) return;
	vis[a] = true;
	for (int i = 0; i<G[a].size(); i++)
	{
		if (vis[G[a][i]] == false)
		{
			dfs(G[a][i]);
		}
	
	}
}
int main(){
	int m;
	int k;
	int n;
	
	int a;
	int b;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++)
	{
		
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for (int j = 0; j < k; j++)
	{
		scanf("%d", &delpoint);
		memset(vis, false, sizeof(vis));
		int block = 0;
		for (int i = 1; i <= n; i++)
		{
			if (vis[i] == false && delpoint != i)
			{
				dfs(i);
				block++;
			}

		}
		printf("%d\n", (block - 1));   //非连通区域数减一即为边数量
	}
	return 0;
}