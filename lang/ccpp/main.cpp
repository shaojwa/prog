

#include <stdio.h>

void PayBack();
bool GenAverage(void);
int GetSingle(int arr[], int count);

int main()
{
    int buf[] = {1,2,3,1,2};
    int ret = GetSingle(buf, 5);
    printf("the one is %d\n", ret);
    GenAverage();
    PayBack();
    return 0;
}