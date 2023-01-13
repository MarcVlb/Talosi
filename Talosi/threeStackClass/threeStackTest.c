/**
* @file threeStackTest.c
* @author VALEMBOIS Marc
* @brief Test de la classe threeStack.
* @date 2023/01/13 
*/
#include "threeStack.h"

int main()
{

    struct threeStack stack = threeStack.new();

    stack.push(&stack,1, "{name:\"object1\"}");
    stack.push(&stack,1, "{name:\"object2\"}");
    stack.push(&stack,2, "{name:\"object3\"}");
    stack.push(&stack,2, "{name:\"object4\"}");
    stack.push(&stack,2, "{name:\"object5\"}");
    stack.push(&stack,3, "{name:\"object6\"}");
    stack.push(&stack,3, "{name:\"object7\"}");
    stack.push(&stack,3, "{name:\"object8\"}");
    stack.push(&stack,1, "{name:\"object9\"}");
    stack.push(&stack,1, "{name:\"object10\"}");
    stack.push(&stack,2, "{name:\"object11\"}");
    stack.push(&stack,2, "{name:\"object12\"}");
    stack.push(&stack,2, "{name:\"object13\"}");
    stack.push(&stack,3, "{name:\"object14\"}");
    stack.push(&stack,3, "{name:\"object15\"}");
    stack.push(&stack,3, "{name:\"object16\"}");
    stack.push(&stack,1, "{name:\"object17\"}");
    stack.push(&stack,1, "{name:\"object18\"}");
    stack.push(&stack,2, "{name:\"object19\"}");
    stack.push(&stack,2, "{name:\"object20\"}");
    stack.push(&stack,2, "{name:\"object21\"}");
    stack.push(&stack,3, "{name:\"object22\"}");
    stack.push(&stack,3, "{name:\"object23\"}");
    stack.push(&stack,3, "{name:\"object24\"}");
    stack.push(&stack,4, "{name:\"object25\"}");

    printf("%s\n",stack.pop(&stack,1));
    printf("%s\n",stack.pop(&stack,1));
    printf("%s\n",stack.pop(&stack,1));
    printf("%s\n",stack.pop(&stack,1));
    printf("%s\n",stack.pop(&stack,1));
    printf("%s\n",stack.pop(&stack,1));
    printf("%s\n",stack.pop(&stack,1));

    stack.push(&stack,1, "{name:\"object26\"}");

    printf("%s\n",stack.pop(&stack,1));
    printf("%s\n",stack.pop(&stack,2));
    printf("%s\n",stack.pop(&stack,2));
    printf("%s\n",stack.pop(&stack,2));
    printf("%s\n",stack.pop(&stack,2));
    printf("%s\n",stack.pop(&stack,2));
    printf("%s\n",stack.pop(&stack,2));
    printf("%s\n",stack.pop(&stack,2));
    printf("%s\n",stack.pop(&stack,2));
    printf("%s\n",stack.pop(&stack,2));
    printf("%s\n",stack.pop(&stack,3));
    printf("%s\n",stack.pop(&stack,3));
    printf("%s\n",stack.pop(&stack,3));
    printf("%s\n",stack.pop(&stack,3));
    printf("%s\n",stack.pop(&stack,3));
    printf("%s\n",stack.pop(&stack,3));
    printf("%s\n",stack.pop(&stack,3));
    printf("%s\n",stack.pop(&stack,3));
    printf("%s\n",stack.pop(&stack,3));
    printf("%s\n",stack.pop(&stack,3));
    printf("%s\n",stack.pop(&stack,3));
    printf("%s\n",stack.pop(&stack,3));
    printf("%s\n",stack.pop(&stack,4));


    


    printf("fin");

    stack.freeStack(&stack);
}