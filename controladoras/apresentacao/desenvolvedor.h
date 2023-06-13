#ifndef CONTROLADORA_DESENVOLVEDOR_H_INCLUDED
#define CONTROLADORA_DESENVOLVEDOR_H_INCLUDED

#include "../../interfaces.h"
#include "../../bibliotecas/dominios.h"
#include "../../bibliotecas/entidades.h"

class ApresentacaoDesenvolvedor:public InterfaceApresentacaoDesenvolvedor{
    private:
        bool deletar_desenvolvedor(Matricula);
        void retornar_desenvolvedor(Matricula);
        void atualizar_desenvolvedor(Matricula);
        InterfaceServicoDesenvolvedor *servicos_desenvolvedor;
    public:
        bool executar(Matricula) override;
        void criar_desenvolvedor() override;
        void set_servico_desenvolvedor(InterfaceServicoDesenvolvedor*) override;
};

#endif