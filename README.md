- [minishell](#minishell)
- [Tips for setting up](#tips-for-setting-up)
- [Function](#function)
- [What is shell](#what-is-shell)
- [Check signal command](#check-signal-command)
- [Reference](#reference)
# minishell
create a mini shell program that mimic actual bash terminal

# Tips for setting up
1. include -lreadline to include readline library
2. brew info readline to check if readline install in mac.
3. from the brew info look for export and include it into compilation

  export LDFLAGS="-L/usr/local/opt/readline/lib"
  export CPPFLAGS="-I/usr/local/opt/readline/include"

For example:
gcc rl_on_new_line.c -o rl_on_new_line -lreadline -L/usr/local/opt/readline/lib -I/usr/local/opt/readline/include


# Function
readline
rl_clear_history
rl_on_new_line
rl_replace_line
rl_redisplay
add_history
fork
wait
waitpid
wait3 - obsolete (user waitpid)
wait4 - obsolete (user waitpid)
signal
kill
exit
getcwd
chdir
stat
lstat
fstat
unlink
execve
dup
dup2
pipe
opendir
readdir
closedir
strerror
perror
isatty
ttyname
ttyslot
ioctl
getenv
tcsetattr
tcgetattr
tgetent
tgetflag
tgetnum
tgetstr
tgoto
tputs

# What is shell
Shell is an interface between the user and the operating system.

# Check signal command
```stty -e```

# Reference
1. [Difference between bash and shell](https://www.geeksforgeeks.org/difference-between-sh-and-bash/#:~:text=bash%20is%20a%20superset%20of,to%20interact%20with%20the%20device.)
2. [Difference between unix, linux, posix](https://www.youtube.com/watch?v=hy4OeVCLGZ4)
3. [Simple shell scripting](https://www.tecmint.com/create-shell-scripts-in-linux/)
4. [Bash in 100 seconds](https://www.youtube.com/watch?v=I4EWvMFj37g)
5. [Custom Shell video](https://www.youtube.com/watch?v=ZGmg8wEdQOM)
6. [Order in pipe, redirection](https://stackoverflow.com/questions/12942042/pipe-redirection-precedence)
7. [Unix File Attributes, stat(), fstat(), lstat()](https://www.youtube.com/watch?v=jOl0ezOuoNE)
8. [Sample code for fstat](http://codewiki.wikidot.com/c:system-calls:fstat)
9. [execve](https://linuxhint.com/c-execve-function-usage/#:~:text=Execve()%20function%20is%20used,program%20and%20print%20the%20output.)
10. [execve jameshfisher](https://jameshfisher.com/2017/02/05/how-do-i-use-execve-in-c/)
11. [Creating Pipes in C](https://tldp.org/LDP/lpg/node11.html)
12. [dup()](https://stackoverflow.com/questions/7861611/can-someone-explain-what-dup-in-c-does)
13. [dup() geeks](https://www.geeksforgeeks.org/dup-dup2-linux-system-call/)
14. [What does dup2() do in C](https://stackoverflow.com/questions/24538470/what-does-dup2-do-in-c)
15. [Pipe geeksforgeek](https://www.geeksforgeeks.org/pipe-system-call/)
16. [Pipe linux hint](https://linuxhint.com/using_pipe_function_c_language/)
17. [Fork and pipe](https://www.geeksforgeeks.org/c-program-demonstrate-fork-and-pipe/)
18. [Fork and pipe tutorialpoint](https://www.tutorialspoint.com/c-program-to-demonstrate-fork-and-pipe)
19. [Fork and pipe codevault](https://www.youtube.com/watch?v=6u_iPGVkfZ4)
20. [Minishell video mandaron](https://www.youtube.com/watch?v=o6nW-Pqg4Rk)
21. [Unix Processes in C playlist](https://www.youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY)