#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<pwd.h>

//This stores the whole information regarding the particular file
typedef struct record {
	char name[100];
	int is_directory;
	int num_childs;
	int num_all_childs;
	int num_all_directories;
	int num_directories;
	long size;
	int level;
	char username[100];
} record;


//This is particular node in tree
typedef struct node {
	struct node ** pointers;
	record* rec;
} node;	

//This is used for diffrent colors and strings in the program
#define STR "\u2503 \u0336\u0336\u0336\u0336 \u0336\u0336\u0336\u0336"
#define NRM "\x1B[0m"
#define BLUE "\033[1m\x1B[34m"
#define GRN "\033[1m\x1B[32m"
#define RED "\033[1m\x1B[31m"
#define MAGENTA "\033[1m\x1B[35m"

//To Insert the nodes in tree
node* insert_node(node* , char*, int, int , int );

//To destroy the tree after the use
node* destroy_tree(node* , node* );

//To get the file size 
long get_file_size(char* );

//To get the username of file
void get_username(char*, char* );
