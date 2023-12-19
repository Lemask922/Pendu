//
// Created by aboudaay on 17/11/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include"Pendu.h"
#include<string.h>
#include <time.h>
#include <ctype.h>
#include "/Users/abouda/Desktop/Esiea/Project CCCCCC/raylib-master/src/raylib.h"


//Thème ANIMAUX
char animauxFacile[50][15] = {
        "Chat", "Chien", "Cheval", "Lapin", "Poule",
        "Canard", "Oie", "Cochon", "Vache", "Mouton",
        "Chèvre", "Biche", "Cerf", "Renard", "Lion",
        "Tigre", "Ours", "Panda", "Léopard", "Girafe",
        "Zèbre", "Éléphant", "Hippopotame", "Kangourou", "Koala",
        "Paresseux", "Fourmi", "Abeille", "Mouche", "Papillon",
        "Escargot", "Grenouille", "Tortue", "Lézard", "Serpent",
        "Crocodile", "Perroquet", "Canari", "Hibou", "Faucon",
        "Pie", "Corbeau", "Mouette", "Goéland", "Pigeon",
        "Colombe", "Dindon", "Paon", "Faisan", "Cygne"
};
char animauxMoyen[50][15] = {
        "Antilope", "Babouin", "Carcajou", "Dromadaire", "Écureuil",
        "Flamant", "Gorille", "Hérisson", "Iguane", "Jaguar",
        "Kiwi", "Lama", "Mandrill", "Narval", "Orang-outan",
        "Pangolin", "Quokka", "Rhinocéros", "Saïmiri", "Tapir",
        "Uakari", "Varan", "Wallaby", "Xérus", "Yack",
        "Zorille", "Axolotl", "Bison", "Capybara", "Dugong",
        "Fennec", "Grizzly", "Hamster", "Impala", "Jabiru",
        "Kouprey", "Loris", "Marmotte", "Numbat", "Ocelot",
        "Potorou", "Quetzal", "Requin", "Serval", "Tamanoir",
        "Urubu", "Vautour", "Wombat", "Xénarthre", "Yéti"
};
char animauxDifficile[50][15] = {
        "Anhinga", "Balbuzard", "Cacatoès", "Daman", "Échidné",
        "Fouine", "Galago", "Hocco", "Indri", "Jacamar",
        "Kakapo", "Loir", "Manchot", "Narval", "Oryctérope",
        "Pécari", "Quokka", "Ratel", "Sarigue", "Tatou",
        "Urial", "Vipère", "Wapiti", "Xérus", "Yapok",
        "Zibeline", "Aye-aye", "Blaireau", "Coendou", "Dik-dik",
        "Elan", "Fossa", "Gibbon", "Hydre", "Ibex",
        "Jaguarundi", "Kinkajou", "Loutre", "Mouflon", "Nyala",
        "Oribi", "Pudu", "Quoll", "Roussette", "Sitatunga",
        "Takin", "Uranoscope", "Vicogne", "Wallaroo", "Xénops"
};

