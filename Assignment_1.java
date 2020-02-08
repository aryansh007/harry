/*
 * State Space:- An 8X8 matrix with any arrangement of n<=8 queens
 * Initial State:- No queens on the board(i.e., all entries are null)
 * 				0 0 0 0 0 0 0 0
 *				0 0 0 0 0 0 0 0
 * 				0 0 0 0 0 0 0 0
 * 				0 0 0 0 0 0 0 0
 * 				0 0 0 0 0 0 0 0
 * 				0 0 0 0 0 0 0 0
 * 				0 0 0 0 0 0 0 0
 * 				0 0 0 0 0 0 0 0
 * Transition Operator:- Add a new queen in an empty row
 * Goal state:- 8 Queens placed on the board such that all queens are in non-attacking position
 * For example,
 * 				0 0 Q 0 0 0 0 0
 * 				0 0 0 0 0 0 Q 0  
 * 				0 0 0 0 0 0 0 Q
 * 				Q 0 0 0 0 0 0 0
 * 				0 0 0 Q 0 0 0 0
 * 				0 0 0 0 0 0 Q 0
 * 				0 0 0 0 Q 0 0 0
 * 				0 Q 0 0 0 0 0 0
 * Cost:- One per move
 * 
 * Submitted by:- Aryan Sharma
 * Roll no:- 1801028
 * Btech 2nd Year CSE
 */

import java.util.*;
public class EightQueens
{
	int SIZE = 8;
	
	//Creating initial state
	String initialise(String arr)
	{
		for(int i=0;i<SIZE;i++)
			for(int j=0;j<SIZE;j++)
				arr+="0";
		return arr;
	}
	
	//Find the row where to insert the queen
	int find(String arr)
	{
	    int i;
		for(i=0;i<SIZE;i++)
		{
			int flag = 0;
			for(int j=0;j<SIZE;j++)
			{
				if(arr.charAt(SIZE*i+j) == '1')
				{
					flag = 1;
					break;
				}
			}
			if(flag == 0)
				return i;
		}
		return i;
	}
	
	//check if current state is valid
	boolean isValid(String arr)
	{
		for(int i=0;i<SIZE;i++)
		{
			int sum_row = 0;
			int sum_col = 0;
			for(int j=0;j<SIZE;j++)
			{
				sum_row+=(int)arr.charAt(SIZE*i+j)-48;
				sum_col+=(int)arr.charAt(SIZE*j+i)-48;
			}
			if(sum_row > 1 || sum_col > 1)
				return false;
		}
		for(int i=0;i<SIZE;i++)
		{
			int sum_left = 0;
			int sum_right = 0;
			for(int j=0;j+i<SIZE;j++)
			{
				sum_left+=(int)arr.charAt(SIZE*j+j+i)-48;
				sum_right+=(int)arr.charAt(SIZE*(j+i)+j)-48;
			}
			if(sum_left > 1 || sum_right > 1)
				return false;
		}
		for(int i=0;i<2*SIZE-1;i++)
		{
			int sum_left = 0;
			int sum_right = 0;
			if(i<SIZE)
			{
			   for(int j=0;i-j>=0;j++)
			   {
				   sum_left+=(int)arr.charAt(SIZE*j+i-j)-48;
			   }
			}
			else
			{
			   for(int j=i-SIZE+1;j<SIZE;j++)
			   {
			       sum_right+=(int)arr.charAt(SIZE*j+i-j)-48;
			   }
			}
			if(sum_left > 1 || sum_right > 1)
				return false;
		}
		return true;
	}
	
	//display valid state
	void display(String arr)
	{
		for(int i=0;i<SIZE;i++)
		{
			for(int j=0;j<SIZE;j++)
			{
				if(arr.charAt(SIZE*i+j)=='1')System.out.print("Q ");
				else System.out.print("_ ");
			}
		System.out.println();
		}
	}
	
	//driver function
	public static void main(String args[])
	{
		EightQueens obj = new EightQueens();
		String sol = "";
		sol = obj.initialise(sol);
		
		LinkedList<String> ucs = new LinkedList<String>();
		ucs.add(sol);
		
		int count = 1;
		
		while(!(ucs.isEmpty()))
		{
			//dequeue head of the queue
			String ans = ucs.poll();
			
			//check if the current state is valid
			if(!(obj.isValid(ans)))continue;
			
			//find where to insert the queen
			int i = obj.find(ans);
			
			//if the state is valid and solution is complete
			if(i==obj.SIZE)
			{
				System.out.println("----Solution "+count+"----");
				obj.display(ans);
				System.out.println("-------------------\n");
				count++;
			}
			else
			{
				//explore the current node and enqueue it
				for(int j=0;j<obj.SIZE;j++)
				{
					ans = ans.substring(0, obj.SIZE*i+j)+"1"+ans.substring(obj.SIZE*i+j+1);
					ucs.offer(ans);
					ans = ans.substring(0, obj.SIZE*i+j)+"0"+ans.substring(obj.SIZE*i+j+1);
				}
			}
			
		}
	}
}
