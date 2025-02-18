//CMSC 257 HW5
//Author: Weikang Yang
//Compelete  date:10/16

unsigned mask_and_merge(unsigned x, unsigned y)
{
    return (x & 0xFF) | (y & ~0xFF);//Get the lowest byte of x, and keep the upper 3 bytes of y
}

unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    unsigned mask = ~(0xFF << (i * 8));// a mask to clear the specified byte position
    unsigned b_shifted = b << (i * 8); // move byte b to the specified position
    return (x & mask) | b_shifted; //replace the specified byte in x
}

unsigned lower_one_mask(unsigned x, unsigned n)
{
    unsigned mask = ~0U >> (32 - n); //a mask with n bits of 1
    return x & mask; //apply the mask to x
}
