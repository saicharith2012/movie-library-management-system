#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

class Movie
{
protected:
    string movie_id, title, Director, release_date, production, cast; //private variables

public:
    int copies, rent;

    //setters - assigning user value to private variables
    void setmovie_id(string a) { movie_id = a; }
    void setTitle(string b) { title = b; }
    void setDirector(string c) { Director = c; }
    void setrelease_date(string d) { release_date = d; }
    void setproduction(string e) { production = e; }
    void setcast(string f) { cast = f; }
    void setcopies(int g) { copies = g; }
    void setrent(int h) { rent = h; }

    //getters - getting the values from private variables
    string getmovie_id() { return movie_id; }
    string getTitle() { return title; }
    string getDirector() { return Director; }
    string getrelease_date() { return release_date; }
    string getproduction() { return production; }
    string getcast() { return cast; }
    int getcopies() { return copies; }
    int getrent() { return rent; }
};

//initializing functions with counter as parameter
void addMovie(int counter);
void deleteMovie(int counter);
void editMovie(int counter);
void searchMovie(int counter);
void viewAllMovies(int counter);
void quit();

//counter for Movie array
int counter = 0;

//function for incrementing counter
void increment(int a)
{
    a++;
    counter = a;
}

//function for decrementing counter
void decrement(int a)
{
    a--;
    counter = a;
}

//CLASS user

class User : protected Movie
{
private:
    string user_id, username, user_email, user_number;
    int balance;
    string movies_rented = "";

public:

    //setters - assigning user value to private variables
    void setuser_id(string a) { user_id = a; }
    void setusername(string b) { username = b; }
    void setuser_email(string c) { user_email = c; }
    void setuser_number(string d) { user_number = d; }
    void setbalance(int e) { balance = e; }

    //getters - getting the values from private variables
    string getuser_id() { return user_id; }
    string getusername() { return username; }
    string getuser_email() { return user_email; }
    string getuser_number() { return user_number; }
    int getbalance() { return balance; }

    //friend function declaration
    friend void rent_movie(int);
    friend void add_balance(int);
    friend void edit_details(int);
};

void add_user(int ucounter);
void edit_details(int ucounter);
void add_balance(int ucounter);
void rent_movie(int ucounter);
void return_movie(int ucounter);

//counter for users
int ucounter = 0;

void uincrement(int a)
{
    a++;
    ucounter = a;
}

//function for decrementing counter
void udecrement(int a)
{
    a--;
    ucounter = a;
}

//Movie class array initialization
Movie movies[10];
User users[10];

//main function
int main()
{

    while (true)
    {
        string person;
        //Main Menu
        system("CLS");
        cout << "\n\n\t\t\t\t\t\xB3  MOVIE LIBRARY MANAGEMENT SYSTEM  \xB3\n\n";
        cout << "ARE YOU A USER OR ADMIN ?\n\n";
        getline(cin, person);
        if (person == "ADMIN")
        {
            string choice;
            cout << "[1]ADD MOVIE\n";
            cout << "[2]DELETE MOVIE\n";
            cout << "[3]EDIT MOVIE\n";
            cout << "[4]SEARCH MOVIE\n";
            cout << "[5]VIEW ALL MOVIES\n";
            cout << "[6]QUIT\n\n";

            cout << "ENTER CHOICE: ";
            getline(cin, choice);
            system("CLS");

            if (choice == "1")
            {
                addMovie(counter); //function call
                continue;
            }
            else if (choice == "2")
            {
                deleteMovie(counter); //function call
                continue;
            }
            else if (choice == "3")
            {
                editMovie(counter); //function call
                continue;
            }
            else if (choice == "4")
            {
                searchMovie(counter); //function call
                continue;
            }
            else if (choice == "5")
            {
                viewAllMovies(counter); //function call
                continue;
            }
            else if (choice == "6")
            {
                quit();
                 //function call
            }
        }
        else if (person == "USER")
        {
            string uchoice;
            cout << "[1]ADD USER\n";
            cout << "[2]EDIT USER\n";
            cout << "[3]ADD BALANCE\n";
            cout << "[4]RENT MOVIE\n";
            cout << "[5]RETURN MOVIES\n";
            cout << "[6]QUIT\n\n";

            cout << "ENTER CHOICE: ";
            getline(cin, uchoice);
            system("CLS");

            if (uchoice == "1")
            {
                add_user(ucounter);
                continue;
            }
            else if (uchoice == "2")
            {
                edit_details(ucounter);
                continue;
            }
            else if (uchoice == "3")
            {
                add_balance(ucounter);
                continue;
            }
            else if (uchoice == "4")
            {
                rent_movie(ucounter);
                continue;
            }
            else if (uchoice == "5")
            {
                return_movie(ucounter);
                continue;
            }
            else if (uchoice == "6")
            {
                quit();
               
            }
        }
    }
}

