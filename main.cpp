#include<iostream>
#include<algorithm>
using namespace std;


int get(char c) {
   if(c >= '0' && c<='9')
          return int(c-'0');        //decimal value of given number
   else
          return int(c-'A'+10);        //for Alphanumeric numbers
}


char rev(int n) {
   if(n >= 0 && n <=9)
          return char(n+'0');        //character value of given number
   else
          return char(n+'A'-10);        //for Alphanumeric numbers, get alphabet from decimal
}


int baseNtoDec(string number, int base) {
   int len = number.size();
   int power = 1;
   int num = 0;


   for(int i = len-1; i>= 0; i--) {        //from last digit to first digit
          if(get(number[i]) >= base)
             return -1;   //when a digit is >= base, return -1
          num += get(number[i])*power;
          power = power*base;
   }
   return num;
}


string decToBaseN(int dec, int base) {
   string res = "";        //empty string
   while(dec > 0) {
          res += rev(dec%base);
          dec /= base;
   }


   reverse(res.begin(), res.end());        //reverse the string to get final answer
   return res;
}


int main() {
   int base;
   string num1;
   while(1)
   {
   string  num1,num2, sum;
  cin >> num1;
   if(num1=="0")
            break;
   cin >> num2;
        cin>>sum;
        int i;
   for( i=1;i<=36;i++)
   {
        if(sum==decToBaseN((baseNtoDec(num1, i) + baseNtoDec(num2, i)), i))
        {
            break;
        }
   }
   if(i>36)
        cout<<num1<<" + "<< num2<<" != "<< sum<<"\n";
    else
        cout<<num1<<" + "<< num2<<" = "<< sum<< " in base "<<i<<"\n";
   }

}
