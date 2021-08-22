class Car
{
protected void getData()
{
System.out.println("Inside car");
}
}
class Innova extends Car
{
protected void getData()
{
System.out.println("Inside Innova");
}
}

public class MyClass {
    public static void main(String args[]) {
        Car car = new Innova();
        car.getData();
    }
}
class A 
{
    public int i;
    protected int j;
}
 
class B extends A 
{
    int j;
    void display() 
    {
        super.j = 3;
        System.out.println(i + " " + j);
    }
} 
