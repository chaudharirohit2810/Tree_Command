// This is used for diffrent colors and strings in the program
#define STR "\u2503 \u0336\u0336\u0336\u0336 \u0336\u0336\u0336\u0336"

// To print the tree into the specified file
void file_print_normal(FILE* fp, node* root, int indent, int start, int size_toggle, int user_toggle, int filelimit, int P_toggle, char* pattern) {
	int i;
	if (root == NULL)
		return;
	if (user_toggle && size_toggle) {
		if (start == 1) {
			if(root->rec->num_childs <= filelimit) {
				fprintf(fp, "%s\n", root->rec->name);
			}else {
				fprintf(fp, "%s ", root->rec->name);
			}
		} else {
			if (root->rec->is_directory) {
				D++;
				for (i = 0; i < indent; i++)
					fprintf(fp, "\u2503   ");
				fprintf(fp, "%s", STR);
				if(root->rec->num_childs <= filelimit) {
					fprintf(fp, "[%s\t   %ld]  %s\n", root->rec->username, root->rec->size, root->rec->name);
				}else {
					fprintf(fp, "[%s\t   %ld]  %s ", root->rec->username, root->rec->size, root->rec->name);
				}
			} else {
				if (root->rec->name[0] != '.') {
					if (P_toggle)
					{
						if(strmatch(root->rec->name, pattern, strlen(root->rec->name), strlen(pattern))) {
							F++;
							for (i = 0; i < indent; i++)
								fprintf(fp, "\u2503   ");
							fprintf(fp, "%s[%s\t   %ld]  ", STR, root->rec->username, root->rec->size);
							fprintf(fp, "%s\n", root->rec->name);
						}
					}else {
						F++;
						for (i = 0; i < indent; i++)
							fprintf(fp, "\u2503   ");
						fprintf(fp, "%s[%s\t   %ld]  ", STR, root->rec->username, root->rec->size);
						fprintf(fp, "%s\n", root->rec->name);
					}
				}
			}
		}
	} else if (user_toggle) {
		if (start == 1) {
			if(root->rec->num_childs <= filelimit) {
				fprintf(fp, "%s\n", root->rec->name);
			}else {
				fprintf(fp, "%s ", root->rec->name);
			}
		} else {
			if (root->rec->is_directory) {
				D++;
				for (i = 0; i < indent; i++)
					fprintf(fp, "\u2503   ");
				fprintf(fp, "%s", STR);
				if(root->rec->num_childs <= filelimit) {
					fprintf(fp, "[%s\t]%s\n", root->rec->username, root->rec->name);
				}else {
					fprintf(fp, "[%s\t]%s ", root->rec->username, root->rec->name);
				}
			} else {
				if (root->rec->name[0] != '.') {
					if (P_toggle)
					{
						if(strmatch(root->rec->name, pattern, strlen(root->rec->name), strlen(pattern))) {
							F++;
							for (i = 0; i < indent; i++)
								fprintf(fp, "\u2503   ");
							fprintf(fp, "%s[%s\t]  ", STR, root->rec->username);
							fprintf(fp, "%s\n", root->rec->name);
						}
					}else {
						F++;
						for (i = 0; i < indent; i++)
							fprintf(fp, "\u2503   ");
						fprintf(fp, "%s[%s\t]  ", STR, root->rec->username);
						fprintf(fp, "%s\n", root->rec->name);
					}
				}
			}
		}
	} else if (size_toggle) {
		if (start == 1) {
			if(root->rec->num_childs <= filelimit) {
				fprintf(fp, "%s\n", root->rec->name);
			}else {
				fprintf(fp, "%s ", root->rec->name);
			}
		} else {
			if (root->rec->is_directory) {
				D++;
				for (i = 0; i < indent; i++)
					fprintf(fp, "\u2503   ");
				fprintf(fp, "%s", STR);
				if(root->rec->num_childs <= filelimit) {
					fprintf(fp, "[   %ld]%s\n", root->rec->size, root->rec->name);
				}else {
					fprintf(fp, "[   %ld]%s ", root->rec->size, root->rec->name);
				}
			} else {
				if (root->rec->name[0] != '.') {
					if (P_toggle)
					{
						if(strmatch(root->rec->name, pattern, strlen(root->rec->name), strlen(pattern))) {
							F++;
							for (i = 0; i < indent; i++)
								fprintf(fp, "\u2503   ");
							fprintf(fp, "%s[   %ld]  ", STR, root->rec->size);
							fprintf(fp, "%s\n", root->rec->name);
						}
					}else {
						F++;
						for (i = 0; i < indent; i++)
							fprintf(fp, "\u2503   ");
						fprintf(fp, "%s[   %ld]  ", STR, root->rec->size);
						fprintf(fp, "%s\n", root->rec->name);
					}
				}
			}
		}
	} else {
		if (start == 1) {
			if(root->rec->num_childs <= filelimit) {
				fprintf(fp, "%s\n", root->rec->name);
			}else {
				fprintf(fp, "%s ", root->rec->name);
			}
		} else {
			if (root->rec->is_directory) {
				D++;
				for (i = 0; i < indent; i++)
					fprintf(fp, "\u2503   ");
				fprintf(fp, "%s", STR);
				if(root->rec->num_childs <= filelimit) {
					fprintf(fp, "%s\n", root->rec->name);
				}else {
					fprintf(fp, "%s ", root->rec->name);
				}
			} else {
				if (root->rec->name[0] != '.') {
					if (P_toggle)
					{
						if(strmatch(root->rec->name, pattern, strlen(root->rec->name), strlen(pattern))) {
							F++;
							for (i = 0; i < indent; i++)
								fprintf(fp, "\u2503   ");
							fprintf(fp, "%s", STR);
							fprintf(fp, "%s\n", root->rec->name);
						}
					}else {
						F++;
						for (i = 0; i < indent; i++)
							fprintf(fp, "\u2503   ");
						fprintf(fp, "%s", STR);
						fprintf(fp, "%s\n", root->rec->name);
					}
				}
			}
		}
 	}

	if(root->rec->num_childs <= filelimit) {
    		for (i = 0; i < root->rec->num_all_childs; i++) {
		    	if (root->pointers[i] != NULL && root->pointers[i]->rec->name[0] != '.')
				    file_print_normal(fp, root->pointers[i], indent + 1, 0, size_toggle, user_toggle, filelimit, P_toggle, pattern);
    		}
	}else {
		fprintf(fp, "%s[%d entries exceeds file limit, not opening dir]\n", NRM, root->rec->num_childs);
	}
}

