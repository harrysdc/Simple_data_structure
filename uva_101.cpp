#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>						    // header file for using vector 
using namespace std;
const int maxn = 30;
int n;
vector<int> pile[maxn];

void find_block(int a, int &p, int &h)
{
	for(p=0 ; p<n ; p++)					// loop for each pile
		for(h=0 ; h<pile[p].size() ; h++)	// loop for each element in a single pile
			if(pile[p][h] == a) return;
}

void clear_above(int p, int h)
{
	for(int i = h+1 ; i<pile[p].size() ; i++){ // h+1 means "above"
		int b = pile[p][i];
		pile[b].push_back(b);				// push=add  back=in the rear of vector
	}										// also refered: vec.pop_back()
	pile[p].resize(h+1);					// resize original pile to 0~h element
}

void pile_over(int p, int h, int p2)
{
	for(int i=h ; i<pile[p].size() ; i++)	// moves the pile of blocks consisting of block a and...
		pile[p2].push_back(pile[p][i]);
	pile[p].resize(h);
}

void print()
{
	for(int i=0 ; i<n ; i++){
		printf("%d:",i);
		for(int j=0 ; j<pile[i].size() ; j++)	printf(" %d", pile[i][j]);
	printf("\n");
	}
}

int main()
{
	int a, b;
	cin >> n;
	string s1, s2;
	for(int i = 0 ; i<n ; i++) pile[i].push_back(i);	// new each pile with one block
	
	while(cin >> s1 >> a >> s2 >> b){					// read one line and react
		if(s1 == "quit") printf("!!!\n");
		int pa, pb, ha, hb;
		find_block(a,pa,ha);			// a: desired num, pa: pile# of a, ha: height of pile containg a
		find_block(b,pb,hb);
		if(pa == pb) 	 continue;			// ignore illegal cmd
		if(s2 == "onto") clear_above(pb, hb);
		if(s1 == "move") clear_above(pa, ha);
		pile_over(pa, ha, pb);
	}
	
	print();
	
	system("pause");
	return 0;
}
