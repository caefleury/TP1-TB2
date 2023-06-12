#include "./desenvolvedor.h"

bool ServicoDesenvolvedor::cadastrar(Desenvolvedor desenvolvedor) {
    ComandoCadastrarDesenvolvedor cadastrar_desenvolvedor(desenvolvedor);
    return cadastrar_desenvolvedor.executar();
}

Desenvolvedor ServicoDesenvolvedor::recuperar(Matricula matricula) {
    ComandoPesquisarDesenvolvedor pesquisar_desenvovedor(matricula);
    pesquisar_desenvovedor.executar();
    Desenvolvedor desenvolvedor;
    desenvolvedor = pesquisar_desenvovedor.get_resultado();
    return desenvolvedor;
}

bool ServicoDesenvolvedor::alterar(Desenvolvedor desenvolvedor) {
    ComandoAtualizarDesenvolvedor atualizar_desenvolvedor(desenvolvedor);
    return atualizar_desenvolvedor.executar();
}

bool ServicoDesenvolvedor::descadastrar(Matricula matricula) {
    ComandoDeletarDesenvolvedor deletar_desenvolvedor(matricula);
    return deletar_desenvolvedor.executar();
}


