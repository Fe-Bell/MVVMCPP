#include "fCppStringUtils.hpp"
#include <cstdlib>
#include <string.h>

/// <summary>
/// Converts a wide char array to a char array.
/// </summary>
/// <param name="str"></param>
/// <returns></returns>
char* convertFromWide(const wchar_t* str) {
	size_t len = ::wcslen(str) + 1; // Get the length of the wide string

	char* buffer = new char[len]; // Allocate memory for the char buffer
	if (buffer == nullptr)
		return nullptr; // Check for allocation failure

	size_t result = 0; // Declare a variable to store the result of the conversion

	errno_t err = ::wcstombs_s(&result, buffer, len, str, len); // Convert the wide string to char string
	if (err != 0 || result == 0) { // Check for conversion failure
		delete[](buffer); // Free the allocated memory
		return nullptr;
	}

	return buffer; // Return the char pointer
}

char* copyFromConst(const char* str) {
	size_t len = ::strlen(str) + 1; // Get the length of the const string

	char* buffer = new char[len]; // Allocate memory for the char buffer
	if (buffer == nullptr)
		return nullptr; // Check for allocation failure

	errno_t err = ::memcpy_s(buffer, len, str, len);
	if (err != 0) { // Check for copy failure
		delete[](buffer); // Free the allocated memory
		return nullptr;
	}

	return buffer; // Return the char pointer
}

wchar_t* convertFromCharArr(const char* str) {
	size_t len = ::strlen(str) + 1; // Get the length of the char string

	wchar_t* buffer = new wchar_t[len]; // Allocate memory for the wchar_t buffer
	if (buffer == nullptr) 
		return nullptr; // Check for allocation failure

	size_t result = 0; // Declare a variable to store the result of the conversion
	errno_t err = ::mbstowcs_s(&result, buffer, len, str, len); // Convert the char string to wchar_t string
	if (err != 0 || result == 0) { // Check for conversion failure
		delete[](buffer); // Free the allocated memory
		return nullptr;
	}

	return buffer; // Return the wchar_t pointer
}