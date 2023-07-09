#include "../../interfaces.h"
#include "../../bibliotecas/dominios.h"
#include "../../bibliotecas/entidades.h"
#include <iostream>
#include <list>

using namespace std;

class ServicoTeste : public InterfaceServicoTeste
{ // 212006737
public:
    bool criar_teste(Teste) override;
    bool deletar_teste(Codigo) override;
    bool atualizar_teste(Teste) override;
    list<Teste> listar_testes(Matricula);
    Teste retornar_teste(Codigo) override;
};
