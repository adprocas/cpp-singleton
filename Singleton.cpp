#include "SingletonObject.h"
#include <iostream>

int main() {
	std::cout << "#### ob1 ##### ---- New Example Object using SingletonObject" << endl;
	ExampleObject* o1 = &SingletonObject::getSingleton();
	o1->increment();
	o1->increment();
	o1->increment();
	o1->printMessage();

	std::cout << "#### ob2 ##### ---- New Example Object using SingletonObject" << endl;
	ExampleObject* o2 = &SingletonObject::getSingleton();
	o2->increment();
	o1->printMessage();

	std::cout << "#### ob3 ##### ---- New Example Object using SingletonObject" << endl;
	ExampleObject* o3 = &SingletonObject::getSingleton();
	o3->increment();
	o3->increment();
	o3->increment();
	o3->increment();
	o3->increment();
	o3->increment();
	o1->printMessage();

	std::cout << "#### ob4 ##### ---- New Example Object using SingletonObject" << endl;
	ExampleObject* o4 = &SingletonObject::getSingleton();
	o4->increment();
	o4->increment();
	o4->increment();
	o1->printMessage();

	std::cout << endl << "Print Message for all 4 objects (ob1, ob2, ob3, ob4)" << endl;

	o1->printMessage();
	o2->printMessage();
	o3->printMessage();
	o4->printMessage();


	cout << "Testing with threads" << endl;
	vector<thread> threads;
	int const THREAD_NUM = 100;
	for (int i = 1; i <= THREAD_NUM; ++i) {
		threads.push_back(
			thread(
				[](int num) { SingletonObject::getSingleton().printThreadNum(num);  }, i
			)
		);
	}
	
	cout << "joining threads....." << endl;
	
	for (thread& t : threads) {
		t.join();
	}

	cout << "Ending program - printing out for the four objects again - final number should be 113" << endl;

	o1->printMessage();
	o2->printMessage();
	o3->printMessage();
	o4->printMessage();
}