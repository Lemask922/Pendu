//
// Created by aboudaay on 17/11/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include"Pendu.h"
#include<string.h>
#include <time.h>
#include <ctype.h>
#include "raylib.h"


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

/**
 * @brief   Génère un mot aléatoire à partir d'un tableau de caractères en 2D.
 *
 *
 * @param   tab   Un tableau 2D de caractères représentant une collection de mots.
 *
 *
 * @return  Un pointeur vers une chaîne de caractères allouée dynamiquement contenant le mot sélectionné aléatoirement.
 *
 */
char* Word(char tab[50][15])  //fonction "Word" retourne un pointeur prend en paramètre notre tableau
{
    srand(time(NULL)); // initialisation de la fonction rand
    int value = rand() % 51;
    char* result = malloc(15 * sizeof(char));
    strncpy(result, tab[value], 14);
    result[14] = '\0';
    return result;
}

/**
 * @brief   Initialise une chaîne de caractères masquée à partir d'une chaîne donnée.
 *
 *
 * @param   res   Chaîne de caractères source à partir de laquelle la chaîne masquée est créée.
 * @param   tmp   Chaîne de caractères masquée résultante.
 *
 *
 */
void Mot_Cache(char* res, char* tmp)
{
    int L = strlen(res);
    for (int i = 0; i < L; i++)
    {
        tmp[i]='-';
    }
    tmp[L] = '\0';
}

/**
 * @brief   genere le mot a deviner en fonction des paramètres du jeu thème et lvl choisis par le joueur .
 *
 * @details Cette fonction prend en compte le thème et le lvl  choisis, puis retourne
 *          un mot caché correspondant à ces paramètres.
 *
 * @param   theme   Thème choisi (1: Animaux, 2: Villes, 3: Films).
 * @param   lvl     Niveau choisi (1: Facile, 2: Moyen, 3: Difficile).
 * @param   res     Chaîne de caractères où le mot caché generé sera stocké.
 *
 * @return  Un pointeur vers la chaîne de caractères représentant le mot caché.
 */
char* Settings(int theme,int lvl,char* res)
{
    switch (theme) {
        case 1:
            switch (lvl) {

                case 1:
                    return res = Word(animauxFacile);
                    break;

                case 2:
                    return res = Word(animauxMoyen);
                    break;
                case 3:
                    return res = Word(animauxDifficile);
                    break;

                default:
                    printf("Erreur causé au niveau du thème animaux, des niveaux");
                    break;
            }

            break;

        case 2:
            switch (lvl) {

                case 1:
                    return res = Word(villesFacile);
                    break;

                case 2:
                    return res = Word(villesMoyen);
                    break;
                case 3:
                    return  res = Word(villesDifficile);
                    break;
                default:
                    printf("Erreur causé au niveau du thème villes, des niveaux");
                    break;
            }
            break;
        case 3:
            switch (lvl) {

                case 1:
                    return res = Word(filmsFacile);
                    break;

                case 2:
                    return res = Word(filmsMoyen);
                    break;
                case 3:
                    return res = Word(filmsDifficile);
                    break;
                default:
                    printf("Erreur causé au niveau du thème films, des niveaux");
                    break;
            }
            break;
    }
}


/**
 * @brief   Fonction pour deviner une lettre dans un mot.
 *
 * @details Cette fonction demande à l'utilisateur de saisir une lettre et vérifie
 *          si elle appartient au mot caché.
 *          Elle verifie aussi si l'utilisateur a saisie une lettre valide
 *          Elle met à jour la chaîne masquée en conséquence.
 *
 *
 * @param   res   Chaîne de caractères représentant le mot caché.
 * @param   tmp   Chaîne de caractères représentant le mot masqué, à mettre à jour.
 *
 * @return  true si la lettre était présente dans le mot, false sinon.
 */
bool deviner(char* res, char* tmp) {
    char Lettre;
    bool verif = false;

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
            verif = true;
        }
    }
        if (!(verif)) {
        printf("La lettre %c n'est pas dans le mot.\n", Lettre);
    }
   return verif;
}

