#include <iostream>
#include <stdlib.h>
#include "./autenticacao.h"

void ApresentacaoAutenticacao::set_servico_autenticacao(InterfaceServicoAutenticacao *servico_autenticacao){
    this->servico_autenticacao = servico_autenticacao;
}

bool ApresentacaoAutenticacao::autenticar(Matricula *matricula) {
    char texto1[]="Digite a matricula:";
    char texto2[]="Digite a senha:";

    string campo1, campo2;

    Senha senha;

    while(true) {
        limpar;
        cout << texto1 << endl;
        esperar;
        getline(cin, campo1);
        cout << texto2 << endl;
        getline(cin, campo2);

        try {
            matricula->set_valor_dominio(campo1);
            senha.set_valor_dominio(campo2);
            break;
        } catch (invalid_argument &exp) {
            limpar;
            return false;
        }
    }

    return (servico_autenticacao->autenticar(*matricula, senha));
}