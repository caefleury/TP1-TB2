#include <list>
#include <string>
#include "./bibliotecas/sqlite3.h"
#include "./bibliotecas/dominios.h"
#include "./bibliotecas/entidades.h"

using namespace std;

//--------------------------------- Configuracao ---------------------------------------

//Classe ElementoResultado

class ElementoResultado {
        private:
                string nome_coluna;
                string valor_coluna;
        public:
                void set_nome_coluna(const string&);
                string get_nome_coluna() const;
                void set_valor_coluna(const string&);
                string get_valor_coluna() const;
};

inline string ElementoResultado::get_nome_coluna() const {
        return nome_coluna;
}

inline string ElementoResultado::get_valor_coluna() const {
        return valor_coluna;
}

//Classe ComandoSQL

class ComandoSQL {
        private:
                int rc;
                sqlite3 *bd;
                char *mensagem;
                bool conectar();
                bool desconectar();
                const char *nome_banco_dados;
                static int callback(void *, int, char **, char **);
        protected:
                string comando_sql;
                static list<ElementoResultado> lista_resultado;
        public:
                bool executar();
                ComandoSQL() { nome_banco_dados = "banco_de_dados.db";};
};

//------------------------------------ Provisorio ---------------------------------------

class ComandoCriarTabelas:public ComandoSQL {
    public:
        ComandoCriarTabelas();
};

//------------------------------------ Retornar -----------------------------------------

//Classe ComandoPesquisarSenha

class ComandoPesquisarSenha:public ComandoSQL {
    public:
        string get_resultado();
        ComandoPesquisarSenha(Matricula);
};

//Classe ComandoPesquisarTeste

class ComandoPesquisarTeste:public ComandoSQL {
    public:
        Teste get_resultado();
        ComandoPesquisarTeste(Codigo);
};

//Classe ComandoPesquisarCasoTeste

class ComandoPesquisarCasoTeste:public ComandoSQL {
    public:
        CasoTeste get_resultado();
        ComandoPesquisarCasoTeste(Codigo);
};

//Classe ComandoPesquisarDesenvolvedor

class ComandoPesquisarDesenvolvedor:public ComandoSQL {
    public:
        Desenvolvedor get_resultado();
        ComandoPesquisarDesenvolvedor(Matricula);
};

//------------------------------------- Criar -----------------------------------------

//Classe ComandoPesquisarDesenvolvedor

class ComandoCadastrarDesenvolvedor:public ComandoSQL {
        public:
                ComandoCadastrarDesenvolvedor(Desenvolvedor);
};

//Classe ComandoCadastrarTeste

class ComandoCadastrarTeste:public ComandoSQL {
        public:
                ComandoCadastrarTeste(Teste);
};

//Classe ComandoCadastrarCasoTeste

class ComandoCadastrarCasoTeste:public ComandoSQL {
        public:
                ComandoCadastrarCasoTeste(CasoTeste);
};

//------------------------------------- Atualizar -----------------------------------------

//Classe ComandoAtualizarDesenvolvedor

class ComandoAtualizarDesenvolvedor:public ComandoSQL {
        public:
                ComandoAtualizarDesenvolvedor(Desenvolvedor);
};

//Classe ComandoAtualizarTeste

class ComandoAtualizarTeste:public ComandoSQL {
        public:
                ComandoAtualizarTeste(Teste);
};

//Classe ComandoAtualizarCasoTeste

class ComandoAtualizarCasoTeste:public ComandoSQL {
        public:
                ComandoAtualizarCasoTeste(CasoTeste);
};

//------------------------------------- Deletar -----------------------------------------

//Classe ComandoDeletarDesenvolvedor

class ComandoDeletarDesenvolvedor: public ComandoSQL {
        public:
                ComandoDeletarDesenvolvedor(Matricula);
};

//Classe ComandoDeletarTeste

class ComandoDeletarTeste: public ComandoSQL {
        public:
                ComandoDeletarTeste(Codigo);
};

//Classe ComandoDeletarCasoTeste

class ComandoDeletarCasoTeste: public ComandoSQL {
        public:
                ComandoDeletarCasoTeste(Codigo);
};