#include <stdio.h>
#include <stdlib.h>
#include <sodium.h>


const int NUMBER_OF_RANDOM_NUMBERS = 1000;
const int UPPER_LIMIT_1 = 1000;
const int UPPER_LIMIT_2 = 10;

int main()
{
    if (sodium_init() < 0) 
    {
        /* panic! the library couldn't be initialized; it is not safe to use */
    }
    
    uint32_t random_number ;
    int i;
    printf("\n\n\r*******************************************************************\n\r");
    printf("\n\rrandombytes_random\n\r");
    printf("\n\r*******************************************************************\n\n\r");

    for(i=0; i<NUMBER_OF_RANDOM_NUMBERS; i++){
        random_number = randombytes_random();
        printf("%u ", random_number);
    }

    printf("\n\n\r*******************************************************************\n\r");
    printf("\n\r randombytes_uniform(1000) \n\r");
    printf("\n\r*******************************************************************\n\n\r");

    for(i=0; i<NUMBER_OF_RANDOM_NUMBERS; i++){
        random_number = randombytes_uniform(UPPER_LIMIT_1);
        printf("%u", random_number);
    }

    printf("\n\n\r*******************************************************************\n\r");
    printf("\n\r randombytes_uniform(10) \n\r");
    printf("\n\r*******************************************************************\n\n\r");

    for(i=0; i<NUMBER_OF_RANDOM_NUMBERS; i++){
        random_number = randombytes_uniform(UPPER_LIMIT_2);
        printf("%u ", random_number);
    }

    const unsigned char seed[4] = "seed";
    unsigned char buff[3];

    printf("\n\n\r*******************************************************************\n\r");
    printf("\n\r randombytes_buf_deterministic() \n\r");
    printf("\n\r*******************************************************************\n\n\r");
    
    for(int j =0; j<20; j++){
        randombytes_buf_deterministic(buff, 3,  seed);
        for(i=0; i<3; i++)
            printf("%u ", buff[i]);

        printf("\n\r");
    }

}