- [minishell](#minishell)
- [Tips for setting up](#tips-for-setting-up)
- [Function](#function)
- [What is shell](#what-is-shell)
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
wait3
wait4
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

# Reference
1. [Difference between bash and shell](https://www.geeksforgeeks.org/difference-between-sh-and-bash/#:~:text=bash%20is%20a%20superset%20of,to%20interact%20with%20the%20device.)
2. [Difference between unix, linux, posix](https://www.youtube.com/watch?v=hy4OeVCLGZ4)
3. [Simple shell scripting](https://www.tecmint.com/create-shell-scripts-in-linux/)
4. [Bash in 100 seconds](https://www.youtube.com/watch?v=I4EWvMFj37g)
5. [Custom Shell video](https://www.youtube.com/watch?v=ZGmg8wEdQOM)
6. [Order in pipe, redirection](https://stackoverflow.com/questions/12942042/pipe-redirection-precedence)
