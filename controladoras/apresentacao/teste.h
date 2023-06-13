#ifndef CONTROLADORA_TESTE_H_INCLUDED
#define CONTROLADORA_TESTE_H_INCLUDED

#include "../../interfaces.h"
#include "../../bibliotecas/dominios.h"
#include "../../bibliotecas/entidades.h"

class ApresentacaoTeste:public InterfaceApresentacaoTeste{
    private:
        bool deletar_teste(Codigo);
        void retornar_teste(Codigo);
        void atualizar_teste(Codigo);
        InterfaceServicoTeste *servicos_teste;
    public:
        void criar_teste() override;
        bool executar(Codigo) override;
        void set_servico_teste(InterfaceServicoTeste*) override;
};

#endif