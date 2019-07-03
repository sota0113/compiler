#include <stdio.h>
#include <stdlib.h>


void test(char *p){
	int i = 0;
	while (*p) {
		if (isspace(*p)) {
			printf("[turn]: %d	",i);
			printf("GOT <space>\n");
			printf("NUMBER: %s\n",p);
			p++;
			i++;
			continue;
		}
		if (*p == '+') {
			printf("[turn]: %d	",i);
			printf("GOT '+'.\n");
			printf("NUMBER: %s\n",p);
			p++;
			i++;
			continue;
		}

		if (isdigit(*p)) {
			printf("[turn]: %d	",i);
			printf("GOT number.\n");
			printf("NUMBER: %s\n",p);
			p++;
			i++;
			continue;
		} else {
			printf("[turn]: %d	",i);
			printf("GOT something.\n");
			printf("NUMBER: %s\n",p);
			error("トークナイズできません: %s\n",p);
			exit(1);
		}
	}
}

int main(int argc, char **argv){
	test(argv[1]);
}
