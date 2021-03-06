#ifndef VIDEO_STRUCTURE
#define VIDEO_STRUCTURE

#define MAX_VIDEOS 20
#define MAX_GENRES 10

#include <iostream>

using namespace std;

// definição da estrutura para armazenar o tempo de duração de um vídeo
struct DurationStructure{
    int hours;
    int minutes;
    int seconds;
};

// definição da estrutura para armazenar os gêneros ao qual um vídeo pertence
struct GenresStructure{
    string genres[MAX_GENRES];
    int numberOfGenre;
};

// definição da estrutura para armazenar todos os dados de um vídeo
struct VideoDocumentStructure{
    string identification;
    string kindOfVideo;
    string name;
    string directorName;
    DurationStructure durartion;
    int numberOfSeasons;
    int releaseYear;
    GenresStructure genres;
};

// definição da estrutura para armazenar todos os vídeos
struct VideoListDocumentStructure {
	VideoDocumentStructure videosList[MAX_VIDEOS];
	int numberOfVideos;
};

#endif
