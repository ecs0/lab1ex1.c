#include <stdio.h>

void bsort(int *a, int n) {
    int i,j,temp;
    for(i=0; i<n-1; i++)
        for(j=n-1; j>i; j--)
            if(a[j] < a[j-1]) {
                temp=a[j-1]; a[j-1]=a[j]; a[j]=temp;
            }
}

int main() {
    int x, i=0, sum=0, j=0;
    double avg, median;
    char name[20];
    int nums[100];
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Hello, %s, enter an integer (-1 to quit): ", name);
    scanf("%d", &x);
    if(x == -1) {
        return 0;
    }
    while(x != -1) {
        nums[i] = x;
        i++;
        printf("Enter an integer (-1 to quit): ");
        scanf("%d", &x);
    }
    bsort(nums, i);
    for(; j<i; j++) {
        sum += nums[j];
    }
    if(i%2 != 0) {
        median = nums[i/2];
    } else {
        median = ((double)(nums[i/2] + nums[(i/2)-1])/2);
    }
    avg = (double)sum/i;
    printf("The maximum is: %10d\n", nums[i-1]);
    printf("The minimum is: %10.1f\n", (double)nums[0]);
    printf("The average is: %10.3f\n", avg);
    printf("The sum is: \t%10d\n", sum);
    printf("The median is: %.1f\n", median);
    return 0;
}