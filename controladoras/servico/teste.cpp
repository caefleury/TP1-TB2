#include "./teste.h"
#include "../../acesso_db.h"
#include <list>

bool ServicoTeste::criar_teste(Teste teste) {
    ComandoCadastrarTeste cadastrar_teste(teste);
    return cadastrar_teste.executar();
}

Teste ServicoTeste::retornar_teste(Codigo codigo) {
    ComandoPesquisarTeste pesquisar_teste(codigo);
    pesquisar_teste.executar();
    Teste teste;
    teste = pesquisar_teste.get_resultado();
    return teste;
}

bool ServicoTeste::atualizar_teste(Teste teste) {
    ComandoAtualizarTeste atualizar_teste(teste);
    return atualizar_teste.executar();
}

bool ServicoTeste::deletar_teste(Codigo codigo) {
    ComandoDeletarTeste deletar_teste(codigo);
    return deletar_teste.executar();
};

list<Teste> ServicoTeste::listar_testes(Matricula matricula) {
    ComandoPesquisarTestesDoDesenvolvedor pesquisar_testes_do_desenvolvedor(matricula);
    pesquisar_testes_do_desenvolvedor.executar();
    list<Teste> testes_para_listar;
    testes_para_listar = pesquisar_testes_do_desenvolvedor.get_resultado();
    return testes_para_listar;
};