// To print the tree with hidden files in to the specified file
void file_print_all(FILE* fp, node* root, int indent, int start, int size_toggle, int user_toggle, int filelimit, int P_toggle, char* pattern) {
	int i;
	if (root == NULL)
		return;
	
	if (size_toggle && user_toggle) {
        	if (start == 1) {
			if(root->rec->num_childs <= filelimit) {
            			fprintf(fp, "%s\n", root->rec->name);
			}else {
				fprintf(fp, "%s ", root->rec->name);
			}
        	} else {
           		if (root->rec->is_directory) {
                		D++;
                		for (i = 0; i < indent; i++)
                    			fprintf(fp, "\u2503   ");
                		fprintf(fp, "%s", STR);
				if(root->rec->num_childs <= filelimit) {
                			fprintf(fp, "[%s\t   %ld]  %s\n", root->rec->username, root->rec->size, root->rec->name);
				}else {
                			fprintf(fp, "[%s\t   %ld]  %s ", root->rec->username, root->rec->size, root->rec->name);
				}
            		} else {
                		if (strcmp(root->rec->name, ".") != 0 && strcmp(root->rec->name, "..") != 0) {
                    			if (P_toggle)
					{
						if(strmatch(root->rec->name, pattern, strlen(root->rec->name), strlen(pattern))) {
							F++;
							for (i = 0; i < indent; i++)
								fprintf(fp, "\u2503   ");
							fprintf(fp, "%s[%s\t   %ld]  ", STR, root->rec->username, root->rec->size);
							fprintf(fp, "%s\n", root->rec->name);
						}
					}else {
						F++;
						for (i = 0; i < indent; i++)
							fprintf(fp, "\u2503   ");
						fprintf(fp, "%s[%s\t   %ld]  ", STR, root->rec->username, root->rec->size);
						fprintf(fp, "%s\n", root->rec->name);
					}
                		}
            		}	
        	}
    	} else if (user_toggle) {
        	if (start == 1) {
			if(root->rec->num_childs <= filelimit) {
            			fprintf(fp, "%s\n", root->rec->name);
			}else {
            			fprintf(fp, "%s ", root->rec->name);
			}
        	} else {
           		if (root->rec->is_directory) {
                		D++;
                		for (i = 0; i < indent; i++)
                    			fprintf(fp, "\u2503   ");
                		fprintf(fp, "%s", STR);
				if(root->rec->num_childs <= filelimit) {
                			fprintf(fp, "[%s\t]  %s\n", root->rec->username, root->rec->name);
				}else {
                			fprintf(fp, "[%s\t]  %s ", root->rec->username, root->rec->name);
				}
            		} else {
                		if (strcmp(root->rec->name, ".") != 0 && strcmp(root->rec->name, "..") != 0) {
                    			if (P_toggle)
					{
						if(strmatch(root->rec->name, pattern, strlen(root->rec->name), strlen(pattern))) {
							F++;
							for (i = 0; i < indent; i++)
								fprintf(fp, "\u2503   ");
							fprintf(fp, "%s[%s\t]  ", STR, root->rec->username);
							fprintf(fp, "%s\n", root->rec->name);
						}
					}else {
						F++;
						for (i = 0; i < indent; i++)
							fprintf(fp, "\u2503   ");
						fprintf(fp, "%s[%s\t]  ", STR, root->rec->username);
						fprintf(fp, "%s\n", root->rec->name);
					}
                		}
            		}	
        	}
    	} else if (size_toggle) {
        	if (start == 1) {
			if(root->rec->num_childs <= filelimit) {
            			fprintf(fp, "%s\n", root->rec->name);
			}else {
            			fprintf(fp, "%s ", root->rec->name);
			}
        	} else {
           		if (root->rec->is_directory) {
                		D++;
                		for (i = 0; i < indent; i++)
                    			fprintf(fp, "\u2503   ");
                		fprintf(fp, "%s", STR);
				if(root->rec->num_childs <= filelimit) {
                			fprintf(fp, "[   %ld]%s\n", root->rec->size, root->rec->name);
				}else {
                			fprintf(fp, "[   %ld]%s ", root->rec->size, root->rec->name);
				}
            		} else {
                		if (strcmp(root->rec->name, ".") != 0 && strcmp(root->rec->name, "..") != 0) {
                    			if (P_toggle)
					{
						if(strmatch(root->rec->name, pattern, strlen(root->rec->name), strlen(pattern))) {
							F++;
							for (i = 0; i < indent; i++)
								fprintf(fp, "\u2503   ");
							fprintf(fp, "%s[   %ld]  ", STR, root->rec->size);
							fprintf(fp, "%s\n", root->rec->name);
						}
					}else {
						F++;
						for (i = 0; i < indent; i++)
							fprintf(fp, "\u2503   ");
						fprintf(fp, "%s[   %ld]  ", STR, root->rec->size);
						fprintf(fp, "%s\n", root->rec->name);
					}
                		}
            		}	
        	}
    	} else {
        	if (start == 1) {
			if(root->rec->num_childs <= filelimit) {
         	 	  	fprintf(fp, "%s\n", root->rec->name);
			}else {
				fprintf(fp, "%s ", root->rec->name);
			}
        	} else {
            		if (root->rec->is_directory) {
                		D++;
                		for (i = 0; i < indent; i++)
                    			fprintf(fp, "\u2503   ");
                		fprintf(fp, "%s", STR);
				if(root->rec->num_childs <= filelimit) {
                			fprintf(fp, "%s\n", root->rec->name);
				}else {
					fprintf(fp, "%s ", root->rec->name);
				}
            		} else {
                		if (strcmp(root->rec->name, ".") != 0 && strcmp(root->rec->name, "..") != 0) {
                    			if (P_toggle)
					{
						if(strmatch(root->rec->name, pattern, strlen(root->rec->name), strlen(pattern))) {
							F++;
							for (i = 0; i < indent; i++)
								fprintf(fp, "\u2503   ");
							fprintf(fp, "%s", STR);
							fprintf(fp, "%s\n", root->rec->name);
						}
					}else {
						F++;
						for (i = 0; i < indent; i++)
							fprintf(fp, "\u2503   ");
						fprintf(fp, "%s", STR);
						fprintf(fp, "%s\n", root->rec->name);
					}
                		}
            		}
        	}
    	}

	if(root->rec->num_childs <= filelimit) {
    		for (i = 0; i < root->rec->num_all_childs; i++) {
        		if (root->pointers[i] != NULL)
            			file_print_all(fp, root->pointers[i], indent + 1, 0, size_toggle, user_toggle, filelimit, P_toggle, pattern);
    		}
	}else {
		fprintf(fp, "[%d entries exceeds file limit, not opening dir]\n", root->rec->num_childs);
	}
}

