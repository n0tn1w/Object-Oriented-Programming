#include <iostream>
#include <fstream>
#include <cstring>
#include "Time.h"

using std::cout;
using std::cin;
using std::endl;

// Error handling with a struct
// Setter wokring 
// Setter with global is good flag and the setter return an error struct
// Time struct

namespace Const
{
    const size_t SONG_NAME_MAX_LENGHT = 64;
    const size_t SONG_FILE_MAX_LENGHT = 64;
    const size_t PLAYLIST_LENGHT = 30;
} 

enum class ErrorCodes {
	OK,
	NotFound,
    FileCannotOpen,
    PlaylistIsFull,
    IncorrectNameLenght,
    FileContentIsInvalid,
    NoGenreFound
};

namespace Helper 
{
    int log2(int x) {
        int result = 0;
        while (x > 1) {
            x /= 2;
            result++;
        }
        return result;
    }

    size_t getFileSize(std::ifstream& ifs) {
        size_t curr = ifs.tellg();
        ifs.seekg(0, std::ios::end);
        size_t len = ifs.tellg();
        ifs.seekg(curr);

        return len;
    }
}

struct Song
{
private:
    char name[Const::SONG_NAME_MAX_LENGHT];
    Time time;
    uint64_t song[4];
    uint8_t genre = 0;
    uint8_t songLen = 0;

    ErrorCodes isValid = ErrorCodes::OK;
public:
    ErrorCodes getError() const {
        return this->isValid;
    }

    bool good() const {
        return this->isValid == ErrorCodes::OK;
    }

    Song() = default;

    Song(const char* name, unsigned hours, unsigned minutes, unsigned seconds, const char* genre, const char* songFile) {
        if(!good()) { return; }

        setName(name);
        setTime(hours, minutes, seconds);
        setGenre(genre);
        setSong(songFile);
    }

    const char* getName() const {
        if(!good()) { return nullptr;}

        return name;
    }

    const Time getTime() const {
        if(!good()) { return {}; }

        return time;
    }

    const uint64_t* getSong() const {
        if(!good()) { return nullptr;}

        return song;
    }

    uint8_t getGenre() const {
        if(!good()) { return 0; }

        return genre;
    }

    uint8_t getSongLen() const {
        if(!good()) { return 0; }

        return songLen;
    }

    void setName(const char* name) {
        if(!good()) { return; }

        if(strlen(name) > Const::SONG_NAME_MAX_LENGHT) {
            isValid = ErrorCodes::IncorrectNameLenght;
        }
        strcpy(this->name, name);
    }


    void setTime(unsigned hours, unsigned minutes, unsigned seconds) {
        if(!good()) { return; }

        this->time = Time(hours, minutes, seconds);
        // Time validation will be a good thing tbh
    }

    void setSong(const char* songFile) {
        if(!good()) { return; }

        std::ifstream ifs(songFile, std::ios::in | std::ios::binary);
        if(!ifs.is_open()) {
            isValid = ErrorCodes::FileCannotOpen;
        }
        size_t len = Helper::getFileSize(ifs);
        if(len == 0 || len > 256) {
            isValid = ErrorCodes::FileContentIsInvalid;
        }

        setSongLen(len);
        ifs.read((char*) song, getSongLen());

        ifs.close();
    }
    void setSongLen(size_t len) {
        if(!good()) { return; }
        this->songLen = len;
    }
    
    void setGenre(const char* genre) {
        if(!good()) { return; }

        uint8_t tempGenre = converGenreToUint(genre);
        if(tempGenre == 0) {
            isValid = ErrorCodes::NoGenreFound;
            return;
        }

        this->genre = tempGenre;
    }

    void setSong(uint64_t songBucket, size_t index) {
        if(!good()) { return; }
        
        if(index < 0 || index > 4) {
            return;
        }
        this->song[index] = songBucket;
    }

