#include <iostream>
#include "./caso_teste.h"
#include <limits>

void ApresentacaoCasoTeste::set_servico_caso_teste(InterfaceServicoCasoTeste *servicos_caso_teste){
    this->servicos_caso_teste = servicos_caso_teste;
}

bool ApresentacaoCasoTeste::executar(Matricula matricula) {
    char texto1[] = "Selecione um dos servicos : ";
    char texto2[] = "1 - Criar caso de teste.";
    char texto3[] = "2 - Listar casos de teste.";
    char texto4[] = "3 - Consultar informaCOes de um caso teste.";
    char texto5[] = "4 - Editar caso teste.";
    char texto6[] = "5 - Excluir caso teste.";
    char texto7[] = "6 - Retornar.";

    int campo;

    bool apresentar = true;

    while(apresentar) {

        cout << texto1 << endl;
        cout << texto2 << endl;
        cout << texto3 << endl;
        cout << texto4 << endl;
        cout << texto5 << endl;
        cout << texto6 << endl;
        cout << texto7 << endl;

        campo = getchar() - 48;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

         switch(campo){
            case 1:
                criar_caso_teste();
                break;
            case 3:
                retornar_caso_teste();
                break;
            case 4:
                atualizar_caso_teste();
                break;
            case 5:
                deletar_caso_teste();
                break;
            case 6:
                apresentar = false;
                break;
        }
    }
    return true;
}

void ApresentacaoCasoTeste::deletar_caso_teste() {
    int campo;
    string campo1;
    Codigo codigo;
    char texto1[] = "Codigo em formato incorreto. Digite algo.";
    bool apresentar = true;
    while(apresentar){
        cout << "Digite o codigo do caso de teste :" <<  endl;
        getline(cin, campo1);
        try {
            codigo.set_valor_dominio(campo1);
            apresentar = false;
        } catch(invalid_argument &exp) {
            cout << texto1 << endl;
            cout << "1 - Para tentar novamente." << endl;
            cout << "2 - Para retornar." << endl;
            campo = getchar() - 48;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            if (campo == 2)
                return;
        }
    }

    codigo.set_valor_dominio(campo1);

    cout << "Tem certeza que deseja excluir esse caso de teste?" << endl;
    cout << "1 - Sim, quero excluir." << endl;
    cout << "2 - Nao quero excluir, retornar." << endl;
    campo = getchar() - 48;
    if (campo == 2){
        cout << "Processo cancelado." << endl;
        getchar();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        return;
    }
    if(servicos_caso_teste->deletar_caso_teste(codigo)){
        cout << "Caso de Teste removido com sucesso" << endl;
        cout << "Digite algo para retornar." << endl;
        getchar();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        return;
    }
    cout << "Falha na exclusao. Tente novamente." << endl;
    cout << "Digite algo para retornar." << endl;
    getchar();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    return;
}

