#include <iostream>
#include <string>

using namespace std;

string addition(string num1, string num2) {
    ssize_t l1 = num1.length()-1, l2 = num2.length()-1;
    string num3;
    bool over= false;
    if(l1<l2){
        swap(num1,num2);
        swap(l1,l2);
    }
    while (l2>=0) {
        num3.push_back((num1[l1]-'0'+num2[l2]-'0'+over)%10+'0');

        if(num1[l1]-'0'+num2[l2]-'0'+over>=10){
            over= true;
        }else{
            over= false;
        }
        l1--;
        l2--;
    }

    while(l1>=0){
        num3.push_back((num1[l1]-'0'+over)%10+'0');
        if(num1[l1]-'0'+over>=10){
            over= true;
        }else{
            over= false;
        }
        l1--;
    }

    if(over){
        num3.push_back('1');
    }

    reverse(num3.begin(), num3.end());

    return num3;
}

int main() {
    cout<<addition("12345675","0")<<endl;
    return 0;
}
