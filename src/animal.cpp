/**
  * @file 		animal.cpp
  * @brief 		Getter-setters e emissor de strings para armazenamento (Loja::salvarFuncionarios())classe mãe de: Anfibio, Mamifero, Ave e Reptil
  * @details 	Sobrecarga do operador de impressão e salvar, além dos elementos padrão. Construtor nas subclasses.
  * @author		Eric Andrade
  * @since		26/07/2018
  * @date		05/07/2018
  * @sa 		https://github.com/vloxflox/petFera
  */
#include <iostream>
#include <fstream>
#include <string> 
#include <memory>

#include "tratador.h"
#include "veterinario.h"
#include "animal.h"

Animal::Animal  (){};

Animal::~Animal(){}


//GETTERS/SETTERS
int Animal::getId(){return m_id;}
void Animal::setId(int id){m_id = id;}
std::string Animal::getClasse(){return m_classe;}
void Animal::setClasse(std::string classe){m_classe = classe;}
std::string Animal::getNome(){return m_nome;}
void Animal::setNome(std::string nome){m_nome = nome;}
std::string Animal::getCientifico(){return m_cientifico;}
void Animal::setCientifico(std::string cientifico){m_cientifico = cientifico;}
char Animal::getSexo(){return m_sexo;}
void Animal::setSexo(char sexo){m_sexo = sexo;}
float Animal::getTamanho(){return m_tamanho;}
void Animal::setTamanho(float tamanho){m_tamanho = tamanho;}
std::string Animal::getDieta(){return m_dieta;}
void Animal::setDieta(std::string dieta){m_dieta = dieta;}
std::string Animal::getBatismo(){return m_batismo;}
void Animal::setBatismo(std::string batismo){m_batismo = batismo;}
std::shared_ptr<Funcionario> Animal::getVeterinario(){return m_veterinario;}
void Animal::setVeterinario(std::shared_ptr<Funcionario> veterinario){m_veterinario = veterinario;}
std::shared_ptr<Funcionario> Animal::getTratador(){return m_tratador;}
void Animal::setTratador(std::shared_ptr<Funcionario> tratador){m_tratador = tratador;}


/**
 * Gera uma string que pode ser lida pelo carregador do petFera
 * @brief por meio de sucetivas concatenações e conversões ao formato de string, gera um texto válido para leitura na próxima inicialização 
 * @return uma string válida para leitura por (Loja::carregaFuncionarios()) na próxima inicialização
 */
std::string Animal::emiteSave(){
	std::string dataSave; //string a ser retornada, informações são adicionadas por meio de concatenação (sobrecarga do + na string)
	std::string separador = ";";//escolhe separador (leitura funciona somente com ; de acordo com o solicitado)


	dataSave = std::to_string(m_id)                   + separador
			 + m_classe                               + separador
			 + m_nome                                 + separador
			 + m_cientifico                           + separador
			 + m_sexo                                 + separador
			 + std::to_string(m_tamanho)              + separador
			 + m_dieta                                + separador
			 + std::to_string(m_veterinario->getId()) + separador//pega o ponteiro que armazena o funcionário e retorna o ID associado a ele para armazenar
			 + std::to_string(m_tratador->getId())    + separador//pega o ponteiro que armazena o funcionário e retorna o ID associado a ele para armazenar
			 + m_batismo;

	return dataSave;
}

/**
 * Mostra na tela informações do funcionário
 * @brief consulta-se o ponteiro para retornar o nome do funcionário
 */
std::ostream& operator<<(std::ostream& os, const Animal& animal){
	os<<"ID: "<< animal.m_id << std::endl
	  <<"Classe: "<< animal.m_classe << std::endl
	  <<"Espécie: "<< animal.m_nome << std::endl
	  <<"Nome cientifico: "<< animal.m_cientifico << std::endl
	  <<"Sexo: "<< animal.m_sexo << std::endl
	  <<"Tamanho: "<< animal.m_tamanho << std::endl
	  <<"Dieta: "<< animal.m_dieta << std::endl
	  <<"Veterinario: "<< animal.m_veterinario->getNome() << std::endl
	  <<"Tratador: "<< animal.m_tratador->getNome() << std::endl
	  <<"Nome de batismo: "<< animal.m_batismo << std::endl;

	return os;
}