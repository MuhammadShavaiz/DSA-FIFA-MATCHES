using namespace std;
#include "parser.h"


//main creates an object of parser 1 class
//main calls parser method of parser1 class
//main calls mainmenu methos of parser1 class

int main(){
        cout<<"DSA PROJECT: FIFA MATCHES DATA STRUCTURING\n";
        parser1 * element = new parser1;
        element->parser();
        element->mainmenu();


    return 0;
}
