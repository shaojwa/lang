

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
    printf("* ���ƣ����ݷ�Χ 1-%d, ��������%d, ƽ����������0.5��������\n",NUM_MAX, COUNT_MAX);
    printf("**********************************************************************\n\n");

    while (true)
    {
        printf("�����뷶Χ: ");
        ret = scanf("%d %d", &min, &max);
        if (0 == min && 0 == max)
        {
            break;
        }
        if (min < 1 || max < 1 || min > NUM_MAX || max > NUM_MAX)
        {
            printf("\n**** ����: ��Χ�� 1-%d֮��\n\n", NUM_MAX);
            continue;
        }
        if (min > max)
        {
            int temp = min;
            min = max;
            max = temp;
        }
label_input_average:
        printf("������ƽ��ֵ: ");
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
            printf("**** ����ƽ��ֵҪ��Ϊ 0.5 ��������\n\n");
        }
        if (average < min || average > max)
        {
            printf("\n**** ����ƽ��ֵҪ�������뷶Χ��\n\n");
            goto label_input_average;
        }

label_count:
        printf("���������ɸ�����");
        ret = scanf("%d", &count);
        if (ret != 1 || count < 1 && count > COUNT_MAX)
        {
            printf("**** ����������1-%d���ڵ���\n\n");
            goto label_count;
        }
        /* ���ƽ������0.5�������������ָ�������Ϊż�� */
        if (average != (int)average && count % 2 == 1)
        {
            printf("**** ����ƽ������0.5�������������ֻ��Ϊż��\n\n");
            goto label_count;
        }

        printf("\n�ڷ�Χ %d-%d��ƽ��ֵΪ %.1lf �� %d ��������(ÿ�����10��):\n",
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
        printf("\n\n*******************���***********************************************\n\n");
    }
    return true;
}