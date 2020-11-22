//
//  CipherTexted
//  This is a tool that enciphers your text
//

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    int key;
    int counter = 0;

    if (argc != 2)
    {
        printf("Usage: ./ceaser key\n");
        return 1;
    }
    
    int n = strlen(argv[1]);

    for (int i = 0; i < n ; i++)
    {
        if (isdigit(argv[1][i]) == 0)
        {
            printf("Usage: ./ceaser key\n");
            return 1;
        }
    }
    
    key = atoi(argv[1]);

    string plaintext = get_string("plaintext: ");
    int m = strlen(plaintext);

    for (int i = 0; i < m; i++)
    {
        if (isupper(plaintext[i]) != 0)
        {
            plaintext[i] = 65 + (plaintext[i] - 65 + key) % 26;
        }
        if (islower(plaintext[i]) != 0)
        {
            plaintext[i] = 97 + (plaintext[i] - 97 + key) % 26;
        }
        else
        {
            plaintext[i] = plaintext[i];
        }
    }

    printf("ciphertext: %s\n", plaintext);

    return 0;
}