import java.util.ArrayList;

/**
*@author marc_vlb sur insta
*@version 1.0
 */

public class ThreeStack
{
    private ArrayList<String> hashmap;

    /**
     * Constructeur de notre classe threeStack
     */
    public ThreeStack()
    {
            this.hashmap = new ArrayList<String>();
    }


    /**
     * méthode qui cherche tout les elements d'une pile grâce a un patterne donnée en parametre 
     * @param key pattern correspondant à la pile dans laquelle on veut chercher 
     * @return entier correspondant au nombre d'element d'une pile
     */
    private int everyMembers(String key)
    {
        int res=0;
        for(int i = 0;i<hashmap.size();i+=2)
        {
            if(hashmap.get(i).contains(key))
            {
                res+=1;
            }
        }
        return res;
    }

    /**
     * chercher le derniere élément d'une pile
     * @param key pattern correspondant à la pile dans laquelle on veut chercher
     * @return entier correspondant à l'index du derniere element d'une pile
     */
    private int lastElement(String key)
    {
        int res = -1;
        for(int i = 0;i<hashmap.size();i+=2)
        {
            if(hashmap.get(i).contains(key))
            {
                res=i;
            }
        }
        return res;
    }

    /**
     * check si le numéro de la pile est valide
     * @param numeroPile entier représentant le numéro de la pile
     * @return boolean true si valide false sinon;
     */
    private boolean checkPile(int numeroPile)
    {
        if(numeroPile>3 || numeroPile<=0){
            return false;
        }
        else
        {
            return true;
        }
    }

    /**
     * fonction push qui rajoute un element a la fin d'une pile donnée en argument
     * @param numeroPile numero de la pile dans laquelle on veut rajouter un element
     * @param objet element que l'on veut rajouter
     */
    public void push(int numeroPile,String objet)
    {
        if(checkPile(numeroPile))
        {
            String KeyMatch = "pile"+numeroPile;
            String ourKey = KeyMatch+everyMembers(KeyMatch);
            hashmap.add(ourKey);
            hashmap.add(objet);
        }
        else
        {
            System.out.print("Erreur : cette pile n'existe pas\n");
        }
    }

    /**
     * fonction pop qui retirer et retourne un element d'une pile donnée en argument
     * @param numeroPile numéro de la pile dans laquelle on veut retirer un element
     * @return dernier element de la pile
     */
    public String pop(int numeroPile)
    {
        String res = "";
        if((!checkPile(numeroPile)))
        {
            System.out.print("Erreur : cette pile n'existe pas\n");
            return res;
        }
        String KeyMatch = "pile"+numeroPile;
        int index = lastElement(KeyMatch);
        if (index == -1)
        {
            System.out.println("Erreur : la pile est vide");
        }
        else
        {
            res = hashmap.get(index+1);
            hashmap.remove(index);
            hashmap.remove(index);
        }
        return res;
    }
}