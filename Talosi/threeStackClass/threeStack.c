/**
* @file threeStack.c
* @author VALEMBOIS Marc
* @brief Méthode de la classe threeStack.
* @date 2023/01/13 
*/

#include "threeStack.h"
//TAILLE d'une pile vous êtes libre de le changer
#define TAILLE 1

/**
* @brief Copie le tableau de l'objet courant vers un nouveau tableau avec de la mémoire supplémentaire
* @param newPile nouveau tableau avec la mémoire supplémentaire
* @param this pointeur vers l'objet courant
* @param pile entier désigant la pile nécessitant plus de mémoire
*/
void copyTab(String* newPile,struct threeStack *this,int pile)
{
    int decalage;
    switch(pile)
    {
        case 1:
            memcpy(newPile,this->tab,sizeof(String)*this->P1size);
            decalage = this->P1size;
            memcpy(newPile+decalage+this->size,this->tab+decalage,sizeof(String)*this->P2size);
            decalage += this->P2size;
            memcpy(newPile+decalage+this->size,this->tab+decalage,sizeof(String)*this->P3size);
            break;
        case 2:
            memcpy(newPile,this->tab,sizeof(String)*this->P1size);
            decalage = this->P1size;
            memcpy(newPile+decalage,this->tab+decalage,sizeof(String)*this->P2size);
            decalage += this->P2size;
            memcpy(newPile+decalage+this->size,this->tab+decalage,sizeof(String)*this->P3size);
            break;
        case 3:
            memcpy(newPile,this->tab,sizeof(String)*(this->P1size+this->P2size+this->P3size));
            break;
    }
}

/**
* @brief met à jour les attribut de l'objet (toujours appelé dans resizeTab())
* @param this pointeur vers l'objet courant
* @param pile entier désigant la pile nécessitant plus de mémoire
*/
void refreshArgument(struct threeStack *this,int pile)
{
    switch(pile)
    {
        case 1:
            this->P1size+=this->size;
            this->P2LastElement+=this->size;
            this->P3LastElement+=this->size;
            break;
        case 2:
            this->P2size+=this->size;
            this->P3LastElement+=this->size;
            break;
        case 3:
            this->P3size+=this->size;
            break;
    }
}

/**
* @brief creer le nouveau tableau avec la mémoire en plus pour l'instance de l'objet courant
* @param this pointeur vers l'objet courant
* @param pile entier désigant la pile nécessitant plus de mémoire
*/
static void resizeTab(struct threeStack *this,int pile)
{
    String* newPile;
    newPile=(String*)malloc(sizeof(String)*(this->P1size+this->P2size+this->P3size+this->size));

    copyTab(newPile,this,pile);
    refreshArgument(this,pile);
    free(this->tab);
    this->tab = newPile;
}

/**
* @brief vérifie si une pile donné en paramètre du tableau de l'objet courant est complete
* @param this pointeur vers l'objet courant
* @param pile entier désigant la pile nécessitant une vérification
* @return un entier : 1 si la pile est pleine, 0 si elle ne l'est pas
*/
int isFull(struct threeStack *this,int pile)
{
    switch(pile)
    {
        case 1:
            if(this->P1LastElement==this->P1size)
            {
                return 1;
            }
            break;
        case 2:
            if(this->P2LastElement==this->P2size+this->P1size)
            {
                return 1;
            }
            break;
        case 3:
            if(this->P3LastElement==this->P3size+this->P2size+this->P1size)
            {
                return 1;
            }
            break;
    }
    return 0;
}
/**
* @brief ajouter un element dans une pile (donné en parametre) du tableau de l'objet courant
* @param this pointeur vers l'objet courant
* @param pile entier désigant la pile ou l'on veut ajouter un élément
* @param value element que l'on veut ajouter
*/
static void push(struct threeStack *this,int pile,String value)
{
    if(isFull(this,pile))
    {
        resizeTab(this,pile);
    }
    switch(pile)
    {
        case 1:
            this->tab[this->P1LastElement]=value;
            this->P1LastElement++;
            break;
        case 2:
            this->tab[this->P2LastElement]=value;
            this->P2LastElement++;
            break;
        case 3:
            this->tab[this->P3LastElement]=value;
            this->P3LastElement++;
            break;
        default :
            fprintf(stderr,"Erreur : Cette pile n'existe pas\n");
            break;
    }
}

/**
* @brief vérifie si une pile donné en paramètre du tableau de l'objet courant est vide
* @param this pointeur vers l'objet courant
* @param pile entier désigant la pile nécessitant une vérification
* @return un entier : 1 si la pile est vide, 0 si elle ne l'est pas
*/
int isEmpty(struct threeStack *this,int pile)
{
    switch(pile)
    {
        case 1:
            if(this->P1LastElement==0)
            {
                return 1;
            }
            break;
        case 2:
            if(this->P2LastElement==this->P1size)
            {
                return 1;
            }
            break;
        case 3:
            if(this->P3LastElement==this->P2size+this->P1size)
            {
                return 1;
            }
            break;
    }
    return 0;
}

/**
* @brief retire et retourne le dernier element ajouter d'une pile (donner en parametre) du tableau de l'objet courant
* @param this pointeur vers l'objet courant
* @param pile entier désigant la pile où l'on veut retirer un element
* @return chaine de caractère qui est retirer de la pile
*/
static String pop(struct threeStack *this,int pile)
{
    String res="";
    if(isEmpty(this,pile))
    {
        fprintf(stderr,"Erreur : cette pile n'as pas d'élément");
        return res;
    }
    switch(pile)
    {
        case 1:
            res = this->tab[this->P1LastElement-1];
            this->P1LastElement--;
            break;
        case 2:
            res = this->tab[this->P2LastElement-1];
            this->P2LastElement--;
            break;
        case 3:
            res = this->tab[this->P3LastElement-1];
            this->P3LastElement--;
            break;
        default:
            fprintf(stderr,"Erreur : Cette pile n'existe pas");
    }
    return res;
}

/**
* @brief libère la mémoire allouer aux tableau de l'objet courant
* @param this pointeur vers l'objet courant
*/
static void freeStack(struct threeStack *this)
{
    free(this->tab);
}




static int getLast3(struct threeStack *this)
{
    return this->P3LastElement;
}

static int getLast2(struct threeStack *this)
{
    return this->P2LastElement;
}

static int getLast1(struct threeStack *this)
{
    return this->P1LastElement;
}








/**
* @brief constructeur de la classe threeStack
* @return un objet threeStack
*/
static struct threeStack new()
{
    return(struct threeStack)
    {
        .size=TAILLE,
        .P1size=TAILLE,
        .P2size=TAILLE,
        .P3size=TAILLE,
        .P1LastElement=0,
        .P2LastElement=TAILLE,
        .P3LastElement=TAILLE*2,
        .tab = (String*)malloc(sizeof(String)*(TAILLE*3)),
        .resizeTab=&resizeTab,
        .push=&push,
        .pop=&pop,
        .freeStack=&freeStack,
        .getLast1=&getLast1,
        .getLast2=&getLast2,
        .getLast3=&getLast3
    };
}
const struct threeStackClass threeStack={.new=&new};
