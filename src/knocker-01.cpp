//v 0.1
#include "swap.h"
#include "mydlltest.h"
int main(){
    using namespace std;
    int val0=10,val1=20;
    cout<<"Before swap:  "<<"val0="<<val0<<"   val1="<<val1<<endl;
    swap(val0,val1);
    cout<<"After swap:  "<<"val0="<<val0<<"   val1="<<val1<<endl;
    cout<<"-----46-----"<<endl;
    my_print();
    return 0;
}