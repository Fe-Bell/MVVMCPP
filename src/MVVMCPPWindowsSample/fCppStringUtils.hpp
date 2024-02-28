#pragma once

/// <summary>
/// Converts a char array to a wide char array.
/// </summary>
/// <param name="str"></param>
/// <returns></returns>
wchar_t* convertFromCharArr(const char* str);

/// <summary>
/// Converts a wide char array to a char array.
/// </summary>
/// <param name="str"></param>
/// <returns></returns>
char* convertFromWide(const wchar_t* str);

/// <summary>
/// Converts a const char array to a char array.
/// </summary>
/// <param name="str"></param>
/// <returns></returns>
char* copyFromConst(const char* str);