#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Use unsigned long long to store numbers up to 4,294,967,295
typedef unsigned long long ull;

int main() {
    ull total_numbers = 4594967295ULL;
    ull max_number = 4294967295ULL;
    ull i;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate and print the random numbers
    for (i = 0; i < total_numbers; i++) {
        ull random_number = (ull)rand() * (max_number / RAND_MAX) + (ull)rand();
        printf("%llu\n", random_number);
    }

    return 0;
}
