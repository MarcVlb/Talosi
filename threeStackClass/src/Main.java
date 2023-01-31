/**
*@author marc_vlb sur insta
*@version 1.0
 */
public class Main {
    
    /**
     * Test Sur la classe ThreeStack
     */
    public static void main(String[] args)
    {
        ThreeStack myStack = new ThreeStack();

        myStack.push(1, "{name:\"object1\"}");
        myStack.push(1, "{name:\"object2\"}");
        myStack.push(2, "{name:\"object3\"}");
        myStack.push(2, "{name:\"object4\"}");
        myStack.push(2, "{name:\"object5\"}");
        myStack.push(3, "{name:\"object6\"}");
        myStack.push(4, "{name:\"object7\"}");

        System.out.println(myStack.pop(1));
        System.out.println(myStack.pop(2));
        System.out.println(myStack.pop(2));
        System.out.println(myStack.pop(3));
        System.out.println(myStack.pop(3));
        System.out.println(myStack.pop(1));
        System.out.println(myStack.pop(2));
        System.out.println(myStack.pop(4));
    }
}
