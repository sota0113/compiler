#include <stdio.h>
#include <stdarg.h>

int sum(int num, ...) {
    va_list list;
    int sum = 0;

    va_start(list, num);
    printf("%d\n",num);

    int i;
    for(i = 0; i < num; i++) {
        sum += va_arg(list, int);
    }
    va_end(list);

    return sum;
}

int main (void) {
    printf("%d\n", sum(5, 1, 2, 3, 4, 5));
    printf("%d\n", sum(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
return 0;
}
