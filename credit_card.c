#include <stdio.h>
void main()
{

    int i = 0, j;
    int sum = 0, sum1 = 0, sum2 = 0, sum3 = 0, t, r, z;
    long long int cn;
    int a[16];
abc:
    printf("ENTER YOUR CARD NUMBER:\n");
    scanf(" %lld", &cn);
    while (cn != 0)
    {
        r = cn % 10;
        cn = cn / 10;
        a[i] = r;
        i++;
    }
    j = i;
    //LUHN'S THEOREM

    i = 1;
    while (i <= j)
    {
        t = a[i] * 2;
        if (t >= 10)
        {
            while (t != 0)
            {
                r = t % 10;
                t = t / 10;
                sum2 = sum2 + r;
            }
        }
        else if (t < 10)
        {
            sum = sum + t;
        }
        i = i + 2;
    }
    sum3 = sum + sum2;
    // printf("%d\n",sum3);
    for (i = 0; i <= j; i += 2)
    {
        sum1 = a[i] + sum1;
    }
    sum3 = sum + sum1 + sum2;
    // return sum3;
    // printf("%d", sum3);
    z = sum3 % 10;

    int test;
    test = a[j-1] * 10 + a[j - 2];
    //CONDITION FOR AMERICAN EXPRESS
    if (j == 15 && (test == 34 || test == 37) && z == 0)
    {
        printf("AMERICAN EXPRESS\n");
    }
    //CONDITION FOR MASTERCARD
    else if (j == 16 && (test == 51 || test == 52 || test == 53 || test == 54 || test == 55) && z == 0)
    {
        printf("MASTERCARD\n");
    }
    //CONDITION FOR VISA CARD
    else if ((j == 13 || j == 16) && (a[j-1] == 4) && (z == 0))
    {
        printf("VISA CARD\n");
    }
    else
    {
        printf("INVALID\n");
        goto abc;
    }
}