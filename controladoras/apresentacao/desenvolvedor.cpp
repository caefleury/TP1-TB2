#include <iostream>
#include "./desenvolvedor.h"
#include <limits>
void ApresentacaoDesenvolvedor::set_servico_desenvolvedor(InterfaceServicoDesenvolvedor *servicos_desenvolvedor)
{
    this->servicos_desenvolvedor = servicos_desenvolvedor;
}

bool ApresentacaoDesenvolvedor::executar(Matricula matricula)
{
    char texto1[] = "Selecione um dos servicos : ";
    char texto2[] = "1 - Consultar meus dados.";
    char texto3[] = "2 - Editar meus dados.";
    char texto4[] = "3 - Excluir minha conta.";
    char texto5[] = "4 - Retornar.";

    int campo;

    bool apresentar = true;

    while (apresentar)
    {

        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;
        cout << texto4 << endl;
        cout << texto5 << endl;

        campo = getchar() - 48;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (campo)
        {
        case 1:
            retornar_desenvolvedor(matricula);
            break;
        case 2:
            atualizar_desenvolvedor(matricula);
            break;
        case 3:
            if (deletar_desenvolvedor(matricula))
            {
                cout << "Desenvolvedor excluido com sucesso. Voce nao ira conseguir logar novamente." << endl;
                getchar();
                return false;
            }
            break;
        case 4:
            apresentar = false;
            break;
        }
    }
    return true;
}

bool ApresentacaoDesenvolvedor::deletar_desenvolvedor(Matricula matricula)
{
    int campo;
    cout << "Tem certeza que deseja excluir sua conta?" << endl;
    cout << "1 - Sim, quero excluir." << endl;
    cout << "2 - Nao tenho certeza." << endl;
    campo = getchar() - 48;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (campo == 2)
    {
        cout << "Processo cancelado." << endl;
        getchar();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    if (servicos_desenvolvedor->deletar_desenvolvedor(matricula))
        return true;

    cout << "Falha na exclusao. Tente novamente." << endl;
    getchar();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return false;
}

void ApresentacaoDesenvolvedor::criar_desenvolvedor()
{
    char texto1[] = "Preencha os seguintes campos:";
    char texto2[] = "Nome            :";
    char texto3[] = "Matricula       :";
    char texto4[] = "Senha           :";
    char texto5[] = "Telefone        :";
    char texto6[] = "Dados em formato incorreto. Digite algo.";
    char texto7[] = "Sucesso no cadastramento. Digite algo.";
    char texto8[] = "Falha no cadastramento. Digite algo.";

    int campo;
    string campo1, campo2, campo3, campo4;

    Texto nome;
    Senha senha;
    Telefone telefone;
    Matricula matricula;

    bool apresentar = true;

    while (apresentar)
    {
        cout << "-----CADASTRO DE DESENVOLVEDOR-----" << endl;
        cout << texto1 << endl;
        cout << texto2 << " ";
        getline(cin, campo1);
        cout << texto3 << " ";
        getline(cin, campo2);
        cout << texto4 << " ";
        getline(cin, campo3);
        cout << texto5 << " ";
        getline(cin, campo4);

        try
        {
            nome.set_valor_dominio(campo1);
            senha.set_valor_dominio(campo3);
            telefone.set_valor_dominio(campo4);
            matricula.set_valor_dominio(campo2);
            apresentar = false;
        }
        catch (invalid_argument &exp)
        {
            cout << texto6 << endl;
            cout << "1 - Para tentar novamente." << endl;
            cout << "2 - Para retornar." << endl;
            campo = getchar() - 48;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (campo == 2)
                return;
        }
    }

    Desenvolvedor desenvolvedor;

    desenvolvedor.set_nome(nome);
    desenvolvedor.set_senha(senha);
    desenvolvedor.set_telefone(telefone);
    desenvolvedor.set_matricula(matricula);

    if (servicos_desenvolvedor->criar_desenvolvedor(desenvolvedor))
    {
        cout << texto7 << endl;
        getchar();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    cout << texto8 << endl;
    getchar();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return;
}

void ApresentacaoDesenvolvedor::retornar_desenvolvedor(Matricula matricula)
{
    Desenvolvedor desenvolvedor;
    desenvolvedor = servicos_desenvolvedor->retornar_desenvolvedor(matricula);

    cout << "DADOS DO DESENVOLVEDOR" << endl;
    cout << "Matricula: " << desenvolvedor.get_matricula().get_valor_dominio() << endl;
    cout << "Nome     : " << desenvolvedor.get_nome().get_valor_dominio() << endl;
    cout << "Telefone : " << desenvolvedor.get_telefone().get_valor_dominio() << endl;
    cout << "Senha    : " << desenvolvedor.get_senha().get_valor_dominio() << endl;

    cout << "Digite algo para retornar." << endl;
    getchar();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return;
}

void ApresentacaoDesenvolvedor::atualizar_desenvolvedor(Matricula matricula)
{
    Texto nome;
    Senha senha;
    Telefone telefone;
    Desenvolvedor desenvolvedor;
    desenvolvedor = servicos_desenvolvedor->retornar_desenvolvedor(matricula);

    int campo;
    string campo1, campo2, campo3;
    bool apresentar = true;

    while (apresentar)
    {
        try
        {
            cout << "-----ATUALIZACAO DE DADOS-----" << endl;
            cout << "---------DADOS ATUAIS---------" << endl;
            cout << "Nome    : " << desenvolvedor.get_nome().get_valor_dominio() << endl;
            cout << "Telefone: " << desenvolvedor.get_telefone().get_valor_dominio() << endl;
            cout << "Senha   : " << desenvolvedor.get_senha().get_valor_dominio() << endl;
            cout << "------------------------------" << endl;

            cout << "---------NOVOS DADOS----------" << endl;
            cout << "Alterar nome: ";
            getline(cin, campo1);

            cout << "Alterar senha: ";
            getline(cin, campo2);

            cout << "Alterar telefone: ";
            getline(cin, campo3);

            nome.set_valor_dominio(campo1);
            senha.set_valor_dominio(campo2);
            telefone.set_valor_dominio(campo3);

            desenvolvedor.set_nome(nome);
            desenvolvedor.set_senha(senha);
            desenvolvedor.set_telefone(telefone);

            apresentar = false;
        }
        catch (invalid_argument &exp)
        {
            cout << "Novos dados invalidos. Insira novamente." << endl;
            cout << "1 - Para tentar novamente." << endl;
            cout << "2 - Para retornar." << endl;
            campo = getchar() - 48;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (campo == 2)
                return;
            getchar();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    if (servicos_desenvolvedor->atualizar_desenvolvedor(desenvolvedor))
        cout << "Dados atualizados com sucesso!" << endl;
    else
        cout << "Falha na atualizacao dos dados!" << endl;
    cout << "Digite algo para retornar." << endl;
    getchar();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
};