#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, A;
    int colunas, linhas, brilho;
    char tipo[4], L2[50]; //tipo é a primeira linha que define se o tipo de arquivo é binário ou ascii
                          //L2 é a segunda linha que tem no arquivo

    FILE *fp;
    fp = fopen("ctskull-256.pgm", "r");
    if (fp == NULL){
        printf("Nao foi possível abrir o arquivo\n");
        return 0;
    }

    fgets(tipo, 4, fp);
    fgets(L2, 50, fp);
    fscanf(fp, "%d %d", &colunas, &linhas);
    fscanf(fp, "%d", &brilho);
    printf("%s", tipo);
    printf("%s", L2);
    printf("%d %d\n", colunas, linhas);
    printf("%d\n", brilho);

    int MatOriginal[linhas][colunas];
    int MatModificada[linhas][colunas];

    // Lendo a imagem do arquivo PGM
    for (i = 0; i < linhas; i++){
        for (j = 0; j < colunas; j++){
            fscanf(fp, "%d", &MatOriginal[i][j]); //aqui eu estou colocando os valores do arquivo na matriz "MatOriginal"
                                                  //que eu instanciei na linha 27
        }
    }
    fclose(fp);


//======================================================================================================================

    //deixando a imagem espelhada horizontalmente

    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            MatModificada[i][j] = MatOriginal[i][colunas-1-j];
        }
    }

    //escrevendo um arquivo com a matriz a -90º
    fp = fopen("Espelhada.pgm", "w");
    if(fp == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    // Writing Magic Number to the File
    fprintf(fp, "P2\n");

    //escrevendo oque tem na linha 2 do arquivo principal
    fprintf(fp, "# Created by IrfanView\n");

    // Writing Width and Height
    fprintf(fp, "%d %d\n", colunas, linhas);

    //escrevendo o brilho máximo
    fprintf(fp, "%d\n", brilho);

    //escrevendo os pixels
    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas; j++)
        {
            fprintf(fp, "%3d\n", MatModificada[i][j]);
        }
    }

    fclose(fp);

//======================================================================================================================

//deixando a imagem espelhada verticalmente

    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            MatModificada[i][j] = MatOriginal[linhas-1-i][j];
        }
    }

    //escrevendo um arquivo com a matriz a -90º
    fp = fopen("Espelhada2.pgm", "w");
    if(fp == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    // Writing Magic Number to the File
    fprintf(fp, "P2\n");

    //escrevendo oque tem na linha 2 do arquivo principal
    fprintf(fp, "# Created by IrfanView\n");

    // Writing Width and Height
    fprintf(fp, "%d %d\n", colunas, linhas);

    //escrevendo o brilho máximo
    fprintf(fp, "%d\n", brilho);

    //escrevendo os pixels
    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas; j++)
        {
            fprintf(fp, "%3d\n", MatModificada[i][j]);
        }
    }

    fclose(fp);


//======================================================================================================================

//binarizando a imagem

    for(i=0; i<linhas; i++){
        for(j=0; j<colunas; j++){
            if(MatOriginal[i][j] <= 112){
                MatModificada[i][j] = 0;
            }else{
                MatModificada[i][j] = 255;
            }
        }
    }

    //escrevendo um arquivo com a matriz binarizada
    fp = fopen("ImagemBinarizada.pgm", "w");
    if(fp == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    // Writing Magic Number to the File
    fprintf(fp, "P2\n");

    //escrevendo oque tem na linha 2 do arquivo principal
    fprintf(fp, "# Created by IrfanView\n");

    // Writing Width and Height
    fprintf(fp, "%d %d\n", colunas, linhas);

    //escrevendo o brilho máximo
    fprintf(fp, "%d\n", brilho);

    //escrevendo os pixels
    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas; j++)
        {
            fprintf(fp, "%3d\n", MatModificada[i][j]);
        }
    }

    fclose(fp);


//======================================================================================================================

//reduzindo os níveis de cinza da imagem


    for(i=0; i<linhas; i++){
        for(j=0; j<colunas; j++){
            MatModificada[i][j] = MatOriginal[i][j]-250;
        }
    }


    //escrevendo um arquivo com a matriz com menos tons de cinza
    fp = fopen("TonsDeCinzaReduzidos.pgm", "w");
    if(fp == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    // Writing Magic Number to the File
    fprintf(fp, "P2\n");

    //escrevendo oque tem na linha 2 do arquivo principal
    fprintf(fp, "# Created by IrfanView\n");

    // Writing Width and Height
    fprintf(fp, "%d %d\n", colunas, linhas);

    //escrevendo o brilho máximo
    fprintf(fp, "%d\n", brilho);

    //escrevendo os pixels
    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas; j++)
        {
            fprintf(fp, "%3d\n", MatModificada[i][j]);
        }
    }

    fclose(fp);


//======================================================================================================================


    return 0;
}
