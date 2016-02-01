package onlinejudge;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.GridLayout;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.AdjustmentEvent;
import java.awt.event.AdjustmentListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

import javax.swing.BorderFactory;
import javax.swing.BoxLayout;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollBar;
import javax.swing.JScrollPane;
import javax.swing.ScrollPaneConstants;

public class fixmatch extends MouseAdapter implements Runnable {
	//just override mouseclicked
	JFrame frame=new JFrame() ;
	JPanel mainFrame=new JPanel();
	JPanel 	header=new JPanel();
	JPanel 	leftlistouter=new JPanel();
	JPanel 	rightlistouter=new JPanel();
	JPanel 	leftlistinner=new JPanel();
	JPanel 	rightlistinner=new JPanel();
     JPanel buttonpanel=new JPanel();
	JButton war=new JButton();
	JButton moveright=new JButton();
	JButton moveleft=new JButton();
	JButton stopknockout=new JButton();
	ArrayList<String> playernames=new ArrayList<String>();
	ArrayList<String> playerroll=new ArrayList<String>();
	ArrayList<String> playermail=new ArrayList<String>();
	ArrayList<panel> leftlist=new ArrayList<panel>();
	ArrayList<panel> rightlist=new ArrayList<panel>();
	ArrayList<String> codefileaddress=new ArrayList<String>();
	 private String softwarepath,codefolderaddress;
	private File codefolder;
	public static  boolean knockout=true;
	panel firstselected=null;
	panel secondselected=null;
	public int selected=0,firstselectedno=-1,secondselectedno=-1,firstlistitemcounter=0,secondlistitemcounter=0;
    private JLabel gamename,leftlistheader,rightlistheader,warbuttonlabel,moveleftlabel,moverightlabel,knockoutbuttonlabel;

public ProcessFile processfileref;
public fixmatch(ProcessFile p,JFrame f)
{
	//frame=f;
	processfileref=p;
	getfiles();
	//adddummy();
	initialize();
}
public void run()
{getfiles();
//adddummy();
initialize();}
public void getfiles()
{
String softwarepath=System.getProperty("user.dir");	
System.out.println(softwarepath);
codefolderaddress=softwarepath+"/code";
codefolder=new File(codefolderaddress);

File[] codefilelist=codefolder.listFiles();

for(File f:codefilelist)
{
	//System.out.println("df");
	String filename=f.getName();
if(isccode(filename))
{//System.out.println(f.getAbsolutePath());
	codefileaddress.add(f.getAbsolutePath());
	askuserdetails(f.getAbsolutePath());
	}
	}
}
private void askuserdetails(String path)
{
	Scanner input=new Scanner(System.in);
	System.out.println(path);
	String name=input.nextLine();
	String rollno=input.nextLine();
	System.out.println(name);
	System.out.println(rollno);
	playernames.add(name);
	playerroll.add(rollno);
	}

private boolean isccode(String filename)
{int lastpoint=filename.lastIndexOf(".");
String exName=filename.substring(lastpoint+1);
if(exName.equals("c"))
	return true;
else 
	return false;

	
}