//Thème Ville
char villesFacile[50][15] = {
        "Paris", "Lyon", "Marseille", "Nice", "Nantes",
        "Strasbourg", "Bordeaux", "Lille", "Rennes", "Toulouse",
        "Montpellier", "Dijon", "Rouen", "Nancy", "Metz",
        "Reims", "Tours", "Clermont", "Grenoble", "Angers",
        "Le Mans", "Brest", "Limoges", "Amiens", "Perpignan",
        "Orléans", "Caen", "Mulhouse", "Roubaix", "Boulogne",
        "Toulon", "Avignon", "Poitiers", "Versailles", "Nanterre",
        "Pau", "Colmar", "Bayonne", "Brive", "Calais",
        "Beziers", "Arles", "Biarritz", "Cannes", "Dieppe",
        "Evreux", "Fecamp", "Gap", "Hyeres", "Joue"
};
char villesMoyen[50][15] = {
        "Aberdeen", "Bilbao", "Cordoue", "Dresde", "Essen",
        "Florence", "Gand", "Hambourg", "Innsbruck", "Jerez",
        "Kiev", "Lisbonne", "Malaga", "Naples", "Ostende",
        "Palermo", "Quebec", "Rennes", "Séville", "Turin",
        "Utrecht", "Venise", "Warsaw", "Xanten", "York",
        "Zurich", "Albi", "Braga", "Cremona", "Delft",
        "Erfurt", "Forli", "Girona", "Huesca", "Irun",
        "Jaen", "Kosice", "Lucca", "Modena", "Nimes",
        "Olbia", "Parma", "Quimper", "Ragusa", "Spezia",
        "Trapani", "Udine", "Varese", "Worms", "Ypres"
};
char villesDifficile[50][15] = {
        "Aalborg", "Badajoz", "Cuenca", "Dunedin", "Esbjerg",
        "Foggia", "Gavle", "Huelva", "Iquique", "Jujuy",
        "Kutaisi", "Larissa", "Murmansk", "Norrkoping", "Oulu",
        "Parnu", "Quetzaltenango", "Ravenna", "Szczecin", "Trabzon",
        "Utsunomiya", "Vlissingen", "Wakayama", "Xining", "Yokohama",
        "Zamora", "Augsburg", "Bergamo", "Cagliari", "Dijon",
        "Elche", "Ferrara", "Gyor", "Hasselt", "Izmir",
        "Jena", "Klagenfurt", "Leuven", "Mostar", "Novi Sad",
        "Opole", "Pilsen", "Rijeka", "Sarajevo", "Tarragona",
        "Umea", "Viborg", "Wexford", "Yaroslavl", "Zadar"
};
//thème FILM
char filmsFacile[50][15] = {
        "Intouchables", "Amélie", "La La Land", "Avatar", "Titanic",
        "Gladiator", "Inception", "Matrix", "Fight Club", "Léon",
        "Le Pianiste", "Memento", "Seven", "Alien", "Forrest Gump",
        "Braveheart", "Coco", "Wall-E", "Up", "Ratatouille",
        "Shrek", "Toy Story", "Cars", "Frozen", "Zootopie",
        "Joker", "Skyfall", "Dunkerque", "Gran Torino", "Interstellar",
        "Les Misérables", "Parasite", "Juno", "Moonlight", "Birdman",
        "Gravity", "Sully", "Fargo", "Her", "Arrival",
        "Whiplash", "Boyhood", "Drive", "Gone Girl", "Sicario",
        "Django", "Lincoln", "Hugo", "Argo", "Spotlight"
};
char filmsMoyen[50][15] = {
        "Le Prestige", "Old Boy", "Synecdoche", "No Country", "The Master",
        "Antichrist", "Dogville", "Biutiful", "Babel", "21 Grams",
        "Moonrise", "Melancholia", "Interstellar", "Inception", "Gravity",
        "Under Skin", "Moonlight", "Boyhood", "The Artist", "Birdman",
        "Lost in Trans", "Mystic River", "Blue Velvet", "Fight Club", "Dark Knight",
        "Pulp Fiction", "Inglourious", "Django", "Jackie Brown", "Kill Bill",
        "Reservoir", "The Hateful", "Gone Girl", "Zodiac", "Panic Room",
        "The Game", "Seven", "Alien", "Blade Runner", "Prometheus",
        "Gladiator", "Black Hawk", "American Gan", "Body of Lies", "Exodus",
        "The Martian", "A Beautiful", "Matchstick", "Thelma Louise", "White Squall"
};
char filmsDifficile[50][15] = {
        "Mulholland", "Atonement", "Revolutiona", "Blood Diamond", "No Country",
        "Lost in Trans", "The Master", "Mystic River", "Blue Velvet", "Mullholland",
        "Under Skin", "Melancholia", "Dogville", "Biutiful", "Inherent Vice",
        "21 Grams", "Eternal Sun", "Science Sleep", "Be Kind Rewind", "Mood Indigo",
        "Green Ray", "Golden Days", "Umbrellas", "Holy Motors", "Lovers Bridge",
        "Pola X", "Irreversible", "Enter Void", "Climax", "Love",
        "Fifth Element", "Valerian", "Lucy", "Angel-A", "Big Blue",
        "Subway", "Atlantis", "Nikita", "Leon", "Ronin",
        "Léon", "Wasabi", "Lucy", "Family", "Gandahar",
        "Time Masters", "Fantastic P", "Delicatessen", "City Lost Ch", "Amélie"
};




