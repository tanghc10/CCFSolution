#include <stdio.h>

int main()
{
    int op = -1;
    int current_grade = 0;
    int total_grade = 0;
    scanf("%d", &op);
    while (op != 0) {
        if (op == 2)
        {
            if (current_grade > 1)
            {
                current_grade += 2;
            }
            else
            {
                current_grade = 2;
            }
        }else
        {
            current_grade = 1;
        }
        total_grade += current_grade;
        scanf("%d", &op);
    }
    printf("%d\n", total_grade);
    return 0;
}
