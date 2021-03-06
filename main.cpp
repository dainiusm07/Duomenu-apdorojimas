#include "header.h"

int main () {
    auto startas = std::chrono::system_clock::now();
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> range(1, 10);
    std::string temp;
    std::list<Studentas> A,vargsai;
    std::list<Studentas> :: iterator it;
    it = A.begin();
    int stud_nr=-1; // Studento identifikacijos nr (-1 nes nera dar jokios stud, prasideda nuo 0)
    int ivedimo_pasirinkimas;
    new_line();

    std::cout << "Kaip noretum ivesti visus duomenis?\n1- Ivesti paciam\n2- Nuskaityti is failo kursiokai.txt\n3- Sugeneruoti faila kursiokai.txt ir nuskaityti is jo" << std::endl;
    auto pabaiga = std::chrono::system_clock::now();
    auto uztruko = std::chrono::duration_cast<std::chrono::duration<double> >(pabaiga - startas).count();
    while (true){   // Laukiam kol pasirenka 1 arba 2
        int temp_nr;
        std::cin >> temp_nr;
        try {
            if (std::cin.fail()){
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                throw "Turi ivesti skaiciu!";
            }
            else{
                if (temp_nr==1 or temp_nr==2 or temp_nr==3){
                    ivedimo_pasirinkimas=temp_nr;
                    break;
                }
                else{
                    throw "Netinkamas skaicius.";
                }    
            }
        } catch (const char* e){
            std::cout << e << std::endl;
        }
    }
    std::cin.ignore(); //  Kadangi i cin ieina ir \n tai reikia ignorint, nes getline susimauna tada, galit be sito pabandyt pamatysit :)

    if (ivedimo_pasirinkimas==1)
    {
        int vid_pasirinkimas;
        std::cout << "Kaip noretum skaiciuoti galutini pazymi?\n1- Naudojant vidurki\n2- Naudojant mediana" << std::endl;
        while (true){   // Laukiam kol pasirenka 1 arba 2
            std::cin>>temp;
            if (temp=="1"){
                vid_pasirinkimas=1;
            break;
            }
            else if (temp=="2"){
                vid_pasirinkimas=2;
            break;
            }
            else
            std::cout<< erroras << std::endl;
        }
        std::cin.ignore(); //  Kadangi i cin ieina ir \n tai reikia ignorint, nes getline susimauna tada, galit be sito pabandyt pamatysit :)

        while (true) {
            new_line();
            std::cout << "Ivesk " << stud_nr+2 <<" studento varda ir pavarde. (Vardenis Pavardenis)" << std::endl << "Jei jau pabaigiai vesti duomenis tiesiog spausk ENTER." << std::endl;

            std::getline(std::cin, temp);

            if (!temp.empty())
            {
                int pos = temp.find(" "); // Tarpo pozicija, reikalinga tam, kad atskirti varda nuo pavardes

                if (temp.length()-1>pos and all_letters(temp)==true) { // Tikrinu ar yra ivestas vardas ir pavarde ir nera skaiciu
                    A.push_back(Studentas()); // Pakeiciu array A dydi su kiekvienu tinkamu vardu ir pav
                    stud_nr++; // Paruosiamas nr studentui
                    it++;
                    it->vardas = temp.substr(0,pos);
                    convert_to_proper_format(it->vardas);
                    it->pavarde = temp.substr(pos+1);
                    it->pavarde = it->pavarde.substr(0,it->pavarde.find(" ")); // Palieka 2 pirmus zodzius jei iveda daugiau nei 2
                    convert_to_proper_format(it->pavarde);

                    new_line();
                    std::cout << "Kaip nori ivesti namu darbus rezultatus?\n1- Rankiniu budu\n2- Sugeneruoti automatiskai" << std::endl;
                    std::vector<int> pazymiai;
                    int sk=0; // Namu darbus kiekis
                    while(true){
                        std::cin>>temp;
                    if (temp=="1") {
                        new_line();
                        std::cout << "Ivedinek skaicius 0-10, noredamas sustoti ivesk betkoki kita skaiciu." << std::endl;
                        while(true){
                            std::cin>>temp;
                            if(is_digits(temp)==true)
                            {
                                int ivestis = std::stoi(temp);
                                if (ivestis>=0 and ivestis<=10){
                                    pazymiai.push_back(int());
                                    pazymiai[sk]=ivestis;
                                    sk++;
                                }
                                else {
                                    if (sk!=0)
                                        break;
                                    else
                                        std::cout << "Ivesk bent 1 skaiciu..." << std::endl;
                                }
                            } 
                            else
                                std::cout << erroras << std::endl;
                        }
                        break;
                    }
                    if (temp=="2"){
                    new_line();
                    std::cout << "Kiek skaiciu sugeneruoti?" << std::endl;
                    while(true){
                        std::cin>>temp;
                        if(is_digits(temp)==true)
                        {
                            int ivestis = std::stoi(temp);
                            if (ivestis>0){
                                auto startas = std::chrono::system_clock::now();
                                for (int i=0;i<ivestis;i++){
                                    pazymiai.push_back(int());
                                    pazymiai[sk]=range(mt);
                                    sk++;
                                }
                                auto pabaiga = std::chrono::system_clock::now();
                                uztruko += std::chrono::duration_cast<std::chrono::duration<double> >(pabaiga - startas).count();
                                break;
                            }
                            else {
                                if (sk!=0)
                                    break;
                                else
                                    std::cout << "Turi buti bent 1 pazymys..." << std::endl;
                            }
                        } 
                        else
                            std::cout << erroras << std::endl;
                    }
                    break;
                    }
                    else {
                        std::cin.ignore();
                        std::cin.clear();
                        std::cout << erroras << std::endl;}
                    
                    }
                    
                    new_line();
                    std::cout << "Dabar ivesk gauta egzamino pazymi " << std::endl;
                    int egz;
                    while(true){
                        std::string ivestis_string;
                        std::cin >> ivestis_string;
                        int ivestis;

                        if (is_digits(ivestis_string)==false){ // Tikrinu ar ten tik skaiciai, jei ne tai tiesiog i ivesti irasau netinkama skaiciu
                            ivestis=-1;
                        }
                        else
                        {
                            ivestis = std::stoi(ivestis_string); // Jei viskas ok string pavercia i int
                        }
                        

                        if (ivestis<0 or ivestis>10){ // Per mazas ar per didelis skaicius netinka
                            std::cout << erroras << std::endl;
                        }
                        else
                        {
                            egz=ivestis;
                            break;
                        }
                    }

                    double vid;
                    auto startas = std::chrono::system_clock::now();
                    if (vid_pasirinkimas==1)
                        vid=vidurkis(pazymiai,sk);
                    else
                        vid=mediana(pazymiai,sk);
                    auto pabaiga = std::chrono::system_clock::now();
                    uztruko += std::chrono::duration_cast<std::chrono::duration<double> >(pabaiga - startas).count();
                    

                    it->galutinis=1.0*(0.4*vid+0.6*egz);
                    std::cin.ignore();
                    std::cin.clear(); // Trinu visus cin, kad isvengti nesamoniu visokiu
                }
                else{
                    std::cout << erroras << std::endl;
                }
            }
            
            else{
                if (stud_nr==-1)
                    std::cout << "Irasyk duomenis bent apie 1 studenta!"<< std::endl;
                else{
                    auto startas = std::chrono::system_clock::now();
                    spausdinimas(stud_nr,A,vid_pasirinkimas);
                    auto pabaiga = std::chrono::system_clock::now();
                    uztruko += std::chrono::duration_cast<std::chrono::duration<double> >(pabaiga - startas).count();
                    break;
                }       
            }
        }
    }
    else if (ivedimo_pasirinkimas==2)
    {
        auto startas = std::chrono::system_clock::now();
        std::string eilute,vardas,pavarde;
        std::ifstream in_file ("kursiokai.txt");
        if (in_file.good()){
            while(std::getline(in_file,eilute)){  // Nuskaito po visa eilute txt faile
                A.push_back(Studentas());
                std::istringstream in_line(eilute); // Skaitymas is eilutes

                in_line >> vardas >> pavarde;
                if(all_letters(vardas) and all_letters(pavarde)){
                    stud_nr++;
                    it++;
                    it->vardas=vardas;
                    it->pavarde=pavarde;

                    
                    convert_to_proper_format(it->vardas);
                    convert_to_proper_format(it->pavarde);

                    int sk=0;
                    std::vector<int> pazymiai;
                    while(in_line>>temp){
                        if(is_digits(temp)){
                            int ivestis = std::stoi(temp);
                            if (ivestis>=0 and ivestis<=10){
                                pazymiai.push_back(int());
                                pazymiai[sk]=ivestis;
                                sk++;
                            }
                        }
                    }

                    in_line.end;

                    int egz = 0;
                    if (sk>0) // Cia nes gali buti, jog neives skaiciu visai ir tada gali iseit pazymiai[-1]
                        egz = pazymiai[sk-1]; // Paskutinis ivestas skaicius egzamino pazimys

                    if (sk>1){
                        it->galutinis=1.0*(0.4*vidurkis(pazymiai,sk-1)+0.6*egz);
                        it->galutinis2=1.0*(0.4*mediana(pazymiai,sk-1)+0.6*egz);
                    }
                    else
                    {
                        it->galutinis=1.0*(0.6*egz);
                        it->galutinis2=1.0*(0.6*egz);
                    }
                }
            }
            if (stud_nr>-1)
                rikiavimas(A,stud_nr); // Ten rikiuoju o isrikiaves siunciu iskart i spausdinima
            else{
                new_line();
                std::cout << "Failas yra tuscias arba ivesti duomenys yra netinkami." << std::endl;
            }
        }
        else{
            new_line();
            std::cout << "Tokio failo nera." << std::endl;
        }

        auto pabaiga = std::chrono::system_clock::now();
        uztruko += std::chrono::duration_cast<std::chrono::duration<double> >(pabaiga - startas).count();
        
        in_file.end;
    }
    else if (ivedimo_pasirinkimas==3){
        new_line();
        std::cout << "Kiek zmoniu turetu but sugeneruota?\n1- 10\n2- 100\n3- 1000\n4- 10000\n5- 100000\n";
        int sk_pasirinkimas,pazymiu_sk=10; //pagal pazymiu_sk sprendzia kiek pazymiu kiekvienam generuoti
        int zmoniu_sk=10;
        while (true){
            int temp_nr;
            std::cin >> temp_nr;
            try {
                if (std::cin.fail()){
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    throw "Turi ivesti skaiciu!";
                }
                else{
                    if (temp_nr>=1 and temp_nr<=5){
                        sk_pasirinkimas=temp_nr;
                        break;
                    }
                    else{
                        throw "Netinkamas skaicius.";
                    }    
                }
            } catch (const char* e){
                std::cout << e << std::endl;
            }
        }
        auto startas = std::chrono::system_clock::now();

        std::ofstream toFile ("kursiokai.txt");
        for (int i=1;i<sk_pasirinkimas;i++)
            zmoniu_sk=zmoniu_sk*10;



        for (int i=0; i<zmoniu_sk; i++){
            toFile << "Vardas" << i+1 << " Pavarde" << i+1;
            for (int j=0;j<=pazymiu_sk;j++)
                toFile << " " << range(mt);
            toFile << "\n";
        }
        toFile.close();

        ///----------------------------------

        std::string eilute,vardas,pavarde;
        std::ifstream in_file ("kursiokai.txt");
        std::ofstream kietas ("kieti.txt");
        std::ofstream vargsas ("vargsai.txt");
        while(std::getline(in_file,eilute)){  // Nuskaito po visa eilute txt faile
            A.push_back(Studentas());
            std::istringstream in_line(eilute); // Skaitymas is eilutes

            in_line >> vardas >> pavarde;
            stud_nr++;
            it++;
            it->vardas=vardas;
            it->pavarde=pavarde;

            int sk=0;
            std::vector<int> pazymiai;
            while(in_line>>temp){
                if(is_digits(temp)){
                    int ivestis = std::stoi(temp);
                    if (ivestis>=0 and ivestis<=10){
                        pazymiai.push_back(int());
                        pazymiai[sk]=ivestis;
                        sk++;
                    }
                }
            }

            int egz = 0;
            if (sk>0) // Cia nes gali buti, jog neives skaiciu visai ir tada gali iseit pazymiai[-1]
                egz = pazymiai[sk-1]; // Paskutinis ivestas skaicius egzamino pazimys

            if (sk>1){
                it->galutinis=1.0*(0.4*vidurkis(pazymiai,sk-1)+0.6*egz);
                it->galutinis2=1.0*(0.4*mediana(pazymiai,sk-1)+0.6*egz);
            }
            else
            {
                it->galutinis=1.0*(0.6*egz);
                it->galutinis2=1.0*(0.6*egz);
            }

        }
        rusiavimas(A,vargsai);
    
        for (it = vargsai.begin(); it != vargsai.end(); it++){
            vargsas << it->vardas << " " << it->pavarde << " " << it->galutinis << " " << it->galutinis2 << std::endl;
        }
        
        for (it = A.begin(); it != A.end(); it++){
            kietas << it->vardas << " " << it->pavarde << " " << it->galutinis << " " << it->galutinis2 << std::endl;
        }

        kietas.close();
        vargsas.close();
        in_file.close();

        std::cout << "Studentai surusiuoti i failus kieti.txt ir vargsai.txt" << std::endl;
        auto pabaiga = std::chrono::system_clock::now();
        uztruko += std::chrono::duration_cast<std::chrono::duration<double> >(pabaiga - startas).count();

        
    }
    
    std::cout << "\nPrograma uztruko - " << uztruko << " sekundziu.\n" << std::endl;
return 0;
}
