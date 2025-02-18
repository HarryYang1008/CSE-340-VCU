#include <stdio.h>
#include "functions.h"

int main()
{
    unsigned int x = 0x89ABCDEF;
    unsigned int y = 0x12345678;
    
    //1-testing mask_and_merge
    printf("0x%08X\n",mask_and_merge(x,y));
    
    //2-testing replace_byte
    printf("0x%08X\n",replace_byte(0x12345678, 0, 0xEF));
    printf("0x%08X\n",replace_byte(0x12345678, 3, 0xEF));
    
    //3-testing lower_one_mask
    printf("0x%08X\n",lower_one_mask(x,3));
    printf("0x%08X\n",lower_one_mask(x,16));
}
