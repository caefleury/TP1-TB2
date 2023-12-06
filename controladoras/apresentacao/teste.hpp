#ifndef CONTROLADORA_TESTE_H_INCLUDED
#define CONTROLADORA_TESTE_H_INCLUDED

#include "../../interfaces.h"
#include "../../bibliotecas/dominios.h"
#include "../../bibliotecas/entidades.h"

class ApresentacaoTeste:public InterfaceApresentacaoTeste{ // 211068440
    private:
        void deletar_teste(Matricula);
        void retornar_teste(Matricula);
        void atualizar_teste(Matricula);
        void listar_testes(Matricula);
        InterfaceServicoTeste *servicos_teste;
    public:
        void criar_teste(Matricula);
        bool executar(Matricula) override;
        void set_servico_teste(InterfaceServicoTeste*) override;
};

#endif
