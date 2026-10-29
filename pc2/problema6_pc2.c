#include<stdio.h>
#include<stdlib.h>

int buscar(const int *v, int n, int objetivo, int *posicion){
    if(v == NULL || n <= 0 || posicion == NULL){
        return 0;
    }
    for(int i = 0; i < n; i++){
        if(v[i] == objetivo){
            *posicion = i;
            return 1;
        }
    }
    return 0;
}

void reemplazar(int *v, int n, int antiguo, int nuevo){
    for(int i = 0; i < n; i++){
        if(v[i] == antiguo){
            v[i] = nuevo;
        }
    }
}

int main(){

    int n;
    do{
        printf("Ingrese un numero entero n(1 a 1500): ");
        scanf("%d", &n);
    } while(!(n>=1 && n<=1500));

    

    int *v = (int *) malloc(n * sizeof(int));
    int *posicion;
    if(v == NULL){
        printf("No hay suficiente memoria\n");
        return 1;
    }


    for(int i = 0; i < n; i++){
        printf("v[%d] = ", i);
        scanf("%d", &v[i]);
    }
    

    int objetivo;
    printf("Ingrese 'objetivo': ");
    scanf("%d", &objetivo);
    printf("Buscando el numero %d:\n", objetivo);
    if(buscar(v, n, objetivo, posicion)){
        printf("Se encontro el numero %d en la posicion %d\n", objetivo, *posicion);
    } else {
        printf("No se encuentra el numero %d\n", objetivo);
    }
    
    int antiguo, nuevo;
    printf("Ingrese 'antiguo': ");
    scanf("%d", &antiguo);
    printf("Ingrese 'nuevo': ");
    scanf("%d", &nuevo);

    printf("Reemplazando todos los %d por %d\n", antiguo, nuevo);
    reemplazar(v, n, antiguo, nuevo);
    for(int i = 0; i < n; i++){
        printf("%d\t", v[i]);
    }
    printf("\n");

    free(v);
    v = NULL;
    
    return 0;
}