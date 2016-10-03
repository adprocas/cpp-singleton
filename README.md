# C++ Singleton example using C++11 and Windows.h

######
# Info
######

I believe that using smart pointers makes the Singleton thread safe.  I have provided a small test at the beginning of the program with multiple threads.

I'm also using CRITICAL_SECTION with InitializeCriticalSection, EnterCriticalSection, and LeaveCriticalSection to keep the critical part of the ExampleObject thread safe.
