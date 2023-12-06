#include "../../interfaces.h"
#include "../../bibliotecas/dominios.h"
#include "../../bibliotecas/entidades.h"

class ServicoDesenvolvedor: public InterfaceServicoDesenvolvedor {
    public:
        bool deletar_desenvolvedor(Matricula) override;
        bool criar_desenvolvedor(Desenvolvedor) override;
        bool atualizar_desenvolvedor(Desenvolvedor) override;
        Desenvolvedor retornar_desenvolvedor(Matricula) override;
};