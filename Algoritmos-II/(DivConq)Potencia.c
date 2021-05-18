#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int potenciacao(int a, int b){
    int aux;
    if( a == 0)
        return 0;
    
    else if( b == 0)
        return 1;
    
    else if(b != 1){
        if(b % 2 == 0){
            aux = potenciacao(a, b/2);
            return aux * aux;
        }
        else{
            aux = potenciacao(a, (b-1)/2);
            return aux * aux * a;
        }
    }
    else
        return a;
}

int main(void) {
    int a;
    int b;
    int aux;

    scanf("%d %d", &a, &b);
    
    if( a >= 0 && b >=0){
        aux = potenciacao(a,b);
        printf("%d",aux);
    }
   
       
    return 0;
}

//________________________OU________________________________
/*
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int potenciacao(int a, int b){
    int aux;

    if(b != 1){
        if(b % 2 == 0){
            aux = potenciacao(a, b/2);
           return printf("%d",aux * aux);
        }
        else{
            aux = potenciacao(a, (b-1)/2);
            return printf("%d",aux * aux * a);
        }
    }
    else
        return a;
}

int main(void) {
    int a;
    int b;

    scanf("%d %d", &a, &b);
    if( a && b != 0){
        aux = potenciacao(a,b);
    }
   
       
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int potenciacao(int a, int b){
    int aux;

    if(b != 1){
        if(b % 2 == 0){
            aux = potenciacao(a, b/2);
           return printf("%d",aux * aux);
        }
        else{
            aux = potenciacao(a, (b-1)/2);
            return printf("%d",aux * aux * a);
        }
    }
    else if(b == 1)
        return a;
    else
        return 0;
    
}

int main(void) {
    int a;
    int b;

    scanf("%d %d", &a, &b);
   
     potenciacao(a,b);
   
       
    return 0;
}

*/