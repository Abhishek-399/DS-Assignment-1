//to find the sum of two very large numbers using string
//time complexity = O(n) and space complexity = O(length of string)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* findSum(const char* string1, const char* string2) {
    int n1 = strlen(string1);
    int n2 = strlen(string2);
    
    
    int maxLength = (n1 > n2) ? n1 : n2;
    
    // Allocate memory for result (one extra for carry)
    char* result = (char*)malloc((maxLength + 2) * sizeof(char));
    result[maxLength + 1] = '\0'; // Null-terminate the result
    
    int carry = 0;
    int i = n1 - 1, j = n2 - 1, k = maxLength;
    
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0)
            sum += string1[i--] - '0';
        if (j >= 0)
            sum += string2[j--] - '0';
        
        carry = sum / 10;
        result[k--] = (sum % 10) + '0';
    }
    
    
    char* finalResult = result + k + 1;
    
    
    return finalResult;
}

int main() {
    char* string1;
    char* string2;
    char a[1000],b[1000];
    printf("enter first number: ");
    scanf("%s",a);
    printf("enter second number: ");
    scanf("%s",b);
    string1=a,string2=b;
    char* result = findSum(string1, string2);
    
    printf("Sum: %s\n", result);
    
    free(result);
    
    return 0;
}
