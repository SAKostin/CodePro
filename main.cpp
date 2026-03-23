#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

string usernames[20];
string passwords[20];
int scores[20];
int userCount = 0;

int currentUser = -1;

void registerUser()
{
    if (userCount >= 20)
    {
        cout << "No space\n";
        return;
    }

    string u;
    cout << "Username: ";
    cin >> u;


    for (int i = 0; i < userCount; i++)
    {
        if (usernames[i] == u)
        {
            cout << "User already exists\n";
            return;
        }
    }

    string p;
    cout << "Password: ";
    cin >> p;

    usernames[userCount] = u;
    passwords[userCount] = p;
    scores[userCount] = 0;
    userCount++;

    cout << "Registration successful\n";
}

void login()
{
    string u, p;

    cout << "Username: ";
    cin >> u;

    cout << "Password: ";
    cin >> p;

    for (int i = 0; i < userCount; i++)
    {
        if (usernames[i] == u && passwords[i] == p)
        {
            currentUser = i;
            cout << "Login successful\n";
            return;
        }
    }

    cout << "Incorrect credentials\n";
}

int getGrade(int p)
{
    if (p >= 50) return 6;
    else if (p >= 40) return 5;
    else if (p >= 30) return 4;
    else if (p >= 20) return 3;
    else return 2;
}

void readArticle()
{
    cout << "\n--- Biology Article ---\n";
    cout << "Plants produce food through photosynthesis using sunlight, water, and carbon dioxide.\n";
    cout << "Humans have organs like lungs for breathing, brain for thinking, heart for pumping blood.\n";
    cout << "Animals can be domestic or wild; some live in water, some fly, some are mammals.\n";
    cout << "This knowledge will help you answer the test questions.\n";
}

void test()
{
    if (currentUser == -1)
    {
        cout << "You must register and login first\n";
        return;
    }

    readArticle(); 
    int points = 0;
    string a;

    int r = rand() % 2;

    if (r == 0)
    {
        cout << "\n--- Version 1 ---\n";

        cout << "\nPlants\n";
        cout << "1 Photosynthesis?\n a) Oxygen b) Metal c) Salt\n"; cin >> a; if (a == "a") points += 2;
        cout << "2 What does the root do?\n a) Support b) Think c) Fly\n"; cin >> a; if (a == "a") points += 2;
        cout << "3 Leaf?\n a) Food b) Stone c) Iron\n"; cin >> a; if (a == "a") points += 2;
        cout << "4 Sun?\n a) Helps b) Hinders c) No effect\n"; cin >> a; if (a == "a") points += 2;
        cout << "5 What does a plant have?\n a) Root b) Heart c) Brain\n"; cin >> a; if (a == "a") points += 2;

        cout << "\nHuman\n";
        cout << "6 Breathing?\n a) Lungs b) Leg c) Hand\n"; cin >> a; if (a == "a") points += 2;
        cout << "7 Thinking?\n a) Brain b) Hair c) Nails\n"; cin >> a; if (a == "a") points += 2;
        cout << "8 Blood?\n a) Heart b) Skin c) Ear\n"; cin >> a; if (a == "a") points += 2;
        cout << "9 Bones?\n a) 206 b) 100 c) 50\n"; cin >> a; if (a == "a") points += 2;
        cout << "10 Food?\n a) Stomach b) Hair c) Ear\n"; cin >> a; if (a == "a") points += 2;

        cout << "\nAnimals\n";
        cout << "11 Mammal?\n a) Dog b) Fish c) Snake\n"; cin >> a; if (a == "a") points += 2;
        cout << "12 Water?\n a) Fish b) Horse c) Dog\n"; cin >> a; if (a == "a") points += 2;
        cout << "13 Can fly?\n a) Bird b) Cow c) Horse\n"; cin >> a; if (a == "a") points += 2;
        cout << "14 Wild?\n a) Lion b) Cat c) Dog\n"; cin >> a; if (a == "a") points += 2;
        cout << "15 Domestic?\n a) Cat b) Tiger c) Lion\n"; cin >> a; if (a == "a") points += 2;
    }
    else
    {
        cout << "\n--- Version 2 ---\n";

        cout << "\nPlants\n";
        cout << "1 Green?\n a) Leaf b) Stone c) Metal\n"; cin >> a; if (a == "a") points += 2;
        cout << "2 Grows?\n a) Plant b) Chair c) Computer\n"; cin >> a; if (a == "a") points += 2;
        cout << "3 Needs water?\n a) Yes b) No c) Never\n"; cin >> a; if (a == "a") points += 2;
        cout << "4 Needs sun?\n a) Yes b) No c) None\n"; cin >> a; if (a == "a") points += 2;
        cout << "5 Part?\n a) Leaf b) Engine c) Tire\n"; cin >> a; if (a == "a") points += 2;

        cout << "\nHuman\n";
        cout << "6 Organ?\n a) Heart b) Stone c) Tree\n"; cin >> a; if (a == "a") points += 2;
        cout << "7 Thinks?\n a) Brain b) Leg c) Hand\n"; cin >> a; if (a == "a") points += 2;
        cout << "8 Breaths?\n a) Lungs b) Hair c) Nails\n"; cin >> a; if (a == "a") points += 2;
        cout << "9 Blood?\n a) Heart b) Ear c) Skin\n"; cin >> a; if (a == "a") points += 2;
        cout << "10 Food?\n a) Stomach b) Hair c) Eye\n"; cin >> a; if (a == "a") points += 2;

        cout << "\nAnimals\n";
        cout << "11 Lives in water?\n a) Fish b) Dog c) Cat\n"; cin >> a; if (a == "a") points += 2;
        cout << "12 Can fly?\n a) Bird b) Cow c) Horse\n"; cin >> a; if (a == "a") points += 2;
        cout << "13 Mammal?\n a) Dog b) Shark c) Frog\n"; cin >> a; if (a == "a") points += 2;
        cout << "14 Wild?\n a) Tiger b) Cat c) Dog\n"; cin >> a; if (a == "a") points += 2;
        cout << "15 Domestic?\n a) Dog b) Lion c) Tiger\n"; cin >> a; if (a == "a") points += 2;
    }

    cout << "\nPoints: " << points << "\n";
    cout << "Grade: " << getGrade(points) << "\n";

    scores[currentUser] = points;
}

