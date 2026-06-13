#include <iostream>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <conio.h>
#include <cctype> 
/*  **Variables and funtions of the game**
Here the variable n is used for the size of the box/the size of the arena for the snake to move in
box is the square string array for it(it will also be used to build the whole arena for printing)
The function build will be where this whole will be build.... it will just be a string array which will keep cghanging the valu on depending on the circumstancs
*/
/*  **Level mechanics for the game**
The basic mechanic for increasing the defficulty for the game is to just change the size(initial=3, every increment will be done by 2 to keep the size odd, and the map symmetrical, so that the snake(initially will start as a single block)to be at the absolute centre of the whole map)
Also, the speed of the snake will increase after every level
*/
using namespace std;
int level=1;
int total=0;
/*------------------------------Fruit spawner-----------------------------------*/
void fruit(vector <vector<string> >& board, int *p)
{
	int x_axis_fruit;
	int y_axis_fruit;
	bool temp =true;
	while(temp)
	{
		x_axis_fruit=rand()%(*p);
		y_axis_fruit=rand()%(*p);
		if(board[x_axis_fruit][y_axis_fruit]==" . ")
		{
			board[x_axis_fruit][y_axis_fruit]=" F ";
			temp=false;
		}
	}
}

/* -----------------------------Printing----------------------------------------*/
void print(vector <vector<string> >& board, int *p, int *level)
{
	system("cls");
	int n=*p;
	cout<<"Level:-"<<*level<<endl;
	cout<<" ";
		for(int j=0;j<n;j++)//first ,line for the board's top
		{
			cout<<"---";
		}
		cout<<""<<endl;
		for(int i=0;i<n;i++)//this is for printing the boad for the game
		{
			cout<<"|";
			for(int j=0;j<n;j++)
			{
				cout<<board[i][j];
			}
			cout<<"|"<<endl;
			
		}
		cout<<" ";
		for(int j=0;j<n;j++)
		{
			cout<<"---";
		}
		cout<<""<<endl;
}
/*--------------------------Self collision test-----------------------------*/
bool check(vector <vector <int> > &pos)
{
	if(pos.size()>2)
	{
	
		for(int i=1;i<pos.size();i++)
		{
			if(pos[i][0]==pos[0][0]&&pos[i][1]==pos[0][1])
			{
				return true;
			}	
		}
	}
	return false;
}
/*--------------------------Movement of the snake---------------------------*/
int movement(vector <vector<string> >& board, char *head_dir, vector <vector <int> >& pos, char *new_dir, bool *game_over, int *n, bool *playing, int *total,int *level)
{

	for(int i=0;i<pos.size();i++)
	{
		board[pos[i][0]][pos[i][1]]=" . ";
	}
	int a=pos[0][0];int b=pos[0][1];
	if(*head_dir==*new_dir)
	{
		if(*new_dir=='w')
		{
			*head_dir=*new_dir;
			pos.insert(pos.begin(), vector<int>{a-1,b});
		}
		else if(*new_dir=='a')
		{
			*head_dir=*new_dir;
			pos.insert(pos.begin(), vector<int>{a,b-1});	
		}
		else if(*new_dir=='s')
		{
			*head_dir=*new_dir;
			pos.insert(pos.begin(), vector<int>{a+1,b});
		}
		else if(*new_dir=='d')
		{
			*head_dir=*new_dir;
			pos.insert(pos.begin(), vector<int>{a,b+1});
		}
	}
	else if(*head_dir=='w'&&*new_dir=='s')
	{
			pos.insert(pos.begin(), vector<int>{a-1,b});
	}
	else if(*head_dir=='a'&&*new_dir=='d')
	{
		pos.insert(pos.begin(), vector<int>{a,b-1});	
	}
	else if(*head_dir=='s'&&*new_dir=='w')
	{
		pos.insert(pos.begin(), vector<int>{a+1,b});
	}
	else if(*head_dir=='d'&&*new_dir=='a')
	{
			pos.insert(pos.begin(), vector<int>{a,b+1});
	}
	else if(*new_dir=='w')
	{
		*head_dir=*new_dir;
		pos.insert(pos.begin(), vector<int>{a-1,b});
	}
	else if(*new_dir=='a')
	{
		*head_dir=*new_dir;
		pos.insert(pos.begin(), vector<int>{a,b-1});	
	}
	else if(*new_dir=='s')
	{
		*head_dir=*new_dir;
		pos.insert(pos.begin(), vector<int>{a+1,b});
	}
	else if(*new_dir=='d')
	{
		*head_dir=*new_dir;
		pos.insert(pos.begin(), vector<int>{a,b+1});
	}
	
	
	
	
	bool checking=check(pos);
	
	if(checking&&*total!=((*n)*(*n)))
	{
		*game_over=true;
		cout<<"Game over!!!\nYour total score was "<<(*level*10)+*total<<"\n Do you want to play again? \n Enter yes or no\n";
		string choice;
		bool re=true;
		while(re)
		{
			string choice;
			cin>>choice;
			for (char &c : choice) 
			{
   	     		c = std::tolower(static_cast<unsigned char>(c));
	    	}
			if(choice=="yes")
			{
				*playing=true;
				cout<<"Restarting\n";
				Sleep(1000);
				re=false;
			}
			else if(choice=="no")
			{
				*playing=false;
				re=false;
			}
			else
			{
				cout<<"Wrong input, please enter again\n";
				re=true;
			}
		}
	}
	else if(pos[0][0]>=*n||pos[0][1]>=*n||pos[0][0]<0||pos[0][1]<0&&*total!=((*n)*(*n)))
	{
		*game_over=true;
		cout<<"Game over!!!\n Do you want to play again? \n Enter yes or no\n";
		bool re=true;
		while(re)
		{
			string choice;
			cin>>choice;
			for (char &c : choice) 
			{
   	     		c = std::tolower(static_cast<unsigned char>(c));
	    	}
			if(choice=="yes")
			{
				*playing=true;
				cout<<"Restarting\n";
				Sleep(1000);
				re=false;
			}
			else if(choice=="no")
			{
				*playing=false;
				re=false;
			}
			else
			{
				cout<<"Wrong input, please enter again\n";
				re=true;
			}
		}
	}
	else if(board[pos[0][0]][pos[0][1]]==" F ")
	{
		
		*total++;
		board[pos[0][0]][pos[0][1]]=" H ";
		for(int i=1;i<pos.size();i++)
		{
			board[pos[i][0]][pos[i][1]]=" S ";
		}
		fruit(board,n);		
	}
	
	else if(board[pos[0][0]][pos[0][1]]==" . ")
	{
		board[pos[0][0]][pos[0][1]]=" H ";
		pos.pop_back();
		for(int i=1;i<pos.size();i++)
		{
			board[pos[i][0]][pos[i][1]]=" S ";
		}	
	}
} 

