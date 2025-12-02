# my\_libft

Big libft

Contains:

- Basic libft functions (the most useful to avoid bloat)

- get\_next\_line

- printf (and fprintf)

- libmalloc

Todo:

- Rewrite gnl to use libmalloc
	- One function has 4 args, which is pretty bad - can't add t\_libmlc in args
	- Will just rewrite gnl completely and make a version with libmlc
	- Printf does not use any mallocs, but it might with floats, might see later
	- Obviously the much better way would be to have a global variable in `libmalloc.h`, and maybe even find a way to override calls to `malloc()` and `free()`, but we can't do this yet
