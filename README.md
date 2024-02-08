# CS303Assignment1Pt1MB
This is an assignment to build array functions that replicate the functionality of vectors.
The main program will read the inputs from the file "A1input.txt" into integer arrays.

This will require a user screen to choose the operation from a list. It will require a read array option, and manipulate array menu. The manipulate menu will have "add int", "del int", "search for int", "change index val", and "print index".

Creating new arrays will not allow for variable size entry ie newArray[i+1], and arrays cannot be passed by reference. In order to accomplish the assignment without that functionality, I will need to exploit the fact that the integers in the file number 10 or less. I will also exploit the fact that none of the inputs are zero, and initialize the array to size [15] with zero values as default empty.

