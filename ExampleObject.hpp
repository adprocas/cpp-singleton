#pragma once

#include <process.h>
#include <iostream>
#include <Windows.h>

class ExampleObject {
	CRITICAL_SECTION cs;
	int i = 0;
	//Make it so a new object can't be copied in a constructor
	ExampleObject(ExampleObject const&) = delete;
	//Delete the copy operator
	ExampleObject& operator=(ExampleObject const&) = delete;

protected:
	ExampleObject() {}
	virtual ~ExampleObject() {}

public:
	void increment() {
		InitializeCriticalSection(&cs);
		EnterCriticalSection(&cs);
		++i;
		std::cout << "++ Increment :: " << i << std::endl;
		LeaveCriticalSection(&cs);
	}

	void printMessage() {
		std::cout << "----------- Number is " << i << std::endl;
	}

	void printThreadNum(int i) {
		std::cout << "Thread #: " << i << std::endl;
		increment();
	}
};