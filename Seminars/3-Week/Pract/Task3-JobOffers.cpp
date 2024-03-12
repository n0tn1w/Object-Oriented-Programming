#include <iostream>
#include <fstream>
#include <assert.h>
#include <cstring>

using std::cin;
using std::cout;

#define endl '\n';

namespace Const
{
    const size_t OFFER_NAME_SIZE = 25;
    const char* FILE_NAME = "offers.dat";
    const char* VALID_OFFERS_FILE_NAME = "valid.dat";
};

struct Offer{
    long long salary;
    uint16_t team;
    uint16_t vacation;
    char name[Const::OFFER_NAME_SIZE];
};

struct OfferHolder {
    size_t len;
    Offer* offers;
};

void EnterOffer(Offer& offer) {
    //name, team, vacation, salary
    cin >> offer.name >> offer.team >> offer.vacation >> offer.salary;
}

OfferHolder* EnterOffers(const char* filename, size_t n) {
    Offer* offers = new Offer[n];
    for(size_t i = 0; i < n; i++) {
        cout << "Enter next: " << endl;
        EnterOffer(offers[i]);
    }

    return new OfferHolder{n, offers};
}

void WriteOfferIntoFile(std::ofstream& ofs, const Offer& offer) {
    ofs.write((const char*)&offer, sizeof(Offer));
}

void WriteOffersIntoFile(const char* filename, const OfferHolder* oH) {
    std::ofstream ofs(filename, std::ios::out | std::ios::app| std::ios::binary);
    assert(ofs.is_open());

    for(size_t i = 0; i < oH->len; i++) {
        WriteOfferIntoFile(ofs, oH->offers[i]);
    }
    ofs.close();
}

size_t GetFileSize(std::ifstream& ifs) {
    size_t curr = ifs.tellg();
    ifs.seekg(0, std::ios::end);
    size_t len = ifs.tellg();
    ifs.seekg(curr);

    return len;
}

OfferHolder* ExtractDataFromFile(const char* filePath) {
    std::ifstream ifs(filePath, std::ios::in | std::ios::binary);
    assert(ifs.is_open());

    size_t fileSize = GetFileSize(ifs);
    size_t countOffers = fileSize / sizeof(Offer);
    Offer* offers = new Offer[countOffers];
    ifs.read((char*) offers, fileSize);

    ifs.close();
    return new OfferHolder{countOffers, offers};
}

size_t CountOfFilterOffers(const OfferHolder* oH, long long minSalary) {
    size_t len = 0;
    for(size_t i = 0; i < oH->len; i++) {
        if(oH->offers[i].salary >= minSalary) {
            len++;
        }
    }
    return len;
}

OfferHolder* filterOffers(const char* filePath, long long minSalary) {
    OfferHolder* oH = ExtractDataFromFile(filePath);
    size_t len = CountOfFilterOffers(oH, minSalary);
    OfferHolder* newOH = new OfferHolder();
    newOH->len = len;
    newOH->offers = new Offer[newOH->len];

    size_t index = 0;
    for(size_t i = 0; i < oH->len; i++) {
        if(oH->offers[i].salary >= minSalary) {
            newOH->offers[index++] = Offer(oH->offers[i]);
        }
    }

    delete[] oH->offers;
    delete oH;
    return newOH;
}

bool existOffer(const char* filePath, const char* name) {
    OfferHolder* oH = ExtractDataFromFile(filePath);

    bool exist = false;
    for(size_t i = 0; i < oH->len; i++) {
        if(strcmp(oH->offers[i].name, name)) {
            exist = true;
            break;
        }
    }

    delete[] oH->offers;
    delete oH;
    return exist;
}

size_t CountOfValidOffers(const OfferHolder* oH, int maxCoworkers, int minVacancyDays, long long minSalary) {
    size_t len = 0;
    for(size_t i = 0; i < oH->len; i++) {
        if(oH->offers[i].team < maxCoworkers && oH->offers[i].vacation >= minVacancyDays && oH->offers[i].salary >= minSalary) {
            len++;
        }
    }
    return len;
}

// Task is wrong so im adding a VALID_OFFERS_FILE_NAME where the offers will be put
void perfectOffer(const char* filePath, uint16_t maxCoworkers, uint16_t minVacancyDays, long long minSalary, const char* validOffersFilePath) {
    OfferHolder* oH = ExtractDataFromFile(filePath);
    size_t len = CountOfValidOffers(oH, maxCoworkers, minVacancyDays, minSalary);
    OfferHolder* validOH = new OfferHolder();
    validOH->len = len;
    validOH->offers = new Offer[validOH->len];

    size_t index = 0;
    for(size_t i = 0; i < oH->len; i++) {
        if(oH->offers[i].team < maxCoworkers && oH->offers[i].vacation >= minVacancyDays && oH->offers[i].salary >= minSalary) {
            validOH->offers[index++] = Offer(oH->offers[i]);
        }
    }

    delete[] oH->offers;
    delete oH;
    WriteOffersIntoFile(validOffersFilePath, validOH);
    delete[] validOH->offers;
    delete validOH;
}

void PrintSingleOffer(const Offer& offer) {
    cout << offer.name << ' ' << offer.team << ' ' << offer.vacation << ' ' << offer.salary << endl;
}

void PrintOfferHold(const OfferHolder* oH) {
    for(size_t i = 0; i < oH->len; i++) {
        PrintSingleOffer(oH->offers[i]);
    }
}

int main() {

    bool shouldStop = false;
    while(!shouldStop) {
        char command;
        cin >> command;
        switch (command)
        {
            case 'a':
            {
                size_t n;
                cin >> n;
                OfferHolder* oH = EnterOffers(Const::FILE_NAME, n); 
                WriteOffersIntoFile(Const::FILE_NAME, oH);
                
                delete[] oH->offers;
                delete oH;
                break;
            }
            case 'i':
            {
                OfferHolder* oH = ExtractDataFromFile(Const::FILE_NAME);
                PrintOfferHold(oH);
                
                delete[] oH->offers;
                delete oH; 
                break;
            }
            case 's':
            {
                char buff[Const::OFFER_NAME_SIZE];
                cin >> buff;
                OfferHolder* oH = ExtractDataFromFile(Const::FILE_NAME);
                cout << existOffer(Const::FILE_NAME, buff) << endl;
                
                delete[] oH->offers;
                delete oH; 
                break;
            }
            case 'f':
            {
                long long minSalary;
                cin >> minSalary;
                OfferHolder* filtered = filterOffers(Const::FILE_NAME, minSalary);
                PrintOfferHold(filtered);

                delete[] filtered->offers;
                delete filtered; 
                break;
            }
            case 'p':
            {
                uint16_t maxCoworker, minVacancyDays;
                long long minSalary;
                cin >> maxCoworker >> minVacancyDays >> minSalary;
                perfectOffer(Const::FILE_NAME, maxCoworker, minVacancyDays, minSalary, Const::VALID_OFFERS_FILE_NAME);
                break;
            }
            case 'q':
            {
                shouldStop = true;
                break;
            }
        }
    }
}