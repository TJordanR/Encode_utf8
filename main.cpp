/**
*   Teste de compresao para texto
*   Autor Tiago Jordan
*   Github https://github.com/TJordanR
*   Versão 1.0.0
*   TENTAR A SOMA DOS CONJUTOS DE 8 BITS DE DOIS PARES PRA OBTER UM NUMERO INTEIRO DIVIDIDO POR DOIS
*   QUE POR SUA VEZ TERA O VALOR DA SEQUENCIA EXPECIFICA DE CARACTERES REPRESENTANDO OS DOIS PARERS DE
*   CARACTERES CORRESPONDENTE A PALAVRA OU FRASE
**/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

using namespace std;

/**
*   Class LerArqBim
*   Define um novo caminho para o arquivo ser lido
*   Ler arquivo
*   Obtem o tamanho do arquivo
*   Salva dados lidos e guarda em uma matriz
**/
class LerArqBim{
private:
    char *Url = "C:\\arquivo.txt";
    char Dados[999999];
    int tamDados = 0;
public:
    /// Define novo caminho do arquivo
    char DefineUrl(char *str){
        Url = str;
    }
    /// Ler o caminho do arquivo e retorna
    char *LerUrlArq(){
        return Url;
    }
    /// Ler os dados do arquivo e salva na variavel
    char LerArqTxt(char *str);
    /// Defini o tamanho da matriz de dados
    int DefineTamDados(int tam){
        tamDados = tam;
    }
    /// Ler o tamanho da matriz de dados
    int LerTamDados(){
        return tamDados;
    }
    /// Ler dados da variavel
    char *AcessaDadosArqMemoria(){
        return Dados;
    }
};

/**
*   Class EncodeDados
*   Ler dados da class e armazena em uma nova matriz para processamento
*   Retorna dados processados
*   Processa dados para uma nova saida em uma matriz
**/
class EncodeDados{
private:
    char *Dados;
    int tamDados = 0;
public:
    /// Recede dados e tamanho da Class LerArqBim
    void recebeData(char *str, int tam){
        Dados = str;
        tamDados = tam;
    }
    /// Retorna dados buff
    char *strDados(){
        return Dados;
    }
    /// Retorna tamanho do dados
    int retTamDados(){
        return tamDados;
    }
    /// METODO DE PROCESSAMENTO E CONVERSAO DE DADOS
    char EncodeBim(char *str);
};

/**
*   Class SalveEncode
*   Defino um novo caminho para salvar os dados processados
*   Retorna o novo caminho definido
*   Salva os dados processados no arquivo
**/
class SalvEncode{
public:
    char *Url_s = "C:\\arquivo.txt";
    char Dados_s[999999];

    /// Incrementa valor de entrada no contador
    int contador = -1;

    /// Define novo caminho do arquivo
    char DefineUrl_s(char *str_s){
        Url_s = str_s;
    }
    /// Ler o caminho do arquivo e retorna
    char *LerUrlArq_s(){
        return Url_s;
    }
    /// Salva os dados processados do arquivo no arquivo de texto
    char SalvArqTxt(char *str_s, char *url);

};

