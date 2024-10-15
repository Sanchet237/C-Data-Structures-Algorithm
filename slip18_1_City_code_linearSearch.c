/*Q.1) Write a C program to display the city code of the corresponding city name using linear search method. 
The structure is:
struct city
{
int city_code; char name[30];*/

#include <stdio.h>
#include <string.h>

struct city {
    int city_code;
    char name[30];
};

int linear_search(struct city cities[], int size, const char *name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(cities[i].name, name) == 0) {
            return cities[i].city_code;
        }
    }
    return -1; 
}

int main() {
    struct city cities[] = {
        {101, "Mumbai"},
        {102, "Delhi"},
        {103, "Bangalore"},
        {104, "Chennai"},
        {105, "Kolkata"},
        {106, "Hyderabad"},
        {107, "Pune"},
        {108, "Ahmedabad"},
        {109, "Jaipur"},
        {110, "Lucknow"}
    };

    int size = sizeof(cities) / sizeof(cities[0]);
    char search_name[30];

    printf("Enter the city name: ");
    fgets(search_name, sizeof(search_name), stdin);
    
    search_name[strcspn(search_name, "\n")] = '\0';

    int city_code = linear_search(cities, size, search_name);
    
    if (city_code != -1) {
        printf("City Code for %s is: %d\n", search_name, city_code);
    } else {
        printf("City not found.\n");
    }

    return 0;
}
