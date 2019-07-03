#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void myPrintf( const char *format, ... ){
    va_list ap;
    va_start( ap, format );
    va_end( ap );
}


int main (void) {
    myPrintf( "%d %f %s\n", 100, 3.14, "piyo" );
}
