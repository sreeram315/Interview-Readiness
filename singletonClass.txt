#include<iostream>
#include<vector>
using namespace std;

int data = 7; // unique external resource being used

class ObjectPointer{
	int* ptr;
	static ObjectPointer* instance;
	ObjectPointer(){
		ptr = &data;
	}
public:

	int get_data(){
		return *ptr;
	}

	void put_data(int data){
		*(this->ptr) = data;
	}

	static ObjectPointer* get_ptr(){
		if(!instance)
			instance = new ObjectPointer();
		return instance;
	}
};
ObjectPointer* ObjectPointer:: instance = NULL;

int main(){
	ObjectPointer* objptr = ObjectPointer::get_ptr();
	printf("Data is: %d\n", objptr->get_data());
	objptr->put_data(11);

	ObjectPointer* objptr2 = ObjectPointer::get_ptr();
	printf("Data is: %d\n", objptr2->get_data());
	data = 20;
	printf("Data is: %d\n", objptr2->get_data());
	printf("---------------\n");
}
