import java.util.*;

class Employee
{
	//name,age,phno,addr,sal
	int age;
	int phone,sal;
	String name=new String();
	String add=new String();
	Employee(int a,int b,int c,String d,String e)
	{
		age=a;
		phone=b;
		sal=c;
		name=d;
		add=d;
	}
	void printSalary()
	{
		System.out.println("Salary: "+sal);
	}
}

class Officer extends Employee
{
	String spl=new String();
	Officer(int age,int phone,int sal,String name,String add,String f,String g)
	{
		super(age,phone,sal,name,add);
		spl=f;
	}
	void display()
	{
		System.out.println();
		System.out.println("Officer's Copy:-");
		System.out.println("Name: "+name);
		System.out.println("Age: "+age);
		System.out.println("Phone number: "+phone);
		System.out.println("Address: "+add);
		System.out.println("Salary: "+sal);
		System.out.println("Specialization: "+spl);
	}
}

class Manager extends Employee
{
	String dpt=new String();
	Manager(int age,int phone,int sal,String name,String add,String f,String g)
	{
		super(age,phone,sal,name,add);
		dpt=g;
	}
	void display()
	{
		System.out.println();
		System.out.println("Manager's Copy:-");
		System.out.println("Name: "+name);
		System.out.println("Age: "+age);
		System.out.println("Phone number: "+phone);
		System.out.println("Address: "+add);
		System.out.println("Salary: "+sal);
		System.out.println("Department: "+dpt);
	}
}

class EmpDemo
{
	public static void main(String Args[])
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the name of the employee:");
		String name=new String(sc.nextLine());
		System.out.println("Enter the address of the employee:");
		String add=new String(sc.ne xtLine());
		System.out.println("Enter the specialization of the employee:");
		String spl=new String(sc.nextLine());
		System.out.println("Enter the department of the employee:");
		String dpt=new String(sc.nextLine());
		System.out.println("Enter the age of the employee:");
		int age=sc.nextInt();
		System.out.println("Enter the phone number of the employee:");
		int phone=sc.nextInt();
		System.out.println("Enter the salary of the employee:");
		int sal=sc.nextInt();
		
		//Employee s1=new Employee(age,phone,sal,name,add,spl,dpt);
		Officer o1=new Officer(age,phone,sal,name,add,spl,dpt);
		Manager m1=new Manager(age,phone,sal,name,add,spl,dpt);
		o1.display();
		m1.display();
	}
}