    void print() const {
        if(!good()) { return; }

        cout << name << " "; 
        time.print();
        cout << " " << (int)genre << " " << genre << " " << (int)songLen;
    }

    // This is not context specific function could be in a different place but
    // in my opinion the function should be held in the class 
    static uint8_t converGenreToUint(const char* genre) {
        // рок, поп, хип-хоп, електронна музика, джаз
        // r, p, h, e, d
        // 1, 2, 4, 8, 16

        size_t len = strlen(genre);
        uint8_t generatedGenre = 0;

        for(size_t i = 0; i < len; i++) {
            if(genre[i] == 'r') {
                generatedGenre += 1;
            }else if(genre[i] == 'p') {
                generatedGenre += 2;
            }else if(genre[i] == 'h') {
                generatedGenre += 4;
            }else if(genre[i] == 'e') {
                generatedGenre += 8;
            }else if(genre[i] == 'd') {
                generatedGenre += 16;
            }
        }

        return generatedGenre;
    }
};

// DTO means data transfering object
struct ResponseFindNameDTO { 
	ErrorCodes code;
	Song song;
    size_t index = -1;
};

struct ReposnseFindGenreDTO {
    ErrorCodes code;
	Song song[Const::PLAYLIST_LENGHT];
    size_t songsCount = 0;
};  

struct Playlist
{
    private:
    Song songs[Const::PLAYLIST_LENGHT];
    size_t songsCount = 0;

    public:
    size_t getSongsCount() const {
        return this->songsCount;
    }

    void setSongsCount(size_t songsCount) {
        this->songsCount = songsCount;
    }

    void increaseSongsCount() {
        setSongsCount(getSongsCount() + 1);
    }

    ErrorCodes add(const char* name, size_t hours, size_t min, size_t sec, const char* genre, const char* sonfFile) {
        if(getSongsCount() >= Const::PLAYLIST_LENGHT) {
            return ErrorCodes::PlaylistIsFull;
        }
        this->songs[getSongsCount()] = Song(name, hours, min, sec, genre, sonfFile);
        increaseSongsCount();

        return this->songs[getSongsCount()- 1].getError();
    }

    void print() const {
        for(size_t i = 0; i < getSongsCount(); i++) {
            this->songs[i].print();
            cout << endl;
        }
    }

    ResponseFindNameDTO find(const char* name) const {
        for(size_t i = 0; i < getSongsCount(); i++) {
            if(!strcmp(name, this->songs[i].getName())) {
                return ResponseFindNameDTO{ this->songs[i].getError(), this->songs[i], i };
            }
        }
        // Error no song found
        // We dont give index because it has -1 default value
        return {ErrorCodes::NotFound, {}};
    }

    ReposnseFindGenreDTO findGenre(char genre) const {
        ReposnseFindGenreDTO reposnseFindGenreDTO;
        char myStr[2] = {genre, '\0'};
        uint8_t generatedGenre = Song::converGenreToUint(myStr);
        int offset = Helper::log2(generatedGenre);

        for(size_t i = 0; i < getSongsCount(); i++) {
            if((this->songs[i].getGenre() & (1 << offset)) != 0) {
                reposnseFindGenreDTO.song[reposnseFindGenreDTO.songsCount++] = this->songs[i];
            }
        }

        if(reposnseFindGenreDTO.songsCount == 0) {
            reposnseFindGenreDTO.code = ErrorCodes::NotFound;
        } else {
            reposnseFindGenreDTO.code = ErrorCodes::OK;
        }

        return reposnseFindGenreDTO;
    }

    void sortByName() {
        for(size_t i = 0; i < getSongsCount(); i++) {
            size_t minIndex = i;
            Song currElt = songs[i];

            for(int k = i + 1; k < getSongsCount(); k++) {
                if(strcmp(currElt.getName(), songs[k].getName()) > 0) {
                    currElt = songs[k];
                    minIndex = k;
                }
            }

            if(minIndex != -1) {
                swap(i, minIndex);
            }
        }
    }

