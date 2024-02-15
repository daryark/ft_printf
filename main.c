#include <stdio.h>
#include "ft_printf.h"

#define RESET_COLOR "\033[0;0m"
#define GREEN "\033[0;32m"
#define MAGENTA "\033[0;35m"
#define YELLOW "\033[0;33m"

int main (void)
{
    // printf("..%1s.\n\n", "");
    // printf("..%-1s.\n", "");
    // printf(".%-2s.\n", "");
    // printf(".%-3s.\n", "");
    // printf(".%-0s.\n", "");
    // printf(".%-s.\n", "");

    // printf(". %-s .\n", "-");
    // printf(". %-1s %-2s .\n", "", "-");
    // printf(". %-3s %-4s .\n", " - ", "");
    // printf(". %-2s %-3s %-4s %-5s .\n", " - ", "", "4", "");
    // printf(". %-3s %-3s %-4s %-5s %-3s .\n", " - ", "", "4", "", "2 ");

    // int res;

    //*its original printf, be aware to check this with ft_printf also!!
    // res = printf("%1.s, %1.s, %1.s, %1.s", (char *)NULL, "", "test", "joihwhhgsdkhksdgsdg\t\v\n\r\f\a25252\b6");
    // printf("%d\n", res);

    // printf(".%.s.\n", NULL);
    // printf(".%.s.\n", "hello");
    // printf(".%.0s.\n", "hello");
    // printf(".%.s.\n", "NULL");
    // printf(".%.0s.\n", "NULL");
    // printf(".%.s.\n", "");
    // printf(".%.03s.\n", "");
    // printf(".%.09s.\n", "");

    int res;
    int i;

    const char *s_arr[2] = {".%.03s.\n", ".%.09s.\n"};
    void *out_arr[2] = {NULL, NULL};
    i = 0;
    while (i < 2)
    {

        printf(YELLOW "----------------------PRINTF--------------------------" RESET_COLOR "\n");
        res = printf(s_arr[i], out_arr[i]);
        printf("\nres: %d\n", res);
        printf(YELLOW "----------------------FT_PRINTF-----------------------" RESET_COLOR "\n");
        res = ft_printf(s_arr[i], out_arr[i]);
        ft_printf("res: %d\n", res);
        i++;
    }
    // printf(".%.03s.\n", NULL);
    // printf(".%.09s.\n", NULL);
    // printf(YELLOW "---------------------------------------------" RESET_COLOR "\n");
    // ft_printf(".%.03s.\n", NULL);
    // ft_printf(".%.09s.\n", NULL);
    // printf(".%.01s.\n", "\0");
    // printf(".%.03s.\n", "\0");
    // printf(".%.09s.\n", "\0");
    // printf(".%3.s.\n", "");
    // printf(".%10.s.\n", "");
    // printf(".%3.s.\n", NULL);
    // printf(".%10.s.\n", NULL);
    // printf(".%-3.s.\n", "");
    // printf(".%-8.s.\n", "");
    // printf(".%-3.s.\n", NULL);
    return (0);
}