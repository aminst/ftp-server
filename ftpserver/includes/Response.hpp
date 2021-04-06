#ifndef __RESPONSE__
#define __RESPONSE__

#include <string>

#define USERNAME_OKAY 331
#define BAD_SEQUENCE 503
#define USER_LOGGEDIN 230
#define INVALID_USERPASS 430
#define FILE_UNAVAILABLE 550
#define PWD_DIRECTORY 257
#define MKD_DIRECTORY 258
#define DELETE 250
#define LIST_TRANSFER 226
#define SUC_CHANGE 251
#define SUC_DOWNLOAD 252
#define HELP 214
#define SUC_QUIT 221
#define NEED_ACC 332
#define SYNTAX_ERROR 501
#define ERROR 500
#define CANT_CONNECTION 425

class Response
{
public:
    std::string get_message(int num);
    std::string get_message(int num, std::string str);
private:
    std::string _331 = "‫‪331:‬‬ ‫‪User‬‬ ‫‪name‬‬ ‫‪okay,‬‬ ‫‪need‬‬ ‫‪password.‬‬";
    std::string _503 = "‫‪‫‪503:‬‬ ‫‪Bad‬‬ ‫‪sequence‬‬ ‫‪of‬‬ ‫‪commands.‬‬";
    std::string _230 = "‫‪‫‪‫‪230:‬‬ ‫‪User‬‬ ‫‪logged‬‬ ‫‪in,‬‬ ‫‪proceed.‬‬ ‫‪Logged‬‬ ‫‪out‬‬ ‫‪if‬‬ ‫‪appropriate.‬‬‬‬";
    std::string _430 = "‫‪‫‪‫‪430:‬‬ ‫‪Invalid‬‬ ‫‪username‬‬ ‫‪or‬‬ ‫‪password‬‬";
    std::string _550 = "‫‪‫‪‫‪550:‬‬ ‫‪File‬‬ ‫‪unavailable.‬‬‬‬";
    std::string _257_1 = "‫‪‫‪‫‪257:‬‬ ‫‪";
    std::string _257_2 = "‫‪‫‪‫‪ ‫‪‫‪created.‬‬‬‬";
    std::string _250_1 = "‫‪250:‬‬ ‫‪";
    std::string _250_2 = " ‫‪deleted.‬‬";
    std::string _226_1 = "‫‪‫‪‫‪226:‬‬ ‫‪List ‫‪transfer‬‬ ‫‪done.‬‬‬‬";
    std::string _250_3 = "‫‪‫‪‫‪250:‬‬ ‫‪Successful‬‬ ‫‪change.‬‬";
    std::string _226_2 = "‫‪‫‪‫‪226:‬‬ ‫‪Successful‬‬ ‫‪Download.‬‬";
    std::string _214 = "‫‪‫‪‫‪214: \nuser [name], Its argument is used to specify the user’s string. It is used for user authentication.\n\n\
                        pass [password], Its argument is used to specify the user’s password, if any user ready to log in.\n\n\
                        ls, Lists all files and directories in the present working directory.\n\n\
                        mkd [directory_name], Creates a new directory in the present working directory or at the specified path.\n\n\
                        rename [from] [to], rename file or directory with name <from> to <to>.\n\n\
                        dele -d/-f [name], remove a file or directory in the current directory with name <name>; -f is used for files and -d for directories.\n\n\
                        pwd, show the current working directory.\n\n\
                        cwd [directory_name], To change to a particular directory with name <directory_name>. Move one level up if it’s argument is <..>.\n\n\
                        retr [file_name], download a file with name <file_name>.\n\n\
                        quit, logout from account.‬‬‬‬";
    std::string _221 = "‫‪‫‪‫‪221:‬‬ ‫‪Successful‬‬ ‫‪Quit.‬‬‬‬";
    std::string _332 = "‫‪‫‪‫‪‫‪332:‬‬ ‫‪Need‬‬ ‫‪account‬‬ ‫‪for‬‬ ‫‪login.‬‬‬‬‬‬";
    std::string _501 = "‫‪‫‪‫‪‫‪501:‬‬ ‫‪Syntax‬‬ ‫‪error‬‬ ‫‪in‬‬ ‫‪parameters‬‬ ‫‪or‬‬ ‫‪arguments.‬‬";
    std::string _500 = "‫‪‫‪‫‪‫‪500:‬‬ ‫‪Error‬‬‬‬‬‬";
    std::string _425 = "‫‪‫‪‫‪‫‪‫‪425:‬‬ ‫‪Can't‬‬ ‫‪open‬‬ ‫‪data‬‬ ‫‪connection.‬‬";
};

#endif