	private void initialize()
	{
	gamename = new JLabel("Time Starts now", JLabel.CENTER);
	gamename.setFont(new Font("SERIF", Font.BOLD, 30));
	gamename.setText("Clash Of Clans");
	
	leftlistheader = new JLabel("Time Starts now", JLabel.CENTER);
	leftlistheader.setFont(new Font("SERIF", Font.BOLD, 30));
	leftlistheader.setText("Crazy Battlers");
	

	rightlistheader = new JLabel("Time Starts now", JLabel.CENTER);
	rightlistheader.setFont(new Font("SERIF", Font.BOLD, 30));
	rightlistheader.setText("Better Half");
	
	//button
	warbuttonlabel = new JLabel("Time Starts now", JLabel.CENTER);
	warbuttonlabel.setFont(new Font("SERIF", Font.BOLD, 20));
	warbuttonlabel.setText("Start war");
	
	knockoutbuttonlabel = new JLabel("Time Starts now", JLabel.CENTER);
	knockoutbuttonlabel.setFont(new Font("SERIF", Font.BOLD, 20));
	knockoutbuttonlabel.setText("Stop knockout");
	
	moveleftlabel = new JLabel("Time Starts now", JLabel.CENTER);
	moveleftlabel.setFont(new Font("SERIF", Font.BOLD, 20));
	moveleftlabel.setText("move left");
	
	moverightlabel = new JLabel("Time Starts now", JLabel.CENTER);
	moverightlabel.setFont(new Font("SERIF", Font.BOLD, 20));
	moverightlabel.setText("move right");
	
	
	
	//list1
	int i;
	for(i=0;i<playernames.size();i++)
	{panel p=new panel(playernames.get(i));
	p.addMouseListener(new listener(1,i));
	firstlistitemcounter++;
	p.setBorder(BorderFactory.createLineBorder(Color.black,2));
	p.setBackground(Color.red);
	p.setPreferredSize(new Dimension(490,50));
	p.setMaximumSize(new Dimension(490,50));
	leftlist.add(p);
		leftlistinner.add(p);
		
	}
	
	//list2
	/*int j;
	for(j=0;j<playernames.size();j++)
	{panel q=new panel(playernames.get(j));
	q.addMouseListener(new listener(2,j));
	q.setPreferredSize(new Dimension(40,50));
	//q.add(new JLabel(playernames.get(j),JLabel.CENTER));
	q.setBorder(BorderFactory.createLineBorder(Color.black,2));
	rightlist.add(q);
	
		rightlistinner.add(q);
		
	}*/
	//scrollers
	JScrollPane leftscroll=new JScrollPane(leftlistinner);
	leftscroll.setHorizontalScrollBarPolicy(ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);
	leftscroll.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);
	leftscroll.setPreferredSize(new Dimension(500,500));
	JScrollBar scbarleft=leftscroll.getVerticalScrollBar();
	scbarleft.addAdjustmentListener(new adjust());
	
	
	JScrollPane rightscroll=new JScrollPane(rightlistinner);
	rightscroll.setHorizontalScrollBarPolicy(ScrollPaneConstants.HORIZONTAL_SCROLLBAR_NEVER);
	rightscroll.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_ALWAYS);
rightscroll.setPreferredSize(new Dimension(500,500));
JScrollBar scbarright=rightscroll.getVerticalScrollBar();
scbarright.addAdjustmentListener(new adjust());

//bouutton listening and passing buttinid for distiction at action time
	war.addActionListener(new buttonclass(1));
	moveright.addActionListener(new buttonclass(2));
	moveleft.addActionListener(new buttonclass(3));
stopknockout.addActionListener(new buttonclass(4));
//setting layout
	leftlistinner.setLayout(new BoxLayout(leftlistinner,BoxLayout.Y_AXIS));	
	rightlistinner.setLayout(new BoxLayout(rightlistinner,BoxLayout.Y_AXIS));	
   // leftlistinner.setLayout(new GridLayout(i,0));
	//rightlistinner.setLayout(new GridLayout(j,0));
	mainFrame.setLayout(new GridLayout(0,2));
    buttonpanel.setLayout(new GridLayout(0,4));
    war.setLayout(new GridLayout(0,1));
    moveleft.setLayout(new GridLayout(0,1));
    moveright.setLayout(new GridLayout(0,1));
	
	//bordering
header.setBorder(BorderFactory.createLoweredBevelBorder());
buttonpanel.setBorder(BorderFactory.createLoweredBevelBorder());
//leftscroll.setBorder(BorderFactory.createLoweredBevelBorder());	
//rightscroll.setBorder(BorderFactory.createLoweredBevelBorder());	
leftscroll.setBorder(BorderFactory.createBevelBorder(1, Color.black, Color.gray));
rightscroll.setBorder(BorderFactory.createBevelBorder(1, Color.black, Color.gray));
	//adding
	
	//button
	war.add(warbuttonlabel);
	moveright.add(moverightlabel);
	moveleft.add(moveleftlabel);
	stopknockout.add(knockoutbuttonlabel);
	//header
	header.add(gamename);
	//list
	leftlistouter.add(leftlistheader);
	rightlistouter.add(rightlistheader);
	leftlistouter.add(leftscroll);
	rightlistouter.add(rightscroll);
	
	//buttonpanrl
	buttonpanel.add(moveleft);
	buttonpanel.add(war);

	buttonpanel.add(moveright);
