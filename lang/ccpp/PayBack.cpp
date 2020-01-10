
#include <stdio.h>

const unsigned int MAX = 10000000;
const unsigned int BUF_LEN = 1024;

void PayBack()
{
    unsigned int points = 0;
    unsigned int total = 0;
    unsigned int days = 0;
    unsigned int sum = 0;
    unsigned int pay = 0;
    int count = 0;
    char *pbuf = 0;
    char gs_buf[BUF_LEN] = {0};

    while (true) {
        printf("input points [ < 10,000,000 ]: ");
        count = scanf("%d", &points);
        if (count == 0){
             printf("please input a integer.\n");
             fflush(stdin);
             continue;
        }
        if (0 == points) {
            break;
        }
        if (points > MAX) {
            printf("points should < 10,000,000\n");
            continue;
        }
        total = 400 * points;
        days = 0;
        sum = 0;
        pay = points;
        while (total) {
            days++;
            total -= pay;
            sum += pay;
            pay = points - sum/400;
        }
        printf("days: %d\n", days);
    }
    return;
}