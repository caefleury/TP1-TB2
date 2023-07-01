// Arquivo de implementação das classes de entidades.
#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include <string>
#include "dominios.h"

using namespace std;

// -------------------
// Entidade Desenvolvedor.

/**
* @brief Classe Entidade Desenvolvedor que tem atributos:
* - matricula,
* - nome
* - senha
* - telefone
* estes que sao objetos das classes Nome,Senha e Classe
*/

class Desenvolvedor // 212006737
{
private:
    Texto nome;
    Senha senha;
    Matricula matricula;
    Telefone telefone;

public:
    /**
     * @brief Metodo para atribuir a matricula
     * @param string com o valor da matricula a ser atribuido
     */
    void set_matricula(const Matricula &);
    /**
     * @brief Metodo para obter o valor da matricula
     * @return String com o valor da matricula
     */
    Matricula get_matricula() const;

    /**
     * @brief Metodo para atribuir o nome
     * @param string com o valor do nome a ser atribuido
     */
    void set_nome(const Texto &);
    /**
     * @brief Metodo para obter o valor do nome
     * @return String com o valor do nome
     */
    Texto get_nome() const;

    /**
     * @brief Metodo para atribuir a senha
     * @param string com o valor da senha a ser atribuido
     */
    void set_senha(const Senha &);
    /**
     * @brief Metodo para obter o valor da senha
     * @return String com o valor da senha
     */
    Senha get_senha() const;

    /**
     * @brief Metodo para atribuir o telefone
     * @param string com o valor do telefone a ser atribuido
     */
    void set_telefone(const Telefone &);
    /**
     * @brief Metodo para obter o valor do telefone
     * @return String com o valor do telefone
     */
    Telefone get_telefone() const;
};

// Métodos modificadores da entidade Desenvolvedor
inline void Desenvolvedor::set_matricula(const Matricula &matricula)
{
    this->matricula = matricula;
};
inline void Desenvolvedor::set_nome(const Texto &nome)
{
    this->nome = nome;
};
inline void Desenvolvedor::set_senha(const Senha &senha)
{
    this->senha = senha;
};
inline void Desenvolvedor::set_telefone(const Telefone &telefone)
{
    this->telefone = telefone;
};

// Métodos acessadores da entidade Desenvolvedor
inline Matricula Desenvolvedor::get_matricula() const
{
    return matricula;
};
inline Texto Desenvolvedor::get_nome() const
{
    return nome;
};
inline Senha Desenvolvedor::get_senha() const
{
    return senha;
};
inline Telefone Desenvolvedor::get_telefone() const
{
    return telefone;
};

// -------------------
// Entidade Teste.

/**
* @brief Classe Entidade Teste que tem atributos:
* - codigo
* - nome
* - classe
* - matricula_criador
* estes que sao objetos das classes Codigo, Nome e Classe
*/

class Teste // 211068440
{
private:
    Codigo codigo;
    Texto nome;
    Classe classe;
    Matricula matricula_criador;

public:
    /**
     * @brief Metodo para atribuir o codigo
     * @param string com o valor do codigo a ser atribuido
     */
    void set_codigo(const Codigo &);
    /**
     * @brief Metodo para obter o valor do codigo
     * @return String com o valor do codigo
     */
    Codigo get_codigo() const;

    /**
     * @brief Metodo para atribuir o nome
     * @param string com o valor do nome a ser atribuido
     */
    void set_nome(const Texto &);
    /**
     * @brief Metodo para obter o valor do nome
     * @return String com o valor do nome
     */
    Texto get_nome() const;

    /**
     * @brief Metodo para atribuir a classe
     * @param string com o valor da classe a ser atribuido
     */
    void set_classe(const Classe &);
    /**
     * @brief Metodo para obter o valor da classe
     * @return String com o valor da classe
     */
    Classe get_classe() const;

    /**
     * @brief Metodo para atribuir a matricula do criador do teste
     * @param string com o valor da matricula do criador do teste a ser atribuido
     */
    void set_matricula_criador(const Matricula &);
    /**
     * @brief Metodo para obter o valor da matricula do criador do teste
     * @return String com o valor da matricula do criador do teste
     */
    Matricula get_matricula_criador() const;
};

// Métodos modificadores da entidade Teste
inline void Teste::set_codigo(const Codigo &codigo)
{
    this->codigo = codigo;
};
inline void Teste::set_nome(const Texto &nome)
{
    this->nome = nome;
};
inline void Teste::set_classe(const Classe &classe)
{
    this->classe = classe;
};
inline void Teste::set_matricula_criador(const Matricula &matricula_criador)
{
    this->matricula_criador = matricula_criador;
};

