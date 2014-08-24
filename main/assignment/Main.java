package assignment;

import java.io.*;
import java.util.*;
import java.util.regex.Pattern;

import comm.AddStepException;
import domain.*;
import service.TrainsService;

public class Main {
    public static void main(String args[]) throws Exception {
        //Scanner scanner = new Scanner(new File("input.txt"));
    	Scanner scanner = new Scanner(System.in);
        scanner.skip(Pattern.compile("Graph:\\s*"));
        TownsMap map = new TownsMap();
        while(scanner.hasNext())
        {
        	String str = scanner.next();
        	System.out.println(str);
        	int distance;
        	try {
        		distance = Integer.parseInt(str.substring(2, str.indexOf(',')));
        	}
        	catch (Exception e)
        	{
        		distance = Integer.parseInt(str.substring(2));
        	}
        	
        	map.addRoute(str.charAt(0) - 'A' + 1, str.charAt(1) - 'A' + 1, distance);
        } 
        TrainsService trainsService = new TrainsService(map);
        
        int count = 1;
        trainsService.getTownsMap().printMap();
        
        //Case 1
    	try {
    		Path path = new Path();
    		path.addStep(1, 2);
    		path.addStep(2, 3);
    		System.out.println("Output #" + count + ": " + trainsService.walkThroughPath(path));
    		count++;
    	}
    	catch (AddStepException e)
    	{
    	}
        
    	//Case 2
    	try {
    		Path path = new Path();
    		path.addStep(1, 4);
    		System.out.println("Output #" + count + ": " + trainsService.walkThroughPath(path));
    		count++;
    	}
    	catch (AddStepException e)
    	{
    	}     
        
    	//Case 3
    	try {
    		Path path = new Path();
    		path.addStep(1, 4);
    		path.addStep(4, 3);
    		System.out.println("Output #" + count + ": " + trainsService.walkThroughPath(path));
    		count++;
    	}
    	catch (AddStepException e)
    	{
    	}     
    	
    	//Case 4
    	try {
    		Path path = new Path();
    		path.addStep(1, 5);
    		path.addStep(5, 2);
    		path.addStep(2, 3);
    		path.addStep(3, 4);
    		System.out.println("Output #" + count + ": " + trainsService.walkThroughPath(path));
    		count++;
    	}
    	catch (AddStepException e)
    	{
    	}     
        
    	//Case 5
    	try {
    		Path path = new Path();
    		path.addStep(1, 5);
    		path.addStep(5, 4);
    		System.out.println("Output #" + count + ": " + trainsService.walkThroughPath(path));
    		count++;
    	}
    	catch (AddStepException e)
    	{
    	}   
    	
    	//Case 6
    	try {
    		System.out.println("Output #" + count + ": " + trainsService.searchStops(3, 3, 1, 3));
    		count++;
    	}
    	catch (Exception e)
    	{
    	}   
    	
    	//Case 7
    	try {
    		System.out.println("Output #" + count + ": " + trainsService.searchStops(1, 3, 4, 4));
    		count++;
    	}
    	catch (Exception e)
    	{
    	}  
    	
    	//Case 8
    	try {
    		System.out.println("Output #" + count + ": " + trainsService.minimumDistance(1, 3));
    		count++;
    	}
    	catch (Exception e)
    	{
    	}  
    	
    	//Case 9
    	try {
    		System.out.println("Output #" + count + ": " + trainsService.minimumDistance(2, 2));
    		count++;
    	}
    	catch (Exception e)
    	{
    	}  
    	
    	//Case 10
    	try {
    		System.out.println("Output #" + count + ": " + trainsService.searchDistance(3, 3, 1, 29));
    		count++;
    	}
    	catch (Exception e)
    	{
    	}  
    }
}
