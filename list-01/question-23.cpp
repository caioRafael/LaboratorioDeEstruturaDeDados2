#include<iostream>
#include<cstring>
using namespace std; 
void reverter(char num[99]);
int main() {
    char num[99] = "1234";
    reverter(num);

    return 0;
}

 void reverter(char num[99]){
    printf("reverso: %s", strrev(num));
 }