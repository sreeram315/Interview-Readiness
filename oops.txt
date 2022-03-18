#include<bits/stdc++.h>
using namespace std;


class Employee{
	static int count;

	protected:
	int id, age, salary, *years_of_service, total_years;
	string name;

	public:

		Employee():id(++count){/*printf("DEFAULT");*/}																		// Default constructor										
		Employee(string name, int age, int salary): id(++count), name(name), age(age), salary(salary), total_years(0){ /*printf("Parameterized ");*/} // Parameterized constrcutor
		Employee(const Employee &obj):  id(++count), name(obj.name), age(obj.age), salary(obj.salary), total_years(obj.total_years){ // Copy constructor
			this->years_of_service = (int*)malloc(sizeof(int)*obj.total_years);
			for(int i = 0; i < obj.total_years; i++)
				this->years_of_service[i] = obj.years_of_service[i];	// copy manually - dynamically allocated data(deep copy)
																		// otherwise only pointer will be copied. 
		}
		~Employee(){
			printf(" Destructing %s\n", name.c_str());
			if(total_years!=0)
				free(years_of_service);										// destrcutor to deallocate dynamically allocated space
		}
										
	void add_service(const int year){
		years_of_service = (int *)realloc(years_of_service, total_years+1);
		years_of_service[total_years++] = year;
	}

	void change_name(const string name){
		this->name = name;
	}

	void edit_serve(const int i, const int year){
		years_of_service[i] = year;
	}

	void print(){
		printf("\n ID     : %d\n Name   : %s\n Age    : %d\n Salary : %d\n N years: %d\n", id, name.c_str(), age, salary, total_years);
		printf(" Years of service: ");
		for(int i = 0; i < total_years; i++)
				printf("%d, ", years_of_service[i]);
		printf("\n");
	}

	virtual int get_eid_bonus(){				// virtual to skip when using Teacher, Trainer, or TeachTrainer object
		return 0;
	}

	Employee* operator +(const Employee& e2){
		int age 	= this->age + e2.age,
			salary  = this->salary + e2.salary;
		string name = this->name + " " + e2.name;
		Employee *e3 = new Employee(name, age, salary);
		return e3;
	}

	static int get_total_employees();
	friend int get_salary(const Employee&);
	friend class Director;

};

int Employee:: get_total_employees(){
	return count;
}

int Employee:: count = 0;

class Teacher: virtual public Employee{			// virtual because this is used in multiple inheritence later (avoid diomond problem)
	public:		
		Teacher(){}
		Teacher(string name, int age, int salary): Employee(name, age, salary) {}

	int get_eid_bonus(){						// virtual to skip when using TeachTrainer object
		int diwali_bonus = salary*0.1;
		return diwali_bonus;
	}
};

class Trainer: virtual public Employee{			// virtual because this is used in multiple inheritence later
	public:
		Trainer(){}
		Trainer(string name, int age, int salary): Employee(name, age, salary) {}

	int get_eid_bonus(){						// virtual to skip when using TeachTrainer object
		int diwali_bonus = salary*0.05;
		return diwali_bonus;
	}
};

class TeachTrainer:  public Teacher, Trainer{
	public:
		TeachTrainer(string name, int age, int salary): Teacher(name, age, salary), Trainer(name, age, salary), Employee(name, age, salary) {}

	int get_eid_bonus(){						// employees object calling get_eid_bonus() skips two level to come here
		int diwali_bonus = salary*0.15;
		return diwali_bonus;
	}

};

class MathTeacher: public Teacher{				// Multilevel inheritence
	set<int>sections;
	public:
		MathTeacher(string name, int age, int salary): Teacher(name, age, salary), Employee(name, age, salary){}

	void print(){
		Teacher::print();
		printf(" Section: ");
		for(int x: sections) printf("%d, ", x);
		printf("\n");
	}

	void add_section(const int section){
		sections.insert(section);
	}

	void add_section(const vector<int>& sections){	// Function overloading
		for(const int &section: sections)
			this->sections.insert(section);
	}
};

int get_salary(const Employee& E){				// Friend of Employee
	return E.salary;
}

class Director: public Employee{				// friend of Employee (declared by Employee)
	public:
		Director(string name, int age, int salary):Employee(name, age, salary) {}
	
	int get_employee_salary(const Employee& e){	// Employee declared Director as friend class, so this class can access Employee's private data
		return e.salary;
	}
};




int main(){
	/* Constructors, Dynamic allocation deep copy, Static members.

	Employee wira("Sreeram", 21, 1000);
	wira.add_service(2003);
	wira.add_service(2004);
	wira.print();

	Employee ram(wira);
	ram.change_name("Ram");
	ram.edit_serve(0, 1717);
	ram.print();

	Employee maram(wira);
	maram.change_name("Maram");
	maram.edit_serve(0, 1450);
	maram.print();

	printf("\n No. of Employees: %d\n", Employee::get_total_employees());
	*/
	



	/* Inheritence, Virtual function

	printf("\n");
	Teacher golu("Golu", 31, 30000);
	Trainer laddu("Laddu", 27, 23000);
	golu.print();
	laddu.print();

	Employee *e1 = &golu, *e2 = &laddu;

	printf("\n Golu Diwali Bonus: %d\n", e1->get_eid_bonus());
	printf(" Laddu Diwali Bonus: %d\n", e2->get_eid_bonus());

	Employee *sachin = new TeachTrainer("Sachin", 30, 10000);
	printf("\n Sachin's Diwali Bonus: %d\n", sachin->get_eid_bonus());
	*/



	/* Multiple inheritence, virtual inheritence for diamond problem

	TeachTrainer man("man", 30, 5000);
	man.print();
	*/



	/* Multilevel inheritence, function overloading, parent function calling using scope specifier

	MathTeacher guru("Guru", 21, 8000);
	guru.add_section(1);
	guru.add_section({1,2,3});
	guru.print();
	*/



	/* Operator overloading

	Employee rajini("Rajini", 23, 100000), kanth("Kanth", 37, 20000); 
	Employee *rajinikanth = rajini+kanth;
	rajini.print();
	kanth.print();
	rajinikanth->print();
	delete rajinikanth;
	*/



	/*	Friend function, Friend class

	Employee maara("Maara", 22, 10000);
	maara.print();
	printf(" Maara's Salary: %d\n", get_salary(maara));
	Director loviraj("Loviraj", 52, 700000);
	loviraj.print();
	printf(" Loviraj says Maara's salary is: %d\n", loviraj.get_employee_salary(maara));
	*/
	printf("\n\n");
	return 0;
}

