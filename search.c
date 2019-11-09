// Function that matches input str with
// given wildcard pattern
int strmatch(char str[], char pattern[],
              int n, int m)
{
    // empty pattern can only match with
    // empty string
    if (m == 0)
        return (n == 0);

    // lookup table for storing results of
    // subproblems
    int lookup[n + 1][m + 1];

    // initailze lookup table to false
    for(int i = 0; i < n+1; i++) {
	    for(int j = 0; j < m+1; j++) {
		    lookup[i][j] = 0;
	    }
    }

    // empty pattern can match with empty string
    lookup[0][0] = 1;

    // '*' can match with empty string
    for (int j = 1; j <= m; j++)
        if (pattern[j - 1] == '*')
            lookup[0][j] = lookup[0][j - 1];

    // fill the table in bottom-up fashion
    for (int i = 1; i <= n; i++)
    {
	    for (int j = 1; j <= m; j++) 
        { 
            /* * can be empty character or character in the string we check that two conditions here*/ 
            if (pattern[j - 1] == '*') 
                lookup[i][j] = lookup[i][j - 1] || 
                               lookup[i - 1][j]; 
  
            /* ? should be exact match which we check here */
            else if (pattern[j - 1] == '?' || 
                    str[i - 1] == pattern[j - 1]) 
                lookup[i][j] = lookup[i - 1][j - 1]; 
            else lookup[i][j] = 0; 
        } 
    } 
  
    return lookup[n][m]; 
}