#include "../../interfaces.h"
#include "../../bibliotecas/dominios.h"
#include "../../bibliotecas/entidades.h"

class ServicoAutenticacao: public InterfaceServicoAutenticacao {
    public:
        bool autenticar(Matricula, Senha);
};
