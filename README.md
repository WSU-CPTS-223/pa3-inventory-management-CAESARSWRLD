[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/pAwGQi_N)

# PA4 Skeleton Code
We expect a fully functioninig command line REPL application for an inventory querying system. Feel free to modify the skeleton code as you see fit.

### How to run the current skeleton code
`make` will compile and execute the skeleton code

Feel free to modify Makefile as you see fit.



Docs:
I decided to use a hash map for this assignment. Given the required operations(search for product and list from category) I decided that a hash map 
would be a good data structure due to it's constant time search speed. The data set is not sorted and none of the required operations necessarily
rely on the data being sorted. Arguably the "list from category" operation requires sorting, however, my list from category function simply iterates through 
the data set printing any product with the given category. This may not be quite as fast as other data structures, but the speed of the lookup product 
function is so fast that it outweighs the costs of the listing from category function speed. 
For my test functions I decided that I should test normal cases and edge cases for my listing and searching operations. One of my test functions
also verifies that the insert function is working properly. I chose these tests because they ensure that the functions most crucial to my program are working properly.