//addMovie function
void addMovie(int counter)
{
    string movie_id, title, Director, release_date, production, cast;
    int copies, rent;
    cout << "ADD MOVIE\n\n";
    if (counter < 10)
    {
        cout << "Enter Movie ID : ";
        getline(cin, movie_id); //getline - just like cin but includes white spaces
        cout << "Enter Title : ";
        getline(cin, title);
        cout << "Enter Director : ";
        getline(cin, Director);
        cout << "Enter Release Date (Format: Nov 11, 2021 (country)) : ";
        getline(cin, release_date);
        cout << "Enter production : ";
        getline(cin, production);
        cout << "Enter Cast : ";
        getline(cin, cast);
        cout << "Enter the number of copies : " ;
        cin >> copies;
        cout << "Enter the rent of the movie : " ;
        cin >> rent;
        movies[counter].setmovie_id(movie_id); //assigning the values entered to movie object
        movies[counter].setTitle(title);
        movies[counter].setDirector(Director);
        movies[counter].setrelease_date(release_date);
        movies[counter].setproduction(production);
        movies[counter].setcast(cast);
        movies[counter].setcopies(copies);
        movies[counter].setrent(rent);
        increment(counter); //calling function to increment counter
        cout << "\nMOVIE ADDED SUCCESSFULLY!\n\nPress any key to continue . . .";
        _getch();
        main();
    }
    else
    {
        cout << "YOU HAVE REACHED THE MAXIMUM NUMBER OF MOVIES TO BE ADDED!\n\nPress any key to continue . . .";
        _getch();
    }
}

//deleteMovie function

void deleteMovie(int counter)
{
    string movie_id;
    int choice;
    cout << "DELETE MOVIE\n\n";
    if (counter == 0)
    {
        cout << "THERE IS NO MOVIE TO DELETE!\n\nPress any key to continue . . .";
        _getch();
    }
    cout << "Enter movie_id: ";
    getline(cin, movie_id);

    for (int i = 0; i < counter; i++)
    {
        //finding a match using for loop
        if (movies[i].getmovie_id() == movie_id)
        {
            cout << "\nMOVIE FOUND\n\n";
            cout << "Do you want to delete?\n[1]Yes\n[2]No\n\nEnter Choice : ";
            cin >> choice;
            if (choice == 1)
            {
                movies[i].setmovie_id(""); //setting the value to none
                movies[i].setTitle("");
                movies[i].setDirector("");
                movies[i].setrelease_date("");
                movies[i].setproduction("");
                movies[i].setcast("");
                movies[i].setcopies(0);
                movies[i].setrent(0);
                for (int a = i; a < counter; a++)
                {
                    //adjusting the values after deletion of data eg. data from movie[4] copied to movie[3]
                    movies[a] = movies[a + 1];
                }
                movies[9].setmovie_id(""); //adjustment if the library is full(10 movies)
                movies[9].setTitle("");
                movies[9].setDirector("");
                movies[9].setrelease_date("");
                movies[9].setproduction("");
                movies[9].setcast("");
                movies[9].setcopies(0);
                movies[9].setrent(0);
                decrement(counter); //calling function to decrement counter
                cout << "\nMOVIE SUCCESSFULLY DELETED!\n\nPress any key to continue . . .";
                _getch();
            }
            else
            {
                cout<<"Nothing is deleted.Press any key to continue . . ."<<endl;
                _getch();
                main();
            }
        }
    }
    cout << "\nMOVIE NOT FOUND!\n\nPress any key to continue . . .";
    _getch();
}

