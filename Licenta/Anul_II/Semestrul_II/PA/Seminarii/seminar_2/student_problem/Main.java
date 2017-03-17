class Main
{
    public static void main(String args[])
    {
        Problem problem = new Problem(4, 3); //4 students, 3 projects
        Student s1 = new Student("S1", "s1@info.uaic.ro");        
        Student s2 = new Student("S2", "s2@info.uaic.ro");        
        Student s3 = new Student("S3", "s3@info.uaic.ro");        
        Student s4 = new Student("S4", "s4@info.uaic.ro");        

        Project p1 = new Project("P1", 10); //capacity is 2
        Project p2 = new Project("P2", 4); //capacity is 4
        Project p3 = new Project("P3", 6); //capacity is 6

        try
        {
            s1.setPreferences(p1, p2, p3);
            p1.setPreferences(s3, s1, s2, s4);                
            problem.setStudents(s1, s2, s3, s4);
            problem.setProjects(p1, p2, p3);
            System.out.println(problem);
        }
        catch(PBException exp)
        {
            System.out.println("Exceptioe :" + exp.toString());
        }
    }
}
