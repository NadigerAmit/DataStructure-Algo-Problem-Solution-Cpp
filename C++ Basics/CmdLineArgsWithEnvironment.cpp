/*
int main(int argc, char *argv[], char *envp[])

The main() function parameter envp is not specified by POSIX but is widely supported.

he optional envp parameter is an array of strings representing the variables set in the user's environment.
This array is terminated by a NULL entry. It can be declared as an array of pointers to char (char *envp[]) or
as a pointer to pointers to char (char **envp). If your program uses wmain instead of main, use the wchar_t data type instead of char.

The environment block passed to main and wmain is a "frozen" copy of the current environment. 
If you later change the environment by making a call to putenv or _wputenv, the current environment 
(as returned by getenv or _wgetenv and the _environ or _wenviron variable) will change, but the block pointed to by envp won't change. 
For more information on how to suppress environment processing, see Customize C++ command-line processing. 
The envp argument is compatible with the C89 standard, but not with C++ standards.

It is an alternative method of accessing the environment list is to declare a third argument to the main() function:
This argument can then be treated in the same way as environ, with the difference that its scope is local to main(). 
Although this feature is widely implemented on UNIX systems, its use should be avoided since, in addition to the scope limitation, it is not specified in SUSv3.

Reocmmanded way to get the env varaiable is below :
getenv()
extern char **environ;
*/

#include <iostream>
#include <string>

int main(int argc, char **argv, char **environ){
    if(argc < 2){
       std::cerr << "Error: invalid command line argument. Expected -args or -env "
                 << "\n";
       // Exit  immediately (return 1)
       return EXIT_FAILURE; 
    }

    if(std::string(argv[1]) == "-args"){
       std::cout << "Number of command line arguments = " << argc << "\n";
       std::cout << "argv[0] = " << argv[0] << "\n";
       std::cout << "\n";
       std::cout << "Showing command line arguments:" << "\n";
       std::cout << "+-----------------------------+" << "\n";
       for(int i = 0; i < argc; i++)
               std::cout << "argv[" << i << "] = " << argv[i] << "\n";		
       return EXIT_SUCCESS;
    }

    if(std::string(argv[1]) == "-env"){
       std::cout << "Show environment variables" << "\n";
       char** env = environ;
       while(*(env++) != nullptr)
               std::cout << " => env = " << *env << "\n";
       return EXIT_SUCCESS;

    }
    std::cerr << "Error: invalid argument <" <<  argv[1] << "> " <<"\n";     
    // return 1
    return EXIT_FAILURE;
};

/*
How to run 
$ ./minimal-program2.bin 
Error: invalid command line argument. Expected -args or -env 

$ ./minimal-program2.bin -args opt1 opt2 key=value
Number of command line arguments = 5
argv[0] = ./minimal-program2.bin

Showing command line arguments:
+-----------------------------+
argv[0] = ./minimal-program2.bin
argv[1] = -args
argv[2] = opt1
argv[3] = opt2
argv[4] = key=value

$ ./minimal-program2.bin sadsad
Error: invalid argument <sadsad> 

$ ./minimal-program2.bin -env
Show environment variables
 => env = WSL_DISTRO_NAME=Ubuntu-22.04
 => env = NAME=DESKTOP-9LTOFUP
 => env = PWD=/home/amit/********
 => env = LOGNAME=amit
 => env = MOTD_SHOWN=update-motd
 => env = HOME=/home/amit
 => env = LANG=C.UTF-8
 => env = LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35********
 => env = TERM=xterm-256color
 => env = LESSOPEN=| /usr/bin/lesspipe %s
 => env = USER=amit
 => env = SHLVL=1
 => env = WSLENV=
 => env = XDG_DATA_DIRS=/usr/local/share:/usr/share:/var/lib/snapd/desktop
 => env = PATH=/usr/local/sbin:/usr/loc***********
 => env = OLDPWD=/home/amit
 => env = _=./a.out
 ... ... ... 
*/
