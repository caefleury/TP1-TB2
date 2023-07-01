#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#include "./bibliotecas/dominios.h"
#include "./bibliotecas/entidades.h"

//------------------------------------- Servicos ------------------------------------------------

class InterfaceServicoDesenvolvedor {
    public:
        virtual ~InterfaceServicoDesenvolvedor(){};
        virtual bool deletar_desenvolvedor(Matricula) = 0;
        virtual bool criar_desenvolvedor(Desenvolvedor) = 0;
        virtual bool atualizar_desenvolvedor(Desenvolvedor) = 0;
        virtual Desenvolvedor retornar_desenvolvedor(Matricula) = 0;
};

class InterfaceServicoTeste {
    public:
        virtual ~InterfaceServicoTeste(){};
        virtual bool criar_teste(Teste) = 0;
        virtual bool deletar_teste(Codigo) = 0;
        virtual bool atualizar_teste(Teste) = 0;
        virtual Teste retornar_teste(Codigo) = 0;
};

class InterfaceServicoCasoTeste {
    public:
        virtual ~InterfaceServicoCasoTeste(){};
        virtual bool deletar_caso_teste(Codigo) = 0;
        virtual bool criar_caso_teste(CasoTeste) = 0;
        virtual bool atualizar_caso_teste(CasoTeste) = 0;
        virtual CasoTeste retornar_caso_teste(Codigo) = 0;
};

class InterfaceServicoAutenticacao {
    public:
        virtual ~InterfaceServicoAutenticacao(){}
        virtual bool autenticar(Matricula, Senha) = 0;
};

//------------------------------------- Apresentacao ---------------------------------------------

class InterfaceApresentacaoDesenvolvedor {
    public:
        virtual bool executar(Matricula) = 0;
        virtual void criar_desenvolvedor() = 0;
        virtual ~InterfaceApresentacaoDesenvolvedor(){}
        virtual void set_servico_desenvolvedor(InterfaceServicoDesenvolvedor*) = 0;
};

class InterfaceApresentacaoTeste {
    public:
        virtual void criar_teste() = 0;
        virtual bool executar(Matricula) = 0;
        virtual ~InterfaceApresentacaoTeste(){}
        virtual void set_servico_teste(InterfaceServicoTeste*) = 0;
};

class InterfaceApresentacaoCasoTeste {
    public:
        virtual bool executar(Codigo) = 0;
        virtual void criar_caso_teste() = 0;
        virtual ~InterfaceApresentacaoCasoTeste(){}
        virtual void set_servico_caso_teste(InterfaceServicoCasoTeste*) = 0;
};

class InterfaceApresentacaoAutenticacao {
    public:
        virtual bool autenticar(Matricula*) = 0;
        virtual ~InterfaceApresentacaoAutenticacao(){}
        virtual void set_servico_autenticacao(InterfaceServicoAutenticacao*) = 0;
};

#endif
