#include "read_file_video.hpp"

void readVideoIdentification(ifstream &fn, string &identificator) {
	string aux;
	getline(fn, aux);
	//cout << "-- o identificador --\n";
	//cout << "Leitura da linha = [" << aux << "]\n";
	aux = removeStringDelimitator(aux);
	//cout << "Tirando o espaço = [" << aux << "]\n";
	aux = processInput(aux);
	//cout << "Processando o dado = [" << aux << "]\n";
	identificator = aux;
	//cout << "Então ficou = " << identificator << endl;
}

void readKindOfVideo(ifstream &fn,  string &kindOfVideo) {
	string aux;
	getline(fn, aux);
	aux = removeStringDelimitator(aux);
	kindOfVideo = processInput(aux);
	//cout << "li o kindOfVideo " << kindOfVideo << endl;
}

void readName(ifstream &fn,  string &name) {
	string aux;
	getline(fn, aux);
	aux = removeStringDelimitator(aux);
	name = processInput(aux);
	//cout << "li o nome " << name << endl;
}

void readDirectorName(ifstream &fn, string &directorName) {
	string aux;
	getline(fn, aux);
	aux = removeStringDelimitator(aux);
	directorName = processInput(aux);
	//cout << "li o diretor " << directorName << endl;
}

//void readHours(ifstream &fn,  unsigned int &hours) {
//}

//void readMinutes(ifstream &fn, unsigned int &minutes) {
//}

//void readSeconds(ifstream &fn, unsigned int &seconds) {
//}

void readDuration(ifstream &fn, DurationStructure &duration) {
	string aux;
	char delimitator;
	//getline(fn, aux);
	//aux = removeStringDelimitator(aux);
	//aux = processInput(aux);
	//aux = removeStringDelimitator(aux, ':');
	//duration.hours = 
	//duration.minutes = 
	//duration.seconds = 

	// le duration
	fn >> aux;
	// le =
	fn >> aux;
	fn >> duration.hours;
	fn >> delimitator;
	fn >> duration.minutes;
	fn >> delimitator;
	fn >> duration.seconds;
	while( delimitator != '\n') fn.get(delimitator);

	//cout << "li a hora " << duration.hours << endl;
	//cout << "li o minuto " << duration.minutes << endl;
	//cout << "li o segundo " << duration.seconds << endl;
}

void readNumberOfSeasons(ifstream &fn, int &numberOfSeasons) {
	string aux;
	char acha_fim_linha = 1;
	fn >> aux;
	fn >> aux;
	fn >> numberOfSeasons;

	while( acha_fim_linha != '\n') fn.get(acha_fim_linha);
	//cout << "li o numberOfSeasons " << numberOfSeasons << endl;

}

void readReleaseYear(ifstream &fn, int &releaseYear) {
	string aux;
	char acha_fim_linha = 1;

	fn >> aux;
	fn >> aux;
	fn >> releaseYear;
	while( acha_fim_linha != '\n') fn.get(acha_fim_linha);
	//cout << "li o ReleaseYear " << releaseYear << endl;
}

string processGenre(string s) {
	return s.substr( 0 , s.find(","));
}

bool readGenre(ifstream &fn, string &genre) {
	string aux;
	getline(fn, aux);
	if (aux == "}") {
		return false;
	}
	genre = aux;
	return true;
}

void readGenres(ifstream &fn, GenresStructure &genres) {
	string aux;
	int i;
	getline(fn, aux);
	if (aux != "genres = {") {
		//cout << "Não achei o inicio de genre bora mata isso\n";
		//cout << "So achei:" << aux << endl;
		return;
	}

	for (i = 0; readGenre(fn, aux); i++) {
		genres.genres[i] = processGenre(aux);
		//cout << "li o genero numero " << i << " = [" << genres.genres[i] << "]\n";
	}
	genres.numberOfGenre = i;
	//cout << "Acabei com os generos\n";
}

void readVideo(ifstream &fn, VideoDocumentStructure &video) {
}

bool findBeginOfStructureVideo(ifstream &fn) {
	string aux;

	//if (!getline(fn, aux)) {
//		return false;
//	}
//	while(aux != "{") {
//		if (!getline(fn, aux)) {
//			return false;
//		}
//	}
//	return true;


	while(!fn.eof()) {
		getline(fn, aux);
		if (aux == "{") {
			return true;
		}
	}
	return false;
}

void findEndOfStructureVideo(ifstream &fn) {
	string aux;
	getline(fn, aux);
	while(aux != "}") {
		getline(fn, aux);
	}
	//cout << "Achei o fim da structure\n";
	return;
}

VideoDocumentStructure readStructure(ifstream &fn) {

	VideoDocumentStructure aux;

	readVideoIdentification(fn, aux.identification);
	readKindOfVideo(fn, aux.kindOfVideo);
	readName(fn, aux.name);
	readDirectorName(fn, aux.directorName);
	readDuration(fn, aux.durartion);
	readNumberOfSeasons(fn, aux.numberOfSeasons);
	readReleaseYear(fn, aux.releaseYear);
	readGenres(fn, aux.genres);
	findEndOfStructureVideo(fn);

	return aux;
}

bool readFile(string file_name, VetorOfVideos &vetor) {
	ifstream inputFile;
	string aux;

	inputFile.open(file_name);

	if( !inputFile.is_open() ) {
		errorMessagesRead(7);
		return false;
	}

	for (int i = 0; findBeginOfStructureVideo(inputFile); i++) {
		//findBeginOfStructureVideo(inputFile);
		vetor.vet[i] = readStructure(inputFile);
	}
	return true;
}