#include <stdio.h>

int main(void)
{
    int r;
    int re;
    int res;
    // printf("char: .%035+#.0 50c.\n",  'z');
    // printf("percent: .%035+#.0 50%%-10%.\n");
    r = printf("%.3s\n", "");
    re = printf("%s", "");
    res = printf("NULL %s NULL\n", "");
    printf("%d, %d, %d\n", r, re, res);
    return (0);
}