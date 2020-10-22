#include <stdio.h>

int main(void)
{
        int system, algorithm, network;
        int average;

        printf("Input the system programming, algortihm, and network score:");
        scanf("%d%d%d", &system, &algorithm, &network);

        average = (system + algorithm + network) / 3;

        printf("The average of the three subjects is %d.\n", average);

        return 0;
}
