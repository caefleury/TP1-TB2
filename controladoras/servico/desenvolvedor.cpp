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
    ComandoPesquisarTestesDoDesenvolvedor pesquisar_testes_do_desenvolvedor(matricula);
    pesquisar_testes_do_desenvolvedor.executar();
    list<Teste> testes_para_deletar;
    testes_para_deletar = pesquisar_testes_do_desenvolvedor.get_resultado();

    int deletou_teste = 1;
    int deletou_caso_teste = 1;

    for (Teste teste : testes_para_deletar){
        if ( deletou_teste ){
            ComandoPesquisarCasosTesteDoTeste pesquisar_casos_teste_do_teste(teste.get_codigo());
            pesquisar_casos_teste_do_teste.executar();
            list<CasoTeste> casos_teste_para_deletar;
            casos_teste_para_deletar = pesquisar_casos_teste_do_teste.get_resultado();

            for (CasoTeste caso_teste: casos_teste_para_deletar){
                if ( deletou_caso_teste ){
                    ComandoDeletarCasoTeste deletar_caso_teste(caso_teste.get_codigo());
                    deletou_caso_teste = deletar_caso_teste.executar();
                } else {
                    return deletou_caso_teste;
                }
            }

            ComandoDeletarTeste deletar_teste(teste.get_codigo());
            deletou_teste = deletar_teste.executar();
        } else {
            return deletou_teste;
        }      
    }

    ComandoDeletarDesenvolvedor deletar_desenvolvedor(matricula);
    return deletar_desenvolvedor.executar();
}


