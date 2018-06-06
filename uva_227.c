#include<stdio.h>
#include<string.h>

char puzzle[5][5];

void display(int num)		
{	// to display the puzzle
	int i, x, y;
	
	printf("Puzzle #%d:\n",i);
	for(y=0 ; y<5 ; y++){
		for(x=0 ; x<5 ; x++)
			printf("%c ",puzzle[y][x]);
		printf("\n");	
	}
	printf("\n");
}

void swap(char puzzle[][5], int a, int b, int c, int d)	
{	// to swap two squares
	char temp;
	temp = puzzle[a][b];
	puzzle[a][b] = puzzle[c][d];
	puzzle[c][d] = temp;
}

int main(void)
{
	int y, x, cmd_end, len, blank_y, blank_x, i, t = 0, error;
	char cmd[100];
	
	while(1)
	{
		error = 0;
		for(y=0 ; y<5 ; y++)					// read puzzle
			fgets(puzzle[y], 10, stdin);		// logically I cannot understand why it works
	
		for(y=0 ; y<5 ; y++){					// find whitespace
			for(x=0 ; x<5 ; x++){
				if(puzzle[y][x] == ' '){
					blank_y = y;
					blank_x = x;
				}
			}
		}
		
		cmd_end=0;
		while(!cmd_end){						// read cmd
			fgets(cmd, 100, stdin);
	
			len = strlen(cmd);
			for(i=0 ; i<len ; i++){				// cmd's manipulations
				if(cmd[i] == 'A'){
					swap(puzzle, blank_y, blank_x, blank_y-1, blank_x);
					blank_y-=1; 
				}else if(cmd[i] == 'B'){
					swap(puzzle, blank_y, blank_x, blank_y+1, blank_x);
					blank_y+=1;
				}else if(cmd[i] == 'L'){
					swap(puzzle, blank_y, blank_x, blank_y, blank_x-1);
					blank_x-=1;
				}else if(cmd[i] == 'R'){
					swap(puzzle, blank_y, blank_x, blank_y, blank_x+1);
					blank_x+=1;
				}else if(cmd[i] == '0'){
					cmd_end = 1;
				}
				
				if(blank_y<0 || blank_y>4)
					error = 1;
				if(blank_x<0 || blank_x>4)
					error = 1;
			}			
		}
		
		if(!error){
			display(1);
		}else
			printf("This puzzle has no final configuration.\n");
	}
				
	system("pause");
	return 0;
}
