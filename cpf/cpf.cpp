#include <iostream>
#include <iomanip> // maninpulação de saída de dados
#include <string> //biblioteca de strings
#include <cstdlib>
#include <stdfix.h>
#include <locale>
// 45867793060 -> cpf aleatorio usado para teste, gerado por um site
using namespace std;

void digitarCpf(); //usuário vai digitar um cpf
char primeiroDigito(); //vai checar o primeiro digito validador de um cpf
char segundoDigito(); //vai checar o segundo digito validador de um cpf
char validacao(char di9, char gi10); // vai verificar se os digitos validaores batem com o cpf e trazer uma mensagem se é válido ou nn

char cpf[12];
int res, soma, cont, num, r = 0;

int main()
{
    char d9, d10;
    while(r <= 1) {

        digitarCpf();
        d9  = primeiroDigito();
        d10 = segundoDigito();
        validacao(d9,  d10);

        cout << "-------------------------------------------------------\n\n" << endl;
        cout << "Pressione ENTER para continuar...." << endl;
        cin.ignore();
        getchar();
        system("clear");
    }
    return 0;
}

void digitarCpf(){

        INICIO:
        system("sleep 2");
        setlocale(LC_ALL, "Portuguese");
        system("clear");

        cout << "\n------------------ VALIDADOR DE CPF -------------------\n";
        cout << "Deseja validar algum CPF? \n";
        cout << "[0] NAO\n";
        cout << "[1] SIM\n";
        cout << "--> ";
        cin >> r;

        if (r == 0) {
            cout << "\n------------------ VALIDADOR DE CPF -------------------\n";
            cout << "\nObrigado por usar o nosso sistema!\n";
            getchar();
            exit(0);
        }
        else if (r == 1){
            cout << "\n------------------ VALIDADOR DE CPF -------------------\n";
            cout << "Digite seu cpf sem tracos, espacos e sem pontos!\n";
            cout << "--> ";
            cin.ignore();
            fgets(cpf, 12, stdin); // salvar os 11 digitos do cpf no vetor cpf[11] que contem 11 slots na memoria
        }                         //fgets(não para a leitura do teclado dps do usuario dar um espaço)
                                 //stdin = leitura do teclado
        else{
            cout << "\n\nOPÇÃO INVÁLIDA!\n";
            goto INICIO;
        }


}

char primeiroDigito(){
    char dig9;
        //encontrando o primeiro digito validador
        soma = 0;

        for (cont = 0; cont < 9; cont++) {
            num = cpf[cont] - 48;//transformar os 11 digitos do cpf que est�o em caracteres
                                 //de acordo com a tela ascii em inteiros
            soma += (num * (10 - cont));//realizar o calculo de multiplicar os primeiros 9 digitos
                                    //multiplicando de 10 até 2 e somando-os
                                    //ex: 5*10 + 8*9 + 2*8...até...1*2
        }
        res = 11 - (soma % 11); //achando o primeiro digito validador

        (res >= 10) ? dig9 = '0' : dig9 = res + 48;//transformando o primeiro digito validador em character

      return dig9;
}

char segundoDigito(){

  char dig10;
        //encontrando o segundo digito validador
        soma = 0;
        for (cont = 0; cont < 10; cont++) {
            num = cpf[cont] - 48;//transformar os 11 digitos do cpf que est�o em caracteres
                                 //de acordo com a tela ascii em inteiros
            soma += (num * (11 - cont));//realizar o calculo de multiplicar os primeiros 9 digitos
                                    //multiplicando de 11 ate 2 e somando-os
                                    //ex: 5*10 + 8*9 + 2*8...ate...1*2
        }
        res = 11 - (soma % 11);//achando o segundo digito validador
        (res >= 10) ? dig10 = '0' : dig10 = res + 48;//transformando o primeiro digito validador em character

        return dig10;
}

char validacao(char di9, char di10){
  //mensagem de validação
  ((di9 == cpf[9]) && (di10 == cpf[10])) ? cout << "\nCPF VáLIDO!\n" : cout << "\nCPF INVáLIDO\n";

}
