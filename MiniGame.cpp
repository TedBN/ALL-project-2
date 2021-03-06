#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <unistd.h>
#include <cstdlib>
#include <sqlite3.h>
#pragma GCC diagnostic ignored "-Wwrite-strings" //Ignores invalid warning message
// #include <windows.h> //Windows API - Disabled when working on Linux
using namespace std;

//Initilialises callback function for SQL
static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s: ", (const char*)data);
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

const int height = 15, width = 30; //Grid Values
int x = 0, y = 0; // Player Coordinates

//Setting colour values for Linux/Codio
const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");
const std::string cyan("\033[0;36m");
const std::string magenta("\033[0;35m");
const std::string reset("\033[0m");

// Classes
class enemySoldier{
  int amount = 5;
};

class enemyBomb{
   int amount = 3;
};

// Grid/Map
char myMap[height][width] = {
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
    {'.', '.', '.', '.', '.', '.', '~', '~', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
    {'~', '~', '~', '~', '~', '~', '~', '~', '~', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
    {'.', '.', '~', '.', '~', '~', '~', '~', '~', '~', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
    {'.', '.', '.', '.', '.', '~', '~', '~', '~', '~', '~', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
    {'.', '.', '.', '.', '.', '.', '~', '~', '~', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
    {'.', '.', '.', '.', '.', '.', '.', '~', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' }
};

// Applying Colours to Map and Print
void PrintMap() {
    cout << "(" << x << ','<< y << ")" << endl;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (myMap[i][j] == '.') {
                cout << green << myMap[i][j]; // Grass
            }
            else if (myMap[i][j] == '~'){
                cout << cyan << myMap[i][j]; // Water
            }
            else if (myMap[i][j] == '@') {
                cout << red << myMap[i][j]; // Player Icon
            }
            else{
                cout << reset << myMap[i][j];
            }
        }
        cout << reset << endl;
    }
}

int main() {

// Presetting Types
sqlite3 *db;
char *zErrMsg = 0;
int rc;
char *sql;
const char *data = "Callback function called";

rc = sqlite3_open("Obstacles.db", &db); //Linking/Opening Database

//Testing
if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
}
else{
      fprintf(stderr, "Opened database successfully\n");
}
    
//Selecting Elements Needed
sql = "SELECT amount FROM Obstacles";

//Executing
rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

//Testing
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
}
    else{
      fprintf(stdout, "Operation done successfully\n");
}
    
//Random Obstacle Placement
int store1 = 3;
int store2 = 5;
char bomb = '.';
char soldier = '.';

while (store1 > 0){
    myMap[rand() % 15][rand() % 30] = bomb;
    store1 = store1 - 1;
    continue;
}

while (store2 > 0){
    myMap[rand() % 15][rand() % 30] = soldier;
    store2 = store2 - 1;
    continue;
}

//User-Movement Input
char input;
char temp_tile = myMap[y][x]; // '.' (0, 0);
myMap[y][x] = '@'; // '@' (0, 0);
PrintMap(); 

// Looping map generation  
while (true) {
    myMap[14][29] = '=';
    cin >> input;
    int enemySoldier = 5;
    int enemyBomb = 3;

//Keeping player within boundaries
    if (input == 's' && y < height - 1) {
        myMap[y][x] = temp_tile;
        y++;
        temp_tile = myMap[y][x];
        myMap[y][x] = '@';
        PrintMap();
    }
    if (input == 'd' && x < width - 1) {
        myMap[y][x] = temp_tile;
        x++;
        temp_tile = myMap[y][x];
        myMap[y][x] = '@';
        PrintMap();
    }
    if (input == 'w' && y > 0){
        myMap[y][x] = temp_tile;
        y--;
        temp_tile = myMap[y][x];
        myMap[y][x] = '@';
        PrintMap();
    }

    if (input == 'a' && x > 0) {
        myMap[y][x] = temp_tile;
        x--;
        temp_tile = myMap[y][x];
        myMap[y][x] = '@';
        PrintMap();
    }
    if (input == '?'){   //Player Help
        cout << "There are: " << enemySoldier << " Enemy Soldiers." << endl;
        cout << "There are: " << enemyBomb << " Enemy Bombs." << endl;
    }

// Using preset bomb and enemy values for demonsration purposes
    if(x == 25 && y == 12){
    cout << "You ran into a bomb!" << endl;
    usleep(5000000); //Wait
    std::terminate(); //Program ends
    }
    
    if(x == 7 && y == 2){
    cout << "You ran into an enemy soldier!" << endl;
    usleep(5000000);
    std::terminate();
    }
    
    if(x == 7 && y == 2){
    cout << "You ran into an enemy soldier!" << endl;
    usleep(5000000);
    std::terminate();
    }
    
    if(x == 12 && y == 1){
    cout << "You ran into an enemy soldier!" << endl;
    usleep(5000000);
    std::terminate();
    }
    
    if(x == 19 && y == 5){
    cout << "You ran into an enemy soldier!" << endl;
    usleep(5000000);
    std::terminate();
    }
    
    if(x == 16 && y == 8){
    cout << "You ran into an enemy soldier!" << endl;
    usleep(5000000);
    std::terminate();
    }
    
    if(x == 1 && y == 9){
    cout << "You ran into an enemy soldier!" << endl;
    usleep(5000000);
    std::terminate();
    }
    
    if(x == 25 && y == 8){
    cout << "You ran into a bomb!" << endl;
    usleep(5000000);
    std::terminate();
    }
    
    if(x == 16 && y == 13){
    cout << "You ran into a bomb!" << endl;
    usleep(5000000);
    std::terminate();
    }
    
//Victory/Win Condition
    if(x == 29 && y == 14){
    sql = "UPDATE Score SET User_Score=User_Score+1"; // Update User Score
    cout << "You successfully escaped the battlefield!" << endl;
    
//Testing Update to Database
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   }
   else{
      fprintf(stdout, "Records updated successfully\n");
   } 
    usleep(5000000);
    std::terminate();
    }
}
    system("PAUSE");
    return 0;
}

// Luke Kilmartin - AxleCat