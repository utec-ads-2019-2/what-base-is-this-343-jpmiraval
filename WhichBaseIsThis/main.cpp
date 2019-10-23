#include <iostream>
#include <cmath>
#include <string>
using namespace std;

bool esNumero(char x){
    char numeros[10] = {'0','1','2','3','4','5','6','7','8','9'};
    for(char c : numeros)
        if (x == c){
            return true;
        }
    return false;
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

void searchComonBase(const string& x, const string& y){
    int xBase = minBase(x);
    int yBase = minBase(y);
    for(int i = xBase; i<=36; i++){
        for(int j = yBase; j<=36; j++){
            if(base10(x, i) == base10(y, j)){
                cout<< x <<" (base "<<i<<") = "<< y <<" (base "<<j<<")\n";
                return;
            }
        }
    }
    cout<<x<<" is not equal to "<<y<<" in any base 2..36\n";
}

int main() {
    string num1;
    string num2;
    while(cin>>num1>>num2){
        searchComonBase(num1, num2);
    }
    return 0;
}