class Employee
{
	void display()
	{
		System.out.println("Employee");
	}
	void calcSal()
	{
		System.out.println("Salary of employee is 10000.");
	}
}

class Engineer extends Employee
{
	void calcSal()
	{
		super.calcSal();
		System.out.println("Salary of employee is 20000.");
	}
}

class emp1
{
	public static void main(String args[])
	{
		Engineer o = new Engineer();
		o.display();
		o.calcSal();
	}
}

/*
OUTPUT

Employee
Salary of employee is 10000.
Salary of employee is 10000.

*/