// edit movie function
void editMovie(int counter)
{
    system("CLS");
    string editmovie_id, choice;
    string movie_id, title, Director, release_date, production, cast;
    int copies, rent;
    cout << "\nEDIT MOVIE\n\n";
    if (counter == 0)
    {
        cout << "THERE IS NO MOVIE TO EDIT!\n\nPress any key to continue . . .";
        _getch();
    }
    cout << "Enter movie_id: ";
    getline(cin, editmovie_id);
    for (int i = 0; i < counter; i++)
    {
        //finding a match using for loop
        if (movies[i].getmovie_id() == editmovie_id)
        {
            cout << "\nMOVIE FOUND!\n\n";
            cout << "MOVIE_ID: " << movies[i].getmovie_id() << endl;
            cout << "TITLE: " << movies[i].getTitle() << endl;
            cout << "DIRECTOR: " << movies[i].getDirector() << endl;
            cout << "RELEASE DATE: " << movies[i].getrelease_date() << endl;
            cout << "PRODUCTION: " << movies[i].getproduction() << endl;
            cout << "CAST: " << movies[i].getcast() << endl;
            cout << "COPIES AVAILABLE: " << movies[i].getcopies() << endl;
            cout << "RENT OF MOVIE: " << movies[i].getrent() << endl;
            cout << "\nDo you want to edit?\n[1]Yes\n[2]No\n\nEnter choice: ";
            getline(cin, choice);
            if (choice == "1")
            {
                //re-entering values
                cout << "Enter Movie_id: ";
                getline(cin, movie_id);
                cout << "Enter Title: ";
                getline(cin, title);
                cout << "Enter Director: ";
                getline(cin, Director);
                cout << "Enter Release date (Format: Nov 11, 2021 (country)) : ";
                getline(cin, release_date);
                cout << "Enter Production: ";
                getline(cin, production);
                cout << "Enter Cast: ";
                getline(cin, cast);
                cout << "Enter the number of copies: " ;
                cin >> copies;
                cout << "Enter the rent of the movie: " ;
                cin >> rent;
                movies[counter].setmovie_id(movie_id); //assigning the values entered to movie object
                movies[counter].setTitle(title);
                movies[counter].setDirector(Director);
                movies[counter].setrelease_date(release_date);
                movies[counter].setproduction(production);
                movies[counter].setcast(cast);
                movies[counter].setcopies(copies);
                movies[counter].setrent(rent);
                cout << "\nMOVIE INFO EDITED SUCCESSFULLY!\n\nPress any key to continue . . .";
                _getch();
                editMovie(counter); //function call to self
            }
            else
            {
            cout<<"No Changes Done.\n\nPress any key to continue . . ."<<endl;
            _getch();
            main();
            }
        }
    }
    cout << "\nMOVIE NOT FOUND!\n\nPress any key to continue . . .";
    _getch();
}
void searchMovie(int counter)
{
    string movie_id;
    int choice;
    bool print = false; //boolean expression to decide which to print
    cout << "SEARCH MOVIE\n\n";
    if (counter == 0)
    {
        cout << "THERE IS NO MOVIE TO SEARCH!\n\nPress any key to continue . . .";
        _getch();
    }
    cout << "Enter Movie ID: ";
    getline(cin, movie_id);
    for (int i = 0; i < counter; i++)
    {
        //finding a match using for loop
        if (movies[i].getmovie_id() == movie_id)
        {
            cout << "\nMOVIE FOUND!\n\n";
            cout << "MOVIE_ID: " << movies[i].getmovie_id() << endl;
            cout << "TITLE: " << movies[i].getTitle() << endl;
            cout << "DIRECTOR: " << movies[i].getDirector() << endl;
            cout << "RELEASE DATE: " << movies[i].getrelease_date() << endl;
            cout << "PRODUCTION: " << movies[i].getproduction() << endl;
            cout << "CAST: " << movies[i].getcast() << endl;
            cout << "COPIES AVAILABLE: " << movies[i].getcopies() << endl;
            cout << "RENT OF MOVIE: " << movies[i].getrent() << endl;
            print = true;
        }
    }
    if (print)
    {
        cout << "\n\nPress any key to continue . . .";
        _getch();
    }
    //if there's no movie found
    else
    {
        cout << "\nMOVIE NOT FOUND!\n\nPress any key to continue . . .";
        _getch();
    }
}
void viewAllMovies(int counter)
{
    //iterating all the values on the library using movie array
    cout << "VIEW ALL MOVIES\n\n";
    for (int i = 0; i < counter; i++)
    {
        cout << "MOVIE DETAILS\n\n";
        cout << "MOVIE_ID: " << movies[i].getmovie_id() << endl;
        cout << "TITLE: " << movies[i].getTitle() << endl;
        cout << "DIRECTOR: " << movies[i].getDirector() << endl;
        cout << "RELEASE DATE: " << movies[i].getrelease_date() << endl;
        cout << "PRODUCTION: " << movies[i].getproduction() << endl;
        cout << "CAST: " << movies[i].getcast() << endl;
        cout << "COPIES AVAILABLE: " << movies[i].getcopies() << endl;
        cout << "RENT OF MOVIE: " << movies[i].getrent() << endl
             << endl;
    }
    cout << "Press any key to continue . . .";
    _getch();
}
void quit()
{
    //quit function
    _exit(1);
}