/*

OOPs!

Class - user defined data type
- ease of programming
- security (at least trying)
- Inheritance (less code, consistency)
- polymorphism
    - Static - one name, multiple functionalities (function overloading)
    - Dynamic - at run time deciding what class’s function to class (virtual functions)
- private (abstraction)
- bundling related data (encapsulation)

Constructor - Initialise object
- Initialisers
    - Assignment instead of initialisers list will cause the variable to first take its default value, and then get assigned with its said value. Fine for primitive data types, but if the variable is an object of another class, then its constructor would be called twice. Hence its good to use initialisers instead of assigning inside the constructor.
- Default constructor
- Parameterised constructor
- Copy constructor
    - Default Copy constructor - Shallow copy (data assigned, so pointers addresses are copied not data inside)
    - We define ourselves to make deep copy
    - Passing to copy constructor should be by reference to avoid infinite recursion of constructors
- Destructor
    - Destroy object
    - Default is there. But if we allocate memory dynamically better destroy them when we done need.
    - delete keyword calls destructor

this pointer
- const pointer to self object
- to distinguish when parameter names collide
- chained calling by returning pointer (ex: cout)

Static members
- variables and methods
- unique for all instances of the class
- static variables to be initialised outside class
- static functions cannot access non-static data or call non-static functions. no this pointer.
- Access: ClassName::var, ClassName::get_var();
- member functions can access static data.

Inheritance
- For reusability, consistency, ease.
- protected access (accessible to inherited classes)
- Parent class is initialised first when subclass object is created.
    - Creating subclass, make sure Parent class has default constructor so it can be created. Or create it using other type of constructors in subclass’s constructor.
- Inheritance type - Access specifier (public, protected, private)
    - defines how the public and protected data in parent class should be inherited as.
    - Security can increase, but cannot decrease. Hence private always stays as private.
    - ie. public data of parent class can be made private(private inheritance) or protected(protected inheritance) in child class; protected data can be made private (private inheritance). But private cannot be accessed, protected cannot be made public.

Virtual function
- Normal function func: p.func(); p’s func is executed
- virtual function func: p.func(); p’s func is executed only if p points to an object of class type p. otherwise call function of whatever object it points to (if exists, else p’s func is executed).
- i.e. Base classes pointer skips its own function and calls function of derived class whichever class’s object its pointing to.
- Helps in keeping all pointers as same type even if we needed to call different functions on them.
- Virtual -> if it can skip it and go go to downer level, it will. (if object is also downer level)

Multiple inheritance
- Constructors are called left to right.
- Diamond problem(multiple constructor calls of grand parent class). Virtual inheritance to avoid it.

Multilevel inheritance
- Note: A:B:C inheritance. If C calls B’s Parameterised constructor, B calls A’s default constructor only. TO avoid this C can call both A and B’s constructors directly.

Friend function
- a class can specify its friend functions and friend classes. these people can access this class’s private data.
- Friendship is granted, cannot be taken.
- Friendship is not inherited, hence also not transitive.

Operator overloading
- Global and class method both possible. in class method this pointer is accessible so parameters can be decresed by one. Also can access private data.
- precedence of operators stays
- . , :: , ?: cannot be overloaded
- assignment operator is created by default (but shallow copy)

- Anonymous objects
    - created without assigning a reference to them. Thus, they can be used only once (i.e. in the same statement only)

- Shallow copy: dynamic memory is referred, not copied
    - ie. since variables are copied, pointers are also copied, but not what lies inside of pointers.

- Polymorphism
	- Ability of object variables to take multiple forms (comes by inheritence)
	- Compile time: function overloading (different arguments)
	- Run tie: function overiding (virtual keyword)

- Abstract
	- Abstract functions
		- methods that are not defined in the base class. To enfore to define in derived classes.
		- In c++ abtract funtions are declared by assigning 0 to them. "virtual void show() = 0;"
	- Abstract class
		- classes contaning abstract functions. Objects to these cannot be declared. Pointers can be declared.
		- If the derived class also does not define the function, it also becomes abstract.

Singleton class
	- Only one object is possible to be created. To mutually access a single resource.
	- Can be made by making constructor private. And one static method to return the object pointer.

- Variable types
	- Static
		- Variables: stored in data segment. Lifetime is till end of program execution. 
		  One per function. One per file case of global static variables.
		- Functions: class methods, so they can be called without object. Helps getting object ref in singleton class.
	- Volatile
		- Telling compiler that the value could change because of external means. 
		  So dont do any optimizations to program that includes this variable.
	- Extern
		- Telling compiler that variable exists in different file. Hence no memory alotted.

pure virtual -> abstract fucntions
virtual constructor -> not possible in C++
virtual destructors -> to call destructures of derived classes


*/





