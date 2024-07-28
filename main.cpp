#include <iostream>
#include <string>

using namespace std;

string addition(string num1, string num2) {
    ssize_t l1 = num1.length() - 1, l2 = num2.length() - 1;
    string num3;
    bool over = false;
    if (l1 < l2) {
        swap(num1, num2);
        swap(l1, l2);
    }
    while (l2 >= 0) {
        num3.push_back((num1[l1] - '0' + num2[l2] - '0' + over) % 10 + '0');

        if (num1[l1] - '0' + num2[l2] - '0' + over >= 10) {
            over = true;
        } else {
            over = false;
        }
        l1--;
        l2--;
    }

    while (l1 >= 0) {
        num3.push_back((num1[l1] - '0' + over) % 10 + '0');
        if (num1[l1] - '0' + over >= 10) {
            over = true;
        } else {
            over = false;
        }
        l1--;
    }

    if (over) {
        num3.push_back('1');
    }

    reverse(num3.begin(), num3.end());

    return num3;
}

string subtraction(string num1, string num2) {
    ssize_t l1 = num1.length() - 1, l2 = num2.length() - 1,l3;
    string num3;
    bool over = false,flag= true;

    if(num1==num2){
        return "0";
    }

    if (l1 < l2) {
        swap(num1, num2);
        swap(l1, l2);
        flag= false;
    }

    while (l2 >= 0) {
        if (num1[l1] >= num2[l2]) {
            num3.push_back((num1[l1] - '0' - num2[l2] + '0' - over) + '0');
            over= false;
        } else {
            num3.push_back((num1[l1] - '0' + 10 - num2[l2] + '0' - over) + '0');
            over = true;
        }
        l1--;
        l2--;
    }

    while (l1 >= 0) {
        if(over){
            if(num1[l1]=='0'){
                over= true;
                num3.push_back((num1[l1] - '0' + 10 - over)  + '0');
            }else{
                num3.push_back((num1[l1] - '0' - over) + '0');
                over= false;
            }
        }else{
            num3.push_back((num1[l1] - '0' )  + '0');
        }
        l1--;
    }

    if(over){
        num3.pop_back();
    }

    l3=num3.length()-1;
    while(num3[l3]-'0'==0){
        num3.pop_back();
        l3--;
    }

    if(!flag){
        num3.push_back('-');
    }

    reverse(num3.begin(), num3.end());

    return num3;

}

int main() {
    cout << subtraction("100", "100") << endl;
    cout << subtraction("100", "1") << endl;
    cout << subtraction("1", "100") << endl;
    return 0;
}
