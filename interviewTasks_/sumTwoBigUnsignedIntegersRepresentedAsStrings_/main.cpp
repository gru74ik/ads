// There is required to develop a function that receives 2 string containing very-very big numbers (bigger than 64 bit)
// Function returns a string containing string representation of parameter's sum
// All parameters's strings represent non negative natural numbers
#include <iostream>
#include <string>

std::string sum(const std::string& a, const std::string& b) {
    std::string result(a.size() > b.size() ? a : b);
    const std::string& addend = a.size() > b.size() ? b : a;

    char carry = 0;
    char adder = 0;
    for (int cnt = (result.size() - 1); cnt >= 0; cnt--) {
        adder = result[cnt] - '0' + carry;
        if ((result.size() - addend.size()) <= static_cast<unsigned>(cnt)) {
            adder += addend[cnt - (result.size() - addend.size())] - '0';
        }
        result[cnt] = adder % 10 + '0';
        carry = adder / 10;
    }

    if (carry) {
        result.insert(result.begin(), carry + '0');
    }

    return result;
}

int main() {
    std::cout << sum("888777666555444333222111000", "111000111000333222333222999");
}
//888777666555444333222111000 +
//111000111000333222333222999 =
//999777777555777555555333999

//64-bit unsigned long long is 18,446,744,073,709,551,615

/*
// Function for finding sum of larger numbers 
string findSum(string str1, string str2) 
{ 
    // Before proceeding further, make sure length 
    // of str2 is larger. 
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
  
    // Take an empty string for storing result 
    string str = ""; 
  
    // Calculate length of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    // Reverse both of strings 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
  
    int carry = 0; 
    for (int i=0; i<n1; i++) 
    { 
        // Do school mathematics, compute sum of 
        // current digits and carry 
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
  
        // Calculate carry for next step 
        carry = sum/10; 
    } 
  
    // Add remaining digits of larger number 
    for (int i=n1; i<n2; i++) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
  
    // Add remaining carry 
    if (carry) 
        str.push_back(carry+'0'); 
  
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
  
    return str; 
} 
*/