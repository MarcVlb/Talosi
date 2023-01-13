/**
* @file threeStack.h
* @author VALEMBOIS Marc
* @brief classe threeStack.
* @date 2023/01/13 
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef char* String;

struct threeStack
{
    int size;
    int P1size;
    int P2size;
    int P3size;
    int P1LastElement;
    int P2LastElement;
    int P3LastElement;
    String* tab;
    void (*resizeTab)(struct threeStack *this,int pile);
    void (*push)(struct threeStack *this,int pile,String value);
    String (*pop)(struct threeStack *this,int pile);
    void (*freeStack)(struct threeStack *this);
    int (*getLast3)(struct threeStack *this);
    int (*getLast2)(struct threeStack *this);
    int (*getLast1)(struct threeStack *this);
};

extern const struct threeStackClass
{
    struct threeStack (*new)();
}threeStack;