/**
 * @brief   Affiche et trie un tableau de scores.
 *
 * @details Cette fonction utilise le tri à bulles pour ordonner les scores
 *          en ordre décroissant.
 *          Elle utilise les fonctions de la lib raylib pour l'affichage d'un tableau de score dans une Window prédefinie.
 *
 * @param   Scores  Tableau de structures Track contenant les scores à afficher et à trier.
 * @param   i       Nombre d'éléments dans le tableau Scores.
 */
void ScoresTable(struct Track *Scores, int i)
{
    // Tri à bulles pour ordonner les scores de best vers moins best
    for (int j = 0; j < i - 1; j++)
    {
        for (int k = 0; k < i - j - 1; k++)
        {
            // Si le score actuel est inférieur au score suivant, échangez-les
            if (Scores[k].score < Scores[k + 1].score)
            {
                // Échange des scores
                struct Track temp = Scores[k];
                Scores[k] = Scores[k + 1];
                Scores[k + 1] = temp;
            }
        }
    }

    // Afficher les scores triés
    DrawText("Scores Table : ", 20, 100, 20, WHITE);

    // Draw the table headers
    DrawRectangle(20, 140, 150, 30, GRAY);
    DrawText("Game Number", 30, 145, 15, BLACK);
    DrawRectangle(170, 140, 150, 30, GRAY);
    DrawText("Score", 230, 145, 15, BLACK);

    for (int j = 0; j < i; j++)
    {
        // Draw each row in the table
        DrawRectangle(20, 170 + j * 40, 150, 30, LIGHTGRAY);
        DrawText(TextFormat("%d", j + 1), 60, 175 + j * 40, 15, BLACK);

        DrawRectangle(170, 170 + j * 40, 150, 30, LIGHTGRAY);
        DrawText(TextFormat("%d", Scores[j].score), 250, 175 + j * 40, 15, BLACK);
    }
}

/**
 * @brief   Dessine une illustration du pendu.
 */
void drawHangman()
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    // base
    DrawLine(screenWidth / 2 - 50, screenHeight / 2 + 100, screenWidth / 2 + 50, screenHeight / 2 + 100, BLACK);

// Draw the pole
    DrawLine(screenWidth / 2, screenHeight / 2 + 100, screenWidth / 2, screenHeight / 2 - 100, BLACK);

// Draw the beam
    DrawLine(screenWidth / 2, screenHeight / 2 - 100, screenWidth / 2 - 50, screenHeight / 2 - 100, BLACK);

// Draw the rope
    DrawLine(screenWidth / 2 - 50, screenHeight / 2 - 100, screenWidth / 2 - 50, screenHeight / 2 - 70, BLACK);

// Draw the head
    DrawCircle(screenWidth / 2 - 50, screenHeight / 2 - 70, 20, BLACK);

// Draw the body
    DrawLine(screenWidth / 2 - 50, screenHeight / 2 - 50, screenWidth / 2 - 50, screenHeight / 2 - 20, BLACK);

// Draw the left arm
    DrawLine(screenWidth / 2 - 50, screenHeight / 2 - 50, screenWidth / 2 - 40, screenHeight / 2 - 40, BLACK);

// Draw the right arm
    DrawLine(screenWidth / 2 - 50, screenHeight / 2 - 50, screenWidth / 2 - 60, screenHeight / 2 - 40, BLACK);

// Draw the left leg
    DrawLine(screenWidth / 2 - 50, screenHeight / 2 - 20, screenWidth / 2 - 40, screenHeight / 2 - 10, BLACK);

// Draw the right leg
    DrawLine(screenWidth / 2 - 50, screenHeight / 2 - 20, screenWidth / 2 - 60, screenHeight / 2 - 10, BLACK);
}

/**
 * @brief   Dessine une représentation graphique du pendu en fonction du nombre de vies restantes.
 *
 * @details Cette fonction affiche différentes étapes du dessin du pendu en fonction du nombre de vies restantes.
 *
 * @param   life   Nombre de vies restantes pour le joueur.
 */
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