/**
*   Class Utf8bits
*   Metodo para definiçao de soma dos bits com base em 16 casas
*   Retorna a soma em bits na base 16
*   Zera bits para nova contagem
*   Seleciona o caracter correspondente e retorna seu valor
*   Processa os dados de entrada para conversão dos caracteres
*   Salva os dados de saida
**/
class Utf8bits{
private:
    char alfa16[200] = "!\"#$%&\()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~⌂ÇüéâäàåçêëèïîìÄÅÉæÆôöòûùÿÖÜø£Ø×ƒáíóúñÑªº¿®";
    int  utf_bit16[16]  = {16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    int SomaBits16      = 0;
    int alfa_utf8_num   = 0;
public:
    /// Soma bits da variavel de entra
    int BistSoma(int s){
        SomaBits16 = SomaBits16 + s;
    };
    /// Retorna o valor da soma
    int BitsRetorn(){
        return SomaBits16;
    };
    /// Zera o valor da soma
    void ZeraBist16(){
        SomaBits16 = 0;
    };
    /// Seleciona a variavel correspondente apartir do valor total da soma
    char SelectUtf8(int str_c);
    /// processa os valores de entrada
    char Processamento(char *str);
    /// METODO PARA GRAVAR AS SAIDAS NA NOVA MATRIZ
    SalvEncode *salve   = new SalvEncode;
    /// Salva os dados no arquivo
    void SaveDadosArq(){
        salve->DefineUrl_s("E:\\ENCODE_UTF8_IN_BIM\\saida.txt");
        cout << salve->LerUrlArq_s() << endl;
        salve->SalvArqTxt(salve->Dados_s, salve->Url_s);
    }
};

/**
*   Ler arquivos de entrada e armazena os dados em uma matriz de buff
**/
char LerArqBim::LerArqTxt(char *str){
    FILE *arq;
    arq = fopen(str, "r");
    if(!arq){
        printf("Erro nao foi possivel encontrar o caminho ou o arquivo nao existe!\n");
    }
    char c;
    int cont=0;
    do{
        c = fgetc(arq);
        Dados[cont] = c;
        cont++;
    }while( c!=EOF );
    fclose(arq);

    /// Metodo de gravação do tamanho da matriz de dados str
    DefineTamDados(cont);
    printf("Fim do processo de Leitura do arquivo!\n");
}

/**
*   Recebe o valore interiro correspondente a variavel e retorna
**/
char Utf8bits::SelectUtf8(int str_c){

    for(int a=0; a<=136; a++){
        if(a == str_c){
            alfa_utf8_num = alfa16[a];
        }
    }
    return alfa_utf8_num;
}

/**
*   Processa os dados
*   Entrada de duas variaveis para tratamento
*   Envia os bits para soma acumulativa dos dados
*   Envia dados processados e valor numerico para ser salva em uma arquivo de saida
*/
char Utf8bits::Processamento(char *str){

    for(int a=0; a<=1; a++){
        for(int b=0; b<=7; b++){
            if( (str[a] >> b) %2==0 ){
                printf("0");
            }else{
                printf("1");
                BistSoma(utf_bit16[b]);
            }
        }
        printf(" ");
    }

    printf("  Soma bits:%d = ", BitsRetorn());
    printf("%c\n", SelectUtf8(BitsRetorn()));
    /// Contagem dos bits
    salve->contador++;
    /// Envio os dados para salvar
    salve->Dados_s[salve->contador] = SelectUtf8(BitsRetorn());
    /// Zera a variavel de contagem
    ZeraBist16();
}

/**
*   Metodo de leitura da matriz para envio de dados com paredade par para processamente
**/
char EncodeDados::EncodeBim(char *str){

    /// Metodo de auxiliar de processamento dos dados
    Utf8bits *utf8 = new Utf8bits;

    char *str_Dados = strDados();
    int tam = retTamDados();
    for(int a=0; a<=tam-1; a++){
        /// PARIDADE DE "b" = 2 CONVOCA METODO DE PROCESSAMENTO DE DOIS CARACTERES
        if(a%2==1){
            printf("%c %c  ", str_Dados[a-1], str_Dados[a]);
            char ch2[2];
            ch2[0] = str_Dados[a-1];
            ch2[1] = str_Dados[a];
            utf8->Processamento(ch2);
        }
    }
    printf("\nFim do processamento dos dados do arquivo!\n");

    /// Ativa o metodo para salvar os dados no arquivo
    utf8->SaveDadosArq();
}

/**
*   Acessa dados da matriz ja tratada
*   Salva os dados tratados em um arquivo de texto de saida
**/
char SalvEncode::SalvArqTxt(char *str_s, char *url){
    FILE *arq;
    arq = fopen(url, "a");
    if(!arq){
        printf("Erro nao foi possivel encontrar o caminho ou o arquivo nao existe!\n");
    }
    for(int a=0; a<=contador; a++){
        fprintf(arq, "%c", Dados_s[a]);
        printf("%c", Dados_s[a]);
    }
    fclose(arq);
    printf("\nDados gravado com sucesso!\n");
}

int main()
{
    /// Metodo de definicao do caminho do arquivo
    LerArqBim *darq     = new LerArqBim;

    /// Metodo de leitura do arquivo definido para variavel buff
    LerArqBim *larq     = new LerArqBim;

    /// Metodo de processamento de tratamento de dados
    EncodeDados *endc   = new EncodeDados;

    /// Define um novo caminho para entrada dos dados
    darq->DefineUrl("E:\\ENCODE_UTF8_IN_BIM\\entrada.txt");
    cout << darq->LerUrlArq() << endl;

    /// Ler os dados do arquivo de entrada
    larq->LerArqTxt(darq->LerUrlArq());

    /// Associa os dados para variavel temporaria assim como o tamanho do arquivo
    endc->recebeData(larq->AcessaDadosArqMemoria(), larq->LerTamDados());

    /// Metodo de tratamento
    endc->EncodeBim("Comando");
}

