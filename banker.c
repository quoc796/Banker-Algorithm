#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int max[10][10],allocation[10][10];
int available[10];
int p,r;



void calculateNeed(int needed[10][10],int allocation[10][10],int max[10][10])
{
    for(int i = 0 ; i < p; i++){
        for(int j = 0; j < r; j++)
        {
            needed[i][j] = max[i][j] - allocation[i][j];
        }
        
    }
}
void readMatrixLine(int matrix[10][10],int row[],int rowN)
{
    for(int i = 0; i < r; i++)
    {
        matrix[rowN][i] = row[i];
    }
}

void printMatrix(int matrix[10][10])
{
    for(int i = 0 ; i < p; i++){
        for(int j = 0; j < r; j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}


void banker()
{
    int needed[10][10];
    calculateNeed(needed,allocation,max);
    


    int i,j,sOrder = 0;
    bool finish[10];
    int  sSeq[10];

    //init finish array elememts to false
    for(i = 0; i < p; i++)
    {
        finish[i] = false; 
    }
    for(i = 0; i < p; i++)
    {
        if(!finish[i])
        {
            //comparing need and available
            //Mark true if need greater than available
            bool nGa = false;
            for(j = 0; j < r; j++)
            {
                if(needed[i][j] > available[j])
                {
                    nGa = true;
                    break;
                }
            }
            //Add process i to safeSequence if need < avai
            if(!nGa)
            {
                finish[i] = true;
                sSeq[sOrder] = i;
                sOrder += 1;
                //retrieved allocated R of process i
                for(j = 0; j < r; j++)
                {
                    available[j] += allocation[i][j];
                }
                
                //go back to check from the first proscess
                i = -1;

            }

        }
        
    }

    bool deadlock = false;
    for(int i =0 ; i < p; i++)
    {
        if(finish[i] == false)
        {
            printf("\n Encouter deadlock");  
            deadlock = true;
            break; 
        }
    }
    if(!deadlock)
    {
        printf("\n Safe sequence is: \n");
        
        for(i= 0; i < p;i++)
        {
            printf("%d ",sSeq[i]);
        }
    }

}
int main()
{
    FILE *fp;
    fp = fopen("input.txt","r+");
    

    int lc = 0;
    int lineParams[10];
    int lineIndex = 0;
    while (!feof(fp))
    {
        char c = fgetc(fp);
        if(c == ' ') continue;
        else if(c == '\n' || c == EOF)
        {
            if(lc == 0)
            {
                p = lineParams[0];
                r = lineParams[1];
            }
            else if(lc < p + 1)
            {
                readMatrixLine(allocation,lineParams,lc - 1);
            }
            else if(lc < 1 + 2 * p)
            {
                readMatrixLine(max,lineParams,lc - p - 1);
            }
            else
            {
                for(int i = 0; i < r; i++)
                {
                    available[i] = lineParams[i];
                }
            }
            lineIndex = 0;
            lc += 1;
        }
        else
        {
            lineParams[lineIndex] = c - '0';
            lineIndex++;
        }
        
       
        
    }
    banker();


}