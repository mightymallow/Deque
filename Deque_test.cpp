//
//  Test Program for Deque Class
//
#include <iostream>   // for I/O facilities
#include "Deque.h" //  basic_int_stack declarations

using namespace std;

int main (int argc, char * const argv[]) {

Deque dq1;

Deque * dq3 = new Deque();

dq1.push_left(1);
dq1.push_right(2);
dq1.push_left(3);
dq1.push_right(4);
dq1.display();

Deque dq2(dq1);

delete dq3;

return 0;

}
