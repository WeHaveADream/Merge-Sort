#include<stdio.h>
#include <stdlib.h>

//função para ordenar o vetor, recebe o vetor e o tamanho dele
void merge(int *vetor, int tamanho) {

    //divide no meio o vetor (dividir)
    int meio = tamanho / 2;

    //indices
    int i = 0, j = meio, k = 0;

    //vetor auxiliar de mesmo tamanho
    int auxiliar[tamanho];

    //enquanto o i for menor que a metade e o meio for menor que o tamanho max
    while( i < meio && j < tamanho ){

        //se a posição atual for menor ou igual a posição do meio
        if( vetor[i] <= vetor[j] )

            //o auxiliar na posição k recebe o valor no vetor na porsição seguinte
            auxiliar[k] = vetor[i++];
        else
            //caso contrario o vetor na posição k recebe o valor seguinte do meio
            auxiliar[k] = vetor[j++];

        //roda o k
        k++;
    }
    //se o i for o meio
    if( i == meio )
        //enquanto o j for menor q o tamanho max
        while( j < tamanho )
            //o auxiliar na posição seguinte recebe o proximo do meio
            auxiliar[k++] = vetor[j++];
    else
        //enquanto o i for menor que o meio
        while( i < meio )
            //o axuliar na posição seguinte recebe o vetor na posição seguinte
            auxiliar[k++] = vetor[i++];

            for( i = 0; i < tamanho; i++ )
                vetor[i] = auxiliar[i];
}

//função para a recursão do merge sort
void mergeSort(int *vetor, int tamanho){

    //divide o vetor no meio
    int meio = tamanho / 2;

    //se o tamanho for maior que 1
    if( tamanho > 1 ){
        //chama a função enviando o vetor mais uma vez que a metade dele
        mergeSort(vetor, meio);

        //chama a função enviando o vetor e a metade dele e o tamanho menos o meio
        mergeSort(vetor+meio, tamanho-meio);

        //chama a função de merge
        merge(vetor, tamanho);
    }

}

int main ()
{
    int vetor[5];

    for (int i = 0; i < 5; i++){
        printf("Insira valores: ");
        fflush(stdin);
        scanf("%d", &vetor[i]);
    }

    printf("\nvetor antes:\n");

    for (int i = 0; i < 5; i++){
        printf("%d ",vetor[i]);
    }

    mergeSort(vetor, 5);

    printf("\n\nvetor dps:\n");

    for (int i = 0; i < 5; i++){
        printf("%d ",vetor[i]);
    }

    //getchar();


return 0;

}
