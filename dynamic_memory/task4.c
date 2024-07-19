#include <stdio.h>
#include <stdlib.h>


struct substring{
    char ch;
    int amount;
};

void insert_sort_min(struct substring *substrings, unsigned int length)
{
    int location, current_symbol;
    struct substring current_substring;
    

    for(int i=1; i<length; i++)
    {
        current_substring = substrings[i];
        location = i-1;

        while (location >= 0 && (substrings[location].amount < current_substring.amount || (substrings[location].amount == current_substring.amount && substrings[location].ch > current_substring.ch)))
        {
            substrings[location+1] = substrings[location];
            location--;
        }
        substrings[location+1] = current_substring;
        
    }

}

void next_max(struct substring *substrings){
    static unsigned int num = 0;

    for(int i=0; i<substrings[num].amount; i++) printf("%c", substrings[num].ch);
    printf("\n");

    num++;


}

void main(){
    unsigned int k, symbols_amount[128] = {};
    struct substring substrings[100] = {};

    {
    char ch = getchar(), prev_ch;
    unsigned int i=0, counter=1;
    prev_ch = ch;
    for(; (ch=getchar()) != '\n';)
    {
        if(prev_ch != ch)
        {
            substrings[i].ch = prev_ch;
            substrings[i].amount = counter;
            counter = 0;
            i++;
        }
        prev_ch = ch;
        counter++;

    }

    substrings[i].ch = prev_ch;
    substrings[i].amount = counter;
    }

    scanf("%u", &k);

    insert_sort_min(substrings, 100);

    for(int i=0; i<k; i++) next_max(substrings);
    // for(int i=0; i<k; i++) printf("%u %c\n", substrings[i].amount, substrings[i].ch);
    printf("\n");

}