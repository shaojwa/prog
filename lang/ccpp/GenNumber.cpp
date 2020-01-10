

#include <stdio.h>
#include <stdlib.h>
#include <atltime.h>

#define COUNT_MAX 10000
#define NUM_MAX   10000
#define BUF_SIZE  1024

int result[COUNT_MAX];

bool GenAverage(void)
{
    int min = 0, max = 0, count = 0, ret = 0;
    double average = 0;

    printf("**********************************************************************\n");
    printf("* 限制：数据范围 1-%d, 最大个数：%d, 平均数必须是0.5的整数倍\n",NUM_MAX, COUNT_MAX);
    printf("**********************************************************************\n\n");

    while (true)
    {
        printf("请输入范围: ");
        ret = scanf("%d %d", &min, &max);
        if (0 == min && 0 == max)
        {
            break;
        }
        if (min < 1 || max < 1 || min > NUM_MAX || max > NUM_MAX)
        {
            printf("\n**** 错误: 范围在 1-%d之间\n\n", NUM_MAX);
            continue;
        }
        if (min > max)
        {
            int temp = min;
            min = max;
            max = temp;
        }
label_input_average:
        printf("请输入平均值: ");
        ret = scanf("%lf", &average);
        if (ret != 1)
        {
            goto label_input_average;
        }
        if (0 == average)
        {
            break;
        }
        if (average * 2 != (double)((int)(average * 2)))
        {
            printf("**** 错误：平均值要求为 0.5 的整数倍\n\n");
        }
        if (average < min || average > max)
        {
            printf("\n**** 错误：平均值要求在输入范围内\n\n");
            goto label_input_average;
        }

label_count:
        printf("请输入生成个数：");
        ret = scanf("%d", &count);
        if (ret != 1 || count < 1 && count > COUNT_MAX)
        {
            printf("**** 错误：请输入1-%d以内的数\n\n");
            goto label_count;
        }
        /* 如果平均数是0.5的奇数倍则数字个数必须为偶数 */
        if (average != (int)average && count % 2 == 1)
        {
            printf("**** 错误：平均数是0.5的奇数倍则个数只能为偶数\n\n");
            goto label_count;
        }

        printf("\n在范围 %d-%d内平均值为 %.1lf 的 %d 个数如下(每行最多10个):\n",
            min, max, average, count);

        int len = max - min + 1;
        int total = count * average;
        int space = 0;
        int sum = 0;
        int index = 0;
        int num = 0;
        srand(time(NULL));

label_regen:
        if (index + 1 == count)
        {
            result[index] = total - sum;
            goto label_end;
        }

        num = min + (rand() % len);
        space = total - sum - num;
        if (min * (count - index - 1) <= space &&
            max * (count - index - 1) >= space)
        {
            result[index] = num;
            sum += num;
            index += 1;
        }
        goto label_regen;

label_end:
        index = 0;
        while(index < count)
        {
            printf("%5d", result[index]);
            if (index % 10 == 9) printf("\n");
            index ++;
        }
        printf("\n\n*******************完成***********************************************\n\n");
    }
    return true;
}