// To print only directories into the specified file
void file_print_normal_directory(FILE* fp, node* root, int indent, int start, int size_toggle, int user_toggle, int filelimit)
{
    	int i;
    	if (root == NULL)
        	return;

	if (size_toggle && user_toggle) {
        	if (start == 1) {
            		if(root->rec->num_directories <= filelimit) {
            			fprintf(fp, "%s\n", root->rec->name);
			}else {
				fprintf(fp, "%s ", root->rec->name);
			}
        	} else {
            		if (root->rec->is_directory) {
                		D++;
                		for (i = 0; i < indent; i++)
                    			fprintf(fp, "\u2503   ");
                		fprintf(fp, "%s", STR);
				if(root->rec->num_directories <= filelimit) {
                			fprintf(fp, "[%s\t   %ld]  %s\n", root->rec->username, root->rec->size, root->rec->name);
				}else {
                			fprintf(fp, "[%s\t   %ld]  %s ", root->rec->username, root->rec->size, root->rec->name);
				}
            		}
        	}	
    	} else if (user_toggle) {
        	if (start == 1) {
            		if(root->rec->num_directories <= filelimit) {
            			fprintf(fp, "%s\n", root->rec->name);
			}else {
            			fprintf(fp, "%s ", root->rec->name);
			}
        	} else {
            		if (root->rec->is_directory) {
                		D++;
                		for (i = 0; i < indent; i++)
                    			fprintf(fp, "\u2503   ");
                		fprintf(fp, "%s", STR);
				if(root->rec->num_directories <= filelimit) {
                			fprintf(fp, "[%s\t]  %s\n", root->rec->username, root->rec->name);
				}else {
                			fprintf(fp, "[%s\t]  %s ", root->rec->username, root->rec->name);
				}
            		}
        	}	
    	} else if (size_toggle) {
        	if (start == 1) {
            		if(root->rec->num_directories <= filelimit) {
            			fprintf(fp, "%s\n", root->rec->name);
			}else {
            			fprintf(fp, "%s ", root->rec->name);
			}
        	} else {
            		if (root->rec->is_directory) {
                		D++;
                		for (i = 0; i < indent; i++)
                    			fprintf(fp, "\u2503   ");
                		fprintf(fp, "%s", STR);
				if(root->rec->num_directories <= filelimit) {
                			fprintf(fp, "[   %ld]%s\n", root->rec->size, root->rec->name);
				}else {
                			fprintf(fp, "[   %ld]%s ", root->rec->size, root->rec->name);
				}
            		}
        	}	
    	} else {
        	if (start == 1) {
            		if(root->rec->num_directories <= filelimit) {
            			fprintf(fp, "%s\n", root->rec->name);
			}else {
            			fprintf(fp, "%s ", root->rec->name);
			}
        	} else {
            		if (root->rec->is_directory) {
                		D++;
                		for (i = 0; i < indent; i++)
                    			fprintf(fp, "\u2503   ");
                		fprintf(fp, "%s", STR);
				if(root->rec->num_directories <= filelimit) {
                			fprintf(fp, "%s\n", root->rec->name);
				}else {
					fprintf(fp, "%s ", root->rec->name);
				}
            		}
        	}
    	}

	if(root->rec->num_directories <= filelimit) {
    		for (i = 0; i < root->rec->num_all_childs; i++) {
        		if (root->pointers[i] != NULL && root->pointers[i]->rec->name[0] != '.')
            			file_print_normal_directory(fp, root->pointers[i], indent + 1, 0, size_toggle, user_toggle, filelimit);
    		}
	}else {
		fprintf(fp, "[%d entries exceeds filelimit, not opening dir]\n", root->rec->num_directories);
	}
}