    void sortBySongLen() {
        for(size_t i = 0; i < getSongsCount(); i++) {
            size_t minIndex = i;
            Song currElt = songs[i];

            for(int k = i + 1; k < getSongsCount(); k++) {
                if(currElt.getSongLen() < songs[k].getSongLen()) {
                    currElt = songs[k];
                    minIndex = k;
                }
            }

            if(minIndex != -1) {
                swap(i, minIndex);
            }
        }
    }

    ErrorCodes save(const char* songName, const char* fileName) const {
        ResponseFindNameDTO response = find(songName);
        if(response.code != ErrorCodes::OK) {
            return response.code;
        }

        std::ofstream ofs(fileName, std::ios::out | std::ios::binary);
        if(!ofs.is_open()) {
            return ErrorCodes::FileCannotOpen;
        }

        ofs.write((const char*) response.song.getSong(), response.song.getSongLen() * 8 );

        ofs.close();
        return ErrorCodes::OK;
    }

    ErrorCodes mix(const char* songName1, const char* songName2) {
        ResponseFindNameDTO response1 = find(songName1);
        ResponseFindNameDTO response2 = find(songName2);
        if(response1.code != ErrorCodes::OK || response2.code != ErrorCodes::OK) {
            return ErrorCodes::NotFound;
        }

        int bucketNumber = response1.song.getSongLen() / 64; // Here the bucket will not be full and we will need to cut it 
        size_t k = 0;
        for(; k < bucketNumber; k++) {
            uint64_t res = bucketMix(response1.song.getSong()[k], response2.song.getSong()[k], 64);
            response1.song.setSong(res, k);
        }
        uint64_t res = bucketMix(response1.song.getSong()[k], response2.song.getSong()[k], (response1.song.getSongLen() * 8) % 64);
        response1.song.setSong(res, k);

        this->songs[response1.index] = response1.song;
        return ErrorCodes::OK;
    }

    ErrorCodes tuneChange(const char* songName1, size_t tune) {
        ResponseFindNameDTO response = find(songName1);
        if(response.code != ErrorCodes::OK) {
            return ErrorCodes::NotFound;
        }

        int bucketNumber = response.song.getSongLen() / 64; // Here the bucket will not be full and we will need to cut it 
        size_t k = 0;
        size_t offset = tune - 1;
        for(; k < bucketNumber; k++) {
            uint64_t res = bucketTune(response.song.getSong()[k], tune, offset, 64); 
            response.song.setSong(res, k);

        }
        uint64_t res = bucketTune(response.song.getSong()[k], tune, offset, (response.song.getSongLen() * 8) % 64); 
        response.song.setSong(res, k);

        this->songs[response.index] = response.song;

        return ErrorCodes::OK;
    }

    private: 
    void swap(size_t i1, size_t i2) {
        Song temp = songs[i1];
        songs[i1] = songs[i2];
        songs[i2] = temp;
    }

    uint64_t bucketMix(const uint64_t a, const uint64_t b, int bucketSize) const {
        uint64_t fin = 0;
        for (int i = 0 ; i < bucketSize; i++) { 
            int bit1 = (a >> i) & 1;
            int bit2 = (b >> i) & 1;
            int res  = bit1 ^ bit2;

            fin |= (res << (i));

            //cout << "Bit " << i << ": " << res << endl;
        }
        //a = fin;
        return fin;    
        //cout << "Fin: " << fin<< endl;
    }

    uint64_t bucketTune(const uint64_t a, size_t tuneMix, size_t& offset, size_t len) {
        uint64_t fin = a;
        int i = offset;
        for(; i < len - 1; i += tuneMix) {
            int bit = (a << i) & 1; 
            int resBit = bit || 1;
            //cout << "Bit " << i << " :" << resBit << endl;
            fin |= (resBit << i);
        }
        //a = fin;
        //cout << "Offset: " << i % tuneMix << endl;
        offset = i % tuneMix;
        return fin;
    }
};