/* char tab1[100][15] = {    //tableau 2 dimension 100 éléments,15 caractères
        "Aventure", "Énigme", "Mystère", "Fantaisie", "Magie",
        "Labyrinthe", "Exploration", "Evasion", "Conquête", "Héros",
        "Légende", "Trésor", "Épique", "Sirène", "Chimère",
        "Dragon", "Sorcellerie", "Quête", "Enchanté", "Alliance",
        "Potion", "Courage", "Voyage", "Oracle", "Destin",
        "Illusion", "Éclat", "Renaissance", "Sagesse", "Vision",
        "Harmonie", "Création", "Insolite", "Incantation", "Rêverie",
        "Odyssée", "Phénix", "Portail", "Révélation", "Harmonie",
        "Destinée", "Éclipse", "Miraculeux", "Persévérance", "Fraternité",
        "Merveille", "Secret", "Nirvana", "Vortex", "Mirage",
        "Esprit", "Mirage", "Illimité", "Extase", "Divin",
        "Délire", "Astre", "Mirage", "Illimité", "Extase",
        "Divin", "Délire", "Astre", "Mirage", "Illimité",
        "Extase", "Divin", "Délire", "Astre", "Mirage",
        "Illimité", "Extase", "Divin", "Délire", "Astre",
        "Mirage", "Illimité", "Extase", "Divin", "Délire",
        "Astre", "Mirage", "Illimité", "Extase", "Divin",
        "Délire", "Astre", "Mirage", "Illimité", "Extase",
        "Divin", "Délire", "Astre", "Mirage", "Illimité",
        "Extase", "Divin", "Délire", "Astre", "Mirage"
};
char tab2[100][15] = {
        "Aquarelle", "Balise", "Cactus", "Eclipse",
        "Fauvette", "Girafe", "Haricot", "Iguane", "Jasmin",
        "Koala", "Lanterne", "Mouette", "Nénuphar", "Orchidée",
        "Papaye", "Quartz", "Racine", "Safran", "Tamarin",
        "Uranium", "Voyage", "Wapiti", "Xénophile", "Yucca",
        "Zéphyr", "Aquarium", "Brocoli", "Cygne", "Dynamite",
        "Embrun", "Fenouil", "Grenade", "Hibou", "Iris",
        "Jonquille", "Kaki", "Lilas", "Mangue", "Nectar",
        "Olivier", "Pamplemousse", "Quiche", "Radis", "Sorbet",
        "Tabouret", "Ustensile", "Vinaigre", "Walabi", "Xylophone",
        "Yoga", "Zodiaque", "Avocat", "Bretzel", "Cyclone",
        "Dromadaire", "Esturgeon", "Flamant", "Gazelle", "Horloge",
        "Indigo", "Jacinthe", "Kiwi", "Limonade", "Moustache",
        "Nougat", "Oasis", "Paon", "Quinoa", "Ratatouille",
        "Salamandre", "Tortue", "Ukulélé", "Vanille", "Wagon",
        "Xérès", "Yakitori", "Zèbre", "Armadillo", "Bungalow",
        "Cantaloup", "Dragon", "Escalope", "Festival", "Girouette",
        "Hérisson", "Insulaire", "Javelot", "Kimono", "Lavande",
        "Mandoline", "Narval", "Oeillet", "Pélican", "Quetzal",
        "Ravioli", "Saxophone", "Tournesol", "Urchin", "Vermicelle",
        "Wallaby"
};

char tab3[100][15] = { "Abracadabra", "Baccalauréat", "Chlorophylle", "Déshydratant", "Electrochoc",
                    "Francophile", "Glaciologie", "Héliocentrique", "Iconoclaste", "Juridiction",
                    "Kaleidoscope", "Labyrinthique", "Métamorphose", "Nanotechnologie", "Oxygénation",
                    "Parachutisme", "Quadrilatère", "Radiographie", "Synthétiseur", "Trigonometrie",
                    "Ultraviolet", "Vaccination", "Wolfram", "Xylophone", "Yacht",
                    "Zootechnique", "Amphibien", "Bioluminescent", "Cryptographie", "Dynamomètre",
                    "Encyclopédie", "Fluorescent", "Géographique", "Hippopotame", "Informatique",
                    "Juxtaposer", "Kilométrique", "Lymphatique", "Microscope", "Narcissique",
                    "Omnipotent", "Paléontologie", "Quintessence", "Rhinocéros", "Sismologie",
                    "Télékinésie", "Urbanisation", "Ventriloque", "Wagon-lit", "Xénophobie",
                    "Yin-yang", "Zoologie", "Accélérateur", "Bourdonnement", "Chronomètre",
                    "Désinfectant", "Ectoplasme", "Fibromyalgie", "Gouvernail", "Hydraulique",
                    "Impression", "Jurisprudence", "Logarithme", "Mécanique",
                    "Nymphéas", "Oxygénation", "Périphérique", "Quadrupède", "Réfrigérateur",
                    "Saxophone", "Tachymètre", "Ufologie", "Vulnérable", "Waterpolo",
                    "Xénophile", "Yoga", "Zéphyr", "Antioxydant", "Barycentre", "Catastrophe",
                    "Décapitation", "Extraterrestre", "Formidable", "Grammaire", "Hémisphère",
                    "Idiosyncrasie", "Journalisme", "Kinesthésie", "Léthargie", "Métaphore",
                    "Nébuleuse", "Orthographe", "Pantomime", "Quarantaine", "Rétrospective",
                    "Schizophrénie", "Télépathie", "Utopique", "Vibraphone",
                    "Xénon"
};
*/

