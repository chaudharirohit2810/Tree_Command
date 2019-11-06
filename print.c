// This is used for diffrent colors and strings in the program
#define STR "\u2503 \u0336\u0336\u0336\u0336 \u0336\u0336\u0336\u0336"
#define NRM "\x1B[0m"
#define BLUE "\033[1m\x1B[34m"
#define GRN "\033[1m\x1B[32m"
#define RED "\033[1m\x1B[31m"
#define MAGENTA "\033[1m\x1B[35m"

// Variables to calculate number of directories and files
int D = 0, F = 0;

// To give color to file according to its extension
int colorChecker(char* name) {

	/*
		COLOR		RETURN VALUE
		GREEN			2
		MAGNETA			3
		RED			4
		NONE			0
	*/

	if (strstr(name, ".sh") != NULL || strstr(name, ".") == NULL || strstr(name, ".in") != NULL)
		return 2;

	if (strstr(name, ".svg") != NULL || strstr(name, ".jpg") != NULL || strstr(name, ".png") != NULL || strstr(name, ".xpm") != NULL)
		return 3;

	if (strstr(name, ".tar.gz") != NULL || strstr(name, ".tar.xz") != NULL || strstr(name, ".zip") != NULL)
		return 4;

	return 0;
}

// To print the tree
void print_normal(node* root, int indent, int start, int size_toggle, int user_toggle, int filelimit) {
	int i;
	if (root == NULL)
		return;
	if (user_toggle && size_toggle) {
		if (start == 1) {
			if(root->rec->num_childs <= filelimit) {
				printf("%s%s\n", BLUE, root->rec->name);
			}else {
				printf("%s%s ", BLUE, root->rec->name);
			}
		} else {
			if (root->rec->is_directory) {
				D++;
				for (i = 0; i < indent; i++)
					printf("%s\u2503   ", NRM);
				printf("%s%s", NRM, STR);
				if(root->rec->num_childs <= filelimit) {
					printf("[%s\t   %ld]  %s%s\n", root->rec->username, root->rec->size, BLUE, root->rec->name);
				}else {
					printf("[%s\t   %ld]  %s%s ", root->rec->username, root->rec->size, BLUE, root->rec->name);
				}
			} else {
				if (root->rec->name[0] != '.') {
					F++;
					for (i = 0; i < indent; i++)
						printf("%s\u2503   ", NRM);
					printf("%s%s[%s\t   %ld]  ", NRM, STR, root->rec->username, root->rec->size);
					if (colorChecker(root->rec->name) == 2) {
						printf("%s%s\n", GRN, root->rec->name);
					} else if (colorChecker(root->rec->name) == 3) {
						printf("%s%s\n", MAGENTA, root->rec->name);
					} else if (colorChecker(root->rec->name) == 4) {
						printf("%s%s\n", RED, root->rec->name);
					} else {
						printf("%s%s\n", NRM, root->rec->name);
					}
				}
			}
		}
	} else if (user_toggle) {
		if (start == 1) {
			if(root->rec->num_childs <= filelimit) {
				printf("%s%s\n", BLUE, root->rec->name);
			}else {
				printf("%s%s ", BLUE, root->rec->name);
			}
		} else {
			if (root->rec->is_directory) {
				D++;
				for (i = 0; i < indent; i++)
					printf("%s\u2503   ", NRM);
				printf("%s%s", NRM, STR);
				if(root->rec->num_childs <= filelimit) {
					printf("[%s\t]%s%s\n", root->rec->username, BLUE, root->rec->name);
				}else {
					printf("[%s\t]%s%s ", root->rec->username, BLUE, root->rec->name);
				}
			} else {
				if (root->rec->name[0] != '.') {
					F++;
					for (i = 0; i < indent; i++)
						printf("%s\u2503   ", NRM);
					printf("%s%s[%s\t]  ", NRM, STR, root->rec->username);
					if (colorChecker(root->rec->name) == 2) {
						printf("%s%s\n", GRN, root->rec->name);
					} else if (colorChecker(root->rec->name) == 3) {
						printf("%s%s\n", MAGENTA, root->rec->name);
					} else if (colorChecker(root->rec->name) == 4) {
						printf("%s%s\n", RED, root->rec->name);
					} else {
						printf("%s%s\n", NRM, root->rec->name);
					}
				}
			}
		}
	} else if (size_toggle) {
		if (start == 1) {
			if(root->rec->num_childs <= filelimit) {
				printf("%s%s\n", BLUE, root->rec->name);
			}else {
				printf("%s%s ", BLUE, root->rec->name);
			}
		} else {
			if (root->rec->is_directory) {
				D++;
				for (i = 0; i < indent; i++)
					printf("%s\u2503   ", NRM);
				printf("%s%s", NRM, STR);
				if(root->rec->num_childs <= filelimit) {
					printf("[   %ld]%s%s\n", root->rec->size, BLUE, root->rec->name);
				}else {
					printf("[   %ld]%s%s ", root->rec->size, BLUE, root->rec->name);
				}
			} else {
				if (root->rec->name[0] != '.') {
					F++;
					for (i = 0; i < indent; i++)
						printf("%s\u2503   ", NRM);
					printf("%s%s[   %ld]", NRM, STR, root->rec->size);
					if (colorChecker(root->rec->name) == 2) {
						printf("%s%s\n", GRN, root->rec->name);
					} else if (colorChecker(root->rec->name) == 3) {
						printf("%s%s\n", MAGENTA, root->rec->name);
					} else if (colorChecker(root->rec->name) == 4) {
						printf("%s%s\n", RED, root->rec->name);
					} else {
						printf("%s%s\n", NRM, root->rec->name);
					}
				}
			}
		}
	} else {
		if (start == 1) {
			if(root->rec->num_childs <= filelimit) {
				printf("%s%s\n", BLUE, root->rec->name);
			}else {
				printf("%s%s ", BLUE, root->rec->name);
			}
		} else {
			if (root->rec->is_directory) {
				D++;
				for (i = 0; i < indent; i++)
					printf("%s\u2503   ", NRM);
				printf("%s%s", NRM, STR);
				if(root->rec->num_childs <= filelimit) {
					printf("%s%s\n", BLUE, root->rec->name);
				}else {
					printf("%s%s ", BLUE, root->rec->name);
				}
			} else {
				if (root->rec->name[0] != '.') {
					F++;
					for (i = 0; i < indent; i++)
						printf("%s\u2503   ", NRM);
					printf("%s%s", NRM, STR);
					if (colorChecker(root->rec->name) == 2) {
						printf("%s%s\n", GRN, root->rec->name);
					} else if (colorChecker(root->rec->name) == 3) {
						printf("%s%s\n", MAGENTA, root->rec->name);
					} else if (colorChecker(root->rec->name) == 4) {
						printf("%s%s\n", RED, root->rec->name);
					} else {
						printf("%s%s\n", NRM, root->rec->name);
					}
				}
			}
		}
 	}

	if(root->rec->num_childs <= filelimit) {
    		for (i = 0; i < root->rec->num_all_childs; i++) {
		    	if (root->pointers[i] != NULL && root->pointers[i]->rec->name[0] != '.')
				    print_normal(root->pointers[i], indent + 1, 0, size_toggle, user_toggle, filelimit);
    		}
	}else {
		printf("%s[%d entries exceeds file limit, not opening dir]\n", NRM, root->rec->num_childs);
	}
}

