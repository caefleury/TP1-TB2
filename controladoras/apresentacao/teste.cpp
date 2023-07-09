#include <iostream>
#include "./teste.h"
#include <limits>
#include <list>

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
            criar_teste(matricula);
            break;
        case 2:
            listar_testes(matricula);
            break;
        case 3:
            retornar_teste(matricula);
            break;
        case 4:
            atualizar_teste(matricula);
            break;
        case 5:
            deletar_teste(matricula);
            break;
        case 6:
            apresentar = false;
            break;
        }
    }
    return true;
}

void ApresentacaoTeste::listar_testes(Matricula matricula)
{

    cout << "-------------------------Lista de Testes-------------------------" << endl;
    /*
    for(teste = testes.begin(); teste!= testes.end(); ++teste) {
        retornar_teste(*teste);
    }
    */
    cout << "Digite algo para retornar" << endl;
    getchar();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void ApresentacaoTeste::deletar_teste(Matricula matricula)
{
    int campo;
    string campo1;
    Codigo codigo;
    Teste teste;
    char texto1[] = "Codigo em formato incorreto. Digite algo.";
    char texto2[] = "1 - Para tentar novamente.";
    char texto3[] = "2 - Para retornar.";
    bool apresentar = true;
    while (apresentar)
    {
        cout << "Digite o codigo do caso de teste :" << endl;
        getline(cin, campo1);
        try
        {
            char texto4[] = "Voce nao tem acesso a esse teste!";
            codigo.set_valor_dominio(campo1);
            teste = servicos_teste->retornar_teste(codigo);

            if (matricula.get_valor_dominio() != teste.get_matricula_criador().get_valor_dominio())
            {
                cout << texto4 << endl;
                cout << texto2 << endl;
                cout << texto3 << endl;
                campo = getchar() - 48;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (campo == 2)
                    return;
            }
            else
            {
                apresentar = false;
            };
        }
        catch (invalid_argument &exp)
        {
            cout << texto1 << endl;
            cout << texto2 << endl;
            cout << texto3 << endl;
            campo = getchar() - 48;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (campo == 2)
                return;
        }
    }

    codigo.set_valor_dominio(campo1);

    cout << "Tem certeza que deseja excluir esse caso de teste?" << endl;
    cout << "1 - Sim, quero excluir." << endl;
    cout << "2 - Nao quero excluir, retornar." << endl;
    campo = getchar() - 48;
    if (campo == 2)
    {
        cout << "Processo cancelado." << endl;
        getchar();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    if (servicos_teste->deletar_teste(codigo))
    {
        cout << "Caso de Teste removido com sucesso" << endl;
        cout << "Digite algo para retornar." << endl;
        getchar();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    cout << "Falha na exclusao. Tente novamente." << endl;
    cout << "Digite algo para retornar." << endl;
    getchar();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return;
}

void ApresentacaoTeste::criar_teste(Matricula matricula)
{
    char texto1[] = "Preencha os seguintes campos:";
    char texto2[] = "Nome            :";
    char texto3[] = "Classe          :";
    char texto4[] = "Codigo          :";
    char texto5[] = "Dados em formato incorreto. Digite algo.";
    char texto6[] = "Sucesso na criacao. Digite algo.";
    char texto7[] = "Falha na criacao. Digite algo.";

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
    teste.set_matricula_criador(matricula);

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

void ApresentacaoTeste::retornar_teste(Matricula matricula)
{
    int campo;
    string campo1;
    Codigo codigo;
    char texto1[] = "Dados em formato incorreto. Digite algo.";
    char texto2[] = "1 - Para tentar novamente.";
    char texto3[] = "2 - Para retornar.";

    bool apresentar = true;
    Teste teste;

    while (apresentar)
    {
        cout << "Digite o codigo do teste que deseja visualizar: " << endl;
        getline(cin, campo1);
        try
        {
            char texto4[] = "Voce nao tem acesso a esse teste!";
            codigo.set_valor_dominio(campo1);
            teste = servicos_teste->retornar_teste(codigo);

            if (matricula.get_valor_dominio() != teste.get_matricula_criador().get_valor_dominio())
            {
                cout << texto4 << endl;
                cout << texto2 << endl;
                cout << texto3 << endl;
                campo = getchar() - 48;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (campo == 2)
                    return;
            }
            else
            {
                apresentar = false;
            };
        }
        catch (invalid_argument &exp)
        {
            cout << texto1 << endl;
            cout << texto2 << endl;
            cout << texto3 << endl;
            campo = getchar() - 48;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (campo == 2)
                return;
        }
    }

    cout << "DADOS DO TESTE" << endl;
    cout << "Nome     : " << teste.get_nome().get_valor_dominio() << endl;
    cout << "Codigo   : " << teste.get_codigo().get_valor_dominio() << endl;
    cout << "Classe   : " << teste.get_classe().get_valor_dominio() << endl;

    cout << "Digite algo para retornar." << endl;
    getchar();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void ApresentacaoTeste::atualizar_teste(Matricula matricula)
{

    Texto nome;
    Teste teste;
    Classe classe;

    int campo_1, campo;
    string campo1;
    Codigo codigo;

    char texto1[] = "Codigo em formato incorreto. Digite algo.";
    char texto2[] = "1 - Para tentar novamente.";
    char texto3[] = "2 - Para retornar.";
    bool apresentar_codigo = true;
    while (apresentar_codigo)
    {
        cout << "Digite o codigo do teste :" << endl;
        getline(cin, campo1);
        try
        {
            char texto4[] = "Voce nao tem acesso a esse teste!";
            codigo.set_valor_dominio(campo1);
            teste = servicos_teste->retornar_teste(codigo);

            if (matricula.get_valor_dominio() != teste.get_matricula_criador().get_valor_dominio())
            {
                cout << texto4 << endl;
                cout << texto2 << endl;
                cout << texto3 << endl;
                campo = getchar() - 48;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (campo == 2)
                    return;
            }
            else
            {
                apresentar_codigo = false;
            };
        }
        catch (invalid_argument &exp)
        {
            cout << texto1 << endl;
            cout << "1 - Para tentar novamente." << endl;
            cout << "2 - Para retornar." << endl;
            campo_1 = getchar() - 48;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (campo_1 == 2)
                return;
        }
    }

    int campo_2;
    string campo2, campo3;
    bool apresentar_dados = true;

    while (apresentar_dados)
    {
        try
        {
            cout << "-----ATUALIZACAO DOS DADOS-----" << endl;
            cout << "---------DADOS ATUAIS---------" << endl;
            cout << "Nome    : " << teste.get_nome().get_valor_dominio() << endl;
            cout << "Classe  : " << teste.get_classe().get_valor_dominio() << endl;
            cout << "------------------------------" << endl;
            cout << "---------NOVOS DADOS----------" << endl;

            cout << "Novo nome: ";
            getline(cin, campo2);

            cout << "Nova classe: ";
            getline(cin, campo3);

            nome.set_valor_dominio(campo2);
            classe.set_valor_dominio(campo3);

            teste.set_nome(nome);
            teste.set_classe(classe);

            apresentar_dados = false;
        }
        catch (invalid_argument &exp)
        {
            cout << "Novos dados invalidos. Insira novamente." << endl;
            cout << "1 - Para tentar novamente." << endl;
            cout << "2 - Para retornar." << endl;
            campo_2 = getchar() - 48;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (campo_2 == 2)
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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
};
