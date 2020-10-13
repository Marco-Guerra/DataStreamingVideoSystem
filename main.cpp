#include "structures/user_structure.hpp"
#include "structures/video_structure.hpp"

#include "interfaces/user_interface/print_file_user.hpp"
#include "interfaces/user_interface/read_file_user.hpp"

#include "interfaces/video_interface/print_file_video.hpp"
#include "interfaces/video_interface/read_file_video.hpp"
#include "interfaces/video_interface/print_stdio_video.hpp"
#include "interfaces/video_interface/read_stdio_video.hpp"

#include "controllers/menu_controller/menu_controller.hpp"
#include "interfaces/menu_interface/menu_messages.hpp"

int main (int argc, char *argv[]) {
 
	UserListDocumentStructure userList;
	VideoListDocumentStructure videoList;
	
	// ler os aruivos de armazenamento
	//readFileUserList(userList); // abre o arquivo que contem a lista de usuários e realiza a leitura
	//readFileVideoList(videoList); // abre o arquivo que contem a lista de vídeos e realiza a leitura

	userList.usersList[0].identification = "0000000000";
	userList.usersList[0].name = "Nome do Usuário";
	userList.usersList[0].date.day = 1;
	userList.usersList[0].date.month = 1;
	userList.usersList[0].date.year = 2000;
	userList.usersList[0].history.videoIdentifications[0] = "1111111111";
	userList.usersList[0].history.videoIdentifications[1] = "2222222222";
	userList.usersList[0].history.videoIdentifications[2] = "3333333333";
	userList.usersList[0].history.videoIdentifications[3] = "4444444444";
	userList.usersList[0].history.videoIdentifications[4] = "5555555555";
	userList.usersList[0].history.historyLenght = 5;
	
	videoList.videosList[0].identification = "1111111111";
	videoList.videosList[0].kindOfVideo = "Serie";
	videoList.videosList[0].name = "Uma serie";
	videoList.videosList[0].directorName = "Nome do diretor 0";
	videoList.videosList[0].durartion.hours = 1;
	videoList.videosList[0].durartion.minutes = 30;
	videoList.videosList[0].durartion.seconds = 30;
	videoList.videosList[0].numberOfSeasons = 10;
	videoList.videosList[0].releaseYear = 2010;
	videoList.videosList[0].genres.genres[0] = "Ação";
	videoList.videosList[0].genres.genres[1] = "Ficção";
	videoList.videosList[0].genres.numberOfGenre = 2;
	
	videoList.videosList[1].identification = "1111111111";
	videoList.videosList[1].kindOfVideo = "Serie";
	videoList.videosList[1].name = "Uma serie";
	videoList.videosList[1].directorName = "Nome do diretor 1";
	videoList.videosList[1].durartion.hours = 1;
	videoList.videosList[1].durartion.minutes = 30;
	videoList.videosList[1].durartion.seconds = 30;
	videoList.videosList[1].numberOfSeasons = 10;
	videoList.videosList[1].releaseYear = 2010;
	videoList.videosList[1].genres.genres[0] = "Ação";
	videoList.videosList[1].genres.genres[1] = "Ficção";
	videoList.videosList[1].genres.numberOfGenre = 2;
	
	videoList.videosList[2].identification = "2222222222";
	videoList.videosList[2].kindOfVideo = "Serie";
	videoList.videosList[2].name = "Uma serie";
	videoList.videosList[2].directorName = "Nome do diretor 2";
	videoList.videosList[2].durartion.hours = 1;
	videoList.videosList[2].durartion.minutes = 30;
	videoList.videosList[2].durartion.seconds = 30;
	videoList.videosList[2].numberOfSeasons = 10;
	videoList.videosList[2].releaseYear = 2010;
	videoList.videosList[2].genres.genres[0] = "Ação";
	videoList.videosList[2].genres.genres[1] = "Ficção";
	videoList.videosList[2].genres.numberOfGenre = 2;
	
	videoList.videosList[3].identification = "3333333333";
	videoList.videosList[3].kindOfVideo = "Serie";
	videoList.videosList[3].name = "Uma serie";
	videoList.videosList[3].directorName = "Nome do diretor 3";
	videoList.videosList[3].durartion.hours = 1;
	videoList.videosList[3].durartion.minutes = 30;
	videoList.videosList[3].durartion.seconds = 30;
	videoList.videosList[3].numberOfSeasons = 10;
	videoList.videosList[3].releaseYear = 2010;
	videoList.videosList[3].genres.genres[0] = "Ação";
	videoList.videosList[3].genres.genres[1] = "Ficção";
	videoList.videosList[3].genres.numberOfGenre = 2;
	
	videoList.videosList[4].identification = "4444444444";
	videoList.videosList[4].kindOfVideo = "Serie";
	videoList.videosList[4].name = "Uma serie";
	videoList.videosList[4].directorName = "Nome do diretor 4";
	videoList.videosList[4].durartion.hours = 1;
	videoList.videosList[4].durartion.minutes = 30;
	videoList.videosList[4].durartion.seconds = 30;
	videoList.videosList[4].numberOfSeasons = 10;
	videoList.videosList[4].releaseYear = 2010;
	videoList.videosList[4].genres.genres[0] = "Ação";
	videoList.videosList[4].genres.genres[1] = "Ficção";
	videoList.videosList[4].genres.numberOfGenre = 2;

	// mensagem inicial e explicação das funcionalidades do programa
	initMessage();

	// entrar no menu
	menuPrincipalController(userList, videoList);

	// escrever os arquivos de armazenamento
	//printFileUserList(userList); // abre o arquivo que contem a lista de usuários e realiza a escrita da nova lista
	//printFileVideoList(videoList); // abre o arquivo que contem a lista de vídeos e realiza a escrita da nova lista

	// mensagem final do programa
	endMessage();

	return 0;
}

/*
	- tem que ter readme
		- nome do software
		- nome dos integrantes da equipe
		- descrição e casos de uso
		- diagrama UML
		- descrição dirigida ao usuário, descrição de atalhos
		- documentar as funcionalidades, e funções, em texto

	- powerpoint (seminario)
		- demostrar ao vivo
		- casos de uso
		- 10 min de apresentação
		- dispor do codigo fonte para apresentar
		

	- struct vídeo
	- struct usuário

	- rotina -> inserir, alterar e consultar, apartir do id (inalteravel)
		- depois de uma rotina de cadastro valida imprimir a lista de id de objetos validos
		- rotina de inserir vídeo
		- rotina de inserir usuário
			- campos obcionais seram preen.hppidos posteriormente .hppistórico)
		- rotinas de validação
			- alertar o usuário caso o video nao posa ser cadastrado
			- guardar alerta em arquivo de log (id do vídeo mais regras desrespeitadas)

	- consultar 
		- imprimir tosdos os campos do usuario ou do video
		- caso nao exista informar isso

	- reuisitos da primeira funcionalidade
		- sem campos vazios
		- valores inteiros serao positivos
		-.hppora e minuto validos min [0-24] [0-59]
		- criar id de usuario de forma automatica
		- criar arquivo de logs

	interface simples -> selecionar funcionalidades e rutinas


	regras de negocio

	-> print file (file*, struct a pritar)
		retorna nada
	-> print stdio (struct a pritar)
		retorna nada
		
	-> read file (file*)
		retorna struct a pritar
	-> read stdio ()
		retorna struct a pritar

	nome = read_st(file*);
*/
