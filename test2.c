# include <stdio.h>
# include <stdlib.h>

int main(int argc, char **argv) {
	char *p = argv[1];
	if (argc != 2) {
		fprintf ("引数が正しくありません");
		
	}

	while (*p) {
		
		if ( *p == '+' ) {
			printf("this is +.");
		}
		
	}

}
