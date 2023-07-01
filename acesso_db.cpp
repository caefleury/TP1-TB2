#include "acesso_db.h"
#include <iostream>

//--------------------------------- CONFIGURAÇÃO --------------------------------------

//Atributo estático container List.

list<ElementoResultado> ComandoSQL::lista_resultado;

//Metodos da Classe ElementoResultado

void ElementoResultado::set_nome_coluna(const string& nome_coluna) {
        this->nome_coluna = nome_coluna;
};

void ElementoResultado::set_valor_coluna(const string& valor_coluna){
        this->valor_coluna = valor_coluna;
};

//Metodos da Classe ComandoSQL

bool ComandoSQL::conectar() {
    rc = sqlite3_open(nome_banco_dados, &bd);
    if( rc != SQLITE_OK )
        return 0;
    return 1;
};

bool ComandoSQL::desconectar() {
    rc =  sqlite3_close(bd);
    if( rc != SQLITE_OK )
        return 0;
    return 1;
};

bool ComandoSQL::executar() {
    if(!conectar())
        return 0;
    rc = sqlite3_exec(bd, comando_sql.c_str(), callback, 0, &mensagem);
    if(rc != SQLITE_OK){
        sqlite3_free(mensagem);
        desconectar();
    }
    desconectar();
    return 1;
};

int ComandoSQL::callback(void *not_used, int argc, char **valor_coluna, char **nome_coluna){
    int i;
    not_used=0;
    ElementoResultado elemento;

    for(i=0; i<argc; i++){
        elemento.set_nome_coluna(nome_coluna[i]);
        elemento.set_valor_coluna(valor_coluna[i] ? valor_coluna[i]: "NULL");
        lista_resultado.push_front(elemento);
    }
    return 0;
};

//------------------------------------ Criar tabelas --------------------------------------------

ComandoCriarTabelaDesenvolvedores::ComandoCriarTabelaDesenvolvedores(){
    comando_sql ="CREATE TABLE desenvolvedores("  \
                 "MATRICULA INT     PRIMARY KEY NOT NULL," \
                 "NOME      TEXT    NOT NULL," \
                 "SENHA     TEXT    NOT NULL," \
                 "TELEFONE  TEXT    NOT NULL);";
}

ComandoCriarTabelaTestes::ComandoCriarTabelaTestes(){
    comando_sql ="CREATE TABLE testes("\
                 "CODIGO           INT  PRIMARY KEY NOT NULL,"\
                 "NOME             TEXT NOT NULL,"\
                 "CLASSE           TEXT NOT NULL,"\
                 "MATRICULA_CRIADOR INT,"\
                 "FOREIGN KEY(MATRICULA_CRIADOR) REFERENCES desenvolvedores(MATRICULA));";
}

ComandoCriarTabelaCasosTeste::ComandoCriarTabelaCasosTeste(){
    comando_sql ="CREATE TABLE casos_teste("  \
                 "CODIGO    INT     PRIMARY KEY NOT NULL," \
                 "DATA      TEXT    NOT NULL," \
                 "NOME      TEXT    NOT NULL," \
                 "ACAO      TEXT    NOT NULL,"\
                 "RESPOSTA  TEXT    NOT NULL," \
                 "RESULTADO TEXT    NOT NULL,"
                 "CODIGO_TESTE_ASSOCIADO INT,"\
                 "FOREIGN KEY(CODIGO_TESTE_ASSOCIADO) REFERENCES testes(CODIGO));";
}

//------------------------------------ INDEX/SHOW ------------------------------------------------

//Metodos da Classe ComandoPesquisarSenha

ComandoPesquisarSenha::ComandoPesquisarSenha(Matricula matricula) {
    comando_sql = "SELECT senha FROM desenvolvedores WHERE matricula = '";
    comando_sql += matricula.get_valor_dominio();
    comando_sql += "'";
};

string ComandoPesquisarSenha::get_resultado() {
    string senha;
    ElementoResultado resultado;

    if (lista_resultado.empty())
        return "Erro";
    resultado = lista_resultado.back();
    lista_resultado.pop_back();
    senha = resultado.get_valor_coluna();
    return senha;
};

//Metodos da Classe ComandoPesquisarTeste

ComandoPesquisarTeste::ComandoPesquisarTeste(Codigo codigo) {
    comando_sql = "SELECT * FROM testes WHERE codigo = '";
    comando_sql += codigo.get_valor_dominio();
    comando_sql += "'";
};

