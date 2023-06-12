#include <regex>
#include <iostream>
#include "dominios.h"

using namespace std;

// ------------------------------------------------
// Implementação do metodo "set" da classe dominio.
void Dominio::set_valor_dominio(const string valor_dominio){
    validar_dominio(valor_dominio);
    this->valor_dominio = valor_dominio;
};

// -----------------------------------------------------------
// Implementação do metodo "validar_dominio" da classe classe.
void Classe::validar_dominio(const string classe){
    regex valores_possiveis("(UNIDADE|INTEGRACAO|FUMACA|SISTEMA|REGRESSAO|ACEITACAO)");
    if(!regex_match(classe, valores_possiveis)){
        throw invalid_argument("Classe invalido.");
    };
};

// -----------------------------------------------------------
// Implementação do metodo "validar_dominio" da classe codigo.
void Codigo::validar_dominio(const string codigo){
    regex formato_codigo("[a-zA-Z]{3}\\d{3}");
    if(!regex_match(codigo, formato_codigo)){
        throw invalid_argument("Codigo invalido.");
    };
};

// ---------------------------------------------------------
// Implementação do metodo "validar_dominio" da classe data.
void Data::validar_dominio(const string data){
    regex formato_data;
    int ano = stoi(data.substr(7,10));
    bool bissexto = ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0));
    string padrao_data = (bissexto ? 
    "(0[1-9]|[1-2][0-9]|3[0-1])/(JAN|FEV|MAR|ABR|MAI|JUN|JUL|AGO|SET|OUT|NOV|DEZ)/2[0-9]{3}" : 
    "(0[1-9]|[1-2][0-8]|3[0-1])/(JAN|FEV|MAR|ABR|MAI|JUN|JUL|AGO|SET|OUT|NOV|DEZ)/2[0-9]{3}");
    if(!regex_match(data, regex(padrao_data))){
        throw invalid_argument("Data invalida.");
    };
};


// ----------------------------------------------
// Implementação do metodo para calcular "modulo 10" da matricula.
bool Matricula::calculo_modulo_10(const string matricula) {
    int i(0),soma(0);
    for (i; i <= (matricula.length()-2); i++) {
        int digito = (matricula[i]-'0');
        if (i%2 != 0) {
            digito *= 2;
            if (digito > 9) {
                digito = (digito/10)+(digito%10);
            }
        }
        soma += digito;
    }
    return (10-(soma%10) == (matricula[i]-'0'));
}

// --------------------------------------------------------------
// Implementação do metodo "validar_dominio" da classe matricula.
void Matricula::validar_dominio(const string matricula){
    regex formato_matricula("[0-9]{7}");
    if(!(regex_match(matricula, formato_matricula) && calculo_modulo_10(matricula))){
        throw invalid_argument("Matricula invalida.");
    }
};

// --------------------------------------------------------------
// Implementação do metodo "validar_dominio" da classe resultado.
void Resultado::validar_dominio(const string resultado){
    regex valores_possiveis("(APROVADO|REPROVADO)");
    if(!regex_match(resultado, valores_possiveis)){
        throw invalid_argument("Resultado invalido.");
    };
};

// ----------------------------------------------------------
// Implementação do metodo "validar_dominio" da classe senha.
void Senha::validar_dominio(const string senha){
    regex formato_senha(R"((?!.*(.).*\1)[A-Za-z0-9@#$%&]{6})");
    if(!regex_match(senha, formato_senha)){
        throw invalid_argument("Senha invalida.");
    };
};

// -------------------------------------------------------------
// Implementação do metodo "validar_dominio" da classe telefone.
void Telefone::validar_dominio(const string telefone){
    regex formato_telefone("\\+\\d{7,15}");
    if(!regex_match(telefone, formato_telefone)){
        throw invalid_argument("Telefone invalido.");
    };
};

// ----------------------------------------------------------
// Implementação do metodo "validar_dominio" da classe texto.
void Texto::validar_dominio(const string texto){
    regex formato_texto("(?!.*\\s{2})(?:[a-zA-Z0-9.,;?!:-@$%& ]){10,20}");
    if(!regex_match(texto, formato_texto)){
        throw invalid_argument("Texto invalido.");
    };
};