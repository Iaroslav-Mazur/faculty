import java.util.Vector;
class Project
{
    protected Vector<Student> studentsRest;
    String name;
    int capacity;

    public Project(String name, int capacity)
    {
        this.name = name;
        this.capacity = capacity;
    }

    /* NOTE(mmicu): Cod duplicat */
    public void setPreferences(Student ... studentList) throws PBException
    {
        /**
         * Adauga studenti pentru proiect.
         * Metoda va verifica daca nr maxim de studenti
         * nu este atins.
         * @param studentList numar variabil de parameri de tip Student
         */
        if (studentList.length > this.capacity)
        {
            String msg = "Numarul maxim de studenti care ii putem adauga este " + this.capacity+ " am primit " + studentList.length;

            throw new PBException(msg);
        }
        this.studentsRest = new Vector<Student>();
        for (int i = 0; i < studentList.length; i++)
        {
            this.studentsRest.addElement(studentList[i]);
        }
    }
    public Vector<Student> getStudents()
    {
        /* TODO(mmicu): Shallow copy find a way to deep copy */
        return this.studentsRest;
    }
    public int getCapacity()
    {
        return this.capacity;
    }

    public String getName()
    {
        return this.name;
    }

    public String toString()
    {
        String msg = "Proiect[" + this.name + "] Restriciti :" + this.studentsRest.toString();
        return msg;
    }
}