buttonpanel.add(stopknockout);
	//mainframe
	//header.setBackground(Color.red);
	//mainFrame.setBackground(Color.red);
	mainFrame.add(leftlistouter);
	mainFrame.add(rightlistouter);
	
fixframe();
	//layouts

	}
	public JFrame returnframe()
	{return frame;}
	public void fixframe()
	{//frame.removeAll();

	frame.getContentPane().add(BorderLayout.NORTH,header);
		frame.getContentPane().add(BorderLayout.CENTER,mainFrame);
		frame.getContentPane().add(BorderLayout.SOUTH,buttonpanel);
	//frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	//frame.setSize(600,600);
//	frame.setExtendedState(JFrame.MAXIMIZED_BOTH);
//	frame.setVisible(true);
	}
	
	public void killloser(int winner)
	{System.out.println("chk");
		if(knockout)
		{	if(winner==1)
		{	if(firstselected.getParent()==leftlistinner)
		{leftlistinner.remove(secondselected);//dont add anywhere
		firstlistitemcounter--;
	
		leftlistinner.remove(firstselected);
		firstlistitemcounter--;
		
		rightlistinner.add(firstselected);
		secondlistitemcounter++;}
		else
			{
			rightlistinner.remove(secondselected);
			secondlistitemcounter--;
			rightlistinner.remove(firstselected);
			secondlistitemcounter--;
			leftlistinner.add(firstselected);
			firstlistitemcounter++;}}
	else
		
	{if(secondselected.getParent()==leftlistinner)
	{leftlistinner.remove(secondselected);//dont add anywhere
	firstlistitemcounter--;
	leftlistinner.remove(firstselected);
	firstlistitemcounter--;

rightlistinner.add(secondselected);
secondlistitemcounter++;}
else
	{rightlistinner.remove(firstselected);
	secondlistitemcounter--;
	rightlistinner.remove(secondselected);
	secondlistitemcounter--;
	leftlistinner.add(secondselected);
	firstlistitemcounter++;
	}
		
	}}
	resetselection();
	}
	public void resetselection()
	{if(firstselected!=null)
		firstselected.setBorder(BorderFactory.createLineBorder(Color.black,2));
	if(secondselected!=null)	
	secondselected.setBorder(BorderFactory.createLineBorder(Color.black,2));
		firstselected=null;
		secondselected=null;
		firstselectedno=-1;
		secondselectedno=-1;
		selected=0;
		mainFrame.repaint();
	}
	//public void makeiteven
	public void godhelp()
	{
		if((firstselected.getParent()==leftlistinner)&&(secondselected.getParent()==leftlistinner))
		{	 firstselected.setBorder(BorderFactory.createLineBorder(Color.black,4));
			//	frame.getContentPane().removeAll();
		}
		frame.validate();
		frame.repaint();
		mainFrame.repaint();
		try{Thread.sleep(250);
		}
	  	catch(Exception ex)
	  	{System.out.println("problem while making a thread sleep");}
		
				processfileref.setfile(codefileaddress.get(firstselectedno), codefileaddress.get(secondselectedno));
			
			  synchronized(processfileref)
		     {try{ processfileref.notify();
		  	}
		  	catch(Exception ex)
		    	{System.out.println("problem while waiting making a thread sleep");}
		    }
			//	processfileref.startgame();
	}
	
	public String getp1name()
	{return playernames.get(firstselectedno); }
	public String getp2name()
	{return playernames.get(secondselectedno); }
	public String getp1roll()
	{return playerroll.get(firstselectedno); }
	public String getp2roll()
	{return playerroll.get(secondselectedno); }
	
	//override
	
class panel extends JPanel{
		
		private static final long serialVersionUID = 1L;
		int x,y;
		Image img;
		JLabel name=new JLabel();
		public panel(String name)//this panel passing solve problem of using single paintcomponent and class by multiple  panel
		{this.name = new JLabel("Time Starts now", JLabel.CENTER);
		this.name.setFont(new Font("SERIF", Font.BOLD, 30));
		this.name.setText(name);
		this.setLayout(new GridLayout(0,1));
		this.add(this.name);
		}public panel()
		{}
		
