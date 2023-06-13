#ifndef CONTROLADORA_CONTROLE_H_INCLUDED
#define CONTROLADORA_CONTROLE_H_INCLUDED

#include "../../interfaces.h"
#include "../../bibliotecas/dominios.h"
#include "../../bibliotecas/entidades.h"

class ApresentacaoControle {
    private:
        Matricula matricula;
        InterfaceApresentacaoTeste *apresentacao_teste;
        InterfaceApresentacaoCasoTeste *apresentacao_caso_teste;
        InterfaceApresentacaoAutenticacao *apresentacao_autenticacao;
        InterfaceApresentacaoDesenvolvedor *apresentacao_desenvolvedor;
    public:
        void executar();
        void set_apresentacao_teste(InterfaceApresentacaoTeste*);
        void set_apresentacao_caso_teste(InterfaceApresentacaoCasoTeste*);
        void set_apresentacao_autenticacao(InterfaceApresentacaoAutenticacao*);
        void set_apresentacao_desenvolvedor(InterfaceApresentacaoDesenvolvedor*);
    };

#endif