interface first {

default public void display() {

System.out.println("This is the display function of interface first");

}

}

interface second {

default public void display() {

System.out.println("This is the display function of interface second");

}

}


public class MyClass implements first, second {
    public static void main(String args[]) {
      
    MyClass object = new MyClass();
    object.display();
    }
}
