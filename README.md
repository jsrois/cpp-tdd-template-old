#C++ TDD template
##with CMake, GoogleTest and FakeIt


This template project is especially suited for kata-like programming exercises.
It uses CMake to manage dependencies and to compile the binaries. 

The following dependencies are included:

- [**GoogleTest**](https://github.com/google/googletest) is one of the most advanced and complete tools for unit testing in C++.
- [**FakeIt**](https://github.com/eranpeer/FakeIt) is a fresh and flexible tool for creating _mocks_, _stubs_ and other types of _double_ objects. 
While GoogleMock (included in GoogleTest) provides such tools as well, FakeIt uses some of the latest features in the C++ standard
 to provide a simple, _Mockito_-style syntax.