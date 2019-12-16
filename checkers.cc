#include "game.h"
#include "checkers.h"
#include <string>
using namespace std;

namespace main_savitch_14 
{


checkers::checkers()
{
	int i;
	int j;
	blacknum = 12;
	rednum = 12;
	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 8; j++)
		{
			board[j][i].setempty(true);
			board[j][i].setred(false);
			board[j][i].setking(false);
		}
	}
	for(i = 0; i < 3; i++) 
	{
		if(i == 0 || i == 2)
		{
			for(j = 1; j < 8; j = j+2) 
			{
				board[j][i].setempty(false);
				board[j][i].setred(false);
				board[j][i].setking(false);
			}
		}
		else if (i == 1) 
		{
			for(j = 0; j < 8; j = j+2)
			{
				board[j][i].setempty(false);
				board[j][i].setred(false);
				board[j][i].setking(false);
			}
		}
	}
	for(i = 7; i >= 5; i--) 
	{
		if(i == 7 || i == 5) 
		{
			for(j = 0; j < 8; j = j+2)
			{
                board[j][i].setempty(false);
                board[j][i].setred(true);
                board[j][i].setking(false);
			}
		}
		else if (i == 6) 
		{
			for(j = 1; j < 8; j = j+2) 
			{
                board[j][i].setempty(false);
                board[j][i].setred(true);
                board[j][i].setking(false);
			}
		}
	}
}

void checkers::restart() 
{
	checkers();
}

void checkers::display_status() const{
    int i;
    int j;
	char l;
	l = 'A';
	cout << "  ";
	for(i = 1; i <= 8; i++) 
	{
		cout << " " << l << " ";
		l ++;
	}
	cout << endl;

        for(i = 0; i < 8; i ++)
        {
		cout << RESET << i+1 << " ";

                if(i % 2 == 0)
                { 
                    for(j = 0; j < 8; j++)
                    {
                        if(j % 2 == 0)
                        {  
                            cout << B_BLACK;
							board[j][i].output();
                        } 
                        else 
                        { 
                            cout << B_GREEN;
							board[j][i].output();
                        }
                    }
                    cout << RESET << endl;
                }

                else 
                { 
                    for(j = 0; j < 8; j++) 
                    {
                        if(j % 2 == 0) 
                        { 
                            cout << B_GREEN;
							board[j][i].output();
                        } 
                        else 
                        { 
						cout << B_BLACK;
						board[j][i].output();
                    	}
                    }
                    cout << RESET << endl;
                }
        }
}