// To print directories including hidden directories into the specified file
void file_print_all_directory(FILE* fp, node* root, int indent, int start, int size_toggle, int user_toggle, int filelimit)
{
    	int i;
    	if (root == NULL)
        	return;
	if (size_toggle && user_toggle) {
        	if (start == 1) {
            		if(root->rec->num_all_directories <= filelimit) {
            			fprintf(fp, "%s\n", root->rec->name);
			}else {
				fprintf(fp, "%s ", root->rec->name);
			}
        	} else {
            		if (root->rec->is_directory) {
                		D++;
                		for (i = 0; i < indent; i++)
                    			fprintf(fp, "\u2503   ");
                		fprintf(fp, "%s", STR);
				if(root->rec->num_all_directories <= filelimit) {
                			fprintf(fp, "[%s\t   %ld]  %s\n", root->rec->username, root->rec->size, root->rec->name);
				}else {
                			fprintf(fp, "[%s\t   %ld]  %s ", root->rec->username, root->rec->size, root->rec->name);
				}
            		}
        	}
    	} else if (user_toggle) {
        	if (start == 1) {
            		if(root->rec->num_all_directories <= filelimit) {
            			fprintf(fp, "%s\n", root->rec->name);
			}else {
            			fprintf(fp, "%s ", root->rec->name);
			}
        	} else {
            		if (root->rec->is_directory) {
                		D++;
                		for (i = 0; i < indent; i++)
                    			fprintf(fp, "\u2503   ");
                		fprintf(fp, "%s", STR);
				if(root->rec->num_all_directories <= filelimit) {
                			fprintf(fp, "[%s\t]  %s\n", root->rec->username, root->rec->name);
				}else {
                			fprintf(fp, "[%s\t]  %s ", root->rec->username, root->rec->name);
				}
            		}
        	}
    	} else if (size_toggle) {
        	if (start == 1) {
            		if(root->rec->num_all_directories <= filelimit) {
            			fprintf(fp, "%s\n", root->rec->name);
			}else {
            			fprintf(fp, "%s ", root->rec->name);
			}
        	} else {
            		if (root->rec->is_directory) {
                		D++;
                		for (i = 0; i < indent; i++)
                    			fprintf(fp, "\u2503   ");
                		fprintf(fp, "%s", STR);
				if(root->rec->num_all_directories <= filelimit) {
                			fprintf(fp, "[   %ld]%s\n", root->rec->size, root->rec->name);
				}else {
                			fprintf(fp, "[   %ld]%s ", root->rec->size, root->rec->name);
				}
            		}
        	}
    	} else {
        	if (start == 1) {
            		if(root->rec->num_all_directories <= filelimit) {
            			fprintf(fp, "%s\n", root->rec->name);
			}else {
            			fprintf(fp, "%s ", root->rec->name);
			}
        	} else {
            		if (root->rec->is_directory) {
                		D++;
                		for (i = 0; i < indent; i++)
                    			fprintf(fp, "\u2503   ");
                		fprintf(fp, "%s", STR);
				if(root->rec->num_all_directories <= filelimit) {
                			fprintf(fp, "%s\n", root->rec->name);
				}else {
					fprintf(fp, "%s ", root->rec->name);
				}
            		}
        	}
    	}
	if(root->rec->num_all_directories <= filelimit) {
    		for (i = 0; i < root->rec->num_all_childs; i++) {
        		if (root->pointers[i] != NULL)
            			file_print_all_directory(fp, root->pointers[i], indent + 1, 0, size_toggle, user_toggle, filelimit);
    		}
	}else {
		fprintf(fp, "[%d entries exceeds filelimit, not opening dir]\n", root->rec->num_all_directories);
	}
}
