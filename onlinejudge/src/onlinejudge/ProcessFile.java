package onlinejudge;

import java.awt.BorderLayout;
import java.awt.EventQueue;
import java.awt.Font;
import java.io.*;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintStream;

import javax.swing.JFrame;
import javax.swing.JLabel;

public class ProcessFile {
	ProcessBuilder processor;
	ProcessBuilder docompile;
	ProcessBuilder dorun;
	private int xno=-1;
	private int yno=-1;
	private boolean fileCompiled=false;
	private boolean invalidmove=false;
	private boolean foundwinner=false;
	private boolean runtimeerror=false;
	private boolean timelimitexceeded=false;
	private board gameboard;
	private   String file1="first.c";
	private   String file2="second.c";
	private   String firstcompiled="firstobject";
	private   String secondcompiled="secondobject";
    private String codefile;
	private  String fileType;
	private boolean compiled=false;
	private int[][] boardarray;
	ProcessBuilder	process2;
	private fixmatch fixmatchpointer;
	public static JFrame f=new JFrame();
	public static ProcessFile p=null;
	public ProcessFile(int a)
	{}
	public ProcessFile()
	{
		p=this;
		fixmatchpointer=	new fixmatch(this,f);
		Thread th=new Thread(fixmatchpointer,"first");
		th.start();
		//gameboard=new board(f);
	
	//f=gameboard.boardgui.returnframe();
	f=fixmatchpointer.returnframe();
	f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	
    f.setExtendedState(JFrame.MAXIMIZED_BOTH);
 	f.setVisible(true);//
	try{Thread.sleep(2500);
	}
  	catch(Exception ex)
  	{System.out.println("problem while making a thread sleep");}
	
//	fixmatchpointer=	new fixmatch(this,f);
//	f=fixmatchpointer.returnframe();
	//f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	
	//f.setExtendedState(JFrame.MAXIMIZED_BOTH);
	//f.setVisible(true);
/*	//f.removeAll();
JLabel gamename = new JLabel("Time Starts now", JLabel.CENTER);
gamename.setFont(new Font("SERIF", Font.BOLD, 30));
gamename.setText("Clash Of Clans");
f.getContentPane().add(BorderLayout.NORTH,gamename);
	f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	
	f.setExtendedState(JFrame.MAXIMIZED_BOTH);
	f.setVisible(true);
	f.getContentPane().removeAll();
	 gamename = new JLabel("Time Starts now", JLabel.CENTER);
	gamename.setFont(new Font("SERIF", Font.BOLD, 30));
	gamename.setText("Clash Of Cls");
	f.getContentPane().add(BorderLayout.NORTH,gamename);
	f.validate();
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		f.setExtendedState(JFrame.MAXIMIZED_BOTH);
		f.setVisible(true);
//	f.repaint();
		startgame();*/
	gameboard=new board(f);
	waittillnotify();
	
	}
	public void waittillnotify()
	{  synchronized(this)
	      {try{ this.wait();
	    	}
	      	catch(Exception ex)
	      	{System.out.println("problem while waiting making a thread sleep");}
	       }
	startgame();
	}
	
public void  setfile(String f1,String f2)
{file1=f1;
file2=f2;
}
public void startgame()
{
//f=gameboard.boardgui.returnframe();
	System.out.println(fixmatchpointer.getp1name());
	
	gameboard.boardgui.setdetails(fixmatchpointer.getp1name(), fixmatchpointer.getp2name(), fixmatchpointer.getp1roll(), fixmatchpointer.getp2roll());
	System.out.println(gameboard.boardgui.p2roll);
//f=fixmatchpointer.returnframe();
//f.getContentPane().removeAll();


JLabel gamename = new JLabel("Time Starts now", JLabel.CENTER);
gamename.setFont(new Font("SERIF", Font.BOLD, 30));
gamename.setText("Clash Of Clans");
//f.getContentPane().add(BorderLayout.NORTH,gamename);

	f=gameboard.boardgui.returnframe();
	f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	f.validate();
	f.setExtendedState(JFrame.MAXIMIZED_BOTH);
	f.setVisible(true);
	f.getContentPane().repaint();


	//fixmatchpointer.frame.setVisible(false);
	//gameboard=new board();
	//fixmatchpointer.frame.setVisible(true);
	//gameboard.boardgui.frame.setVisible(false);
	
	try{Thread.sleep(250);
	}
  	catch(Exception ex)
  	{System.out.println("problem while making a thread sleep");}
	
//	EventQueue.invokeLater(new Runnable()
//	{public void run()
{System.out.println(file1);
checkcompilation(file1,firstcompiled,1);
if(fileCompiled){
checkcompilation(file2,secondcompiled,2);
if(fileCompiled){


	startplaying();
	
}
}}
//});
	
	
	//programRunner();
}
	
	private void checkcompilation(String filename,String objfileName,int num)
	{String errorfound,outputfound;
		try{
			docompile= new ProcessBuilder("gcc",filename,"-o",objfileName);		



docompile.directory(new File(System.getProperty("user.dir")));

	Process pro=docompile.start();
	InputStream error=pro.getErrorStream();
	pro.waitFor();
	BufferedReader b=new BufferedReader(new InputStreamReader(error));
if((errorfound=b.readLine())==null)
{System.out.println("player"+num+" file compiled succesfully!!\n");
fileCompiled=true;
}
else
{
	System.out.println(errorfound);
	while((errorfound=b.readLine())!=null)
	{
		System.out.println(errorfound);
	}}
		}
		catch(Exception e)
		{System.out.println("error occured on opening input stream\n");}
			
}
	