bool checkers::is_legal(const string& move) const
{
	char x;
	int sone, stwo, eone, etwo;
	x = move[0];
	sone = x - '0';
	sone -= 48;

	x = move[1];
	stwo = x - '0';

	x = move[2];
	eone = x - '0';
	eone -= 48;

	x = move[3];
	etwo = x - '0';

	if(board[sone-1][stwo-1].isempty())
	{
		return false;
	}

	if(!(board[eone-1][etwo-1].isempty()))
	{
        	return false;
	}

	if(!board[sone-1][stwo-1].isking()) 
	{
		if(next_mover() == HUMAN)
		{
			if(board[sone-1][stwo-1].isred())
			{
				if(etwo == stwo-1)
				{
					if(eone == sone-1 || eone == sone+1)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				
				else if(etwo == stwo - 2) 
				{
					if(eone == sone - 2) 
					{
						if(!board[sone-2][stwo-2].isempty()) 
						{
							if(!board[sone-2][stwo-2].isred())
							{
								return true;
							}
							else
							{
								return false;
							}
						}
						else
						{
							return false;
						}
					}
					else if(eone = sone + 2) 
					{
						if(!board[sone][stwo-2].isempty()) 
						{
							if(!board[sone][stwo-2].isred())
							{
								return true;
							}
							else
							{
								return false;
							}
						}
						else
						{
							return false;
						}
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}

		else if(next_mover() == COMPUTER) 
		{
			if(!board[sone-1][stwo-1].isred())
			{
				if(stwo == etwo -1) 
				{
					if(eone == sone-1 || eone == sone+1)
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				
				else if(etwo == stwo + 2)
				{
					if(eone == sone + 2) 
					
					{
						if(!board[sone][stwo].isempty()) 
						{
							if(board[sone][stwo].isred())
							{
								return true;
							}
							else
							{
								return false;
							}
						}
						else
						{
							return false;
						}
					}
					else if(eone == sone - 2)
					{
						if(!board[sone-2][stwo].isempty())
						{
							if(board[sone-2][stwo].isred())
							{
								return true;
							}
							else
							{
								return false;
							}
						}
						else
						{
							return false;
						}
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
	}

	
	else 
	{
		if(next_mover() == HUMAN && !board[sone-1][stwo-1].isred())
		{
			return false;
		}
		if(next_mover() == COMPUTER  && board[sone-1][stwo-1].isred())
		{
			return false;
		}
		if(stwo == etwo - 1 || stwo == etwo+1) 
		{
			if(eone == sone -1 || eone == sone+1)
			{
				return true;
			}
			else
			{
				return false;
			}
			
		} 
		else if(etwo == stwo + 2) 
		{
			if(eone == sone + 2)
			{
				if(!board[sone][stwo].isempty()) 
				{
					if(board[sone-1][stwo-1].isred() != board[sone][stwo].isred())
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			
			else if(eone = sone - 2)
			{
				if(!board[sone-2][stwo].isempty()) 
				{
					if(board[sone-1][stwo-1].isred() != board[sone-2][stwo].isred())
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		} 
		else if (etwo == stwo - 2)
		 {
			if(eone == sone + 2)
			{
				if(!board[sone][stwo-2].isempty()) 
				{
					if(board[sone-1][stwo-1].isred() != board[sone][stwo-2].isred())
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else if(eone == sone -2) 
			{
				if(!board[sone-2][stwo-2].isempty())
				 {
					if(board[sone-1][stwo-1].isred() != board[sone-2][stwo-2].isred())
					{
						return true;
					}
					else
					{
						return false;
					}
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}

	}
}

void checkers::make_move(const string& move)
{
	int sone,stwo,eone,etwo;
	char x;
	space temp;

	x = move[0];
	sone = x - '0';
	sone -= 48;

	x = move[1];
	stwo = x - '0';

	x = move[2];
	eone = x - '0';
	eone -= 48;

	x = move[3];
	etwo = x - '0';

 	temp = board[eone-1][etwo-1];
	board[eone-1][etwo-1] = board[sone-1][stwo-1];
	board[sone-1][stwo-1] = temp;
	if(etwo == 1 || etwo == 8)
	{
		board[eone-1][etwo-1].setking(true);
	}
	if(etwo == stwo - 2)
	{
		if(eone == sone + 2)
		{
			if(board[sone][stwo-2].isred())
			{
				rednum--;
			}
			else
			{
				blacknum--;
			}
			board[sone][stwo-2].setempty(true);
		} 
		else if(eone == sone - 2) 
		{
			if(board[sone-2][stwo-2].isred())
			{
				rednum--;
			}
			else
			{
				blacknum--;
			}
			board[sone-2][stwo-2].setempty(true);
		}
	}
	else if(etwo == stwo + 2)
	{
		if(eone == sone + 2) 
		{
			if(board[sone][stwo].isred())
			{
				rednum--;
			}
			else
			{
				blacknum--;
			}
			board[sone][stwo].setempty(true);
		} 
		else if(eone == sone - 2) 
		{
			if(board[sone-2][stwo].isred())
			{
				rednum--;
			}
			else
			{
				blacknum--;
			}
			board[sone-2][stwo].setempty(true);
		}
	}
	game::make_move(move);
}


bool checkers::is_game_over() const
{
	if(rednum == 0) 
	{
		cout << "Black is the winner!";
		return true;
	} 
	else if(blacknum == 0) 
	{
		cout << "Red is the winner!";
		return true;
	} 
	else
	{
		return false;
	}
}

void checkers::compute_moves(queue<string>& moves)const
{
	string x = "    ";
	char i,j,w,q;
        for(i = '1'; i < '9'; i++) 
        {
                for(j = 'a'; j < 'i'; j++) 
                {
                        for(q = '1'; q < '9'; q++) 
                        {
                                for(w = 'a'; w < 'i'; w++) 
                                {
                                        x[0] = j;
                                        x[1] = i;
                                        x[2] = w;
                                        x[3] = q;
                                        if(is_legal(x))
                                                moves.push(x);
                                }
                        }
                }
        }
}

game::who checkers::winning() const 
{
	if(rednum > blacknum)
	{
		return HUMAN;
	}
	else if(blacknum > rednum)
	{
		return COMPUTER;
	}
	else
	{
		return NEUTRAL;
	}
}

int checkers::evaluate()const
{
	return blacknum - rednum;
}

game* checkers::clone() const 
{
	return new checkers(*this);
}

}
