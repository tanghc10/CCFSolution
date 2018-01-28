#include <iostream>
using namespace std;

void quick_sort(int s[], int l, int r)
{
    if (l < r)
    {
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j] >= x)
                j--;
            if(i < j)
                s[i++] = s[j];

            while(i < j && s[i] < x)
                i++;
            if(i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        quick_sort(s, l, i - 1);
        quick_sort(s, i + 1, r);
    }
}

int main(){
    int number = 0;
    cin>>number;
    int *numArray = new int[number];
    int counter = 0;
    int result = 0;
    int counter_less = 0, counter_more = 0;
    for(;counter < number; counter++)
        cin>>numArray[counter];
    quick_sort(numArray, 0, number - 1);
    result = numArray[number/2];
    for (counter = 0; counter < number; counter++)
        if(numArray[counter] < result)
            counter_less++;
        else if (numArray[counter] > result)
            counter_more++;
    if (counter_less != counter_more)
        result = -1;
    cout<<result<<endl;
    delete numArray;
    return 0;
}
