#include <iostream>
#include "./teste.h"
#include <limits>

void ApresentacaoTeste::set_servico_teste(InterfaceServicoTeste *servicos_teste)
{
    this->servicos_teste = servicos_teste;
}

bool ApresentacaoTeste::executar(Matricula matricula)
{
    char texto1[] = "Selecione um dos servicos : ";
    char texto2[] = "1 - Criar teste";
    char texto3[] = "2 - Listar seus testes";
    char texto4[] = "3 - Consultar informacoes do teste pelo codigo.";
    char texto5[] = "4 - Editar teste.";
    char texto6[] = "5 - Excluir teste.";
    char texto7[] = "6 - Retornar.";

    int campo;

    bool apresentar = true;

    while (apresentar)
    {

        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;
        cout << texto4 << endl;
        cout << texto5 << endl;
        cout << texto6 << endl;
        cout << texto7 << endl;

        campo = getchar() - 48;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (campo)
        {
        case 1:
            criar_teste();
            break;
        /*
        case 2:
            retornar_teste(codigo);
            break;
        case 3:
            atualizar_teste(codigo);
            break;
        case 4:
            if(deletar_teste(codigo)){
                cout << "Teste excluido com sucesso. Voce nao vera o teste novamente." << endl;
                getchar();
                return false;
            }
            break;
        */
        case 5:
            apresentar = false;
            break;
        }
    }
    return true;
}

bool ApresentacaoTeste::deletar_teste(Codigo codigo)
{
    int campo;
    cout << "Tem certeza que deseja excluir esse teste?" << endl;
    cout << "1 - Sim, quero excluir." << endl;
    cout << "2 - Nao tenho certeza." << endl;
    campo = getchar() - 48;
    if (campo == 2)
    {
        cout << "Processo cancelado." << endl;
        getchar();
        return false;
    }
    if (servicos_teste->deletar_teste(codigo))
        return true;

    cout << "Falha na exclusao. Tente novamente." << endl;
    getchar();
    return false;
}

void ApresentacaoTeste::criar_teste()
{
    char texto1[] = "Preencha os seguintes campos:";
    char texto2[] = "Nome            :";
    char texto3[] = "Classe          :";
    char texto4[] = "Codigo          :";
    char texto5[] = "Dados em formato incorreto. Digite algo.";
    char texto6[] = "Sucesso na criação. Digite algo.";
    char texto7[] = "Falha na criação. Digite algo.";

    int campo;
    string campo1, campo2, campo3;

    Texto nome;
    Classe classe;
    Codigo codigo;

    bool apresentar = true;

    while (apresentar)
    {
        cout << "-----CRIACAO DE TESTE-----" << endl;
        cout << texto1 << endl;
        cout << texto2 << " ";
        getline(cin, campo1);
        cout << texto3 << " ";
        getline(cin, campo2);
        cout << texto4 << " ";
        getline(cin, campo3);

        try
        {
            nome.set_valor_dominio(campo1);
            classe.set_valor_dominio(campo2);
            codigo.set_valor_dominio(campo3);
            apresentar = false;
        }
        catch (invalid_argument &exp)
        {
            cout << texto5 << endl;
            cout << "1 - Para tentar novamente." << endl;
            cout << "2 - Para retornar." << endl;
            campo = getchar() - 48;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (campo == 2)
                return;
        }
    }

    Teste teste;

    teste.set_nome(nome);
    teste.set_codigo(codigo);
    teste.set_classe(classe);

    if (servicos_teste->criar_teste(teste))
    {
        cout << texto6 << endl;
        getchar();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    cout << texto7 << endl;
    getchar();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return;
}

void ApresentacaoTeste::retornar_teste(Codigo codigo)
{
    Teste teste;
    teste = servicos_teste->retornar_teste(codigo);

    cout << "DADOS DO TESTE" << endl;
    cout << "Nome     : " << teste.get_nome().get_valor_dominio() << endl;
    cout << "Codigo   : " << teste.get_codigo().get_valor_dominio() << endl;
    cout << "Classe   : " << teste.get_classe().get_valor_dominio() << endl;

    cout << "Digite algo para retornar." << endl;
    getchar();
}

void ApresentacaoTeste::atualizar_teste(Codigo codigo)
{
    Texto nome;
    Teste teste;
    Classe classe;
    teste = servicos_teste->retornar_teste(codigo);

    int campo;
    string campo1, campo2;
    bool apresentar = true;

    while (apresentar)
    {
        try
        {
            cout << "-----ATUALIZACAO DOS DADOS-----" << endl;
            cout << "---------DADOS ATUAIS---------" << endl;
            cout << "Nome    : " << teste.get_nome().get_valor_dominio() << endl;
            cout << "Classe  : " << teste.get_classe().get_valor_dominio() << endl;
            cout << "------------------------------" << endl;
            cout << "---------NOVOS DADOS----------" << endl;

            cout << "Alterar nome: ";
            getline(cin, campo1);

            cout << "Alterar classe: ";
            getline(cin, campo2);

            nome.set_valor_dominio(campo1);
            classe.set_valor_dominio(campo2);

            teste.set_nome(nome);
            teste.set_classe(classe);

            apresentar = false;
        }
        catch (invalid_argument &exp)
        {
            cout << "Novos dados invalidos. Insira novamente." << endl;
            cout << "1 - Para tentar novamente." << endl;
            cout << "2 - Para retornar." << endl;
            campo = getchar() - 48;
            if (campo == 2)
                return;
            getchar();
        }
    }

    if (servicos_teste->atualizar_teste(teste))
        cout << "Dados atualizados com sucesso!" << endl;
    else
        cout << "Falha na atualizacao dos dados!" << endl;
    cout << "Digite algo para retornar." << endl;
    getchar();
};
