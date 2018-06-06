#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
	int i, T, b, len, g;
	char s[80];
	double mass, atom, result[100];		// even .3f cannot use float
	
	scanf("%d",&T);
	g = T-1;
	while(T--)					// loop for all molecular formula
	{
		scanf("%s",s);
		len = strlen(s);
		mass = 0;
		atom =0;
		
		for(i=0 ; i<len ; i++)
		{
			if(isalpha(s[i])){			
				mass+=atom*b;						// everytime you meet a new char is the time to sum all
				
				if(s[i]=='C')       atom = 12.01;	// an readable alternative for 'switch'
				else if(s[i]=='H')  atom = 1.008;
				else if(s[i]=='O')  atom = 16.00;
				else if(s[i]=='N')  atom = 14.01;
				b = 1;								// default quantity: assume one molecular
			}
			else if(isdigit(s[i])){
				if(isdigit(s[i-1]))
					b = b*10+s[i]-'0';
				else
					b = s[i]-'0';					// int = char
			}
		}
		mass=mass+atom*b;							// to dance with fetter
		result[g-T] = mass;
	}
	
	for(i=0 ; i<g+1 ; i++)
		printf("%.3f\n",result[i]);
	
	system("pause");
	return 0;
}
