//Micael P. Kutner - ADS tarde - 2º semestre
#include <stdio.h>
#include <string.h>
float max (float *notas, int p){
    int i;
    float maior_nota = notas[0];
    for (i=1; i<p; i++){
        if (notas[i] > maior_nota){
            maior_nota = notas[i];
        }
    }
    return maior_nota;
}
float min (float *notas, int p){
    int i;
    float menor_nota = notas[0];
    for (i=1; i<p; i++){
        if (notas[i] < menor_nota){
            menor_nota = notas[i];
        }
    }
    return menor_nota;
}
float sum_nota (float notas[], int p){
    float soma=0;
    int i;
    for (i=0; i<p; i++){
        soma += notas[i];
    }
    float max_value = max(notas, p);
    float min_value = min(notas, p);
    return soma - max_value - min_value;
}
void argsort (float nfinal[],int *rank,int a){
    int i,j,min_index,temp;
    for (i=0; i<a; i++){
        rank[i] = i;
    }
    for (i=0;i<a-1;i++){
        min_index = i;
        for(j=i+1;j<a;j++){
            if (nfinal[rank[j]] < nfinal[rank[min_index]]){
                min_index = j;
            }   
        }
        temp = rank[i];
        rank[i] = rank[min_index];
        rank[min_index] = temp;
    }
}
int main (){
    int i, j, n=0;
    while (n<1 || n>50){
        printf ("Digite o numero de candidatos: ");
        scanf ("%d", &n);
        getchar();
    }    
    char candidato[n][100];
    float PE[n][4], AC[n][5], PP[n][10], EB[n][3];
    float NF[n], sPE[n], sAC[n], sPP[n], sEB[n];
    int rank[n];  

    for (i=0; i<n; i++){
        printf ("digite o nome do candidato: ");
        fgets (candidato[i],100, stdin);
        candidato[i][strcspn(candidato[i], "\n")] = '\0';
        
        for (j=0; j<4; j++){
            printf ("digite a nota %d da PE: ", j+1);
            scanf ("%f", &PE[i][j]);
        }
        for (j=0; j<5; j++){
            printf ("digite a nota %d da AC: ", j+1);
            scanf ("%f", &AC[i][j]);
        }
        for (j=0; j<10; j++){
            printf ("digite a nota %d da PP: ", j+1);
            scanf ("%f", &PP[i][j]);
        }
        for (j=0; j<3; j++){
            printf ("digite a nota %d da EB: ", j+1);
            scanf ("%f", &EB[i][j]);
        }
        getchar();
    }    
    for (i=0; i<n; i++){
        sPE[i] = sum_nota(PE[i], 4);
        sAC[i] = sum_nota(AC[i], 5);
        sPP[i] = sum_nota(PP[i], 10);
        sEB[i] = sum_nota(EB[i], 3);
        NF[i] = ((sPE[i] * 0.3) + (sAC[i] * 0.1) + (sPP[i] * 0.4) + (sEB[i] * 0.2));
    }
    argsort(NF, rank, n);
    int top15=15;
    if (n<15) top15=n;
    for (i=0;i<top15;i++){
        j=rank[n-1-i];
        printf("Nome: %s Nota: %f Rank: %d\n", candidato[j], NF[j], i+1);        
    }
    return 0;
}
