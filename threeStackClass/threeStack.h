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

/**
*@brief classe threeStack
*@param size taille de base de chaque pile
*@param P1size taille de base de la 1er pile
*@param P2size taille de base de la 2eme pile
*@param P3size taille de base de la 3eme pile
*@param P1LastElement denier element de la pile 1
*@param P2LastElement denier element de la pile 2
*@param P3LastElement denier element de la pile 3
*@param tab tableau de chaine de caractère contenant toute les piles
*@param resizeTab méthode qui agrandi une pile du tableau (donc qui agrandi le tableau)
*@param push méthode qui rajoute un element dans le tableau en fonction de la pile passé en param
*@param pop méthode qui retire un element dans le tableau en fonction de la pile passé en param
*@param freeStack méthode qui libere la mémoire allouer au tableau
*/
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
};

extern const struct threeStackClass
{
    struct threeStack (*new)();
}threeStack;
