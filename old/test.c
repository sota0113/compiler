# include <stdio.h>
# include <stdlib.h>

int main(int argc, char **argv) {
	char *p = argv[1];
	printf("arg is ... %s\n",p);
	printf("FIRST NUM => %ld\n", strtol(p, &p, 10));
	while (*p) {
		if ( *p == '+' ) {
			printf("BEFORE: %s\n",p);
			p++;
			printf("AFTER: %s\n",p);
			printf(p);
			printf("PLUS .... %ld\n", strtol(p, &p, 10));
			printf("%s\n",p);
			continue;
		}
		
	}

}
