#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;


/*Create a class named Circle that has the double radius as a single private member variable.
Include public member functions getRadius, setRadius, and area. The prototypes for the functions are:

double getRadius()
void setRadius(double r)
double area()
getRadius and setRadius are the normal "getter" and "setter" member functions for radius.
 The area member function calculates and returns the area of the circle using the formula:

area = 3.1416 * radius * radius.
A one-parameter constructor should set the radius to whatever value is passed to it.

Write a program that creates a vector of Circle objects.  Use the following set of values to initialize the radius of the 10 Circle objects:

 2.5, 3.5, 1.0, 5.5, 4.8, 6.0, 2.75, 10, 0.5, 9.5
Call a function to sort the vector of Circle objects in ascending sequence by radius using either a bubble or selection sort.
 Finally, display the radius and area of the sorted Circle objects in a tabular form.
 A sample of the display format can be found in the Blackboard Review folder

Submit your solution (main.cpp) as the file lab8_annnnnnn.cpp where annnnnnn is your ACC student identification number.*/


class Circle {

	private:
		double radius;

	public:

        Circle(double r) {
			radius=r;
		}


		~Circle() {

		}


		void setRadius(double r) {
			radius = r;
		}


		double getRadius() {
			return radius;
		}

		double area() {
			return(3.1416 * radius * radius);
		}
};

void sortVector(vector<Circle>& numbers, int size);
void printVectors(vector<Circle>& numbers);

int main(int argc, char** argv) {

    vector <Circle> CircleObject = {2.5, 3.5, 1.0, 5.5, 4.8, 6.0, 2.75, 10, 0.5, 9.5};

    sortVector(CircleObject, CircleObject.size());


    cout << fixed << setprecision(2);
	cout << "Lab 8 - Sorted Vector of Circles" << endl;
	cout << "--------------------------------\n" << endl;
	cout << setw(6) << "Radius" << setw(8) << "Area" << endl;
	cout << setw(6) << "------" << setw(8) << "----" << endl;

	printVectors(CircleObject);

	cout << "\n--------------------------------";


	return 0;
}

 void sortVector(vector<Circle>& numbers, int size){
    double temp;
    bool swap;

 do {
        swap = false;
        for (int count = 0; count < (size - 1); count++){
        if (numbers[count].getRadius() > numbers[count + 1].getRadius()){
            temp = numbers[count].getRadius();
            numbers[count] = numbers[count + 1];
            numbers[count + 1] = temp;
            swap = true;
            }
        };

 } while (swap);
}


void printVectors(vector<Circle>& numbers){
    for(int i = 0; i<numbers.size(); i++) {
		cout << setw(6) << numbers[i].getRadius() << setw(8) << numbers[i].area() << endl;
	};
}

/*
version #2:

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Circle {

	private:
		double radius;

	public:

				Circle(double r) {
			radius=r;
		}


		~Circle() {

		}


		void setRadius(double r) {
			radius = r;
		}


		double getRadius() {
			return radius;
		}

		double area() {
			return(3.1416 * radius * radius);
		}
};

struct Circles{
        double radius;
        double area = 0;
    };

void sortVector(vector<Circles>& numbers, int size);
void printVectors(vector<Circles>& numbers);

int main(int argc, char** argv) {

    double radiuses[] = {2.5, 3.5, 1.0, 5.5, 4.8, 6.0, 2.75, 10, 0.5, 9.5};

	vector<Circles> CircleObjects(10);

	for (int i=0; i < CircleObjects.size(); i++){
        CircleObjects[i].radius = radiuses[i];
	}

	sortVector(CircleObjects, CircleObjects.size());

	for (int i=0; i < CircleObjects.size(); i++){
        Circle circle(CircleObjects[i].radius);
        CircleObjects[i].area = circle.area();
	}

    cout << fixed << setprecision(2);
	cout << "Lab 8 - Sorted Vector of Circles" << endl;
	cout << "--------------------------------\n" << endl;
	cout << setw(6) << "Radius" << setw(8) << "Area" << endl;
	cout << setw(6) << "------" << setw(8) << "----" << endl;

	printVectors(CircleObjects);

	cout << "\n--------------------------------";


	return 0;
}

void sortVector(vector<Circles>& numbers, int size)
 {
    double temp;
    bool swap;

 do {
        swap = false;
        for (int count = 0; count < (size - 1); count++){
        if (numbers[count].radius > numbers[count + 1].radius){
            temp = numbers[count].radius;
            numbers[count].radius = numbers[count + 1].radius;
            numbers[count + 1].radius = temp;
            swap = true;
            }
        };

 } while (swap);

 }

void printVectors(vector<Circles>& numbers){
    for(int i = 0; i<numbers.size(); i++) {
		cout << setw(6) << numbers[i].radius << setw(8) << numbers[i].area << endl;
	};
}
*/
