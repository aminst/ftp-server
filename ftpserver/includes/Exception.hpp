#ifndef __Exception__
#define __Exception__

#include <iostream>
#include <string>

class Exception
{
public:
    virtual void print_error();
    virtual int get_num();

private:
    const std::string error = "‫‪‫‪‫‪500:‬‬ ‫‪Error‬‬‬‬";
    const int number = 500;
};

class InvalidUsernameAndPassword : public Exception
{
public:
    virtual void print_error();
    virtual int get_num();

private:
    const std::string msg = "‫‪‫‪‫‪430:‬‬ ‫‪Invalid‬‬ ‫‪username‬‬ ‫‪or‬‬ ‫‪password‬‬‬‬";
    const int num = 430;
};

class BadSequenceOfCommands : public Exception
{
public:
    virtual void print_error();
    virtual int get_num();

private:
    const std::string msg = "‫‪‫‪503:‬‬ ‫‪Bad‬‬ ‫‪sequence‬‬ ‫‪of‬‬ ‫‪commands.‬‬";
    const int num = 503;
};

class SyntaxErrorInParametersOrArguments: public Exception
{
public:
    virtual void print_error();
    virtual int get_num();

private:
    const std::string msg = "‫‪‫‪‫‪501:‬‬ ‫‪Syntax‬‬ ‫‪error‬‬ ‫‪in‬‬ ‫‪parameters‬‬ ‫‪or‬‬ ‫‪arguments.‬‬";
    const int num = 501;
};

class NeedAccountForLogin: public Exception
{
public:
    virtual void print_error();
    virtual int get_num();

private:
    const std::string msg = "‫‪‫‪‫‪‫‪332:‬‬ ‫‪Need‬‬ ‫‪account‬‬ ‫‪for‬‬ ‫‪login.‬‬‬‬";
    const int num = 332;
};

class FileUnavailable: public Exception
{
public:
    virtual void print_error();
    virtual int get_num();

private:
    const std::string msg = "‫‪550:‬‬ ‫‪File‬‬ ‫‪unavailable.‬‬";
    const int num = 550;
};

#endif