#pragma once

#include "ExampleObject.hpp"
#include <memory>
#include <thread>
#include <vector>
using namespace std;

class SingletonObject : public ExampleObject {

public:
	//return reference to avoid accidental deleting of pointer
	static ExampleObject& getSingleton() {
		static unique_ptr<SingletonObject> singletonInstance(new SingletonObject);
		cout << "==============Singleton Returned==============" << endl;
		return *singletonInstance;
	}
};
