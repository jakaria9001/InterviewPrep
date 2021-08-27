// YOUR CODE GOES HERE
// Please create 3 classes named Circle, Triangle and Rectangle.
// Derive all classes from Polygon.
// write the defination of area methon for each class


class Rectangle: public Polygon{
    
    public:
        void area ()
        {
            double width, height;
            cin>>width>>height;
            double area = (width * height);
            cout<< fixed<< setprecision(2) << area<< endl;
        }
};

class Triangle: public Polygon{
    public:
        void area ()
        {
            double base, height;
            cin>>base>>height;
            double area = (double(0.5)*base*height);
            cout<< fixed<< setprecision(2) << area<<endl;
        }
};

class Circle: public Polygon{
    
    
    public:
        void area ()
        {
            double radius;
            cin>>radius;
            double area = (3.14*radius * radius);
            cout<< fixed<< setprecision(2) <<  area <<endl;
        }
};
