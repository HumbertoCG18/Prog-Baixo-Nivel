#include <stdio.h>
int main()
{
    long nums[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    char* ptr = (char *) nums;
    int i, bytes;
    
    for(i=0, bytes=0; i<10*sizeof(*nums); i++, bytes+=4)
        printf("%d: %p + %d bytes = %p ==> %d\n",
            i, ptr, bytes, (ptr+i), *(ptr+i));

    char   *a;
    short  *b;
    int    *c;
    long   *d;
    float  *e;
    double *f;
    
    printf("sizeof a = %d\n",sizeof(a));
    printf("sizeof b = %d\n",sizeof(b));
    printf("sizeof c = %d\n",sizeof(c));
    printf("sizeof d = %d\n",sizeof(d));
    printf("sizeof e = %d\n",sizeof(e));
    printf("sizeof f = %d\n",sizeof(f));    
    
    return 0;
}
