#include <stdio.h>

int firstMissingPositive(int* nums, int numsSize)
{
    int i = 0, j = 1;
    int n = 1;
    while (j == 1)
    {
        i = 0;
        while (i <= numsSize)
        {
            j = 0;
            if (n == nums[i])
            {
                n++;
                j++;
                break;
            }
            else
                i++;
        }
    }
    return n;
}

int main() {
  int j[] = {1,2,3,5,4};
  int i = firstMissingPositive(j, 5);
  printf("%d", i);
  return 0;
}