**5/19/2025**
*  **feedback.md is for instructor use only. DO NOT change the feedback.md**; make a copy if needed
* class definition style & standards:  first, member vars  none per line and do not forget to initialize them;  second functions: separate group of functions  by a blank line; either matching setter/getter pairs or list all setters back to back and list all getters back to back; start with a default c’tor, followed by  copy c’tor (if any), then other c’tors in the order of increased number of arguments, d’tor- right after c’tor(s), overloaded functions- list them back to back in the order of increased number of arguments;  all accessor/getter functions should be const; all functions with more than one statement should be normal (defined externally, outside of the class and below main()), no inline functions with more than one statement; initialize all member variables to appropriate default values at the time of definition; all member variables must be private; classes must provide a strong exception guarantee; must have default c’tor; implement Rule of Three when necessary
* DMA does not comply with the assignment -20
* class(es) do(es) not provide a strong exception guarantee; -10
* getter/accessor function(s) allow object state modification -5
* inline functions do not adhere to the best practices -5
* multiple return statements in a non-recursive function; may result in unreachable return; use if/else, use a variable to store the results and return the variable; e.g. a function to check the length of a string, function to validate account number,  short validations can be done in the return statement; e.g.  return a<MIN_LENGTH;   -5
* no game class -5
* does not compile -5
* redundant sort implementation; does not comply with the assignment -5
* what if numbers change? if it is not 1 or 0 make it const; in case of ASCII values, use chars, e.g., temp>’a’   -5
* modularization: each menu option should have its own function with a possible exception of the QUIT case; as a rule of thumb, if a case in a switch has more than 2 statements, make it a function; -2
* should initialize all pointers to nullptr at the time of definition/allocation; this helps with debugging, DMA, and providing a strong exception guarantee -1 -2
*  239 and like: if a user enters a value of a wrong data type, the program goes into an infinite loop; should create a highly reusable function that takes an error message string as a parameter, clears the failed input and outputs the error message to be called in the default case of the menu switch -2
* filter should have a “wrapper”/outer filter function  to call a function that returns validated min/max, and then calls an actual filter function that returns a string with matches or an empty string, not throw an exception -2
*  redundant Army c’tor implementation -2
* 561 and like: abruptly terminates the program if  creatures cannot be allocated;  what if existing armies can be  sufficient for main()? -2
* 541 if you use delete on something that was not dynamically allocated, a compiler might throw an exception; check first, then use delete -2
* 80-81 should create a highly reusable function that takes an error message string as a parameter and clears the failed input; it does not need to ask the user to re-enter, the menu loop already does it  -2
* * file name(s) and/or file/folder structure/capitalization do not comply with posted instructions; folder- CSXXX_LN_FL (all caps, X – class catalog number, N- lab number, FL- your initials;  files:  all lower case, main() – main.cpp, input - “in_\*.txt”, output –“out_\*.txt”, error –“err_\*.txt”; do not include any other files or folders; include feedback.md for instructor to post feedback -2
* 148 and like:<< not needed between strings -1
* main()- missing return statement -1
*  UI- no warning/confirmation  about quitting -1
* use no more than one blank line to separate logical chunks of code; extra lines add up and require more scrolling time -.5

