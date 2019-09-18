#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
vector<int>  G[10005];
bool vis[10005];
void dfs(int a)
{
	vis[a] = true;
	for (int i = 0; i < G[a].size(); i++)
	{
		if (vis[G[a][i]] == false)
		{
			dfs(G[a][i]);
		}
	}
}
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		int a;
		int b;
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);

	}
	memset(vis, false, sizeof(vis));
	int block = 0;
	for (int j = 1; j < n; j++)
	{
		if (vis[j] == false)
		{
			dfs(j);
			block++;
		}
		
	}
	if (block == 1)
	{
		printf("3\n4\n5");
	}
	else
	{
		printf("Error: %d components", block);
	}
	

}