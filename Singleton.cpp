#include "SingletonObject.h"
#include <iostream>

int main() {
	cout << "Testing with threads - printing is not consistent, but increment is, as it " << endl;
	cout << "is using CRITICAL_SECTION, which is only available in Windows currently" << endl;

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

	std::cout << "#### ob1 ##### ---- New Example Object using SingletonObject" << endl;
	ExampleObject* ob1 = &SingletonObject::getSingleton();
	ob1->increment();
	ob1->increment();
	ob1->increment();
	ob1->printMessage();

	std::cout << "#### ob2 ##### ---- New Example Object using SingletonObject" << endl;
	ExampleObject* ob2 = &SingletonObject::getSingleton();
	ob2->increment();
	ob1->printMessage();

	std::cout << "#### ob3 ##### ---- New Example Object using SingletonObject" << endl;
	ExampleObject* ob3 = &SingletonObject::getSingleton();
	ob3->increment();
	ob3->increment();
	ob3->increment();
	ob3->increment();
	ob3->increment();
	ob3->increment();
	ob1->printMessage();

	std::cout << "#### ob4 ##### ---- New Example Object using SingletonObject" << endl;
	ExampleObject* ob4 = &SingletonObject::getSingleton();
	ob4->increment();
	ob4->increment();
	ob4->increment();
	ob1->printMessage();

	std::cout << endl << "Print Message for all 4 objects (ob1, ob2, ob3, ob4) -- final number should be 113" << endl;

	ob1->printMessage();
	ob2->printMessage();
	ob3->printMessage();
	ob4->printMessage();
}