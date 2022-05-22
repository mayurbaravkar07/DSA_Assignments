import java.util.*;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

//interface DEPTRECORDS{
//
//    void addrecords(String name , String  dept , int rollnumber);
//    void readRecords();
//
//}
public class ass6  {
    public static Scanner rc= new Scanner(System.in);
    File file = new File("thor.txt");
    private FileWriter writer;

    public static String filename="thor.txt";

    public void addrecords(String name , String department , int rollnumber){
        try {
            writer = new FileWriter(filename , true);
            writer.append(" Name- " + name + "  Department- " + department + "  rollnumber " + rollnumber + "\n");
            writer.close();
        }catch (IOException e){
            System.out.println("an error occured");
        }
    }
    public void readrecord(){
        try{
            file = new File(filename);
            Scanner sc = new Scanner(file);
            while(sc.hasNextLine()) {
                String ata = sc.nextLine();
                System.out.println(ata);
            }
//                file.close();
        }catch (IOException e){
            System.out.println("An error occured");
        }



    }


    public static void main(String[] args) {

        ass6 ob =new ass6();
        int ans,ch;

        do{
            System.out.println("1.addRecords");
            System.out.println("2.ReadRecords");
            System.out.println("ENter your choice");
            ch=rc.nextInt();

            switch(ch){
                case 1:
                    String name,dept;
                    int rollnumber;

                    System.out.println("Enter the name of student");
                    name=rc.next();

                    System.out.println("ENter the name of department");
                    dept=rc.next();

                    System.out.println("Enter the roll number");
                    rollnumber=rc.nextInt();

                    ob.addrecords(name,dept,rollnumber);

                    break;

                case 2:ob.readrecord();
                        break;
                default:
                    System.out.println("You have Entered Wrong choice");
                    break;
            }




            System.out.println("Do you want to continue");
            ans= rc.nextInt();

        }while(ans==1);
        ob.readrecord();

    }
}
