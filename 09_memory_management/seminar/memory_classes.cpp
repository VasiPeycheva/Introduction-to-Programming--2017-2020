/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

/**
 * @file   memory_classes.cpp
 * @author Ivan Filipov
 * @date   12.2019
 * @brief  Example about different memory classes -
 *         automatic, static, dynamic.
 */


#include <iostream>

/*
    For each type of memory we will take a look at those features:
    - scope (from where we can see/access the defined variable);
    - lifetime (when the variable is created and when destroyed).
*/

/*
    Global variables and global static variable belong to the
    static memory class. They are initialized with zeros by default.
    They are created before entering the main function.
    Their lifetime is the lifetime of the application.
*/
int global_var;
static int static_global_var;
// for the `static` specifier - there is a slight difference,
// which will be discussed during OOP course.

void call_me() {
    // this variable also belong to Static memory class,
    // but is created on the first function call.
    // It is destroyed when the application ends.
    static int call_cnt = 0;

    std::cout << "Total calls: " << call_cnt++ << std::endl;
}

void local_vars() {
/*
    Local variables - belong to Automatic memory class, they are allocated on the Stack.
    These variables are declared within a function and are created when a function is called.
    Their scope is restricted to the function and their lifetime is limited to the time
    the function is executing.
*/

    int x = 11;
    std::cout << "Local variable x: " << x << " at "
              << &x << std::endl;

    if (true) {
        int y = 21;
        // here we can use both x, y and global variables
    }   // y got destroyed

} // here x is destroyed

void dynamic_vars() {

/*
    Dynamic class memory -
    Memory is allocated from the heap and can be released when necessary.
    A pointer references the allocated memory.
    The scope is limited to the pointer or pointers that reference the memory.
    It exists until it is released.
*/
    int* dynamic_int = new int;
    *dynamic_int = 11;
    std::cout << "Dynamic int allocated at: " << dynamic_int
              << " and has value of: " << *dynamic_int << std::endl;

    // we are responsible for dynamic memory releasing!
    delete dynamic_int;
} // here the pointer `dynamic_int` is destroyed. If we haven't called
  // delete dynamic_int; - the pointer to the dynamic memory is lost and the memory - LEAKED!

int main() {

    local_vars();
    dynamic_vars();

    call_me();
    call_me();
    call_me();

    return 0;
}
