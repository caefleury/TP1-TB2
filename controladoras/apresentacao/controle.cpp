#include <iostream>
#include "./controle.h"
#include <limits>

void ApresentacaoControle::set_apresentacao_autenticacao(InterfaceApresentacaoAutenticacao* apresentacao_autenticacao) {
    this->apresentacao_autenticacao = apresentacao_autenticacao;
};

void ApresentacaoControle::set_apresentacao_desenvolvedor(InterfaceApresentacaoDesenvolvedor* apresentacao_desenvolvedor) {
    this->apresentacao_desenvolvedor = apresentacao_desenvolvedor;
};

void ApresentacaoControle::set_apresentacao_teste(InterfaceApresentacaoTeste* apresentacao_teste) {
    this->apresentacao_teste = apresentacao_teste;
};

void ApresentacaoControle::set_apresentacao_caso_teste(InterfaceApresentacaoCasoTeste* apresentacao_caso_teste) {
    this->apresentacao_caso_teste = apresentacao_caso_teste;
};

void ApresentacaoControle::executar(){
    char texto1[] = "Selecione um dos servicos: ";
    char texto2[] = "1 - Acessar o sistema.";
    char texto3[] = "2 - Cadastrar-se no sistema.";
    char texto4[] = "3 - Encerrar execucao do sistema.";

    char texto5[] = "Selecione um dos servicos : ";
    char texto6[] = "1 - Servicos de desenvolvedor";
    char texto7[] = "2 - Servicos de teste";
    char texto8[] = "3 - Servicos de caso de teste";
    char texto9[] = "4 - Encerrar sessao.";

    char texto10[] = "Dados incorretos ou falha na autenticacao. Tente novamente.";

    int campo;
    bool apresentar = true;

    while(apresentar) {
        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;
        cout << texto4 << endl;

        campo = getchar() - 48;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        switch(campo){
            case 1:
                if(apresentacao_autenticacao->autenticar(&matricula)) {
                    cout << "Usuario autenticado." << endl;
                    while(apresentar){

                        cout << texto5 << endl;
                        cout << texto6 << endl;
                        cout << texto7 << endl;
                        cout << texto8 << endl;
                        cout << texto9 << endl;

                        campo = getchar() - 48;
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        switch(campo) {
                            case 1:
                                if(!apresentacao_desenvolvedor->executar(matricula)){
                                    apresentar = false;
                                    cout << "Desenvolvedor nao existe" << endl;
                                    getchar();
                                }
                                break;
                            case 2:
                                apresentacao_teste->executar(matricula);
                                break;
                            // case 3:
                            //     apresentacao_caso_teste->executar(matricula);
                            //     break;
                            // case 4:
                            //     apresentar = false;
                            //     break;
                        }
                    }
                } else {
                    cout << texto10 << endl;
                    break;
                }
                break;
            case 2:
                apresentacao_desenvolvedor->criar_desenvolvedor();
                break;
            case 3:
                apresentar = false;
                break;
        }
    };
};
