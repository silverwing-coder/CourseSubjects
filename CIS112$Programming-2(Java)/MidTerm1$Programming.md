<h3>Midterm Exam #1, Programming Question Code</h3>
<h4> CreatePolygon Class </h4>

```java
import java.util.Scanner;

public class CreatePolygon {

	public static void main(String[] args) {
		// TODO: Create a scanner object to read three data from the standard input
		Scanner scnr = new Scanner(System.in);
				
		// TODO:. Read a String for polygon type and two double values
		String polygonShape = scnr.next();
		double num1 = scnr.nextDouble();
		double num2 = scnr.nextDouble();
					
		// TODO: Create a Triangle or Rectangle object from the polygonShape, and print the polygon data by calling printInfo()
		/**
		 - if polygolShape is 'triangle', create a Triangle object with num1 as base and num2 as height
		 - else if polygonShape is 'rectangle', create a Rectangle object with num1 as width and num2 as height
		 - else print "Input error!" and exit the program
		*/
		
		if (polygonShape.equals("triangle")) {
			Triangle triangle = new Triangle(num1, num2);
			triangle.printInfo();
		}
		else if (polygonShape.equals("rectangle")) {
			Rectangle rectangle = new Rectangle(num1, num2);
			rectangle.printInfo();
		}
		else {
			System.out.println("Input error!");
		}
	}

}


```

<h4> Triangle Class </h4>

```java
public class Triangle {
	
	// TODO: Create private fields of base and height
	private double base;
	private double height;
	
	
	//  TODO: Create a constructor that receives the value of base and height
	public Triangle(double base, double height) {
		this.base = base;
		this.height = height;
	}
	
	//  TODO: Create a public method of getArea() that returns the area of triangle
	public double getArea() {
		return this.base * this.height / 2;
	}
	
	//  TODO: Create a public method of printInfo() that printing the value of it's properties as
	/**
	 * 		Triangle	
	 *  	- Base:   xx.xx inches
	 *  	- Height: xx.xx inches 
	 *  	- Area  : xx.xx square inches 
	 */
	
	public void printInfo() {
		System.out.println("	Triangle");
		System.out.printf("	  - Base: %.2f inches", this.base);
		System.out.printf("	  - Height: %.2f inches", this.height);
		System.out.printf("	  - Area: %.2f square inches", this.getArea());
	}
}


```

<h4> Rectangle Class </h4>

```java

public class Rectangle {
	
	//  TODO: Create private fields of width and height
	private double width;
	private double height;
		
	//  TODO: Create a constructor that receives the value of width and height
	public Rectangle(double width, double height) {
		this.width = width;
		this.height = height;
	}
	
	//  TODO: Create a public method of getArea() that returns the area of rectangle	
	public double getArea() {
		return this.width * this.height;
	}
	
	//  TODO: Create a public method of printInfo() that printing the value of it's properties as
	/**
	 * 		Rectangle	
	 *  	- Width:  xx.xx inches
	 *  	- Height: xx.xx inches 
	 *  	- Area  : xx.xx square inches 
	 */
	
	public void printInfo() {
		System.out.println("	Rectangle");
		System.out.printf("	  - Width: %.2f inches", this.width);
		System.out.printf("	  - Height: %.2f inches", this.height);
		System.out.printf("	  - Area: %.2f square inches", this.getArea());
	}
}


```
