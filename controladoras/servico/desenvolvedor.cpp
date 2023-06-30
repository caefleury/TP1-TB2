#include "./desenvolvedor.h"
#include "../../acesso_db.h"
#include <iostream>

bool ServicoDesenvolvedor::criar_desenvolvedor(Desenvolvedor desenvolvedor) {
    ComandoCadastrarDesenvolvedor cadastrar_desenvolvedor(desenvolvedor);
    return cadastrar_desenvolvedor.executar();
}

Desenvolvedor ServicoDesenvolvedor::retornar_desenvolvedor(Matricula matricula) {
    ComandoPesquisarDesenvolvedor pesquisar_desenvolvedor(matricula);
    pesquisar_desenvolvedor.executar();
    Desenvolvedor desenvolvedor;
    desenvolvedor = pesquisar_desenvolvedor.get_resultado();
    return desenvolvedor;
}

bool ServicoDesenvolvedor::atualizar_desenvolvedor(Desenvolvedor desenvolvedor) {
    ComandoAtualizarDesenvolvedor atualizar_desenvolvedor(desenvolvedor);
    return atualizar_desenvolvedor.executar();
}

bool ServicoDesenvolvedor::deletar_desenvolvedor(Matricula matricula) {
    ComandoDeletarDesenvolvedor deletar_desenvolvedor(matricula);
    return deletar_desenvolvedor.executar();
}