void leaderboard()
{
    for (int i = 0; i < userCount; i++)
    {
        for (int j = i + 1; j < userCount; j++)
        {
            if (scores[j] > scores[i])
            {
                int t = scores[i];
                scores[i] = scores[j];
                scores[j] = t;

                string tu = usernames[i];
                usernames[i] = usernames[j];
                usernames[j] = tu;
            }
        }
    }

    cout << "\nLeaderboard\n";
    for (int i = 0; i < userCount; i++)
    {
        cout << usernames[i] << " - " << scores[i] << "\n";
    }
}

int main()
{

    cout << "####  ####   ###  ####  #####  ###  #      ###   ###  #   #" << endl;
    cout << "#   # #   # #   # #   #   #   #   # #     #   # #   # #   #" << endl;
    cout << "#   # #   # #   # #   #   #   #   # #     #   # #      # #" << endl;
    cout << "####  ####  #   # ####    #   #   # #     #   # # ###   #" << endl;
    cout << "#     # #   #   # #   #   #   #   # #     #   # #   #   #" << endl;
    cout << "#     #  #  #   # #   #   #   #   # #     #   # #   #   #" << endl;
    cout << "#     #   #  ###  ####  #####  ###  #####  ###   ###    #" << endl;
    srand(time(0));

    int c;

    while (true)
    {
    
        cout << "\n1 Register\n2 Login\n3 Read Article\n4 Test\n5 Leaderboard\n6 Exit\n";
        cin >> c;

        if (c == 1) registerUser();
        else if (c == 2) login();
        else if (c == 3) readArticle();
        else if (c == 4) test();
        else if (c == 5) leaderboard();
        else if (c == 6) break;
        else {

            cout << "Error\n";
            break;
        }

        

        
    }

    
}