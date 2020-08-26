/***************************************************************************
 * * Program name: 	validateInt.hpp
 * * Author: 		Benjamin Hillen
 * * Date: 		5 October 2019
 * * Description: 	Declaration of the validateInt function defined in
 * * 			validateInt.cpp. Takes by value a string, iterates
 * * 			over each character in the string, and provides an
 * * 			error message prompting for user re-input if any
 * * 			character in the string is not a digit from 0 to 9.
***************************************************************************/	

#ifndef VALIDATE_INT
#define VALIDATE_INT

#include <string>

/*************************************************
 * Function: validateInt
 * Description: validates if the user input was
 * 		only positive integers, forces
 * 		them to enter positive integers
 * 		if input was not.
 * Parameters: string&
 * Pre-conditions: input string from user
 * Post-conditions: none
*************************************************/
void validateInt(std::string& input);

#endif
