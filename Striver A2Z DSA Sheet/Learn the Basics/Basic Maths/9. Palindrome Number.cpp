// 9. Palindrome Number (EASY)
// https://leetcode.com/problems/palindrome-number/description/

bool isPalindrome(int x) {
    unsigned int rev = 0, num = x;
    
    while(num > 0){
        unsigned int rem = num % 10;
        rev = rev * 10 + rem;
        num /= 10;
    }

    if(x == rev) return true;
    return false;
}
