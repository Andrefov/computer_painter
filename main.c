#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void help() {
	printf("select number of pattern which you want to draw:\n");
	printf("1) Rectangle     2) Triangle      3 )Xo Change     4) Frame\n");
	printf("XXXXXX           X                XoXoX            XXXXX\n");
	printf("XXXXXX           XX               oXoXo            XoooX\n");
	printf("XXXXXX           XXX              XoXoX            XoooX\n");
	printf("XXXXXX           XXXX             oXoXo            XoooX\n");
	printf("XXXXXX           XXXXX            XoXoX            XXXXX\n\n");

	printf("5) Frame in Fr   6) Frame with X  7) Diamond       8) chess \n");
	printf("XXXXXXXXX        XXXXXXXXX        ooooXoooo        XXXoooXXX\n");
	printf("XoooooooX        XXoooooXX        oooXXXooo        oooXXXooo\n");
	printf("XoXXXXXoX        XoXoooXoX        ooXXXXXoo        XXXoooXXX\n");
	printf("XoXoooXoX        XooXoXooX        oXXXXXXXo        oooXXXooo\n");
	printf("XoXoXoXoX        XoooXoooX        XXXXXXXXX        XXXoooXXX\n");
	printf("XoXoooXoX        XooXoXooX        oXXXXXXXo        oooXXXooo\n");
	printf("XoXXXXXoX        XoXoooXoX        ooXXXXXoo        XXXoooXXX\n");
	printf("XoooooooX        XXoooooXX        oooXXXooo        oooXXXooo\n");
	printf("XXXXXXXXX        XXXXXXXXX        ooooXoooo        XXXoooXXX\n\n");
	
	printf("5 and 6 must be odd numbers\n");
	printf("9) help          10) exit\n");
}

int readline(char* line, size_t llen) {
	line[llen - 1] = 0xaa;

	if (fgets(line, llen, stdin) == NULL) {
		printf("critical error\n");
		return -1;
	}

	if (line[llen - 1] == "\0" && line[llen - 2] == "\n") {
		printf("critical error\n");
		return -1;
	}
	line[strlen(line) - 1] = '\0';
}

int input_converter(char* line) {
	int input = atoi(line);
	if (input < 0) {
		return -1;
	}
	else
		return input;
	
	
}

int odd_checker(int a_) {
	if (a_ % 2 == 0 && a_ !=0)
		return 0;
	else
		return 1;
}

int suqare_pattern(int args) {
	if (args < 2) {
		printf("incorrect value, try again\n");
		return -1;
	}
	for (int i = 0; i < args; i++) {
		if (i != 0) {
			printf("\n");
		}
		for (int j = 0; j < args; j++) {
			printf("X");
		}
	}
}

int triangle_pattern(int args) {
	if (args < 3) {
		printf("incorrect value, try again\n");
		return -1;
	}
	for (int i = 0; i < args; i++) {
		if (i != 0) {
			printf("\n");
		}
		for (int j = 0; j < args; j++) {
			if (i >= j) {
				printf("X");
			}
			else
				printf(" ");
		}
	}
}

int xo_pattern(int args) {
	if (args < 2) {
		printf("incorrect value, try again\n");
		return -1;
	}
	for (int i = 0; i < args; i++) {
		if (i != 0) {
			printf("\n");
		}
		for (int j = 0; j < args; j++) {
			if (i != 0 && odd_checker(i) == 1 )
				printf("Xo");
			else
				printf("oX");
		}
	}
}

int frame_pattern(int args){
	if (args < 3) {
		printf("incorrect value, try again\n");
		return -1;
	}
	for (int i = 0; i < args; i++) {

		printf('X');

		if (i != 0) {
			printf("\n");
		}
		for (int j = 0; j < (args - 1); j++) {
			if (i == 0 || i == (args - 1)) {
				printf("X");
			}
			if (i != 0 && i != (args - 1) && j != (args - 1))
				printf("o");
			else
				printf("X");
		}
	}
}

