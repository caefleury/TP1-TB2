#include <iostream>
#include <string.h>
#include "../../acesso_db.h"
#include "../../interfaces.h"
#include "../../bibliotecas/dominios.h"
#include "../../bibliotecas/entidades.h"

class ServicoDesenvolvedor: public InterfaceServicoDesenvolvedor {
    public:
        bool alterar(Desenvolvedor);
        bool cadastrar(Desenvolvedor);
        Desenvolvedor recuperar(Matricula);
        bool descadastrar(Matricula);
};
