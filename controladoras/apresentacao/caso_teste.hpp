#ifndef CONTROLADORA_CASO_TESTE_H_INCLUDED
#define CONTROLADORA_CASO_TESTE_H_INCLUDED

#include "../../interfaces.h"
#include "../../bibliotecas/dominios.h"
#include "../../bibliotecas/entidades.h"

class ApresentacaoCasoTeste:public InterfaceApresentacaoCasoTeste{
    private:
        bool deletar_caso_teste(Codigo);
        void retornar_caso_teste(Codigo);
        void atualizar_caso_teste(Codigo);
        InterfaceServicoCasoTeste *servicos_caso_teste;
    public:
        bool executar(Codigo) override;
        void criar_caso_teste() override;
        void set_servico_caso_teste(InterfaceServicoCasoTeste*) override;
};

#endif