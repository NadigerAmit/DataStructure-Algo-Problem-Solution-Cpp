/*
int main(int argc, char *argv[], char *envp[])

The main() function parameter envp is not specified by POSIX but is widely supported.

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
 => env = PWD=/home/amit/OmPracticeC++
 => env = LOGNAME=amit
 => env = MOTD_SHOWN=update-motd
 => env = HOME=/home/amit
 => env = LANG=C.UTF-8
 => env = LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.webp=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:
 => env = LESSCLOSE=/usr/bin/lesspipe %s %s
 => env = TERM=xterm-256color
 => env = LESSOPEN=| /usr/bin/lesspipe %s
 => env = USER=amit
 => env = SHLVL=1
 => env = WSLENV=
 => env = XDG_DATA_DIRS=/usr/local/share:/usr/share:/var/lib/snapd/desktop
 => env = PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/mnt/c/Program Files/WindowsApps/CanonicalGroupLimited.Ubuntu22.04LTS_2204.1.22.0_x64__79rhkp1fndgsc:/mnt/c/WINDOWS/system32:/mnt/c/WINDOWS:/mnt/c/WINDOWS/System32/Wbem:/mnt/c/WINDOWS/System32/WindowsPowerShell/v1.0/:/mnt/c/WINDOWS/System32/OpenSSH/:/mnt/c/Program Files/Git/cmd:/mnt/c/Users/user/AppData/Local/Microsoft/WindowsApps:/mnt/c/Program Files (x86)/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32/bin:/mnt/c/Program Files/JetBrains/IntelliJ IDEA Community Edition 2022.2.1/bin:/snap/bin
 => env = HOSTTYPE=x86_64
 => env = OLDPWD=/home/amit
 => env = _=./a.out
 ... ... ... 
*/