int sujet(){
    int theme = 0;
    int resultatscan;

    do {
        printf("Choisissez votre thème \n");
        printf("1 - Animaux \n");
        printf("2 - Ville \n");
        printf("3 - Film \n");

        resultatscan = scanf("%d", &theme);

        if (resultatscan != 1) {
            printf("Veuillez entrer un nombre valide.\n");
            while (getchar() != '\n'); // Vide le tampon d'entrée tant que le caractère n'est pas recupérer par getchar
            theme = 0; // Réinitialisez pour continuer la boucle
            continue;}

        if (theme < 1 || theme > 3) {
            printf("Choix non valide. Veuillez choisir un thème entre 1 et 3.\n");
            theme = 0; // Réinitialisez pour continuer la boucle
            continue;}


        switch (theme) {
            case 1:
                printf("Oh un passionné d'animaux!\n");
                break;
            case 2:
                printf("Oh un connaisseur de ville!\n");
                break;
            case 3:
                printf("Oh un expert en film!\n");
                break;
            default:
                printf("Choix non valide. Veuillez choisir un thème entre 1 et 3.\n");
                theme = 0; // Réinitialisez lvl pour que la boucle continue
                break;
        }
    } while (theme == 0); // La boucle continue tant que lvl est 0

    return theme;
}

int niveau_jeu() {
    int lvl = 0;
    int resultatscan;

    do {
        printf("Choisissez votre niveau de jeu \n");
        printf("1 - Facile\n");
        printf("2 - Moyen \n");
        printf("3 - Difficile \n");
        resultatscan = scanf("%d", &lvl);

        if(resultatscan != 1){
            printf("Veuillez entrer un nombre valide.\n");
            while (getchar()!= '\n');
            lvl = 0;
            continue;
        }

        if (lvl < 1 || lvl > 3) {
            printf("Choix non valide. Veuillez choisir un thème entre 1 et 3.\n");
            lvl = 0; // Réinitialisez pour continuer la boucle
            continue;
        }



        switch (lvl) {
            case 1:
                printf("Oh un petit débutant!\n");
                break;
            case 2:
                printf("Oh un joueur moyen!\n");
                break;
            case 3:
                printf("Oh un expert!!!!\n");
                break;
            default:
                printf("Choix non valide. Veuillez choisir un niveau entre 1 et 3.\n");
                lvl = 0; // Réinitialisez lvl pour que la boucle continue
                break;
        }
    } while (lvl == 0); // La boucle continue tant que lvl est 0

    return lvl;
}