/*-------Main body for the execution of everything with the logic-----------*/
bool build(int n, bool ne_level, bool playing)
{
	if(playing)
	{
		
		vector <vector <string> > board(n,vector <string>(n," . "));//this is the board
		board[(n-1)/2][(n-1)/2]=" H ";
		fruit( board,  &n);	
		char head_dir='s';
		vector <vector <int> > pos;
		pos.push_back({(n-1)/2,(n-1)/2});
		char new_dir;
		print( board, &n, &level);
		bool game_over=false;
		while(playing)
		{
			while(_kbhit())
			{
    			_getch();
			}
			Sleep(700);				
			if(_kbhit())
			{
				new_dir=_getch();
			}
			else
			{
				new_dir=head_dir;
			}			
			
			movement(board, &head_dir, pos, &new_dir, &game_over,&n, &playing,&total,&level);
			print( board, &n,&level);
			if(total==n*n)
			{
				cout<<"Do you want to continue to the next level?\n";
				bool re=true;
				while(re)
				{
					string choice;
					cin>>choice;
					for (char &c : choice) 
					{
   			     		c = std::tolower(static_cast<unsigned char>(c));
	    			}
					if(choice=="yes")
					{
						level++;
						cout<<"Starting the next level\n";
						Sleep(1000);
						build(n+2, false, true);
					}
					else if(choice=="no")
					{
						playing=false;
						re=false;
					}
					else
					{
						cout<<"Wrong input, please enter again\n";
						re=true;
					}
				}
				
			}
			if(game_over&&playing)
			{
				build(n, false, true);
			}
			else if(game_over&&!playing)
			{
				cout<<"Thanks for playing\n";
				continue;
			}
    	}
		
	}
	
}

int main()
{
	int n=9;
	build(n,true, true);

}


