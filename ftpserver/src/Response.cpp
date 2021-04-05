#include <Response.hpp>

#include <iostream>
#include <string>

std::string Response::get_message(int num)
{
    if (num == USERNAME_OKAY)
        return _331;
    else if (num == BAD_SEQUENCE)
        return _503;
    else if (num == USER_LOGGEDIN)
        return _230;
    else if (num == ERROR)
        return _500;
    else if (num == SYNTAX_ERROR)
        return _501;
    else if (num == SUC_CHANGE)
        return _250_3;
    else if (num == SUC_DOWNLOAD)
        return _226_2;
    else if (num == HELP)
        return _214;
    else if (num == SUC_QUIT)
        return _221;
    else if (num == NEED_ACC)
        return _221;
    else if (num == CANT_CONNECTION)
        return _425;
    else if (num == FILE_UNAVAILABLE)
        return _550;
    else
        return _500;
}

std::string Response::get_message(int num, const std::string str)
{
    if (num == PWD_DIRECTORY)
        return _257_1 + str;
    else if (num == MKD_DIRECTORY)
        return _257_1 + str + _257_2;
    else if (num == LIST_TRANSFER)
        return _226_1 + "\n\n" + str;
    else if (num == DELETE)
        return _250_1 + str + _250_2;
    else
        return _500;
}