// To print the tree with hidden files
void print_all(node* root, int indent, int start, int size_toggle, int user_toggle, int filelimit) {
	int i;
	if (root == NULL)
		return;
	
	if (size_toggle && user_toggle) {
        	if (start == 1) {
			if(root->rec->num_childs <= filelimit) {
            			printf("%s%s\n", BLUE, root->rec->name);
			}else {
				printf("%s%s ", BLUE, root->rec->name);
			}
        	} else {
           		if (root->rec->is_directory) {
                		D++;
                		for (i = 0; i < indent; i++)
                    			printf("%s\u2503   ", NRM);
                		printf("%s%s", NRM, STR);
				if(root->rec->num_childs <= filelimit) {
                			printf("[%s\t   %ld]  %s%s\n", root->rec->username, root->rec->size, BLUE, root->rec->name);
				}else {
                			printf("[%s\t   %ld]  %s%s ", root->rec->username, root->rec->size, BLUE, root->rec->name);
				}
            		} else {
                		if (strcmp(root->rec->name, ".") != 0 && strcmp(root->rec->name, "..") != 0) {
                    			F++;
                    			for (i = 0; i < indent; i++)
                        			printf("%s\u2503   ", NRM);
                    			printf("%s%s[%s\t   %ld]  ", NRM, STR, root->rec->username, root->rec->size);
                    			if (colorChecker(root->rec->name) == 2) {
                        			printf("%s%s\n", GRN, root->rec->name);
                    			} else if (colorChecker(root->rec->name) == 3) {
                        			printf("%s%s\n", MAGENTA, root->rec->name);
                    			} else if (colorChecker(root->rec->name) == 4) {
                        			printf("%s%s\n", RED, root->rec->name);
                    			} else {
                        			printf("%s%s\n", NRM, root->rec->name);
                    			}
                		}
            		}	
        	}
    	} else if (user_toggle) {
        	if (start == 1) {
			if(root->rec->num_childs <= filelimit) {
            			printf("%s%s\n", BLUE, root->rec->name);
			}else {
            			printf("%s%s ", BLUE, root->rec->name);
			}
        	} else {
           		if (root->rec->is_directory) {
                		D++;
                		for (i = 0; i < indent; i++)
                    			printf("%s\u2503   ", NRM);
                		printf("%s%s", NRM, STR);
				if(root->rec->num_childs <= filelimit) {
                			printf("[%s\t]  %s%s\n", root->rec->username, BLUE, root->rec->name);
				}else {
                			printf("[%s\t]  %s%s ", root->rec->username, BLUE, root->rec->name);
				}
            		} else {
                		if (strcmp(root->rec->name, ".") != 0 && strcmp(root->rec->name, "..") != 0) {
                    			F++;
                    			for (i = 0; i < indent; i++)
                        			printf("%s\u2503   ", NRM);
                    			printf("%s%s[%s\t]  ", NRM, STR, root->rec->username);
                    			if (colorChecker(root->rec->name) == 2) {
                        			printf("%s%s\n", GRN, root->rec->name);
                    			} else if (colorChecker(root->rec->name) == 3) {
                        			printf("%s%s\n", MAGENTA, root->rec->name);
                    			} else if (colorChecker(root->rec->name) == 4) {
                        			printf("%s%s\n", RED, root->rec->name);
                    			} else {
                        			printf("%s%s\n", NRM, root->rec->name);
                    			}
                		}
            		}	
        	}
    	} else if (size_toggle) {
        	if (start == 1) {
			if(root->rec->num_childs <= filelimit) {
            			printf("%s%s\n", BLUE, root->rec->name);
			}else {
            			printf("%s%s ", BLUE, root->rec->name);
			}
        	} else {
           		if (root->rec->is_directory) {
                		D++;
                		for (i = 0; i < indent; i++)
                    			printf("%s\u2503   ", NRM);
                		printf("%s%s", NRM, STR);
				if(root->rec->num_childs <= filelimit) {
                			printf("[   %ld]%s%s\n", root->rec->size, BLUE, root->rec->name);
				}else {
                			printf("[   %ld]%s%s ", root->rec->size, BLUE, root->rec->name);
				}
            		} else {
                		if (strcmp(root->rec->name, ".") != 0 && strcmp(root->rec->name, "..") != 0) {
                    			F++;
                    			for (i = 0; i < indent; i++)
                        			printf("%s\u2503   ", NRM);
                    			printf("%s%s[   %ld]", NRM, STR, root->rec->size);
                    			if (colorChecker(root->rec->name) == 2) {
                        			printf("%s%s\n", GRN, root->rec->name);
                    			} else if (colorChecker(root->rec->name) == 3) {
                        			printf("%s%s\n", MAGENTA, root->rec->name);
                    			} else if (colorChecker(root->rec->name) == 4) {
                        			printf("%s%s\n", RED, root->rec->name);
                    			} else {
                        			printf("%s%s\n", NRM, root->rec->name);
                    			}
                		}
            		}	
        	}
    	} else {
        	if (start == 1) {
			if(root->rec->num_childs <= filelimit) {
         	 	  	printf("%s%s\n", BLUE, root->rec->name);
			}else {
				printf("%s%s ", BLUE, root->rec->name);
			}
        	} else {
            		if (root->rec->is_directory) {
                		D++;
                		for (i = 0; i < indent; i++)
                    			printf("%s\u2503   ", NRM);
                		printf("%s%s", NRM, STR);
				if(root->rec->num_childs <= filelimit) {
                			printf("%s%s\n", BLUE, root->rec->name);
				}else {
					printf("%s%s ", BLUE, root->rec->name);
				}
            		} else {
                		if (strcmp(root->rec->name, ".") != 0 && strcmp(root->rec->name, "..") != 0) {
                    			F++;
                    			for (i = 0; i < indent; i++)
                        			printf("%s\u2503   ", NRM);
                    			printf("%s%s", NRM, STR);
                    			if (colorChecker(root->rec->name) == 2) {
                        			printf("%s%s\n", GRN, root->rec->name);
                    			} else if (colorChecker(root->rec->name) == 3) {
                        			printf("%s%s\n", MAGENTA, root->rec->name);
                    			} else if (colorChecker(root->rec->name) == 4) {
                        			printf("%s%s\n", RED, root->rec->name);
                    			} else {
                        			printf("%s%s\n", NRM, root->rec->name);
                    			}
                		}
            		}
        	}
    	}

	if(root->rec->num_childs <= filelimit) {
    		for (i = 0; i < root->rec->num_all_childs; i++) {
        		if (root->pointers[i] != NULL)
            			print_all(root->pointers[i], indent + 1, 0, size_toggle, user_toggle, filelimit);
    		}
	}else {
		printf("%s[%d entries exceeds file limit, not opening dir]\n", NRM, root->rec->num_childs);
	}
}

