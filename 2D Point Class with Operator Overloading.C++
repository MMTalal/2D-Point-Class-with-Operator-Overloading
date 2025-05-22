#include <iostream> // Required for input/output operations (cin, cout)
using namespace std; // Allows us to use standard names without prefixing with "std::"

// Define a class named Point to represent a point in 2D space
class Point {
private:
    int x; // The X-coordinate of the point
    int y; // The Y-coordinate of the point

public:
    // Default constructor: initializes point to (0, 0)
    Point() 
    {
        x = 0;
        y = 0;
    }

    // Parameterized constructor: initializes point with given x and y values
    Point(int x, int y) : x(x), y(y) 
    {
        // The colon (:) syntax is called a member initializer list
    }

    // Setter function for X-coordinate
    void setX(int x) 
    {
        this->x = x; // "this->x" refers to the class member, "x" is the parameter
    }

    // Getter function for X-coordinate
    int getX() 
    {
        return x;
    }

    // Setter function for Y-coordinate
    void setY(int y) 
    {
        this->y = y;
    }

    // Getter function for Y-coordinate
    int getY() 
    {
        return y;
    }

    // Member function to print current coordinates of the point
    void info() 
    {
        cout << "X:" << getX() << " Y:" << getY() << endl;
    }

    // Operator overloading: Multiply two Point objects (element-wise)
    // Returns a new Point where x = this->x * p.x, and y = this->y * p.y
    Point operator* (const Point &p) 
    {
        return Point(x * p.x, y * p.y);
    }

    // Operator overloading: Multiply Point by a scalar value (int)
    Point operator* (int num) 
    {
        return Point(x * num, y * num);
    }

    // Operator overloading: Subtract another Point from this Point (element-wise)
    Point operator-= (const Point &p) 
    {
        x -= p.x; // Subtract x value of p from current x
        y -= p.y; // Subtract y value of p from current y
        return *this; // Return current object after modification
    }

    // Operator overloading: Subtract a scalar from both coordinates
    Point operator-= (int num) 
    {
        x -= num;
        y -= num;
        return *this;
    }

    // Operator overloading: Compare if this Point is greater than or equal to another Point
    // Comparison is true if both x and y are greater than or equal respectively
    bool operator>= (const Point &p) const 
    {
        return (x >= p.x && y >= p.y);
    }
    
    // Add these functions inside the Point class:

    // Pre-increment operator (++Point)
    // Increments x and y by 1 and returns the modified object
    Point& operator++() 
    {
        ++x;
        ++y;
        return *this; // return reference to the current object
    }
    
    // Post-increment operator (Point++)
    // Increments x and y by 1 but returns the original (unmodified) object
    Point operator++(int) 
    {
        Point temp = *this; // store current state
        ++(*this);          // use pre-increment logic
        return temp;        // return old state
    }
    
    // Pre-decrement operator (--Point)
    Point& operator--() 
    {
        --x;
        --y;
        return *this;
    }
    
    // Post-decrement operator (Point--)
    Point operator--(int) 
    {
        Point temp = *this;
        --(*this);
        return temp;
    }
    
    friend istream& operator>> (istream &cin, Point &p);
    // Overload the input stream operator (>>) to allow direct input of Point objects.
    // Declared as a friend to access private/protected members if needed.

    friend ostream& operator<< (ostream &cout, const Point &p);
    // Overload the output stream operator (<<) to allow direct output of Point objects.
    // Declared as a friend to access internal members of the class.
};

istream& operator>> (istream &cin, Point &p)
// This function overloads the >> operator for the Point class.
{
    // Prompt user to enter point coordinates
    cout << "\nEnter a point (X, Y): " << endl;
    // Read x and y values from standard input into the point object
    cin >> p.x >> p.y;
    // Return the stream object to allow chaining (e.g., cin >> p1 >> p2)
    return cin; 
}

ostream& operator<< (ostream &cout, const Point &p)
// This function overloads the << operator for the Point class.
{
    // Inform the user that the point is being printed
    cout << "\nThis point is Printed:" << endl;
    // Output the x and y coordinates separated by space
    cout << p.x << " " << p.y << endl;
    // Return the stream object to allow chaining (e.g., cout << p1 << p2)
    return cout;
}


int main() {
    // Create point P1 using parameterized constructor
    Point P1(5, 3);
    P1.info(); // Output: X:5 Y:3

    // Create point P2
    Point P2(10, 9);
    P2.info(); // Output: X:10 Y:9

    // Multiply P1 by P2 (element-wise)
    cout << endl << "P1 * P2" << endl;
    Point P3 = (P1 * P2); // Result: (5*10, 3*9) = (50, 27)
    P3.info();

    // Multiply P1 by scalar 3
    cout << endl << "P1 * 3" << endl;
    Point P4 = (P1 * 3); // Result: (5*3, 3*3) = (15, 9)
    P4.info();

    // Multiply P2 by scalar 3
    cout << endl << "P2 * 3" << endl;
    Point P5 = (P2 * 3); // Result: (10*3, 9*3) = (30, 27)
    P5.info();

    // Subtract P2 from P1
    cout << endl << "P1 -= P2" << endl;
    Point P6 = (P1 -= P2); // New P1 = (5-10, 3-9) = (-5, -6)
    P6.info();

    // Optional: Uncomment below to test P2 -= P1
    /*
    cout << endl << "P2 -= P1" << endl;
    Point P7 = (P2 -= P1);
    P7.info();
    */

    // Subtract scalar 3 from P1
    cout << endl << "P1 -= 3" << endl;
    Point P8 = (P1 -= 3); // New P1 = (-5 - 3, -6 - 3) = (-8, -9)
    P8.info();

    // Subtract scalar 3 from P2
    cout << endl << "P2 -= 3" << endl;
    Point P9 = (P2 -= 3); // New P2 = (10 - 3, 9 - 3) = (7, 6)
    P9.info();

    // Compare P1 >= P2
    cout << endl << "if P1 >= P2" << endl;
    cout << (P1 >= P2 ? "Greater or Equal" : "Not Greater or Equal.") << endl;

    // Compare P2 >= P1
    cout << endl << "if P2 >= P1" << endl;
    cout << (P2 >= P1 ? "Greater or Equal" : "Not Greater or Equal.") << endl;
    
    cout << endl << "Pre-increment (++P1):" << endl;
    P1 = Point(5, 3); // Reset P1
    Point P10 = ++P1;
    P10.info(); // Both x and y increased by 1
    
    cout << endl << "Post-increment (P1++):" << endl;
    P1 = Point(5, 3); // Reset P1
    Point P11 = P1++;
    P11.info(); // Still shows incremented values
    
    cout << endl << "Pre-decrement (--P1):" << endl;
    P1 = Point(5, 3); // Reset P1
    Point P12 = --P1;
    P12.info(); // Both x and y decreased by 1
    
    cout << endl << "Post-decrement (P1--):" << endl;
    P1 = Point(5, 3); // Reset P1
    Point P13 = P1--;
    P13.info(); // Still shows decremented values

    Point p;               // Create a Point object 'p'
    cin >> p;              // Use overloaded >> operator to input coordinates for p
    // Behind the scenes: operator>>(cin, p) is called
    cout << p;             // Use overloaded << operator to output coordinates of p
    // Behind the scenes: operator<<(cout, p) is called

    return 0; // Indicate successful program termination
}
