#include "../../interfaces.h"
#include "../../bibliotecas/dominios.h"
#include "../../bibliotecas/entidades.h"

class ServicoTeste: public InterfaceServicoTeste {
    public:
        bool criar_teste(Teste) override;
        bool deletar_teste(Codigo) override;
        bool atualizar_teste(Teste) override;
        Teste retornar_teste(Codigo) override;
};
        