int main() {
    std::ofstream ofs("song1.dat", std::ios::out | std::ios::binary);
    char s = 'S';
    ofs.write((const char*)&s, sizeof(s));
    ofs.close();
    std::ofstream ofs2("song2.dat", std::ios::out | std::ios::binary);
    char v = 'V';
    ofs2.write((const char*)&v, sizeof(v));
    ofs2.close();
    std::ofstream ofs3("song7.dat", std::ios::out | std::ios::binary);
    char ua[2] = { 'U', 'a' };
    ofs3.write((const char*)&ua, sizeof(ua));
    ofs3.close();

    std::ofstream ofs4("s1.dat", std::ios::out | std::ios::binary);
    int ninthSeven = 97;
    ofs4.write((const char*)&ninthSeven, sizeof(ninthSeven));
    ofs4.close();
    
    std::ofstream ofs5("s2.dat", std::ios::out | std::ios::binary);
    int eithyFive = 85;
    ofs5.write((const char*)&eithyFive, sizeof(eithyFive));
    ofs5.close();

    std::ofstream ofs6("tune.dat", std::ios::out | std::ios::binary);
    uint16_t bigNumber = 17990;
    ofs6.write((const char*)&bigNumber, sizeof(bigNumber));
    ofs6.close();


    Playlist p;
    p.add("Song 1", 0, 1, 5, "p", "song1.dat");
    p.add("Saong 2", 0, 1, 55, "rp", "song2.dat");
    p.add("Sfong 3", 0, 1, 55, "p", "song2.dat");
    p.add("Song 4", 0, 1, 55, "rph", "song2.dat");
    p.add("Sonvg 5", 1, 1, 5, "peh", "song1.dat");
    p.add("Song 21", 1, 1, 55, "rpd", "song2.dat");
    p.add("Sonag 7", 0, 1, 55, "e", "song7.dat");
    p.add("S 8", 12, 1, 55, "rphed", "song2.dat");

    p.add("mix1", 2, 1, 55, "rphed", "s1.dat");
    p.add("mix2", 123, 1, 55, "rphed", "s2.dat");

    p.add("tune", 12, 1, 55, "rphed", "tune.dat");


    p.print(); 
    // // Song 2, 00:01:55, Pop&Rock
    // // Song 1, 00:01:05, Pop

    // p.sortByName();
    // p.print(); 
    // // Song 1, 00:01:05, Pop
    // // Song 2, 00:01:55, Pop&Rock

    ResponseFindNameDTO sN =  p.find("Song 1"); 
    sN.song.print();
    // // Song 1, 00:01:05, Pop

    cout << endl << "==" << endl;
    ReposnseFindGenreDTO sG = p.findGenre('r');
    for(size_t i = 0; i < sG.songsCount; i++) {
        sG.song[i].print();
        cout << endl;
    }
    cout << endl << "@====@" << endl;

    p.sortByName();
    p.print();
    
    cout << endl << "%====%" << endl;

    p.sortBySongLen();
    p.print();
    // // Song 1, 00:01:05, Pop
    // // Song 2, 00:01:55, Pop&Rock
    // p.findGenre(‘r’);
    // // Song 2, 00:01:55, Pop&Rock

     ErrorCodes ers = p.mix("Saong 2", "Sonag 7");
     if(ers != ErrorCodes::OK)
        cout << "NE";
     p.save("Saong 2", "song3.dat");
    // // съдържание на song3.dat: “S” //0000 0011 

    ErrorCodes mixResponse = p.mix("mix1", "mix2");
     if(mixResponse != ErrorCodes::OK)
        cout << "NE mix";
     p.save("mix1", "sMix.dat");

    p.print();

    ErrorCodes tuneReposne = p.tuneChange("tune", 3);
    p.save("tune", "tune.dat");
}