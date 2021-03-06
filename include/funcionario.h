#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include <iostream>
#include <string>

class Funcionario
{
protected:
	int m_id;
	std::string m_tipo_funcionario;//usado somente para writes e saves
	std::string m_nome;
	std::string m_cpf;
	short int m_idade;
	std::string m_tipo_sanguineo;
	char m_fatorRH;
	std::string m_especialidade;
public:
	std::string emiteSave();
	Funcionario();
	~Funcionario();
	int getId();
	void setId(int);
	std::string getNome();
	void setNome(std::string);
	std::string getCpf();
	void setCpf(std::string);
	short int getIdade();
	void setIdade(short int);
	std::string getTipo_sanguineo();
	void setTipo_sanguineo(std::string);
	char getFatorRH();
	void setFatorRH(char);
	std::string getEspecialidade();
	void setEspecialidade(std::string);

	std::string getTipo_funcionario();
	void setTipo_funcionario(std::string);

	friend std::ostream& operator<<(std::ostream& os, const Funcionario& funcionario);
};



#endif