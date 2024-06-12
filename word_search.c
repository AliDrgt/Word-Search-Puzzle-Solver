#include <stdio.h>
#define row 15
#define column 12

void printPuzzle(char matrix[row][column]){
	int a, b, c;
	c = 0;
	for(a = 0; a < row; a++){
		for(b = 0; b < column; b++){
			printf("%c ", matrix[a][b]);
			c++;
			if(c == column){
				printf("\n");
				c = 0;
			}
		}
	}
}

int computeLength(char string[]){
	int a, count = 0;
	for(a = 0; string[a] != '\0'; a++){
		count++;
	}
	return count;
}

int findString(char matrix[row][column], char string[column], int length){
	int a, b, c, count, e, d;
	c = 0;
	count = 1;
	
	// Search right
	for(a = 0; a < row; a++){ 
		for(b = 0; b < column; b++){
			c = 0;
			if(string[c] != matrix[a][b]){
				continue;
			}
			else if(string[c] == matrix[a][b]){ 
				count = 1;
				d = b;
				for(e = 0; e <= length; e++){
					if(string[c] == matrix[a][d]){
						d++;
						c++;
						count++;
					}
					else if(string[c] != matrix[a][d]){
						break;
					}
					if(count == length){
						return ((a * 12) + b);
					}
				}
			}
		}
	}
	
	// Search left
	count = 1;
	c = 0;
	for(a = 0; a < row; a++){ 
		for(b = 12; b >= 1; b--){
			c = 0;
			if(string[c] != matrix[a][b]){
				continue;
			}
			else if(string[c] == matrix[a][b]){ 
				count = 1;
				d = b;
				for(e = 0; e <= length; e++){
					if(string[c] == matrix[a][d] && d >= 0){
						d--;
						c++;
						count++;
					}
					else if(string[c] != matrix[a][d]){
						break;
					}
					if(count == length){
						return ((a * 12) + b);
					}
				}
			}
		}
	}
	
	// Search down
	count = 1;
	for(b = 0; b < column; b++){ 
		for(a = 0; a < row; a++){
			c = 0;
			if(string[c] != matrix[a][b]){
				continue;
			}
			else if(string[c] == matrix[a][b]){ 
				count = 1;
				d = a;
				for(e = 0; e <= length; e++){
					if(string[c] == matrix[d][b]){
						d++;
						c++;
						count++;
					}
					else if(string[c] != matrix[d][b]){
						break;
					}
					if(count == length){
						return ((a * 12) + b);
					}
				}
			}
		}
	}
	
	// Search up
	for(b = 0; b < column; b++){ 
		for(a = 15; a >= 1; a--){
			c = 0;
			if(string[c] != matrix[a][b]){
				continue;
			}
			else if(string[c] == matrix[a][b]){ 
				count = 1;
				d = a;
				for(e = 0; e <= length; e++){
					if(string[c] == matrix[d][b] && d >= 0){
						d--;
						c++;
						count++;
					}
					else if(string[c] != matrix[d][b]){
						break;
					}
					if(count == length){
						return ((a * 12) + b);
					}
				}
			}
		}
	}
	
	return -1;
}

int main(){
	int i, a;
	char inputstring[15];
	char puzzlestring[column];
	char matrix[row][column] = {
		{'X','T','Z','M','Q','Y','K','C','E','C','F','H'},
		{'S','H','O','U','T','E','X','O','E','A','P','I'},
		{'X','G','T','L','Q','B','E','L','T','N','F','K'},
		{'A','I','R','I','D','Z','A','L','I','O','D','M'},
		{'M','E','I','E','T','Y','S','E','H','R','T','I'},	
		{'A','W','B','R','N','E','T','C','W','O','H','X'},
		{'N','O','U','I','R','U','Z','T','S','C','C','T'},
		{'U','D','T','P','E','C','J','I','E','H','R','U'},
		{'A','L','E','M','C','S','Y','O','N','I','U','R'},
		{'L','V','K','E','R','E','M','N','I','P','H','E'},
		{'E','A','N','B','U','R','E','J','O','N','C','J'},
		{'A','W','I','I','I','J','N','J','R','U','Y','F'},
		{'D','W','T','N','T','H','E','N','P','J','Y','T'},
		{'E','Q','L','Z','D','I','L','E','M','M','A','B'},
		{'R','C','I','T','E','N','G','A','M','T','P','C'}
	};
	
	char userChoice;
	printf("Do you want to input a new puzzle or use the built-in one? (N for new, B for built-in): ");
	scanf(" %c", &userChoice);
	
	if (userChoice == 'N' || userChoice == 'n') {
		for(i = 0; i < row; i++){
			printf("Enter the line %d of the puzzle:\n", i + 1);
			scanf("%s", puzzlestring);
			for(a = 0; a < column; a++){
				matrix[i][a] = puzzlestring[a];
			}	
		}
	}

	printPuzzle(matrix);
	while(1){
		printf("Enter the string to be searched in puzzle (or 'Q' to quit):\n");
		scanf(" %s", inputstring);
		if(*inputstring == 'Q' || *inputstring == 'q'){
			break;
		}
		printf("%d\n", findString(matrix, inputstring, computeLength(inputstring)));
	}
	return 0;
}
