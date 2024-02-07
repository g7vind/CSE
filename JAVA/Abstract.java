abstract class Shape
{
	abstract void numberofsides();
}

class Rectangle extends Shape
{
	void numberofsides()
	{
		System.out.println("The number of sides of Rectangle is 4");
	}
}

class Triangle extends Shape
{
	void numberofsides()
	{
		System.out.println("The number of sides of Triangle is 3");
	}
}

class Hexagon extends Shape
{
	void numberofsides()
	{
		System.out.println("The number of sides of Hexagon is 6");
	}
}

class Abstract
{
	public static void main(String args[])
	{
		Rectangle r1 = new Rectangle();
		Triangle t1 = new Triangle();
		Hexagon h1 = new Hexagon();
		r1.numberofsides();
		t1.numberofsides();
		h1.numberofsides();
	}
}

/*
OUTPUT

The number of sides of Rectangle is 4
The number of sides of Triangle is 3
The number of sides of Hexagon is 6

*/