void ApresentacaoCasoTeste::criar_caso_teste() {
    char texto1[] = "Preencha os seguintes campos:";
    char texto2[] = "Nome                       :";
    char texto3[] = "Data                       :";
    char texto4[] = "Codigo                     :";
    char texto5[] = "Acao                       :";
    char texto6[] = "Resposta                   :";
    char texto7[] = "Resultado                  :";
    char texto11[]= "Codigo do teste associado  :";
    char texto8[] = "Dados em formato incorreto. Digite algo.";
    char texto9[] = "Sucesso na criacao. Digite algo.";
    char texto10[] = "Falha na criacao. Digite algo.";

    int campo;
    string campo1, campo2, campo3, campo4, campo5, campo6, campo7;

    Data data;
    Texto nome;
    Texto acao;
    Codigo codigo;
    Texto resposta;
    Resultado resultado;
    Codigo codigo_associado;

    bool apresentar = true;

    while(apresentar){
        cout << "-----CRIACAO DE CASO TESTE-----" << endl;
        cout << texto1 << endl;
        cout << texto2 << " ";
        getline(cin, campo1);
        cout << texto3 << " ";
        getline(cin, campo2);
        cout << texto4 << " ";
        getline(cin, campo3);
        cout << texto5 << " ";
        getline(cin, campo4);
        cout << texto6 << " ";
        getline(cin, campo5);
        cout << texto7 << " ";
        getline(cin, campo6);
        cout << texto11 << " ";
        getline(cin, campo7);

        try {
            nome.set_valor_dominio(campo1);
            data.set_valor_dominio(campo2);
            codigo.set_valor_dominio(campo3);
            acao.set_valor_dominio(campo4);
            resposta.set_valor_dominio(campo5);
            resultado.set_valor_dominio(campo6);
            codigo_associado.set_valor_dominio(campo7);
            apresentar = false;
        } catch(invalid_argument &exp) {
            cout << texto8 << endl;
            cout << "1 - Para tentar novamente." << endl;
            cout << "2 - Para retornar." << endl;
            campo = getchar() - 48;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            if (campo == 2)
                return;
        }
    }

    CasoTeste caso_teste;

    caso_teste.set_data(data);
    caso_teste.set_acao(acao);
    caso_teste.set_nome(nome);
    caso_teste.set_codigo(codigo);
    caso_teste.set_resposta(resposta);
    caso_teste.set_resultado(resultado);
    caso_teste.set_codigo_teste_associado(codigo_associado);

    if(servicos_caso_teste->criar_caso_teste(caso_teste)) {
        cout << texto9 << endl;
        getchar();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    cout << texto10 << endl;
    getchar();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return;
}

void ApresentacaoCasoTeste::retornar_caso_teste() {
    int campo;
    string campo1;
    Codigo codigo;
    char texto1[] = "Codigo em formato incorreto. Digite algo.";

    bool apresentar = true;
    while(apresentar){
        cout << "Digite o codigo do caso de teste :" <<  endl;
        getline(cin, campo1);
        try {
            codigo.set_valor_dominio(campo1);
            apresentar = false;
        } catch(invalid_argument &exp) {
            cout << texto1 << endl;
            cout << "1 - Para tentar novamente." << endl;
            cout << "2 - Para retornar." << endl;
            campo = getchar() - 48;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            if (campo == 2)
                return;
        }
    }


    CasoTeste caso_teste;
    caso_teste = servicos_caso_teste->retornar_caso_teste(codigo);

    cout << "DADOS DO CASO TESTE" << endl;
    cout << "Codigo      : " << caso_teste.get_codigo().get_valor_dominio() << endl;
    cout << "Nome        : " << caso_teste.get_nome().get_valor_dominio() << endl;
    cout << "Data        : " << caso_teste.get_data().get_valor_dominio() << endl;
    cout << "Acao        : " << caso_teste.get_acao().get_valor_dominio() << endl;
    cout << "Resposta    : " << caso_teste.get_resposta().get_valor_dominio() << endl;
    cout << "Resultado   : " << caso_teste.get_resultado().get_valor_dominio() << endl;
    cout << "Codigo do teste associado   : " << caso_teste.get_codigo_teste_associado().get_valor_dominio() << endl;

    cout << "Digite algo para retornar." << endl;
    getchar();
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

void ApresentacaoCasoTeste::atualizar_caso_teste() {
    Data data;
    Texto nome;
    Texto acao;
    Texto resposta;
    Resultado resultado;
    CasoTeste caso_teste;

    int campo_1;
    string campo0;
    Codigo codigo;
    char texto1[] = "Codigo em formato incorreto. Digite algo.";
    bool apresentar_codigo = true;
    while(apresentar_codigo){
        cout << "Digite o codigo do teste :" <<  endl;
        getline(cin, campo0);
        try {
            codigo.set_valor_dominio(campo0);
            apresentar_codigo = false;
        } catch(invalid_argument &exp) {
            cout << texto1 << endl;
            cout << "1 - Para tentar novamente." << endl;
            cout << "2 - Para retornar." << endl;
            campo_1 = getchar() - 48;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            if (campo_1 == 2)
                return;
        }

    }


    caso_teste = servicos_caso_teste->retornar_caso_teste(codigo);

    int campo;
    string campo1, campo2, campo3, campo4, campo5;
    bool apresentar = true;

    while(apresentar){
        try {
            cout << "-----ATUALIZACAO DOS DADOS-----" << endl;
            cout << "---------DADOS ATUAIS---------" << endl;
            cout << "Nome        : " << caso_teste.get_nome().get_valor_dominio() << endl;
            cout << "Data        : " << caso_teste.get_data().get_valor_dominio() << endl;
            cout << "Acao        : " << caso_teste.get_acao().get_valor_dominio() << endl;
            cout << "Resposta    : " << caso_teste.get_resposta().get_valor_dominio() << endl;
            cout << "Resultado   : " << caso_teste.get_resultado().get_valor_dominio() << endl;
            cout << "------------------------------" << endl;
            cout << "---------NOVOS DADOS----------" << endl;

            cout << "Alterar nome: ";
            getline(cin, campo1);

            cout << "Alterar data: ";
            getline(cin, campo2);

            cout << "Alterar acao: ";
            getline(cin, campo3);

            cout << "Alterar resposta: ";
            getline(cin, campo4);

            cout << "Alterar resultado: ";
            getline(cin, campo5);

            nome.set_valor_dominio(campo1);
            data.set_valor_dominio(campo2);
            acao.set_valor_dominio(campo3);
            resposta.set_valor_dominio(campo4);
            resultado.set_valor_dominio(campo5);

            caso_teste.set_data(data);
            caso_teste.set_acao(acao);
            caso_teste.set_nome(nome);
            caso_teste.set_resposta(resposta);
            caso_teste.set_resultado(resultado);

            apresentar = false;
        } catch(invalid_argument &exp){
            cout << "Novos dados invalidos. Insira novamente." << endl;
            cout << "1 - Para tentar novamente." << endl;
            cout << "2 - Para retornar." << endl;
            campo = getchar() - 48;
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            if (campo == 2)
                return;
            getchar();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
    }

    if (servicos_caso_teste->atualizar_caso_teste(caso_teste))
        cout << "Dados atualizados com sucesso!" << endl;
    else
        cout << "Falha na atualizacao dos dados!" << endl;
    cout << "Digite algo para retornar." << endl;
    getchar();
};