Teste ComandoPesquisarTeste::get_resultado() {
    Texto nome;
    Teste teste;
    Codigo codigo;
    Classe classe;
    ElementoResultado resultado;

    // Remover nome;
    if (lista_resultado.empty())
        throw "not found";
    resultado = lista_resultado.back();
    lista_resultado.pop_back();
    nome.set_valor_dominio(resultado.get_valor_coluna());

    // Remover codigo;
    if (lista_resultado.empty())
        throw "not found";
    resultado = lista_resultado.back();
    lista_resultado.pop_back();
    codigo.set_valor_dominio(resultado.get_valor_coluna());

    // Remover classe;
    if (lista_resultado.empty())
        throw "not found";
    resultado = lista_resultado.back();
    lista_resultado.pop_back();
    classe.set_valor_dominio(resultado.get_valor_coluna());

    teste.set_nome(nome);
    teste.set_codigo(codigo);
    teste.set_classe(classe);

    return teste;
};

//Metodos da Classe ComandoPesquisarCasoTeste

ComandoPesquisarCasoTeste::ComandoPesquisarCasoTeste(Codigo codigo) {
    comando_sql = "SELECT * FROM casos_teste WHERE codigo = '";
    comando_sql += codigo.get_valor_dominio();
    comando_sql += "'";
};

CasoTeste ComandoPesquisarCasoTeste::get_resultado() {
    Data data;
    Texto nome;
    Texto acao;
    Codigo codigo;
    Texto resposta;
    CasoTeste caso_teste;
    ElementoResultado resultado;
    Resultado resultado_caso_teste;

    // Remover data;
    if (lista_resultado.empty())
        throw "not found";
    resultado = lista_resultado.back();
    lista_resultado.pop_back();
    nome.set_valor_dominio(resultado.get_valor_coluna());

    // Remover nome;
    if (lista_resultado.empty())
        throw "not found";
    resultado = lista_resultado.back();
    lista_resultado.pop_back();
    nome.set_valor_dominio(resultado.get_valor_coluna());

    // Remover acao;
    if (lista_resultado.empty())
        throw "not found";
    resultado = lista_resultado.back();
    lista_resultado.pop_back();
    acao.set_valor_dominio(resultado.get_valor_coluna());

    // Remover codigo;
    if (lista_resultado.empty())
        throw "not found";
    resultado = lista_resultado.back();
    lista_resultado.pop_back();
    codigo.set_valor_dominio(resultado.get_valor_coluna());

    // Remover resposta;
    if (lista_resultado.empty())
        throw "not found";
    resultado = lista_resultado.back();
    lista_resultado.pop_back();
    resposta.set_valor_dominio(resultado.get_valor_coluna());

    // Remover resultado;
    if (lista_resultado.empty())
        throw "not found";
    resultado = lista_resultado.back();
    lista_resultado.pop_back();
    resultado_caso_teste.set_valor_dominio(resultado.get_valor_coluna());

    caso_teste.set_data(data);
    caso_teste.set_nome(nome);
    caso_teste.set_acao(acao);
    caso_teste.set_codigo(codigo);
    caso_teste.set_resposta(resposta);
    caso_teste.set_resultado(resultado_caso_teste);

    return caso_teste;
};

//Metodos da Classe ComandoPesquisarDesenvolvedor

ComandoPesquisarDesenvolvedor::ComandoPesquisarDesenvolvedor(Matricula matricula) {
    comando_sql = "SELECT * FROM desenvolvedores WHERE matricula = '";
    comando_sql += matricula.get_valor_dominio();
    comando_sql += "'";
};

Desenvolvedor ComandoPesquisarDesenvolvedor::get_resultado() {
    Texto nome;
    Senha senha;
    Telefone telefone;
    Matricula matricula;
    Desenvolvedor desenvolvedor;
    ElementoResultado resultado;

    // Remover matricula;
    if (lista_resultado.empty())
        throw "not found";
    resultado = lista_resultado.back();
    lista_resultado.pop_back();
    matricula.set_valor_dominio(resultado.get_valor_coluna());


    // Remover nome;
    if (lista_resultado.empty())
        throw "not found";
    resultado = lista_resultado.back();
    lista_resultado.pop_back();
    nome.set_valor_dominio(resultado.get_valor_coluna());


    // Remover senha;
    if (lista_resultado.empty())
        throw "not found";
    resultado = lista_resultado.back();
    lista_resultado.pop_back();
    senha.set_valor_dominio(resultado.get_valor_coluna());


    // Remover telefone;
    if (lista_resultado.empty())
        throw "not found";
    resultado = lista_resultado.back();
    lista_resultado.pop_back();
    telefone.set_valor_dominio(resultado.get_valor_coluna());


    desenvolvedor.set_senha(senha);
    desenvolvedor.set_nome(nome);


    desenvolvedor.set_telefone(telefone);
    desenvolvedor.set_matricula(matricula);

    return desenvolvedor;
};

