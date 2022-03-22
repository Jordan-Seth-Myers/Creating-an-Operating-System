// Jordan Seth Myers

// main driver in C
#include <stdio.h>
// global k_print, k_border;


void k_clearscr();
void k_print(char *string, int string_length, int row, int col);
void print_border(int start_row, int start_col, int end_row, int end_col);

int main()
{
    
    k_clearscr();
    print_border(0, 0, 79, 79);


    k_print("OS 4100", 7, 12, 37);
    
    
    
    while(1)
    {

    }     //keeping the run up and running.
    return 0;
    
}
    
void print_border(int start_row,int start_col, int end_row, int end_col)
{         

    char topBottomLine[80];   // hold - and +
    char sideTosideLine[80];  // ' ' and |

    int i,j; 
    start_row = 0;
    start_col = 0;
    end_row = 24;
    end_col = 79;
    char plus[1] = {"+"};
    char line[1] = {"-"};

    for(i = 0; i <= 25; i++)
    {
        while(i <=25)
        {
            k_print(plus, 1, start_row, start_col);
            k_print(plus, 1, end_row, start_col);
            k_print(plus, 1, start_row, end_col);
            k_print(plus, 1 ,end_row, end_col);
            i++;
        }
    }
    for(i = 0; i <= 79; i++)
    {
        i++;
        while(i <=78)
        {
            k_print(line, 1, 0, i);
            k_print(line, 1 ,24, i);
            i++;
        }
    }
    

     
} 

void k_clearscr()
{
    char spaces[80];

    for(int i = 0; i <= 79; i++)            // filling array row
    {
        spaces[i] = ' ';

    }
    for(int j = 0; j <= 24; j++)           // calling k print to print to screen 
    {
        k_print(spaces, 80, j, 0);
    }
}

    