	public void startplaying()
	{int i=0,player=1,j=2;
	System.out.println("asdsffgd\n");
		
	//gameboard.boardgui.frame.setVisible(true);
		while((!foundwinner)&&(!invalidmove)&&(!runtimeerror)&&(!timelimitexceeded))
		{//f=gameboard.boardgui.returnframe();
		///	f.setVisible(true);
	//	f.getContentPane().repaint();
		
	//	fixmatchpointer.frame.setVisible(false);
			i++;System.out.println("asdsffgd\n");
          if((i%2)==1)	
          {  runfile(firstcompiled,1);
          
          player=1;}
          else
          {	  runfile(secondcompiled,2); 
          player=2;
          }
          foundwinner=gameboard.checkwinner();
          invalidmove=gameboard.checkinvalidmove();
			//break;//remove later

      	try{Thread.sleep(2500);
      	
      	
      if((!foundwinner)&&(!invalidmove)&&(!gameboard.checkwinner())&&(!timelimitexceeded))
    	  gameboard.getgui().updatestatus("waiting for player "+((player%2)+1)+"...");
      	Thread.sleep(500);}
      	catch(Exception ex)
      	{System.out.println("problem while making a thread sleep");}
		}
		
		if(foundwinner)
			{System.out.println("player "+player+" win");
			//f.getContentPane().removeAll();
			f=fixmatchpointer.returnframe();
			f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			f.validate();
			f.setExtendedState(JFrame.MAXIMIZED_BOTH);
			f.setVisible(true);
			f.getContentPane().repaint();
			fixmatchpointer.killloser(player);
			gameboard.reset();
			foundwinner=false;
			waittillnotify();
			}
		else if(invalidmove)
			{System.out.println("invalid move. player "+player+" loss");
			f=fixmatchpointer.returnframe();
			f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			f.validate();
			f.setExtendedState(JFrame.MAXIMIZED_BOTH);
			f.setVisible(true);
			f.getContentPane().repaint();
			fixmatchpointer.killloser(player%2+1);
			gameboard.reset();
			invalidmove=false;
			waittillnotify();
			}
		else if(runtimeerror)
			{System.out.println("runtime error. player "+((player+1)%2)+" loss");
			f=fixmatchpointer.returnframe();
			f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			f.validate();
			f.setExtendedState(JFrame.MAXIMIZED_BOTH);
			f.setVisible(true);
			f.getContentPane().repaint();
			fixmatchpointer.killloser(player);
			gameboard.reset();
			runtimeerror=false;
			waittillnotify();
			}
		else if(timelimitexceeded)
		{	System.out.println("Time limit exceeded. player "+player+" loss");
		 gameboard.getgui().updatestatus("Time limit exceeded. player "+player+" loss");
		 try{Thread.sleep(1000);
			}
		  	catch(Exception ex)
		  	{System.out.println("problem while making a thread sleep");}
			
		 f=fixmatchpointer.returnframe();
			f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			f.validate();
			f.setExtendedState(JFrame.MAXIMIZED_BOTH);
			f.setVisible(true);
			f.getContentPane().repaint();
			fixmatchpointer.killloser(player%2+1);
			gameboard.reset();
			timelimitexceeded=false;
			waittillnotify();
		}
	}
	
	private void runfile(String filecompiled,int player)
	{   	String errorfound, outputfound;
		boardarray=gameboard.getCurrentBoard();
		dorun= new ProcessBuilder("./"+filecompiled);
		dorun.directory(new File(System.getProperty("user.dir")));
		try{
        Process run=dorun.start();
        InputStream output=run.getInputStream();
        InputStream error=run.getErrorStream();
		 OutputStream input=run.getOutputStream(); 
		 PrintStream ps=new PrintStream(input);
		
		 BufferedReader b=new BufferedReader(new InputStreamReader(error));
		 
		// if((errorfound=b.readLine())==null)
		// {
			 System.out.println("player"+player+" file run succesfully!!\n");
		 System.out.println("11asd\n");
		
        for(int i=0;i<=4;i++)
		{
			for(int j=0;j<=4;j++)
			{ 
				if(j==4)
					ps.println(boardarray[i][j]);
				else
				 ps.print(boardarray[i][j]+" ");
				 ps.flush();
				 
			}
		}
        ps.println(player);
		 ps.flush();
        ps.close();
       
        synchronized(run)
        { System.out.println("fff");
        run.wait(1000);}System.out.println("fff");
        
        
     //  run.destroy();
     //
        
      //  while((( errorfound=b.readLine())!=null)&& ( ! errorfound.trim().isEmpty()));
       
        
    //    System.out.println(errorfound);
        BufferedReader out=new BufferedReader(new InputStreamReader(output));
		
        System.out.println("fff");outputfound=out.readLine();
        output.close();
out.close();
        System.out.println("fff");
		 System.out.println(outputfound+"output hai "); 
		 if(outputfound==null)
		 {timelimitexceeded=true;
		 }
		 else{
			
			 String coord[]=outputfound.split(" ");
		 xno=Integer.parseInt(coord[0]);
	//	 outputfound=out.readLine();
		 yno=Integer.parseInt(coord[1]); 
		 System.out.println(xno +"and"+yno);
		 gameboard.play(xno, yno, player);
		 }
		
		//else
	//	{runtimeerror=true; 
		//	System.out.println(errorfound);
		///	while((errorfound=b.readLine())!=null)
		//	{
		//		System.out.println(errorfound);
		//	}
	//	}
		}
		catch(Exception e)
		{
			e.printStackTrace();
			System.out.println("error occured on running compiled file of player "+player+"\n");}
		
	}
	
	
}//class