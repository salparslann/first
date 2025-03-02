#include <stdio.h>

int isPalindrome(int arr[], int size) {
    int left = 0;          // Sol baþlangýç indeksi
    int right = size - 1;  // Sað baþlangýç indeksi

    // Sol ve sað indeksler arasýndaki elemanlarý karþýlaþtýr
    while (left < right) {
        if (arr[left] != arr[right]) {
            return 0;  // Palindrom deðilse 0 döndür
        }
        left++;      // Bir sonraki sol elemana geç
        right--;     // Bir önceki sað elemana geç
    }

    return 1;  // Palindromsa 1 döndür
}

int main() {
    int arr[] = {1, 56, 34, 34, 56, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    if (isPalindrome(arr, size)) {
        printf("Evet, bu liste bir palindromdur.\n");
    } else {
        printf("Hayýr, bu liste bir palindrom deðildir.\n");
    }

    return 0;
} 





#include <stdio.h>

int main() {
    int arr[] = {1, 56, 34, 34, 56, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int isPalindrome = 1;  

    for (int i = 0; i < size / 2; i++) {
        if (arr[i] != arr[size - i - 1]) {
            isPalindrome = 0; 
            break;  
        }
    }

    if (isPalindrome) { 
        printf("Yes, this list is a palindrome.\n");
    } 
	else { 
        printf("No, this list is not a palindrome.\n");
    }

    return 0; 
    
    
    
    
    
    
    
} 



































