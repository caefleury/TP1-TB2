#ifndef CONTROLADORA_AUTENTICACAO_H_INCLUDED
#define CONTROLADORA_AUTENTICACAO_H_INCLUDED

#include "../../interfaces.h"
#include "../../bibliotecas/dominios.h"
#include "../../bibliotecas/entidades.h"

#define limpar system("clear");
#define esperar cin.ignore();

class ApresentacaoAutenticacao:public InterfaceApresentacaoAutenticacao{
    private:
        InterfaceServicoAutenticacao *servico_autenticacao;
    public:
        bool autenticar(Matricula*);
        void set_servico_autenticacao(InterfaceServicoAutenticacao*);
};

#endif