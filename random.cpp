#include <fstream>
#include <time.h>

unsigned char *field = 0;
unsigned int nField_size = 0;
unsigned char nField_x = 0, nField_y = 0;

int main(int argc, char *argv[]){

    if(argc > 1){
        // Initialiseer en voed random nummer generator met huidige tijd
        srand ( time(NULL) );

        // Lees de grootte van 't veld uit de parameters
        nField_size = atoi(argv[1]);
        nField_x = nField_size/10, nField_y = nField_size%10;
        printf("Grootte veld: %dx%d\n",nField_x,nField_y);

        // Creeër de arrays
        field = new unsigned char[nField_x*nField_y];
        memset(field,0x00,nField_x*nField_y);

        // Vul de arrays
        for(unsigned int i = 0;i < nField_x*nField_y;i++)
            field[i] = rand()%10;

        // Print de arrays
        for(unsigned int i = 0;i < nField_x*nField_y;i++){
            printf("%d ",field[i]);
            if((i+1)%nField_x == 0)
                printf("\n");
        }
    } else
        printf("Niet genoeg parameters! Correct gebruik:\n%s <grootte speelveld>\n\n",strrchr(argv[0],'\\')+1);
    return 0;
}