// To print only directories (Execution of -d flag)
void print_normal_directory(node* root, int indent, int start, int size_toggle, int user_toggle, int filelimit)
{
    	int i;
    	if (root == NULL)
        	return;

	if (size_toggle && user_toggle) {
        	if (start == 1) {
            		if(root->rec->num_directories <= filelimit) {
            			printf("%s%s\n", BLUE, root->rec->name);
			}else {
				printf("%s%s ", BLUE, root->rec->name);
			}
        	} else {
            		if (root->rec->is_directory) {
                		D++;
                		for (i = 0; i < indent; i++)
                    			printf("%s\u2503   ", NRM);
                		printf("%s%s", NRM, STR);
				if(root->rec->num_directories <= filelimit) {
                			printf("[%s\t   %ld]  %s%s\n", root->rec->username, root->rec->size, BLUE, root->rec->name);
				}else {
                			printf("[%s\t   %ld]  %s%s ", root->rec->username, root->rec->size, BLUE, root->rec->name);
				}
            		}
        	}	
    	} else if (user_toggle) {
        	if (start == 1) {
            		if(root->rec->num_directories <= filelimit) {
            			printf("%s%s\n", BLUE, root->rec->name);
			}else {
            			printf("%s%s ", BLUE, root->rec->name);
			}
        	} else {
            		if (root->rec->is_directory) {
                		D++;
                		for (i = 0; i < indent; i++)
                    			printf("%s\u2503   ", NRM);
                		printf("%s%s", NRM, STR);
				if(root->rec->num_directories <= filelimit) {
                			printf("[%s\t]  %s%s\n", root->rec->username, BLUE, root->rec->name);
				}else {
                			printf("[%s\t]  %s%s ", root->rec->username, BLUE, root->rec->name);
				}
            		}
        	}	
    	} else if (size_toggle) {
        	if (start == 1) {
            		if(root->rec->num_directories <= filelimit) {
            			printf("%s%s\n", BLUE, root->rec->name);
			}else {
            			printf("%s%s ", BLUE, root->rec->name);
			}
        	} else {
            		if (root->rec->is_directory) {
                		D++;
                		for (i = 0; i < indent; i++)
                    			printf("%s\u2503   ", NRM);
                		printf("%s%s", NRM, STR);
				if(root->rec->num_directories <= filelimit) {
                			printf("[   %ld]%s%s\n", root->rec->size, BLUE, root->rec->name);
				}else {
                			printf("[   %ld]%s%s ", root->rec->size, BLUE, root->rec->name);
				}
            		}
        	}	
    	} else {
        	if (start == 1) {
            		if(root->rec->num_directories <= filelimit) {
            			printf("%s%s\n", BLUE, root->rec->name);
			}else {
            			printf("%s%s ", BLUE, root->rec->name);
			}
        	} else {
            		if (root->rec->is_directory) {
                		D++;
                		for (i = 0; i < indent; i++)
                    			printf("%s\u2503   ", NRM);
                		printf("%s%s", NRM, STR);
				if(root->rec->num_directories <= filelimit) {
                			printf("%s%s\n", BLUE, root->rec->name);
				}else {
					printf("%s%s ", BLUE, root->rec->name);
				}
            		}
        	}
    	}

	if(root->rec->num_directories <= filelimit) {
    		for (i = 0; i < root->rec->num_all_childs; i++) {
        		if (root->pointers[i] != NULL && root->pointers[i]->rec->name[0] != '.')
            			print_normal_directory(root->pointers[i], indent + 1, 0, size_toggle, user_toggle, filelimit);
    		}
	}else {
		printf("%s[%d entries exceeds filelimit, not opening dir]\n", NRM, root->rec->num_directories);
	}
}

