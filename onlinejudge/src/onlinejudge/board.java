package onlinejudge;

import java.util.ArrayList;

import javax.swing.JFrame;

public class board {
	public boolean invalidmove=false;
	public  int currentPlayerCode;
	public static int boardname[][];
	public static int gameTurns=0;
	public static int winnerno=0;
	public static boolean winner=false;
	public ArrayList<affectedBox> al=new ArrayList<affectedBox>();
	public boardGUI boardgui;
	
	public board(JFrame f)
	{System.out.println("asdsffgd\n");
		boardname=new int[5][5];
		
		boardgui=new boardGUI(this,f);
		
	}
	
	public void reset()
	{gameTurns=0;
	winner=false;
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<5;j++)
			{boardname[i][j]=0;}
		}
		
	}
	public void play(int x,int y,int player)
	{gameTurns++;
		boardgui.updatestatus("waiting for player"+player+"..");
		System.out.println("problem while making a thread sleep");
		currentPlayerCode=player;
		int color=getExtractedColor(x,y);
		int quantity=getExtractedQuantity(x,y);
		int n=3;
		if((color==player)||(color==0))
		{
			color=player;
			quantity++;
			boardname[x][y]=((color*10)+quantity);
			boardgui.askforrepaint();
			boardgui.updatecounter(count_color(1),count_color(2));
			boardgui.updatestatus("player"+player+" played "+x+" and "+y+"..");
			while(n-->0)
			{boardgui.selectbox(x, y, player);
			try{Thread.sleep(50);}
	      	catch(Exception ex)
	      	{System.out.println("problem while making a thread sleep");}
			boardgui.deselectbox(x, y);	
			try{Thread.sleep(50);}
	      	catch(Exception ex)
	      	{System.out.println("problem while making a thread sleep");
			}}
		
			System.out.println(boardname[x][y]);
			takeaction(x,y);	
			
		}
		else 
		invalidmove=true;
	//	boardgui.frame.setVisible(false);
	}
	
	public void playafteronce(int x,int y,int player)
	{//boardgui.updatestatus("waiting for player"+player+"..");
		currentPlayerCode=player;
		int color=getExtractedColor(x,y);
		int quantity=getExtractedQuantity(x,y);
		
		//if((color==player)||(color==0))
		//{
			color=player;
			quantity++;
			boardname[x][y]=((color*10)+quantity);
			boardgui.askforrepaint();
			boardgui.updatecounter(count_color(1),count_color(2));
		//	boardgui.updatestatus("player"+player+" played"+x+" "+y+"..");
			
			boardgui.selectbox(x, y, player);
			try{Thread.sleep(100);}
	      	catch(Exception ex)
	      	{System.out.println("problem while making a thread sleep");}
			boardgui.deselectbox(x, y);
			System.out.println(boardname[x][y]);
			takeaction(x,y);	
			
	//	}
		//else 
		//invalidmove=true;
		
	}
	
	
	
	public int count_color(int num)
	{int count=0;
		for(int i=0;i<=4;i++)
		{
			for(int j=0;j<=4;j++)
			{
				int color=this.getExtractedColor(i, j);
				if(color==num)
				{
					count+=this.getExtractedQuantity(i, j);
				}
			}
			}
		return count;
	}
	//publiv bcoz boardgui use it to paint
	public int getExtractedColor(int x,int y)
	{
		return((boardname[x][y])/10);
		
	}
	//publiv bcoz boardgui use it to paint
	public  int getExtractedQuantity(int x,int y)
	{
		return((boardname[x][y])%10);
		
	}
	
	
	private void takeaction(int x,int y)
	{makeWinner();
		System.out.println(x+" "+y);
		int boundary;
	if(((x==0)&&(y==0))||((x==4)&&(y==0))||((y==4)&&(x==4))||((x==0)&&(y==4)))
		boundary=1;
	else if((x==0)||(y==0)||(x==4)||(y==4))
		boundary=2;
		
	else boundary=3;
	
	int quantity=getExtractedQuantity(x,y);
	System.out.println(quantity);
	if(quantity>boundary)
	{boardname[x][y]=0;	
	boardgui.askforrepaint();
	boardgui.updatecounter(count_color(1),count_color(2));
	boardgui.updatestatus(x+","+y+"bursts..");
	boardgui.selectbox(x, y, currentPlayerCode);
	try{Thread.sleep(100);}
  	catch(Exception ex)
  	{System.out.println("problem while making a thread sleep");}
	boardgui.deselectbox(x, y);
	//System.out.println(boardname[x][y]);
	al.add(new affectedBox((x-1),y));//right now just pass them runarray will take care of out of bound array
	al.add(new affectedBox((x+1),y));
	al.add(new affectedBox(x,(y-1)));
	al.add(new affectedBox(x,(y+1)));
	runArray();
	
	}
	
	}
	
	
	
	private void runArray()
	{
		while((!(al.isEmpty()))&&(!winner))
		{	affectedBox ab = al.get(0);
		al.remove(0);
		checkandPlay(ab.getx(),ab.gety());
		
		}
		if(winner)
		{boardgui.updatestatus("player "+winnerno+" wins!!!");}
		
		
	}
	
	private void checkandPlay(int x,int y)
	{
		if((x<=4)&&(y<=4)&&(x>=0)&&(y>=0))
		playafteronce(x,y,currentPlayerCode);
	}
	
	private void makeWinner()
	{int firstplayer=0,secondplayer=0;

	
			int countred=count_color(1);
			int countblue=count_color(2);
			
				if(gameTurns>2)
				{
					 if(countred==0)
					  { winnerno=2;
					  winner=true;
					  }
					  
					     else if(countblue==0)
					     { winnerno=1;
						  winner=true;
						  }	
					
				}
			
				if(winner)
				{
					boardgui.updatestatus("player "+winnerno+" wins!!!");
				}
		}
		
	
	public  boolean checkwinner()
	{
		return winner;	//0 1 or 2 will be the returned value 
	}
	
	public class affectedBox
	{int x,y;
	
		public  affectedBox(int x,int y)
		{this.x=x;
		this.y=y;
		}
		
		private int getx()
		{return x;
		}
		
		private int gety()
		{return y;
		}
	}
	
	
	public boolean checkinvalidmove()
	{return invalidmove;}
	
	
	public int[][] getCurrentBoard()
	{
		return (boardname);
		
	}
	
	public boardGUI getgui()
	{return boardgui;}//return ref that controls the gui of board to processing for status updte
}

