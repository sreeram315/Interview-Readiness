#include<iostream>
#include<vector>
using namespace std;

template<class T>
class SmartPointer{
	T* ptr;
public:
	SmartPointer(){ }
	void operator=(T *a){
		ptr = a;
	}
	void operator=(T val){
		*ptr = val;
	}
	T& operator*(){
		return *ptr;
	}
	T* operator->(){
		return ptr;
	}
	~SmartPointer(){
		free(ptr);
		printf("Destroying\n");
	}
};

class Employee{
public:
	int id;
	string name;
	Employee(int id, string name): id(id), name(name){}
};

void func(){

	SmartPointer<int> obj;
	obj = new int(7);
	printf("Data: %d\n", *obj);
	*obj = 9;
	printf("Data: %d\n\n", *obj);

	SmartPointer<float> obj2;
	obj2 = new float(7.14);
	printf("Data: %f\n", *obj2);
	*obj2 = 9.124;
	printf("Data: %f\n\n", *obj2);

	SmartPointer<Employee> ram;
	ram = new Employee(1, "ram");
	printf("Employee ID  : %d\n", ram->id);
	printf("Employee Name: %s\n\n", ram->name.c_str());

	return;
}

int main(){
	func();
	printf("----------------\n");
}







