import java.util.*;

class Problem
{
    protected Vector<Project> projects;
    protected Vector<Student> students;

    private int maxStudents, maxProjects;

    public Problem(int maxStudents, int maxProjects)
    {
        this.maxStudents = maxStudents;
        this.maxProjects = maxProjects;
    }

    public void setProjects(Project ... projectsList) throws PBException
    {
        /**
         * Adauga proiectele pentru problema.
         * Metoda va verifica daca nr maxim de proiecte 
         * nu este atins.
         * @param projectsList variabil de parameri de tip Student
         */
        if (projectsList.length > this.maxProjects)
        {
            String msg = "Numarul maxim de studenti care ii putem adauga este " + this.maxProjects + " am primit " + projectsList.length;

            throw new PBException(msg);
        }
        this.projects = new Vector<Project>();
        for (int i = 0; i < projectsList.length; i++)
        {
            this.projects.addElement(projectsList[i]);
        }
    }

    public void setStudents(Student ... studentList) throws PBException
    {
        /**
         * Adauga studenti pentru problema.
         * Metoda va verifica daca nr maxim de studenti
         * nu este atins.
         * @param studentList numar variabil de parameri de tip Student
         */
        if (studentList.length > this.maxStudents)
        {
            String msg = "Numarul maxim de studenti care ii putem adauga este " + this.maxStudents + " am primit " + studentList.length;

            throw new PBException(msg);
        }
        this.students = new Vector<Student>();
        for (int i = 0; i < studentList.length; i++)
        {
            this.students.addElement(studentList[i]);
        }

    }
    public String toString()
    {
        String msg = new String();
        msg += "Capacitate Students:" + this.maxStudents +"\n Capacitate Projects :";
        msg += this.maxProjects + "\n ";
        return msg;
    }
}
