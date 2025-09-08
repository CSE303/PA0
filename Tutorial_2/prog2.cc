#include <string>
#include "printer.h"

// We need an external declaration of the printSomething() function, or else we
// can't compile this file.
void printSomething(std::string message);

/// Use the `printSomething` function to print "Hello World"
int main() { printSomething("Hello World"); }