char* Word(char tab[50][15])  //fonction "Word" retourne un pointeur prend en paramètre notre tableau
{
    srand(time(NULL)); // initialisation de la fonction rand
    int value = rand() % 51; // intervalle de la fonction 0-50
    char* result = malloc(15 * sizeof(char)); /* allocation de mémoire 15 octets pour 15 caractères
 et création d'un pointeur result qui pointe vers notre chaine de caractère. free(result) à utiliser */
    strncpy(result, tab[value], 14); // copie jusqu'à 14 caractères de value dans result
    result[14] = '\0'; // confirmation de la fin de chaire de caractères
    return result; // retourne pointeur
}
void Mot_Cache(char* res, char* tmp)
{
    int L = strlen(res);
    for (int i = 0; i < L; i++)
    {
        tmp[i]='-';
    }
    tmp[L] = '\0';
}

void Settings(int theme,int lvl,char* res)
{
    switch (theme) {
        case 1:
            switch (lvl) {

                case 1:
                    res = Word(animauxFacile);
                    break;

                case 2:
                    res = Word(animauxMoyen);
                    break;
                case 3:
                    res = Word(animauxDifficile);
                    break;

                default:
                    printf("Erreur causé au niveau du thème animaux, des niveaux");
                    break;
            }

            break;

        case 2:
            switch (lvl) {

                case 1:
                    res = Word(villesFacile);
                    break;

                case 2:
                    res = Word(villesMoyen);
                    break;
                case 3:
                    res = Word(villesDifficile);
                    break;
                default:
                    printf("Erreur causé au niveau du thème villes, des niveaux");
                    break;
            }
            break;
        case 3:
            switch (lvl) {

                case 1:
                    res = Word(filmsFacile);
                    break;

                case 2:
                    res = Word(filmsMoyen);
                    break;
                case 3:
                    res = Word(filmsDifficile);
                    break;
                default:
                    printf("Erreur causé au niveau du thème films, des niveaux");
                    break;
            }
            break;
    }
}

void deviner(char* res, char* tmp, bool* verif) {
    char Lettre;

    *verif = false;

    printf("Saisir une lettre : \n");

    while (1) {
        if (scanf(" %c", &Lettre) != 1 || getchar() != '\n') {
            // Invalid input (not a single character)
            printf("Veuillez saisir une seule lettre.\n");
            // Clear the input buffer
            while (getchar() != '\n');
        } else if (!isalpha(Lettre)) {
            // Invalid input (not an alphabet letter)
            printf("Veuillez saisir une lettre valide.\n");
        } else {
            // Valid input
            break;
        }
    }

    Lettre = toupper(Lettre);


    for (int i = 0; i < strlen(res); i++) {
        if (Lettre == toupper(res[i])) {
            tmp[i] = res[i];
            *verif = true;
        }
    }

    if (!(*verif)) {
        printf("La lettre %c n'est pas dans le mot.\n", Lettre);
    }
}

void dessine_pendu(int life ) {
    switch (life)
    {
        case 6:
            printf("   +---+\n");
            printf("   |   |\n");
            printf("       |\n");
            printf("       |\n");
            printf("       |\n");
            printf("       |\n");
            printf("=========\n");
            break;
        case 5:
            printf("   +---+\n");
            printf("   |   |\n");
            printf("   O   |\n");
            printf("       |\n");
            printf("       |\n");
            printf("       |\n");
            printf("=========\n");

            break;
        case 4:
            printf("   +---+\n");
            printf("   |   |\n");
            printf("   O   |\n");
            printf("   |   |\n");
            printf("       |\n");
            printf("       |\n");
            printf("=========\n");

            break;
        case 3:
            printf("   +---+\n");
            printf("   |   |\n");
            printf("   O   |\n");
            printf("  /|   |\n");
            printf("       |\n");
            printf("       |\n");
            printf("=========\n");

            break;
        case 2:
            printf("   +---+\n");
            printf("   |   |\n");
            printf("   O   |\n");
            printf("  /|\\  |\n");
            printf("       |\n");
            printf("       |\n");
            printf("=========\n");

            break;
        case 1:
            printf("   +---+\n");
            printf("   |   |\n");
            printf("   O   |\n");
            printf("  /|\\  |\n");
            printf("  /    |\n");
            printf("       |\n");
            printf("=========\n");

            break;
        case 0:
            printf("   +---+\n");
            printf("   |   |\n");
            printf("   O   |\n");
            printf("  /|\\  |\n");
            printf("  / \\  |\n");
            printf("       |\n");
            printf("=========\n");
            break;
    }
}
//
// Created by Abouda on 23/11/2023.
//
