package onlinejudge;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.GridLayout;
import java.awt.Image;

import javax.swing.BorderFactory;
import javax.swing.BoxLayout;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class boardGUI {
	board boardpointer;
	JFrame frame=new JFrame();
	JPanel mainFrame=new JPanel();
	JPanel 	header=new JPanel();
	JPanel 	playerdetails=new JPanel();
	JPanel 	player1=new JPanel();
	JPanel 	player2=new JPanel();

	JLabel gamename,player1details,player2details,player1name,player2name,player1roll,player2roll,player1branch,player2branch;
	JPanel statusbar=new JPanel();
	JLabel redballs,blackballs,status;
	private int redball=0,blackball=0;
	private String curstatus="nothing";
	private panel board[][]=new panel[5][5];
	 public String p1header="  player 1   ",p2header="  player 2   ",p1name="nill",p2name="nill",p1roll="00",p2roll="00",p1branch="--",p2branch="--";
	
	 public boardGUI(board b,JFrame f)
	{//frame=f;
		 this.boardpointer=b;
		initializeBoard();
	}
	
private void initializeBoard()
{
int i,j;
//String song;

gamename = new JLabel("Time Starts now", JLabel.CENTER);
gamename.setFont(new Font("SERIF", Font.BOLD, 30));
gamename.setText("Clash Of Clans");

//name.setBackground(Color.darkGray);
//labeling
player1details = new JLabel("Time Starts now", JLabel.CENTER);
player1details.setFont(new Font("SERIF", Font.BOLD, 20));
player1details.setText(p1header);
player1details.setForeground(Color.red);

player2details = new JLabel("Time Starts now", JLabel.CENTER);
player2details.setFont(new Font("SERIF", Font.BOLD, 20));
player2details.setText(p2header);
player2details.setForeground(Color.black);

player1name = new JLabel("Time Starts now", JLabel.CENTER);
player1name.setFont(new Font("SERIF", Font.BOLD, 15));
player1name.setText("name-"+p1name);


player2name = new JLabel("Time Starts now", JLabel.CENTER);
player2name.setFont(new Font("SERIF", Font.BOLD, 15));
player2name.setText("name-"+p2name);


player1roll = new JLabel("Time Starts now", JLabel.CENTER);
player1roll.setFont(new Font("SERIF", Font.BOLD, 15));
player1roll.setText("rollno-"+p1roll);


player2roll = new JLabel("Time Starts now", JLabel.CENTER);
player2roll.setFont(new Font("SERIF", Font.BOLD, 15));
player2roll.setText("rollno-"+p2roll);

player1branch = new JLabel("Time Starts now", JLabel.CENTER);
player1branch.setFont(new Font("SERIF", Font.BOLD, 15));
player1branch.setText("branch-"+p1branch);


player2branch = new JLabel("Time Starts now", JLabel.CENTER);
player2branch.setFont(new Font("SERIF", Font.BOLD, 15));
player2branch.setText("branch"+p2branch);

redballs = new JLabel("Time Starts now", JLabel.CENTER);
redballs.setFont(new Font("SERIF", Font.BOLD, 15));
redballs.setText("red-"+redball);
redballs.setForeground(Color.red);

blackballs = new JLabel("Time Starts now", JLabel.CENTER);
blackballs.setFont(new Font("SERIF", Font.BOLD, 15));
blackballs.setText("black-"+blackball);
blackballs.setForeground(Color.black);
blackballs.setBorder(BorderFactory.createLoweredBevelBorder());

status = new JLabel("Time Starts now", JLabel.CENTER);
status.setFont(new Font("SERIF", Font.BOLD, 15));
status.setText("status-"+curstatus);
statusbar.setPreferredSize(new Dimension(10,50));
//name = new JLabel("Time Starts now", JLabel.CENTER);
//setting layoout
player1.setLayout(new GridLayout(4,0));
player2.setLayout(new GridLayout(4,0));
playerdetails.setLayout(new GridLayout(2,0));
statusbar.setLayout(new GridLayout(0,3));
mainFrame.setLayout(new GridLayout(5,5));	

//bordering
header.setBorder(BorderFactory.createLoweredBevelBorder());
player1.setBorder(BorderFactory.createLoweredBevelBorder());
player2.setBorder(BorderFactory.createLoweredBevelBorder());
blackballs.setBorder(BorderFactory.createLoweredBevelBorder());
//header.setName("Clash Of Clans");

//adding

for( i=0;i<=4;i++)
{for( j=0;j<=4;j++)
{
	board[i][j]=new panel(i,j);
	board[i][j].setBorder(BorderFactory.createLineBorder(Color.black,3));
	board[i][j].setBackground(Color.black);
	//JLabel lb=new JLabel(new ImageIcon("red1.png"));
	//lb.setIcon(new ImageIcon("red1.png"));
//	board[i][j].add(lb);
mainFrame.add(board[i][j]);
}
	}

header.add(gamename);
player1.add(player1details);
player1.add(player1name);
player1.add(player1roll);
player1.add(player1branch);

player2.add(player2details);
player2.add(player2name);
player2.add(player2roll);
player2.add(player2branch);

playerdetails.add(player1);
playerdetails.add(player2);
statusbar.add(redballs);
statusbar.add(blackballs);
statusbar.add(status);


fixframe();
}
public void fixframe()
{//frame.removeAll();

frame.getContentPane().add(BorderLayout.NORTH,header);
frame.getContentPane().add(BorderLayout.WEST,playerdetails);
frame.getContentPane().add(BorderLayout.CENTER,mainFrame);
frame.getContentPane().add(BorderLayout.SOUTH,statusbar);
//mainFrame.add(new JButton("dvdf"));

}

public void setdetails(String n1,String n2,String r1,String r2)
{
	p1name=n1;
	p2name=n2;
	p1roll=r1;
	p2roll=r2;
}
public JFrame returnframe()
{return frame;}

public void askforrepaint()
{mainFrame.repaint();
frame.repaint();
playerdetails.repaint();
	}

public void updatecounter(int a,int b)
{redball=a;
blackball=b;
redballs.setText("red-"+redball);
blackballs.setText("black-"+blackball);
	}

public void updatestatus(String statusstr)
{this.curstatus=statusstr;
status.setText("status-"+curstatus);
player1name.setText("name-"+p1name);
player2name.setText("name-"+p2name);
player1roll.setText("roll-"+p1roll);
player2roll.setText("roll-"+p2roll);
mainFrame.repaint();
playerdetails.repaint();
	}


public void selectbox(int x,int y,int player)
{
	if(player==1)
board[x][y].setBorder(BorderFactory.createLineBorder(Color.red,6));
	else
		board[x][y].setBorder(BorderFactory.createLineBorder(Color.black,6));
}

public void deselectbox(int x,int y)
{
	
board[x][y].setBorder(BorderFactory.createLineBorder(Color.black,3));
	
}

	class panel extends JPanel{
		
		private static final long serialVersionUID = 1L;
		int x,y;
		Image img;
		public panel(int x,int y)//this panel passing solve problem of using single paintcomponent and class by multiple  panel
		{this.x=x;this.y=y;}
		
		public void paintComponent(Graphics g)
		
		{//magic happens here!! awesome workaround for a massive problem
			int color=boardpointer.getExtractedColor(x, y);
		int quantity=	boardpointer.getExtractedQuantity(x, y);
		if(color==1)
		{
			if(quantity==1)
				img = new ImageIcon("red1.png").getImage() ;	
			else if(quantity==2)
				 img = new ImageIcon("red2.png").getImage() ;	
			else if(quantity==3)
				 img = new ImageIcon("red3.png").getImage() ;	
		}
		else if(color==2)
		{
			if(quantity==1)
				img = new ImageIcon("black1.png").getImage() ;	
			else if(quantity==2)
				 img = new ImageIcon("black2.png").getImage() ;	
			else if(quantity==3)
				 img = new ImageIcon("black3.png").getImage() ;	
			
		}
		else 
			img = new ImageIcon("nill.png").getImage() ;	
			
			//img = new ImageIcon("black1.png").getImage() ;
			//g.getClass().getResource(curstatus);
		     g.drawImage(img,0,0,this.getWidth(),this.getHeight(),this);
			
		}
		
	}
	

}
