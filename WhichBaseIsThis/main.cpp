#include <iostream>
#include <cmath>
#include <string>
using namespace std;

bool esNumero(char x){
    return isdigit(x) != 0;
}

int ctn(char x){
    if(esNumero(x)) return x - 48;
    else return x - 55;
}

int base10(string num, int base) {
    int numero = 0;
    int power = 0;
    int resultado = 0;
    for(int i = num.size()-1; i >= 0; --i){
        numero = ctn(num[i]);
        resultado += numero * pow(base, power);
        power++;
    }
    return resultado;
}

int minBase(const string& number){
    char maxChar = '1';
    for(char c : number){
        if(maxChar < c){
            maxChar = c;
        }
    }
    return ctn(maxChar) + 1;
}

void BaseComun(const string& num1, const string& num2){
    int xBase = minBase(num1);
    int yBase = minBase(num2);
    for(int i = xBase; i<=36; i++){
        for(int k = yBase; k<=36; k++){
            if(base10(num1, i) == base10(num2, k)){
                cout<< num1 <<" (base "<<i<<") = "<< num2 <<" (base "<<k<<")\n";
                return;
            }
        }
    }
    cout<<num1<<" is not equal to "<<num2<<" in any base 2..36\n";
}

int main() {
    string num1;
    string num2;
    while(cin>>num1>>num2){
        BaseComun(num1, num2);
    }
    return 0;
}
