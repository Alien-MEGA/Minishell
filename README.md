# MiniShell

MiniShell will introduce you to the world of shells, which provides a convenient text interface to interact with your system. Shells might seem very easy to understand but have very specific and defined behavior in almost every single case, most of which will need to be handled properly.

Hootgam quote : `lexer`-> `parser` -> `expander`-> `executor` 

- Resources :
    - GitHub  :
        
        [https://github.com/Swoorup/mysh](https://github.com/Swoorup/mysh)
        
    - PDF  :
    
    [https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf)
    
    - Shell Command Language :
    
    [Shell Command Language](https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html)
    
- Function :
    - **`readline`**: Reads a line of input from the user.
    - **`rl_clear_history`**: Clears the history list maintained by the readline library.
    - **`rl_on_new_line`**: Causes the current line to be considered complete and adds it to the history.
    - **`rl_replace_line`**: Replaces the current line with a new one.
    - **`rl_redisplay`**: Updates the display to show the current line.
    - **`add_history`**: Adds a line to the history list.
    - **`printf`**: Prints formatted output to the console.
    - **`malloc`**: Allocates memory dynamically.
    - **`free`**: Frees dynamically allocated memory.
    - **`write`**: Writes data to a file descriptor.
    - **`access`**: Checks the accessibility of a file.
    - **`open`**: Opens a file.
    - **`read`**: Reads data from a file descriptor.
    - **`close`**: Closes a file descriptor.
    - **`fork`**: Creates a new process by duplicating the calling process.
    - **`wait`**: Waits for a child process to terminate.
    - **`waitpid`**: Waits for a specific child process to terminate.
    - **`wait3`**: A variant of **`waitpid`** that provides more information about the terminated process.
    - **`wait4`**: A variant of **`waitpid`** that provides even more information about the terminated process.
    - **`signal`**: Sets a signal handler for a specific signal.
    - **`sigaction`**: A more flexible version of **`signal`** that allows for more control over signal handling.
    - **`sigemptyset`**: Initializes an empty set of signals.
    - **`sigaddset`**: Adds a signal to a set of signals.
    - **`kill`**: Sends a signal to a process or group of processes.
    - **`exit`**: Terminates the calling process.
    - **`getcwd`**: Gets the current working directory.
    - **`chdir`**: Changes the current working directory.
    - **`stat`**: Gets information about a file.
    - **`lstat`**: Gets information about a file, but doesn't follow symbolic links.
    - **`fstat`**: Gets information about an open file descriptor.
    - **`unlink`**: Deletes a file.
    - **`execve`**: Replaces the current process with a new one.
    - **`dup`**: Duplicates a file descriptor.
    - **`dup2`**: Duplicates a file descriptor, but allows for the target descriptor to be specified.
    - **`pipe`**: Creates a pipe for inter-process communication.
    - **`opendir`**: Opens a directory stream.
    - **`readdir`**: Reads a directory stream.
    - **`closedir`**: Closes a directory stream.
    - **`strerror`**: Converts an error number to a string describing the error.
    - **`perror`**: Prints an error message to the console, including the string representation of the current error.
    - **`isatty`**: Checks whether a file descriptor refers to a terminal.
    - **`ttyname`**: Gets the name of the terminal associated with a file descriptor.
    - **`ttyslot`**: Gets the slot number of the current terminal in the terminal database.
    - **`ioctl`**: Performs I/O control operations on a file descriptor.
    - **`getenv`**: Gets the value of an environment variable.
    - **`tcsetattr`**: Sets the attributes of a terminal.
    - **`tcgetattr`**: Gets the attributes of a terminal.
    - **`tgetent`**: Gets the entry for the current terminal type in the terminal database.
    - **`tgetflag`**: Gets the value of a terminal capability flag.
    - **`tgetnum`**: Gets the value of a numeric terminal capability.
    - **`tgetstr`**: Gets the value of a string terminal capability.
    - **`tgoto`**: Constructs a cursor movement sequence for the current terminal type.
    - `tputs
- Shell Should :
    - Create a command-line prompt that can execute different programs based on their location.
    - Have a history of previously executed commands.
    - Do not use more than one global variable.
    - Ignore certain special characters like backslashes and semicolons unless they are in quotes.
    - Handle single and double quotes properly so that meta-characters are not interpreted inside the quotes.
    - Implement redirections, such as input and output redirection, and append mode.
    - Implement pipes so that the output of one command is connected to the input of the next command via a pipe.
    - Handle environment variables by expanding them to their values.
    - Handle special characters like ctrl-C, ctrl-D, and ctrl-\ in interactive mode.
    - Implement several built-in commands, such as echo, cd, pwd, export, unset, env, and exit.
- Exit Status :
    - **`0`** - Success status. This indicates that the process has been completed successfully without any errors.
    - **`1`** - Generic error status. This can be used to indicate any kind of error that does not have a specific exit code.
    - **`2`** - Misuse or syntax error status. This indicates that the command was used incorrectly or that there was a syntax error in the command.
    - **`3`** - Fatal error status. This indicates that the process has encountered a fatal error and cannot continue.
    - **`126`** - Command not executable status. This indicates that the command could not be executed because it is not executable.
    - **`127`** - Command not found status. This indicates that the command could not be found or is not in the search path.
    - **`128+n`** - Fatal error signal **`n`** status. This indicates that the process has terminated due to a fatal signal (where **`n`** is the signal number).
    - **`130`** - Interrupted by the signal status. This indicates that the process has been interrupted by a signal (usually **`SIGINT`**).
    - **`137`** - Killed by signal status. This indicates that the process has been killed by a signal (usually **`SIGKILL`**).
    - **`255`** - Exit status out of range status. This indicates that the exit status is outside the valid range of values (0-255).

# Lexer

- Lexer
    
    Lexer analysis (also known as lexical analysis or tokenization) is the process of breaking down a stream of input text into individual tokens, which are meaningful units of the language being processed.
    
    lexer analysis is often used as the first step in the process of compiling or interpreting a programming language, The lexer then outputs a sequence of tokens that the parser can use to build an abstract syntax tree, which represents the structure of the program.
    
    For example, in the following code snippet:
    
    ```
    pythonCopy code
    int x = 5 + 2;
    
    ```
    
    the lexer would break it down into the following tokens:
    
    ```
    vbnetCopy code
    int     keyword
    x       identifier
    =       operator
    5       integer
    +       operator
    2       integer
    ;       semicolon
    
    ```
    
    The lexer analysis makes it easier for the compiler or interpreter to process the input language because it has a structured representation of the program that it can work with.
    
- How to implement a Lexer analysis
    1. Define the language grammar: Before you can perform lexer analysis, you need to define the grammar of the language you are working with. This includes specifying the set of valid tokens and their syntax.
    2. Define the token definitions: Once you have defined the grammar, you can define the individual token definitions. Each token definition specifies a regular expression pattern that matches the syntax of the token.
    3. Write the lexer code: Using the token definitions and the language grammar, you can now write the code for the lexer. The lexer reads in the input text as a stream of characters and matches each character sequence with the regular expression pattern for the corresponding token.
    4. Generate the token stream: As the lexer reads in the input text, it generates a stream of tokens. Each token is represented by a tuple or object that contains the token type and its value.
    5. Pass the token stream to the parser

# Parser

- Parser
    
    A parser is a component of a compiler or interpreter that takes the stream of tokens generated by the lexer and uses it to build an abstract syntax tree (AST). The AST is a data structure that represents the structure of the program being compiled or interpreted, and is used by the compiler or interpreter to generate executable code or to execute the program directly.
    
    The parser operates according to the rules of the language grammar, which specify the syntax and semantics of the language being processed. The parser reads in the stream of tokens, and uses the grammar rules to determine how to build the AST. Each rule in the grammar specifies a production that describes how a certain construct in the language can be built from other constructs in the language. The parser applies these rules recursively to construct the AST, starting with the top-level rule of the grammar.
    
    As the parser constructs the AST, it checks that the structure of the program is well-formed according to the rules of the language grammar. If the program contains syntax errors or violates the grammar rules, the parser reports an error and halts the compilation or interpretation process.
    
    Once the AST has been constructed, the compiler or interpreter can use it to generate executable code or to execute the program directly. The AST provides a structured representation of the program that can be efficiently traversed and analyzed, and can be used to generate code that is optimized for performance.
    
    In summary, the parser is responsible for taking the stream of tokens generated by the lexer and constructing an abstract syntax tree that represents the structure of the program being compiled or interpreted. The AST provides a structured representation of the program that can be efficiently traversed and analyzed, and is used by the compiler or interpreter to generate executable code or to execute the program directly.
    
- How to implement a Parser analysis
    - Abstract Tree
        
        [https://www.youtube.com/watch?v=UbhlOk7vjVY](https://www.youtube.com/watch?v=UbhlOk7vjVY)
        

# Expander

# Executor