//Metodos da Classe ComandoPesquisarCasosTesteDoTeste

ComandoPesquisarCasosTesteDoTeste::ComandoPesquisarCasosTesteDoTeste(Codigo codigo) {
    comando_sql = "SELECT CT.CODIGO, CT.DATA, CT.NOME, CT.ACAO, CT.RESPOSTA, CT.RESULTADO FROM casos_teste"\
    "AS CT INNER JOIN testes AS T ON CT.CODIGO_TESTE_ASSOCIADO = T.CODIGO WHERE T.CODIGO = '";
    comando_sql += codigo.get_valor_dominio();
    comando_sql += "'";
}

list<CasoTeste> ComandoPesquisarCasosTesteDoTeste::get_resultado() {
    ElementoResultado resultado;
    list<CasoTeste> casos_teste_do_teste;
    CasoTeste caso_teste;
    Codigo codigo;
    Data data;
    Texto nome;
    Texto acao;
    Texto resposta;
    Resultado resultado_caso_teste;

    while(!lista_resultado.empty()){
        resultado = lista_resultado.back();
        lista_resultado.pop_back();

        codigo.set_valor_dominio(resultado.get_valor_coluna());

        resultado = lista_resultado.back();
        lista_resultado.pop_back();

        data.set_valor_dominio(resultado.get_valor_coluna());

        resultado = lista_resultado.back();
        lista_resultado.pop_back();

        nome.set_valor_dominio(resultado.get_valor_coluna());

        resultado = lista_resultado.back();
        lista_resultado.pop_back();

        acao.set_valor_dominio(resultado.get_valor_coluna());

        resultado = lista_resultado.back();
        lista_resultado.pop_back();

        resposta.set_valor_dominio(resultado.get_valor_coluna());

        resultado = lista_resultado.back();
        lista_resultado.pop_back();

        resultado_caso_teste.set_valor_dominio(resultado.get_valor_coluna());

        caso_teste.set_codigo(codigo);
        caso_teste.set_data(data);
        caso_teste.set_nome(nome);
        caso_teste.set_acao(acao);
        caso_teste.set_resposta(resposta);
        caso_teste.set_resultado(resultado_caso_teste);

        casos_teste_do_teste.push_back(caso_teste);
    }
    return casos_teste_do_teste;
}

//Metodos da Classe ComandoPesquisarTestesDoDesenvolvedor

ComandoPesquisarTestesDoDesenvolvedor::ComandoPesquisarTestesDoDesenvolvedor(Matricula matricula) {
    comando_sql = "SELECT  T.CODIGO, T.CLASSE, T.NOME FROM testes AS T INNER JOIN desenvolvedores AS D"\
    "ON T.MATRICULA_CRIADOR = D.MATRICULA WHERE D.MATRICULA = '";
    comando_sql += matricula.get_valor_dominio();
    comando_sql += "'";
}

list<Teste> ComandoPesquisarTestesDoDesenvolvedor::get_resultado() {
    ElementoResultado resultado;
    list<Teste> testes_do_desenvolvedor;
    Teste teste;
    Codigo codigo;
    Classe classe;
    Texto nome;
    

    while(!lista_resultado.empty()){
        resultado = lista_resultado.back();
        lista_resultado.pop_back();

        codigo.set_valor_dominio(resultado.get_valor_coluna());

        resultado = lista_resultado.back();
        lista_resultado.pop_back();

        classe.set_valor_dominio(resultado.get_valor_coluna());

        resultado = lista_resultado.back();
        lista_resultado.pop_back();

       	nome.set_valor_dominio(resultado.get_valor_coluna());

  
        teste.set_codigo(codigo);
        teste.set_classe(classe);
        teste.set_nome(nome);

        testes_do_desenvolvedor.push_back(teste);
    }
    return testes_do_desenvolvedor;
}

//------------------------------------- CREATE -----------------------------------------

//Metodos da Classe ComandoCadastrarDesenvolvedor

ComandoCadastrarDesenvolvedor::ComandoCadastrarDesenvolvedor(Desenvolvedor desenvolvedor) {
    comando_sql = "INSERT INTO desenvolvedores VALUES (";
    comando_sql += "'";
    comando_sql += desenvolvedor.get_matricula().get_valor_dominio();
    comando_sql += "', '";
    comando_sql += desenvolvedor.get_nome().get_valor_dominio();
    comando_sql += "', '";
    comando_sql += desenvolvedor.get_senha().get_valor_dominio();
    comando_sql += "', '";
    comando_sql += desenvolvedor.get_telefone().get_valor_dominio();
    comando_sql += "')";
};