		public void paintComponent(Graphics g)
		
		{this.repaint();
		}
		
	
	
}
class listener extends MouseAdapter
{int listno,playerno;
	public listener(int listno,int playerno)
	{
	this.listno=listno;
	this.playerno=playerno;
	
	}
	public listener()
	{super();}
	private void showselectedred(int listno,int plno)
	{panel p;
		if(listno==1)
		{ p=(panel)leftlist.get(plno);
		p.setBorder(BorderFactory.createLineBorder(Color.red,4));
	}
		else
		{
			p=(panel)rightlist.get(plno);
			p.setBorder(BorderFactory.createLineBorder(Color.red,4));
		}
		firstselected=p;
		firstselectedno=plno;
		//System.out.println("red"+firstselectedno);
		selected++;
	}
	
	private void showselectedblack(int listno,int plno)
	{panel p;
		if(listno==1)
		{ p=(panel)leftlist.get(plno);
		}
		else
		{
			 p=(panel)rightlist.get(plno);
		}
		 if(firstselected!=p)
		 {	if(p!=null)
			 p.setBorder(BorderFactory.createLineBorder(Color.black,4));
		secondselected=p;
		secondselectedno=plno;
	
		selected++;
		 }
	}
	
	
	
	private void deselected(panel p)
	{
		if(p!=null)
				p.setBorder(BorderFactory.createLineBorder(Color.black,2));
	selected--;}
	
	private void showselectedred(panel p)
	{if(p!=null)
		p.setBorder(BorderFactory.createLineBorder(Color.red,4));
	selected++;}
	
	public void mouseClicked(MouseEvent e)
	{
		
	
		if(selected==0)
showselectedred(listno,playerno);
		else if(selected==1)
			showselectedblack(listno,playerno);	
		else if(selected==2)
		{deselected(firstselected);
		deselected(secondselected);
			firstselected=secondselected;
			firstselectedno=secondselectedno;
			showselectedred(firstselected);
			showselectedblack(listno,playerno);
		
		}
		System.out.println("bl"+secondselectedno);
		System.out.println("red"+firstselectedno);
		mainFrame.repaint();
		
	}	
	
}
class adjust implements AdjustmentListener
{
	public void adjustmentValueChanged(AdjustmentEvent e)	
	{mainFrame.repaint();}
}

class buttonclass implements ActionListener
	{int buttonid;
	
	public buttonclass(int buttonid)
	{this.buttonid=buttonid;}
	
	
		
		
		
		public void actionPerformed(ActionEvent event)
		{//to obtain buttonid on nutton click
		//	SongTiles.this.setSongPlayingBackground();
		
			
			if(buttonid==1)
			{//start war
				godhelp();
				(new listener()).deselected(firstselected);
				(new listener()).deselected(secondselected);
				//resetselection();
			//processfileref.startgame();
					mainFrame.repaint();
			
		
			}
			
			else if(buttonid==2)
			{//right
				

				if(firstselected.getParent()==leftlistinner)
				{leftlistinner.remove(firstselected);
			firstlistitemcounter--;
			secondlistitemcounter++;
				rightlistinner.add(firstselected);
				resetselection();}
			}
			else if(buttonid==3)
			{//left
			//	Component a=rightlistinner.getComponents();
				if(firstselected.getParent()==rightlistinner)
				{rightlistinner.remove(firstselected);
				secondlistitemcounter--;
				firstlistitemcounter++;
				System.out.println("blqw"+secondselectedno);
				mainFrame.repaint();
				System.out.println("bldfg"+secondselectedno);
				leftlistinner.add(firstselected);
			//	rightlistinner.repaint();
				
				resetselection();}
			}
			else if(buttonid==4)
			{
				knockout=false;
			}
			mainFrame.repaint();
			
		///	String buttonid=(String)((JButton)event.getSource()).getClientProperty("buttonId");
			
		
		}
		
		
	
	}
}