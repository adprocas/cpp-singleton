# C++ Singleton example using C++11 and Windows.h

######
# Info
######

I believe that using smart pointers makes the Singleton thread safe.  I have provided a small test at the beginning of the program with multiple threads.

I'm also using CRITICAL_SECTION with InitializeCriticalSection, EnterCriticalSection, and LeaveCriticalSection to keep the critical part of the ExampleObject thread safe.

This program will only run on Windows for these reasons.  CRITICAL_SECTION is a Windows thing.  You would need to figure out a way to do this elsewhere if you want to use this.

If you have any comments or suggestions to make this better, or if you know why it wouldn't work properly, please let me know.