//add user function
void add_user(int ucounter)
{
    string user_id, username, user_email, user_number;
    int balance;
    cout << "ADD USER\n\n";
    if (ucounter < 10)
    {
        cout << "Enter user ID: ";
        getline(cin, user_id); //getline - just like cin but includes white spaces
        cout << "Enter username: ";
        getline(cin, username);
        cout << "Enter user_email: ";
        getline(cin, user_email);
        cout << "Enter user_number) : ";
        getline(cin, user_number);
        cout << "Enter balance: ";
        cin >> balance;
        users[ucounter].setuser_id(user_id); //assigning the values entered to movie object
        users[ucounter].setusername(username);
        users[ucounter].setuser_email(user_email);
        users[ucounter].setuser_number(user_number);
        users[ucounter].setbalance(balance);
        uincrement(ucounter); //calling function to increment counter
        cout << "\nUSER ADDED SUCCESSFULLY!\n\nPress any key to continue . . .";
        _getch();
    }
    else
    {
        cout << "YOU HAVE REACHED THE MAXIMUM NUMBER OF MOVIES TO BE ADDED!\n\nPress any key to continue . . .";
        _getch();
    }
}

//edit user details function

void edit_details(int ucounter)
{
    system("CLS");
    string edituser_id, choice;
    int balance;
    string user_id, username, user_email, user_number;
    cout << "\nEDIT USER\n\n";
    if (ucounter == 0)
    {
        cout << "THERE IS NO USER TO EDIT!\n\nPress any key to continue . . .";
        _getch();
    }
    cout << "Enter user_id: ";
    getline(cin, edituser_id);
    for (int i = 0; i < ucounter; i++)
    {
        //finding a match using for loop
        if (users[i].getuser_id() == edituser_id)
        {
            cout << "\nUSER FOUND!\n\n";
            cout << "USER_ID: " << users[i].getuser_id() << endl;
            cout << "USERNAME: " << users[i].getusername() << endl;
            cout << "USER EMAIL: " << users[i].getuser_email() << endl;
            cout << "USER NUMBER : " << users[i].getuser_number() << endl;
            cout << "BALANCE: " << users[i].getbalance() << endl;
            cout << "\nDo you want to edit?\n[1]Yes\n[2]No\n\nEnter choice: ";
            getline(cin, choice);
            if (choice == "1")
            {
                //re-entering values
                cout << "Enter User_id: ";
                getline(cin, user_id);
                cout << "Enter username: ";
                getline(cin, username);
                cout << "Enter user_email: ";
                getline(cin, user_email);
                cout << "Enter user_contact: ";
                getline(cin, user_number);
                cout << "Enter balance: ";
                cin >> balance;
                users[ucounter].setuser_id(user_id);
                users[ucounter].setusername(username);
                users[ucounter].setuser_email(user_email);
                users[ucounter].setuser_number(user_number);
                users[ucounter].setbalance(balance);
                cout << "\nUSER INFO EDITED SUCCESSFULLY!\n\nPress any key to continue . . .";
                _getch();
                edit_details(ucounter); //function call to self
            }
            else
            {
                cout<<"No Changes done.\n\nPress any key to continue . . ."<<endl;
                _getch();
                main();
            }
        }
    }
    cout << "\nMOVIE NOT FOUND!\n\nPress any key to continue . . .";
    _getch();
}

