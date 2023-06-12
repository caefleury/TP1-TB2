#include "./bibliotecas/dominios.h"
#include "./bibliotecas/entidades.h"

class InterfaceServicoDesenvolvedor {
    public:
        virtual bool update(Desenvolvedor) = 0;
        virtual bool delete_desenvolvedor(Matricula) = 0;
        virtual bool create_desenvolvedor(Desenvolvedor) = 0;
        virtual Desenvolvedor show_desenvolvedor(Matricula) = 0;
        virtual ~InterfaceServicoDesenvolvedor(){};
};