#include "stdio.h"
void solve();

int main(){
    solve();
    return 0;
}

int salary_val[7] = {0, 1500, 4500, 9000, 35000, 55000, 80000};
float tax_percent[7] = {97, 90, 80, 75, 70, 65, 55};
int tax_val[6] = {1455, 2700, 3600, 19500, 14000, 16250};

void solve(){
    int salary = 0;
    scanf("%d", &salary);
    if (salary <= 3500){
        printf("%d\n", salary);
    }else{
        int result = salary - 3500;
        int index = 0;
        while(result > tax_val[index] && index < 6){
            result -= tax_val[index++];
        }
        result = salary_val[index] + floor(result/tax_percent[index])*100 + 3500;
        printf("%d", result);
    }
}
