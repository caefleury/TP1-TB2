#include <iostream>
#include "./acesso_db.h"
#include "./bibliotecas/dominios.h"
#include "./bibliotecas/entidades.h"

using namespace std;

int main()
{
    ComandoCriarTabelas start;
    start.executar();

    Texto nome;
    Senha senha;
    Telefone telefone;
    Matricula matricula;
    
    senha.set_valor_dominio("AmO2@&");
    matricula.set_valor_dominio("1234566");
    telefone.set_valor_dominio("+1234567");
    nome.set_valor_dominio("texto para fins test");

    Desenvolvedor teste;

    teste.set_nome(nome);
    teste.set_senha(senha);
    teste.set_telefone(telefone);
    teste.set_matricula(matricula);

    ComandoCadastrarDesenvolvedor cadastrar_desenvolvedor(teste);
    cout << cadastrar_desenvolvedor.executar() << endl;
}