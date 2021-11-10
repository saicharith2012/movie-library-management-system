#include<iostream> 
#include<conio.h>
#include<string>

using namespace std;

class Movie {
	private:
		string movie_id,title,Director,release_date,production,cast; //private variables
	public:
		//setters - assigning user value to private variables
		void setmovie_id(string a){movie_id = a;}
		void setTitle(string b){title = b;}
		void setDirector(string c){Director = c;}
		void setrelease_date(string d){release_date = d;}
		void setproduction(string e){production = e;}
		void setcast(string f){cast = f;}
		
		//getters - getting the values from private variables
		string getmovie_id(){return movie_id;}
		string getTitle(){return title;}
		string getDirector(){return Director;}
		string getrelease_date(){return release_date;}
		string getproduction(){return production;}
		string getcast(){return cast;}
};

//initializing functions with counter as parameter
void addMovie(int counter);
void deleteMovie(int counter);
void editMovie(int counter);
void searchMovie(int counter);
void viewAllMovies(int counter);
void quit();

//counter for Movie array
int counter=0;

//function for incrementing counter
void increment(int a){
	a++;
	counter=a;
}

//function for decrementing counter
void decrement(int a){
	a--;
	counter=a;
}

//Movie class array initialization
Movie movies[10];

//main function
int main(){
string choice;
//Main Menu
system("CLS");
cout<<"LIBRARY MANAGEMENT SYSTEM\n\n";
cout<<"[1]ADD MOVIE\n";	
cout<<"[2]DELETE MOVIE\n";	
cout<<"[3]EDIT MOVIE\n";	
cout<<"[4]SEARCH MOVIE\n";	
cout<<"[5]VIEW ALL MOVIES\n";	
cout<<"[6]QUIT\n\n";

cout<<"ENTER CHOICE: ";
getline(cin,choice);
system("CLS");

if(choice=="1"){
	addMovie(counter); //function call
}		
else if(choice=="2"){	
	deleteMovie(counter); //function call
}
else if(choice=="3"){
	editMovie(counter); //function call	
}
else if(choice=="4"){
	searchMovie(counter); //function call	
}
else if(choice=="5"){
	viewAllMovies(counter); //function call	
}
else if(choice=="6"){
	quit();	 //function call
}
else{
	main();  //function call to self(main)
}
	
_getch();
return 0;
}


