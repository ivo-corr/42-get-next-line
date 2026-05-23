*This project has been created as part of the 42 curriculum by icorrale.*
-
**Description**

In this 42 Project the function get_next_line reads ```BUFFER_SIZE``` bytes from a file descriptor at a time and returns the first line it finds by transferring the whole ```BUFFER``` to a stash and checking for the appearance of the newline character ```\n```.
If a newline is found it is extracted with the extract_line function, which allocates memory for the line to be returned and updates the state of the stash to the character after the newline if there is any. If extract_line is called when there is no newline in stash, then it returns the whole stash. This is the case when ```read``` returns 0, which means EOF.

The project contains only 3 files with the following functions:
* **get_next_line.c**
	* get_next_line
	* extract_line
				
				explained above
* **get_next_line_utils.c**
	* expand_sbuff

			expands the stash and appends the BUFFER at the end of it by concatenation with ft_cpycat.
	* free_stash

			frees the stash and sets it to null, returns null
	* ft_r_read_line
			
			recursive reading function
	* ft_strchr
			
			returns the first occurence of a character in a string
	* ft_cpycat

			custom ft_strlcpy and ft_strlcat hybrid. Receives the following parameters:
			destination, source, size, and mode 'm'. m = 0 means copy from source to destination, m = 1 means concatenate source at the end of destination.
* **get_next_line.h**



**Instructions**

Compile with 
```cc -D BUFFER_SIZE=n *.c``` where n is the desired buffer_size and there is a ```.c``` file containing a main function in the current directory. In your main function open a file using ```open``` from library <fcntl.h>, and use a type from <sys/types.h> as a second parameter, for example 0_RDONLY.

**Resources**

Documentation used in this project: man pages. No articles or tutorials were used.
How AI was used: I used AI to ask general and conceptual questions regarding my algorithm, which initially wasn't blindly appending BUFFER to stash, but micro-managing the state of BUFFER and stash in each step, which was unnecessarily complex. Later i switched to just checking for newlines in stash and using BUFFER to just read and move information to stash with no checks.

**Algorithm**

My most obvious and deliberate design choice was a recursive approach for the core of the algorithm (```ft_r_read_line```)instead of an iterative one. I chose this because I'd like to practice more recursion and functional programming, in this case at the end it didn't seem to offer much of a benefit over the classical iterative approach but it was fun to try.

The string manipulation functions (essentially strlcpy and strlcat fused into a single function ```ft_cpycat```, as well as ```ft_strchr```) were chosen to avoid abusing memory allocation and using it when it was strictly necessary.

```extract_line``` extracts until the newline character from the stash, and updates the stash to begin from the first character after the newline

```expand_sbuff``` append BUFFER to my stash, expanding the stash if necessary.

```free_stash``` methodical way to free and set to null my mallocs, which in this case is only the stash. Originally i just freed when needed but this caused some memory issues
