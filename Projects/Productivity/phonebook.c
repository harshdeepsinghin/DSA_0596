#include <stdio.h>

typedef char *string;

struct contact_info 
{
    string name;
    string number;
    string email;
    string address;
};

int main (void)
{
    struct contact_info person;

    printf("Enter your name: ");
    fgets(person.name, 15, stdin);
    puts(person.name);
    printf("Enter your number: ");
    scanf("%s", person.number);
    puts(person.number);
    printf("Enter your email: ");
    scanf("%s", person.email);
    puts(person.email);
    printf("Enter your address: ");
    scanf("%s", person.address);
    puts(person.address);
    

    return 0;
}