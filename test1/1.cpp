#include <iostream>

using namespace std;

int power(int exp,int num) {
    int i, ret = 1;
    if(num == 0) {
        return 1;
    }
    for(i=0;i<num;i++) {
        ret *= exp;
    }
    return ret;
}

int main() {
    int a, b;
    int aDec = 0, bDec = 0, retVal,i,num;
    cout << "Enter the first integer\n";
    cin >> a;
    cout << "Enter the second integer\n";
    cin >> b;
    i = 10;
    num = 0;
    while( a != 0 ) {
        aDec += (a%i)*(power(7,num));
        num += 1;
        a = a/i;
    }
    while( b != 0 ) {
        bDec += (b%i)*(power(7,num));
        num += 1;
        b = b/i;
    }
    retVal = aDec * bDec;
    
    int retA[100];
    for(i=0; retVal>0; i++)    {    
        retA[i]=retVal%7;    
        retVal = retVal/7;  
    }       
    for(i=i-1;i>0;i--)   {    
        cout << retA[i];    
    }  
    
}