//function to add balance
void add_balance(int ucounter)
{
    string editbalanceuser_id;
    cout << "ENTER YOUR ID: ";
    getline(cin, editbalanceuser_id);
    for (int i = 0; i < ucounter; i++)
    {
        //finding a match using for loop
        if (users[i].getuser_id() == editbalanceuser_id)
        {
            cout << "Your current balance is: " << users[i].balance << endl;
            int amount;
            cout << "Enter the amount you want to add: " << endl;
            cin >> amount;
            users[i].balance = users[i].balance + amount;
            cout << "Balance after addition is: " << users[i].balance << endl;
            cout << "\nBALANCE ADDED SUCCESSFULLY!\n\nPress any key to continue . . .";
            _getch();
        }
        else
        {
            cout << "\nUSER NOT FOUND!\n\nPress any key to continue . . .";
            _getch();
        }
    }
}

void rent_movie(int ucounter)
{
    string youruser_id;
    cout << "ENTER YOUR ID: " ;
    getline(cin, youruser_id);
    for (int i = 0; i < ucounter; i++)
    {
        //finding a match using for loop
        if (users[i].getuser_id() == youruser_id)
        {
            string rent_id;
            cout << "THE MOVIE AVAILABLE ARE: " << endl;
            viewAllMovies(counter);
            cout << "Enter the movie id you want to rent: " << endl;
            getline(cin, rent_id);
            for (int i = 0; i < counter; i++)
            {
                if (movies[i].getmovie_id() == rent_id)
                {
                    if (users[i].balance > movies[i].getrent() && movies[i].getcopies() > 0)
                    {
                        users[i].balance = users[i].balance - movies[i].getrent();
                        movies[i].copies = movies[i].copies - 1;
                        cout << "YOU HAVE SUCCESSFULLY RENTED THE MOVIE . . ." << endl;
                        cout << "Your current balance is: " << users[i].balance;
                        cout << "\n\nPress any key to continue . . .";
                        _getch();
                    }
                    else if (users[i].balance < movies[i].getrent())
                    {
                        cout << "You don't have enough balance." << endl;
                        cout << "Your current balance is: " << users[i].balance << endl;
                    }
                    else if (movies[i].getcopies() < 0)
                    {
                        cout << "There are no copies of the movie you have requested." << endl;
                        cout << "Sorry for the inconvience. Please try again later..." << endl;
                    }
                }
                else
                {
                    cout << "Enter correct movie id!" << endl;
                }
            }
        }
    }
}

void return_movie(int ucounter)
{
    string rent_id;
    cout << "Enter the movie id you want to return: " << endl;
    getline(cin, rent_id);
    for (int i = 0; i < counter; i++)
    {
        if (movies[i].getmovie_id() == rent_id)
        {
            movies[i].copies = movies[i].copies + 1;
            cout << "Thank you for choosing us. Please come again..." << endl;
            cout << "\n\nPress any key to continue . . .";
            _getch();
        }
    }
}