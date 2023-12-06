#include <string>
#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

using namespace std;

// ----------------
// Classe dominio.

/**
* @brief Classe abstrata Dominio que tem um atributo valor
*/
class Dominio // 212006737
{
protected:
    string valor_dominio;
    virtual void validar_dominio(string) = 0;

public:
    /**
     * @brief Metodo para configurar o valor do atributo
     * @param string com o valor a ser atribuído
     */
    void set_valor_dominio(string);
    /**
     * @brief Metodo para configurar o valor do atributo
     * @param String com o valor a ser atribuido
     */
    string get_valor_dominio() const;
};

inline string Dominio::get_valor_dominio() const
{
    return valor_dominio;
}

// --------------
// Classe Classe.

/**
* @brief Classe Classe representando uma string que pode possuir os seguintes valores:
*  - UNIDADE, INTEGRACAO, FUMACA, SISTEMA, REGRESSAO, ACEITACAO.
*/

class Classe : public Dominio // 212006737
{
private:
    void validar_dominio(string codigo) override;
};

// --------------
// Classe Código.

/**
* @brief Classe Codigo representando uma string que possui as seguintes regras de formatacao:
*  - Formato LLLDDD;
*  - D = dígito (0-9);
*  - L = letra (A-Z, a-z);
*/

class Codigo : public Dominio // 212006737
{
private:
    void validar_dominio(string codigo) override;
};

// ------------
// Classe Data.

/**
* @brief Classe Data representando uma string que possui as seguintes regras de formatacao:
* - DD - 1 a 31
* - ANO - 2000 a 2999;
* - Formato DD/MES/ANO;
* - MES - JAN, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV, DEZ;
* - Deve ser levado em consideracao se o ano é bissexto ou não é bissexto;
*/

class Data : public Dominio // 212006577
{
private:
    void validar_dominio(string) override;
};

// -----------------
// Classe Matricula.

/**
* @brief Classe Matricula representando uma string que possui as seguintes regras de formatacao:
* - Formato DDDDDDX;
* - D = dígito (0-9);
* - X = dígito verificador calculado com modulo 10;
*/

class Matricula : public Dominio // 212006577
{
private:
    bool calculo_modulo_10(string);
    void validar_dominio(string) override;
};

// -----------------
// Classe Resultado.

/**
* @brief Classe Resultado representando uma string que possui as seguintes regras de formatacao:
* - So pode possuir os seguintes valores: APROVADO e REPROVADO;
*/

class Resultado : public Dominio // 212006577
{
private:
    void validar_dominio(string) override;
};

// -------------
// Classe Senha.

/**
* @brief Classe Senha representando uma string que possui as seguintes regras de formatacao:
* - Formato XXXXXX;
* - Não pode haver caractere duplicado;
* - X e um dos seguintes caracteres: letra (A-Z, a-z), digito (0-9), @, #, $, % ou &;
*/

class Senha : public Dominio // 211068440
{
private:
    void validar_dominio(string) override;
};

// ----------------
// Classe Telefone.

/**
* @brief Classe Telefone representando uma string que possui as seguintes regras de formatacao:
* - X = digito (0 - 9);
* - Formato +XXXXXXX (7 digitos) a +XXXXXXXXXXXXXXX (15 digitos);
*/

class Telefone : public Dominio // 211068440
{
private:
    void validar_dominio(string) override;
};

// -------------
// Classe Texto.

/**
* @brief Classe Texto representando uma string que possui as seguintes regras de formatacao:
* - Nao ha acentuacao;
* - 10 a 20 caracteres;
* - Não ha espaços em branco em sequencia;
* - Cada caractere X = letra, digito (0-9), sinal de pontuacao (. , ; ? ! : -), @, #, $, % ou &;
*/
class Texto : public Dominio // 211068440
{
private:
    void validar_dominio(string) override;
};

#endif // DOMINIOS_H_INCLUDED