#include <stdio.h>

#define OFFSET 10000
#define MAX_VAL 20001

typedef struct {
    int i, j;
    int found;
} Result;

Result twoSum(int arr[], int n, int target) {
    int map[MAX_VAL];
    for (int i = 0; i < MAX_VAL; i++) {
        map[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int complement = target - arr[i];
        int compIndex = complement + OFFSET;
        if (compIndex >= 0 && compIndex < MAX_VAL && map[compIndex] != -1) {
            Result res = { map[compIndex], i, 1 };
            return res;
        }
        map[arr[i] + OFFSET] = i;
    }

    Result not_found = { -1, -1, 0 };
    return not_found;
}

int main() {
    int a[100], n, target;
    scanf("%d %d", &n, &target);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    Result result = twoSum(a, n, target);
    
    result.found ? printf("%d %d\n", result.i, result.j) : printf("Not found\n");

    return 0;
}

