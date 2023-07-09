#include <iostream>
#include "./autenticacao.h"
#include "../../acesso_db.h"

bool ServicoAutenticacao::autenticar(Matricula matricula, Senha senha)
{
    ComandoPesquisarSenha pesquisar_senha(matricula);
    if (!pesquisar_senha.executar())
        return 0;
    string senha_banco_de_dados;
    senha_banco_de_dados = pesquisar_senha.get_resultado();

    return (senha.get_valor_dominio() == senha_banco_de_dados);
}