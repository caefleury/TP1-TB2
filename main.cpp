#include "./controladoras/apresentacao/teste.h"
#include "./controladoras/apresentacao/controle.h"
#include "./controladoras/apresentacao/caso_teste.h"
#include "./controladoras/apresentacao/autenticacao.h"
#include "./controladoras/apresentacao/desenvolvedor.h"

#include "./controladoras/servico/teste.h"
#include "./controladoras/servico/caso_teste.h"
#include "./controladoras/servico/autenticacao.h"
#include "./controladoras/servico/desenvolvedor.h"

#include "./acesso_db.h"

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
    nome.set_valor_dominio("Hello, 123!");

    Desenvolvedor teste;

    teste.set_nome(nome);
    teste.set_senha(senha);
    teste.set_telefone(telefone);
    teste.set_matricula(matricula);

    ComandoCadastrarDesenvolvedor cadastrar_desenvolvedor(teste);
    cadastrar_desenvolvedor.executar();

    // ApresentacaoTeste *apresentacao_teste;
    // ApresentacaoCasoTeste *apresentacao_caso_teste;
    ApresentacaoAutenticacao *apresentacao_autenticacao;
    ApresentacaoDesenvolvedor *apresentacao_desenvolvedor;

    // apresentacao_teste = new ApresentacaoTeste();
    // apresentacao_caso_teste = new ApresentacaoCasoTeste();
    apresentacao_autenticacao = new ApresentacaoAutenticacao();
    apresentacao_desenvolvedor = new ApresentacaoDesenvolvedor();

    // InterfaceServicoTeste *servico_teste;
    InterfaceServicoAutenticacao *servico_autenticacao;
    // InterfaceServicoCasoTeste *servico_caso_teste;
    InterfaceServicoDesenvolvedor *servico_desenvolvedor;

    // servico_teste = new  ServicoTeste();
    // servico_caso_teste = new ServicoCasoTeste();
    servico_autenticacao = new ServicoAutenticacao();
    servico_desenvolvedor = new ServicoDesenvolvedor();

    ApresentacaoControle *apresentacao_controle;
    apresentacao_controle = new ApresentacaoControle();

    apresentacao_autenticacao->set_servico_autenticacao(servico_autenticacao);
    apresentacao_controle->set_apresentacao_autenticacao(apresentacao_autenticacao);

    apresentacao_desenvolvedor->set_servico_desenvolvedor(servico_desenvolvedor);
    apresentacao_controle->set_apresentacao_desenvolvedor(apresentacao_desenvolvedor);

    apresentacao_controle->executar();

    return 0;
}
