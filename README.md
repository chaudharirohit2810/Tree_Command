# Tree Command in Linux

### Tree command implementation using c : 

--tree is a recursive directory listing program that produces a depth-indented listing of files.
--With no arguments, tree lists the files in the current directory.
--When directory arguments are given, tree lists all the files or directories found in the given directories each in turn.
--Upon completion of listing all files and directories found, tree returns the total number of files and directories listed.
--There are options to change the characters used in the output, and to use color output.

### Options that are implemented :

-a : All files are printed. By default, tree does not print hidden files.

-d : List directories only.

–filelimit # : Do not descend directories that contain more than # entries.

-o file name : Send output to file name.

-u : Print the username, or UID # if no username is available, of the file.

-s : Print the size of each file along with the name.

-t : Sort the output by last modification time instead of alphabetically.

-r : Sort the output in reverse alphabetic order.

-J : Turn on JSON output. Outputs the directory tree as an JSON formatted array.



