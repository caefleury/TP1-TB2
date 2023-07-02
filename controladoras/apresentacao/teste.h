#ifndef CONTROLADORA_TESTE_H_INCLUDED
#define CONTROLADORA_TESTE_H_INCLUDED

#include "../../interfaces.h"
#include "../../bibliotecas/dominios.h"
#include "../../bibliotecas/entidades.h"

class ApresentacaoTeste:public InterfaceApresentacaoTeste{
    private:
        void deletar_teste();
        void retornar_teste();
        void atualizar_teste();
        void listar_testes(Matricula);
        InterfaceServicoTeste *servicos_teste;
    public:
        void criar_teste(Matricula);
        bool executar(Matricula) override;
        void set_servico_teste(InterfaceServicoTeste*) override;
};

#endif