int frame_x_pattern(int args) {
	if (odd_checker(args) == 0 || args < 5) {
		printf("incorrect value, try again\n");
			return -1;
	}
	for (int i = 0; i < args; i++) {

		for (int j = 0; j < args; j++) {
			if (i == 0 ) {
				printf("X");
			}
		//  ex. 1st row, ex last row,     ex last column   ex for xleft       ex for x right  ex 1st col
			if (i != 0 && i != (args - 1) && j != (args - 1) && i != j &&  j != (args - (i +1)) && j != 0 )
				printf("o");
			else if (i != 0)
				printf("X");
		}
		printf("\n");
	}
}

int diamond_pattern(int args) {
	if (odd_checker(args) == 0 || args < 5) {
		printf("incorrect value, try again\n");
		return -1;
	}

	int b = (args / 2);
	int c = 0;
	for (int i = 0; i < args; i++) {


		for (int j = 0; j < args; j++) {

			if (j != b && j < (b - c) || j>(b+c))
				printf("o");
			else
				printf("X");
		}
		if (i < b)
			c++;
		else
			c--;
		
		printf("\n");
	}
}

int chess_pattern(int args) {
	if (args < 6) {
		printf("incorrect value, try again\n");
		return -1;
	}
	for (int i = 0; i < args; i++) {
		if (i != 0) {
			printf("\n");
		}
		for (int j = 0; j < args; j++) {
			if ((j != 0 && odd_checker(j+2) == 1)&& odd_checker(i + 2) == 0 || odd_checker(j+2) == 0 && odd_checker(i+2)== 1)
				printf("XXX");
			else
				printf("000");
		}
	}
}

int frame_in_frame_pattern(int args) {
	if (args < 5 || args > 50) {
		printf("incorrect value, try again\n");
		return -1;
	}

	char matrix[50][50];
	

	
	int begin = 0;
	int end = args - 1;
	int const constant = 2;
	for (int i = 0; i <= end; i++) {
		for (int j = 0; j <= end; j++) {
			matrix[i][j] = 'o';
		}
	}
	while (begin <= end){
		for (int i = begin; i <= end; i++) {

			matrix[begin][i] = 'X';
			matrix[end][i] = 'X';
		}
		for (int i = begin; i <= end; i++) {
			matrix[i][begin] = 'X';
			matrix[i][end] = 'X';
		}
		begin += constant;
		end -= constant;

	}

	for (int i = 0; i < args ; i++){
	
		for (int j = 0; j < args ; j++)
		{
			printf("%c", matrix[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int choice;
	
	for (;;) {
		help();
		char line[10];
		
		if (readline(line, sizeof(line)) == 0) {
			continue;
		}
		if (strncmp(line, "10", 2) == 0)
			break;
		choice = input_converter(line);
		switch (choice) {
		case 1:
			printf("Please input the number of X you want to draw (min 2): \n");
			if (readline(line, sizeof(line)) == 0) {
				continue;
			}
			suqare_pattern(input_converter(line));
			break;
		case 2:
			printf("Please input the number of X you want to draw (min 3): \n");
			if (readline(line, sizeof(line)) == 0) {
				continue;
			}
			triangle_pattern(input_converter(line));
			break;
		case 3:
			printf("Please input the number of X you want to draw (min 2): \n");
			if (readline(line, sizeof(line)) == 0) {
				continue;
			}
			xo_pattern(input_converter(line));
			break;
		case 4:
			printf("Please input the number of X you want to draw (min 3): \n");
			if (readline(line, sizeof(line)) == 0) {
				continue;
			}
			frame_pattern(input_converter(line));
			break;
		case 5:
			printf("Please input the number of X you want to draw (min 5, max 50): \n");
			if (readline(line, sizeof(line)) == 0) {
				continue;
			}
			frame_in_frame_pattern(input_converter(line));
			break;
		case 6:
			printf("Please input the number of X you want to draw (min 5, and odd olny): \n");
			if (readline(line, sizeof(line)) == 0) {
				continue;
			}
			frame_x_pattern(input_converter(line));
			break;
		case 7:
			printf("Please input the number of X you want to draw (min 5, and odd olny): \n");
			if (readline(line, sizeof(line)) == 0) {
				continue;
			}
			diamond_pattern(input_converter(line));
			break;
		case 8:
			printf("Please input the number of X you want to draw (min 6): \n");
			if (readline(line, sizeof(line)) == 0) {
				continue;
			}
			chess_pattern(input_converter(line));
			break;
		case 9:
			help();
			break;
		case 10:
			break;
		}


	}
	
	return 0;

}
