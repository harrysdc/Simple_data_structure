#include<iostream>
#include<cstdio> 
#include<algorithm>
using namespace std;

const int maxn = 10000;

int main()
{
	int n, q, x, p, a[maxn], kase = 0, i;
	
	while(scanf("%d %d", &n, &q) == 2 && n)			// If successful, the total number of characters written is returned
	{	
		for(i=0 ; i<n ; i++)	scanf("%d",&a[i]);
		sort(a,a+n);								
		while(q--){
			scanf("%d",&x);
			p = lower_bound(a, a+n, x) - a;			// lower_bound: find "the first position" which is bigger than or equal to x
			
			printf("CASE# %d:\n",++kase);
			if(a[p] == x)	printf("%d found at %d\n",x,p+1);
			else 			printf("%d not found\n");
		}
	}
	
	system("pause");
	return 0;
}
