#include "./caso_teste.h"
#include "../../acesso_db.h"

bool ServicoCasoTeste::criar_caso_teste(CasoTeste caso_teste) {
    ComandoCadastrarCasoTeste cadastrar_caso_teste(caso_teste);
    return cadastrar_caso_teste.executar();
}

CasoTeste ServicoCasoTeste::retornar_caso_teste(Codigo codigo) {
    ComandoPesquisarCasoTeste pesquisar_caso_teste(codigo);
    pesquisar_caso_teste.executar();
    CasoTeste caso_teste;
    caso_teste = pesquisar_caso_teste.get_resultado();
    return caso_teste;
}

bool ServicoCasoTeste::atualizar_caso_teste(CasoTeste caso_teste) {
    ComandoAtualizarCasoTeste atualizar_caso_teste(caso_teste);
    return atualizar_caso_teste.executar();
}

bool ServicoCasoTeste::deletar_caso_teste(Codigo codigo) {
    ComandoDeletarCasoTeste deletar_caso_teste(codigo);
    return deletar_caso_teste.executar();
}


