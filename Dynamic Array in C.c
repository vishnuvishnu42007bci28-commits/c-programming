#include <stdio.h>
#include <stdlib.h>

/*
 * This stores the total number of books in each shelf.
 */
int* total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int** total_number_of_pages;


int main() {
    int total_number_of_shelves;
    if (scanf("%d", &total_number_of_shelves) != 1) return 1;
    
    int total_number_of_queries;
    if (scanf("%d", &total_number_of_queries) != 1) return 1;
    
    // Allocate tracking array for number of books per shelf (initialized to 0)
    total_number_of_books = (int*)calloc(total_number_of_shelves, sizeof(int));
    
    // Allocate row pointer slots for the 2D page matrix
    total_number_of_pages = (int**)malloc(total_number_of_shelves * sizeof(int*));
    for (int i = 0; i < total_number_of_shelves; i++) {
        total_number_of_pages[i] = NULL; // Initialize rows to NULL for safe reallocations
    }
    
    while (total_number_of_queries--) {
        int type_of_query;
        if (scanf("%d", &type_of_query) != 1) return 1;
        
        if (type_of_query == 1) {
            /*
             * Process Query Type 1: Insert a book with 'y' pages onto shelf 'x'
             */
            int x, y;
            if (scanf("%d %d", &x, &y) != 2) return 1;
            
            // Get the current number of books on shelf x
            int current_book_count = total_number_of_books[x];
            
            // Expand the memory allocation for shelf x to accommodate one more book
            total_number_of_pages[x] = (int*)realloc(total_number_of_pages[x], (current_book_count + 1) * sizeof(int));
            
            // Insert the new book's page count at the end of the shelf array
            total_number_of_pages[x][current_book_count] = y;
            
            // Increment the counter tracking the total number of books on this shelf
            total_number_of_books[x]++;
     

        } else if (type_of_query == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        } else {
            int x;
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    if (total_number_of_books) {
        free(total_number_of_books);
    }
    
    for (int i = 0; i < total_number_of_shelves; i++) {
        if (*(total_number_of_pages + i)) {
            free(*(total_number_of_pages + i));
        }
    }
    
    if (total_number_of_pages) {
        free(total_number_of_pages);
    }
    
    return 0;
}