// Métodos acessadores da entidade Teste
inline Codigo Teste::get_codigo() const
{
    return codigo;
};
inline Texto Teste::get_nome() const
{
    return nome;
};
inline Classe Teste::get_classe() const
{
    return classe;
};
inline Matricula Teste::get_matricula_criador() const
{
    return matricula_criador;
};

// -------------------
// Entidade Caso de Teste.

/**
* @brief Classe Entidade CasoTeste que tem atributos:
* - codigo
* - data
* - nome
* - acao
* - resposta 
* - resultado
* - codigo_teste_associado
* estes que sao objetos das classes Codigo, Data, Nome, Acao, Resposta e Resultado
*/
class CasoTeste // 212006577
{
private:
    Codigo codigo;
    Data data;
    Texto nome;
    Texto acao;
    Texto resposta;
    Resultado resultado;
    Codigo codigo_teste_associado;

public:
    /**
     * @brief Metodo para atribuir o codigo
     * @param string com o valor do codigo a ser atribuido
     */
    void set_codigo(const Codigo &);
    /**
     * @brief Metodo para obter o valor do codigo
     * @return String com o valor do codigo
     */
    Codigo get_codigo() const;

    /**
     * @brief Metodo para atribuir a data
     * @param string com o valor da data a ser atribuido
     */
    void set_data(const Data &);
    /**
     * @brief Metodo para obter o valor da data
     * @return String com o valor da data
     */
    Data get_data() const;

    /**
     * @brief Metodo para atribuir o nome
     * @param string com o valor do nome a ser atribuido
     */
    void set_nome(const Texto &);
    /**
     * @brief Metodo para obter o valor do nome
     * @return String com o valor do nome
     */
    Texto get_nome() const;

    /**
     * @brief Metodo para configurar a acao
     * @param string com o valor de acao a ser atribuido
     */
    void set_acao(const Texto &);
    /**
     * @brief Metodo para obter o valor da acao
     * @return String com o valor da acao
     */
    Texto get_acao() const;

    /**
     * @brief Metodo para configurar a resposta
     * @param string com o valor de resposta a ser atribuido
     */
    void set_resposta(const Texto &);
    /**
     * @brief Metodo para obter o valor da resposta
     * @return String com o valor da resposta
     */
    Texto get_resposta() const;

    /**
     * @brief Metodo para configurar resultado
     * @param string com o valor de resultado a ser atribuido
     */
    void set_resultado(const Resultado &);
    /**
     * @brief Metodo para obter o valor do resultado
     * @return String com o valor do resultado
     */
    Resultado get_resultado() const;

    /**
     * @brief Metodo para atribuir o codigo_teste_associado
     * @param string com o valor do codigo_teste_associado a ser atribuido
     */
    void set_codigo_teste_associado(const Codigo &);
    /**
     * @brief Metodo para obter o valor do codigo_teste_associado
     * @return String com o valor do codigo_teste_associado
     */
    Codigo get_codigo_teste_associado() const;
};

// Métodos acessadores da entidade Caso de Teste
inline void CasoTeste::set_codigo(const Codigo &codigo)
{
    this->codigo = codigo;
};
inline void CasoTeste::set_nome(const Texto &nome)
{
    this->nome = nome;
};
inline void CasoTeste::set_data(const Data &data)
{
    this->data = data;
};
inline void CasoTeste::set_acao(const Texto &acao)
{
    this->acao = acao;
};
inline void CasoTeste::set_resposta(const Texto &resposta)
{
    this->resposta = resposta;
};
inline void CasoTeste::set_resultado(const Resultado &resultado)
{
    this->resultado = resultado;
};
inline void CasoTeste::set_codigo_teste_associado(const Codigo &codigo_teste_associado)
{
    this->codigo_teste_associado = codigo_teste_associado;
};

// Métodos modificadores da entidade Caso de Teste
inline Codigo CasoTeste::get_codigo() const
{
    return codigo;
};
inline Texto CasoTeste::get_nome() const
{
    return nome;
};
inline Data CasoTeste::get_data() const
{
    return data;
};
inline Texto CasoTeste::get_acao() const
{
    return acao;
};
inline Texto CasoTeste::get_resposta() const
{
    return resposta;
};
inline Resultado CasoTeste::get_resultado() const
{
    return resultado;
};
inline Codigo CasoTeste::get_codigo_teste_associado() const
{
    return codigo_teste_associado;
};

#endif // ENTIDADES_H_INCLUDED