//addMovie function
void addMovie(int counter){
	string movie_id,title,Director,release_date,production,cast;
	cout<<"ADD MOVIE\n\n";
	if(counter<10){
		cout<<"Enter Movie ID: ";
		getline(cin,movie_id); //getline - just like cin but includes white spaces
		cout<<"Enter Title: ";
		getline(cin,title);
		cout<<"Enter Director: ";
		getline(cin,Director);
		cout<<"Enter Release Date (Format: Nov 11, 2021 (country)) : ";
		getline(cin,release_date);
		cout<<"Enter production: ";
		getline(cin,production);
		cout<<"Enter Cast: ";
		getline(cin,cast);
		movies[counter].setmovie_id(movie_id); //assigning the values entered to movie object
		movies[counter].setTitle(title);
		movies[counter].setDirector(Director);
		movies[counter].setrelease_date(release_date);
		movies[counter].setproduction(production);	
		movies[counter].setcast(cast);	
		increment(counter);	//calling function to increment counter
		cout<<"\nMOVIE ADDED SUCCESSFULLY!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	else{
		cout<<"YOU HAVE REACHED THE MAXIMUM NUMBER OF MOVIES TO BE ADDED!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
}

//deleteMovie function
void deleteMovie(int counter){
	string movie_id;
	int choice;
	cout<<"DELETE MOVIE\n\n";
	if(counter==0){
		cout<<"THERE IS NO MOVIE TO DELETE!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	cout<<"Enter movie_id: ";
	getline(cin,movie_id);

	for(int i=0;i<counter;i++){
		//finding a match using for loop
		if(movies[i].getmovie_id()==movie_id){
			cout<<"\nMOVIE FOUND\n\n";
			cout<<"Do you want to delete?\n[1]Yes\n[2]No\n\nEnter Choice: ";
			cin>>choice;
			if(choice==1){
				movies[i].setmovie_id(""); //setting the value to none
				movies[i].setTitle("");
				movies[i].setDirector("");
				movies[i].setrelease_date("");
				movies[i].setproduction("");
				movies[i].setcast("");
				for(int a=i;a<counter;a++){
					//adjusting the values after deletion of data eg. data from movie[4] copied to movie[3]
					movies[a] = movies[a+1];
				}
				movies[9].setmovie_id(""); //adjustment if the library is full(10 movies)
				movies[9].setTitle("");
				movies[9].setDirector("");
				movies[9].setrelease_date("");
				movies[9].setproduction("");
				movies[9].setcast("");
				decrement(counter); //calling function to decrement counter
				cout<<"\nMOVIE SUCCESSFULLY DELETED!\n\nPress any key to continue . . .";
				_getch();
				main();
			}
			else{
				main();
			}
		}
	}
	cout<<"\nMOVIE NOT FOUND!\n\nPress any key to continue . . .";
	_getch();
	main();
	
}
// edit movie function
void editMovie(int counter){
	system("CLS");
	string editmovie_id,choice;
	string movie_id,title,Director,release_date,production,cast;
	cout<<"\nEDIT MOVIE\n\n";
	if(counter==0){
		cout<<"THERE IS NO MOVIE TO EDIT!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	cout<<"Enter movie_id: ";
	getline(cin,editmovie_id);
	for(int i=0;i<counter;i++){
		//finding a match using for loop
		if(movies[i].getmovie_id()==editmovie_id){
			cout<<"\nMOVIE FOUND!\n\n";
			cout<<"MOVIE_ID: "<<movies[i].getmovie_id()<<endl;
			cout<<"TITLE: "<<movies[i].getTitle()<<endl;
			cout<<"DIRECTOR: "<<movies[i].getDirector()<<endl;
			cout<<"RELEASE DATE : "<<movies[i].getrelease_date()<<endl;
			cout<<"PRODUCTION: "<<movies[i].getproduction()<<endl;
			cout<<"CAST: "<<movies[i].getcast()<<endl;
			cout<<"\nDo you want to edit?\n[1]Yes\n[2]No\n\nEnter choice: ";
			getline(cin,choice);
			if(choice=="1"){
				//re-entering values
				cout<<"Enter Movie_id: ";
				getline(cin,movie_id);
				cout<<"Enter Title: ";
				getline(cin,title);
				cout<<"Enter Director: ";
				getline(cin,Director);
				cout<<"Enter Release date (Format: Nov 11, 2021 (country)) : ";
				getline(cin,release_date);
				cout<<"Enter Production: ";
				getline(cin,production);
				cout<<"Enter Cast: ";
				getline(cin,cast);
				movies[i].setmovie_id(movie_id);
				movies[i].setTitle(title);
				movies[i].setDirector(Director);
				movies[i].setrelease_date(release_date);
				movies[i].setproduction(production);	
				movies[i].setcast(cast);	
				cout<<"\nMOVIE EDITED SUCCESSFULLY!\n\nPress any key to continue . . .";
				_getch();
				editMovie(counter);//function call to self
			}
			else{
				main();
			}			
		}
}
	cout<<"\nMOVIE NOT FOUND!\n\nPress any key to continue . . .";
	_getch();
	main();
}
void searchMovie(int counter){
	string movie_id;
	int choice;
	bool print = false; //boolean expression to decide which to print
	cout<<"SEARCH MOVIE\n\n";
	if(counter==0){
		cout<<"THERE IS NO MOVIE TO SEARCH!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	cout<<"Enter Movie ID: ";
	getline(cin,movie_id);
	for(int i=0;i<counter;i++){
		//finding a match using for loop
		if(movies[i].getmovie_id()==movie_id){ 
			cout<<"\nMOVIE FOUND!\n\n";
			cout<<"MOVIE_ID: "<<movies[i].getmovie_id()<<endl;
			cout<<"TITLE: "<<movies[i].getTitle()<<endl;
			cout<<"DIRECTOR: "<<movies[i].getDirector()<<endl;
			cout<<"RELEASE DATE: "<<movies[i].getrelease_date()<<endl;
			cout<<"PRODUCTION: "<<movies[i].getproduction()<<endl;
			cout<<"CAST: "<<movies[i].getcast()<<endl;
			print = true;
		}
	}
	if(print){
		cout<<"\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	//if there's no movie found
	else{
		cout<<"\nMOVIE NOT FOUND!\n\nPress any key to continue . . .";
		_getch();
		main();		
	}
}
void viewAllMovies(int counter){
	//iterating all the values on the library using movie array
	cout<<"VIEW ALL MOVIES\n\n";
	for(int i=0;i<counter;i++){
		cout<<"MOVIE DETAILS\n\n";
		cout<<"MOVIE_ID: "<<movies[i].getmovie_id()<<endl;
		cout<<"TITLE: "<<movies[i].getTitle()<<endl;
		cout<<"DIRECTOR: "<<movies[i].getDirector()<<endl;
		cout<<"RELEASE DATE: "<<movies[i].getrelease_date()<<endl;
		cout<<"PRODUCTION: "<<movies[i].getproduction()<<endl;
		cout<<"CAST: "<<movies[i].getcast()<<endl<<endl;
	}
	cout<<"Press any key to continue . . .";
	_getch();
	main();
}
void quit(){
	//quit function
	_exit(1);
}