//Metodos da Classe ComandoCadastrarTeste

ComandoCadastrarTeste::ComandoCadastrarTeste(Teste teste) {
    comando_sql = "INSERT INTO testes VALUES (";
    comando_sql += "'";
    comando_sql += teste.get_codigo().get_valor_dominio();
    comando_sql += "', '";
    comando_sql += teste.get_nome().get_valor_dominio();
    comando_sql += "', '";
    comando_sql += teste.get_classe().get_valor_dominio();
    comando_sql += "')";
};

//Metodos da Classe ComandoCadastrarCasoTeste

ComandoCadastrarCasoTeste::ComandoCadastrarCasoTeste(CasoTeste caso_teste) {
    comando_sql = "INSERT INTO casos_teste VALUES (";
    comando_sql += "'";
    comando_sql += caso_teste.get_codigo().get_valor_dominio();
    comando_sql += "', '";
    comando_sql += caso_teste.get_data().get_valor_dominio();
    comando_sql += "', '";
    comando_sql += caso_teste.get_nome().get_valor_dominio();
    comando_sql += "', '";
    comando_sql += caso_teste.get_acao().get_valor_dominio();
    comando_sql += "', '";
    comando_sql += caso_teste.get_resultado().get_valor_dominio();
    comando_sql += "', '";
    comando_sql += caso_teste.get_resposta().get_valor_dominio();
    comando_sql += "')";
};

//------------------------------------- UPDATE -----------------------------------------

//Metodos da Classe ComandoAtualizarDesenvolvedor

ComandoAtualizarDesenvolvedor::ComandoAtualizarDesenvolvedor(Desenvolvedor desenvolvedor) {
    comando_sql = "UPDATE desenvolvedores ";
    comando_sql += "' WHERE matricula = '" + desenvolvedor.get_matricula().get_valor_dominio(); + "'";
    comando_sql += "SET nome = '" + desenvolvedor.get_nome().get_valor_dominio();
    comando_sql += "', senha = '" + desenvolvedor.get_senha().get_valor_dominio();
    comando_sql += "', telefone = '" + desenvolvedor.get_telefone().get_valor_dominio();


};

//Metodos da Classe ComandoAtualizarTeste

ComandoAtualizarTeste::ComandoAtualizarTeste(Teste teste) {
    comando_sql = "UPDATE testes ";
    comando_sql += "SET nome = '" + teste.get_nome().get_valor_dominio();
    comando_sql += "', classe = '" + teste.get_classe().get_valor_dominio();
    comando_sql += "' WHERE codigo = '" + teste.get_codigo().get_valor_dominio(); + "'";
};

//Metodos da Classe ComandoAtualizarCasoTeste

ComandoAtualizarCasoTeste::ComandoAtualizarCasoTeste(CasoTeste caso_teste) {
    comando_sql = "UPDATE casos_teste";
    comando_sql += "SET data = '" + caso_teste.get_data().get_valor_dominio();
    comando_sql += "', nome = '" + caso_teste.get_nome().get_valor_dominio();
    comando_sql += "', acao = '" + caso_teste.get_acao().get_valor_dominio();
    comando_sql += "', resultado = '" + caso_teste.get_resultado().get_valor_dominio();
    comando_sql += "', resposta = '" + caso_teste.get_resposta().get_valor_dominio();
    comando_sql += "' WHERE codigo = '" + caso_teste.get_codigo().get_valor_dominio(); + "'";
};

//------------------------------------- DELETE -----------------------------------------

//Metodo da Classe ComandoDeletarDesenvolvedor

ComandoDeletarDesenvolvedor::ComandoDeletarDesenvolvedor(Matricula matricula) {
        comando_sql = "DELETE FROM desenvolvedores WHERE matricula = '";
        comando_sql += matricula.get_valor_dominio();
        comando_sql += "'";
};

//Metodo da Classe ComandoDeletarTeste

ComandoDeletarTeste::ComandoDeletarTeste(Codigo codigo) {
        comando_sql = "DELETE FROM testes WHERE codigo = '";
        comando_sql += codigo.get_valor_dominio();
        comando_sql += "'";
};

//Metodo da Classe ComandoDeletarCasoTeste

ComandoDeletarCasoTeste::ComandoDeletarCasoTeste(Codigo codigo) {
        comando_sql = "DELETE FROM casos_teste WHERE codigo = '";
        comando_sql += codigo.get_valor_dominio();
        comando_sql += "'";
};
