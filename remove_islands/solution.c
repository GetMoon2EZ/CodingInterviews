/**
 * Author:    Luc Techer
 * Created:   
 * 
 * Description: 
 * Link: 
 * 
 * Difficulty: 
 * Key words: 
 * 
 * Compile with: gcc -Wall -Wextra solution.c -o solution.exe -g -lm
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

void dfs(int **matrix, int m, int n, int x, int y, int **visited);
int** remove_islands(int **matrix, int m, int n);
void print_matrix(int **matrix, int m, int n);
void free_matrix(int **matrix, int m);

int main()
{
    /***************************************************/
    /****************** INPUT SECTION ******************/
    /***************************************************/
    // Please limit your modifications to the input array while testing
    int in[6][6] = {
        { 1, 0, 0, 0, 0, 0 },
        { 0, 1, 0, 1, 1, 1 },
        { 0, 0, 1, 0, 1, 0 },
        { 1, 1, 0, 0, 1, 0 },
        { 1, 0, 1, 1, 0, 0 },
        { 1, 0, 0, 0, 0, 1 }
    };
    int m = 6;
    int n = 6;
    /***************************************************/
    /************** END OF INPUT SECTION ***************/
    /***************************************************/

    /*  ------------------------------------------------  */
    /* |                                                | */
    /* |     DO NOT MODIFY ANYTHING UNDER THIS LINE     | */
    /* |                                                | */
    /*  ------------------------------------------------  */

    /***************************************************/
    /************** START OF TYPECASTING ***************/
    /***************************************************/
    int **input = calloc(m, sizeof(int*));
    for (int i = 0; i < m; i++) {
        input[i] = calloc(n, sizeof(int));
        for (int j = 0; j < n; j++) {
            input[i][j] = in[i][j];
        }
    }

    printf("input = ");
    print_matrix(input, m, n);
    /***************************************************/
    /*************** END OF TYPECASTING ****************/
    /***************************************************/

    /***************************************************/
    /***************** START OF SOLVER *****************/
    /***************************************************/
    int **output = remove_islands(input, m, n);
    printf("\noutput = ");
    print_matrix(output, m, n);
    /***************************************************/
    /****************** END OF SOLVER ******************/
    /***************************************************/


    /***************************************************/
    /****************** FREE MEMORY ********************/
    /***************************************************/
    free_matrix(input, m);
    free_matrix(output, m);
    /***************************************************/
    /*************** END OF FREE MEMORY ***************/
    /***************************************************/
    return 0;
}

void dfs(int **matrix, int m, int n, int x, int y, int **visited)
{
    if (x < 0 || x >= m || y < 0 || y >=n || visited[x][y])
        return;

    if (matrix[x][y]) {
        visited[x][y] = 1;
        dfs(matrix, m, n, x-1, y, visited);
        dfs(matrix, m, n, x+1, y, visited);
        dfs(matrix, m, n, x, y-1, visited);
        dfs(matrix, m, n, x, y+1, visited);
    }
    return;
}

int** remove_islands(int **matrix, int m, int n)
{
    // Initialize output array
    int **output = calloc(m, sizeof(int *));
    for (int i = 0; i < m; i++) {
        output[i] = calloc(n, sizeof(int));
    }

    // Explore island on top and bottom edges
    for (int i = 0; i < n; i++) {
        dfs(matrix, m, n, 0, i, output);
        dfs(matrix, m, n, m-1, i, output);    
    }

    // Explore island on side edges
    for (int i = 0; i < m; i++) {
        dfs(matrix, m, n, i, 0, output);
        dfs(matrix, m, n, i, n-1, output);
    }
    return output;
}

void print_matrix(int **matrix, int m, int n)
{
    printf("{\n");
    for (int i = 0; i < m; i++) {
        printf("    { ");
        for (int j = 0; j < n; j++) {
            printf("%s%d", j?", ":"", matrix[i][j]);
        }
        printf(" }%s\n", i==m-1?"":",");
    }
    printf("};\n");
}

void free_matrix(int **matrix, int m)
{
    if (matrix) {
        for (int i = 0; i < m; i++) {
            if (matrix[i])
                free(matrix[i]);
        }
        free(matrix);
    }
}