// To print directories including hidden directories
void print_all_directory(node* root, int indent, int start, int size_toggle, int user_toggle, int filelimit)
{
    	int i;
    	if (root == NULL)
        	return;
	if (size_toggle && user_toggle) {
        	if (start == 1) {
            		if(root->rec->num_all_directories <= filelimit) {
            			printf("%s%s\n", BLUE, root->rec->name);
			}else {
				printf("%s%s ", BLUE, root->rec->name);
			}
        	} else {
            		if (root->rec->is_directory) {
                		D++;
                		for (i = 0; i < indent; i++)
                    			printf("%s\u2503   ", NRM);
                		printf("%s%s", NRM, STR);
				if(root->rec->num_all_directories <= filelimit) {
                			printf("[%s\t   %ld]  %s%s\n", root->rec->username, root->rec->size, BLUE, root->rec->name);
				}else {
                			printf("[%s\t   %ld]  %s%s ", root->rec->username, root->rec->size, BLUE, root->rec->name);
				}
            		}
        	}
    	} else if (user_toggle) {
        	if (start == 1) {
            		if(root->rec->num_all_directories <= filelimit) {
            			printf("%s%s\n", BLUE, root->rec->name);
			}else {
            			printf("%s%s ", BLUE, root->rec->name);
			}
        	} else {
            		if (root->rec->is_directory) {
                		D++;
                		for (i = 0; i < indent; i++)
                    			printf("%s\u2503   ", NRM);
                		printf("%s%s", NRM, STR);
				if(root->rec->num_all_directories <= filelimit) {
                			printf("[%s\t]  %s%s\n", root->rec->username, BLUE, root->rec->name);
				}else {
                			printf("[%s\t]  %s%s ", root->rec->username, BLUE, root->rec->name);
				}
            		}
        	}
    	} else if (size_toggle) {
        	if (start == 1) {
            		if(root->rec->num_all_directories <= filelimit) {
            			printf("%s%s\n", BLUE, root->rec->name);
			}else {
            			printf("%s%s ", BLUE, root->rec->name);
			}
        	} else {
            		if (root->rec->is_directory) {
                		D++;
                		for (i = 0; i < indent; i++)
                    			printf("%s\u2503   ", NRM);
                		printf("%s%s", NRM, STR);
				if(root->rec->num_all_directories <= filelimit) {
                			printf("[   %ld]%s%s\n", root->rec->size, BLUE, root->rec->name);
				}else {
                			printf("[   %ld]%s%s ", root->rec->size, BLUE, root->rec->name);
				}
            		}
        	}
    	} else {
        	if (start == 1) {
            		if(root->rec->num_all_directories <= filelimit) {
            			printf("%s%s\n", BLUE, root->rec->name);
			}else {
            			printf("%s%s ", BLUE, root->rec->name);
			}
        	} else {
            		if (root->rec->is_directory) {
                		D++;
                		for (i = 0; i < indent; i++)
                    			printf("%s\u2503   ", NRM);
                		printf("%s%s", NRM, STR);
				if(root->rec->num_all_directories <= filelimit) {
                			printf("%s%s\n", BLUE, root->rec->name);
				}else {
					printf("%s%s ", BLUE, root->rec->name);
				}
            		}
        	}
    	}
	if(root->rec->num_all_directories <= filelimit) {
    		for (i = 0; i < root->rec->num_all_childs; i++) {
        		if (root->pointers[i] != NULL)
            			print_all_directory(root->pointers[i], indent + 1, 0, size_toggle, user_toggle, filelimit);
    		}
	}else {
		printf("%s[%d entries exceeds filelimit, not opening dir]\n", NRM, root->rec->num_all_directories);
	}
}

// Count number of directories
int DCount() {
    return D;
}

// Count number of files
int FCount() {
    return F;
}
