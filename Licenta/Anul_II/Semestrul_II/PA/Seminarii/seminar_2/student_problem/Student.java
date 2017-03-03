import java.util.Vector;
class Student 
{
    protected Vector<Project> projects_rest;
    private String name, email;

    public Student(String name, String email)
    {
        this.name = name;
        this.email = email;
    }

    public String getName()
    {
        return this.name;
    }

    public String getEmail()
    {
        return this.email;
    }

    public void setName(String name)
    {
        this.name = name;
    }

    public void setEmail(String email)
    {
        this.email = email;
    }

    public void setPreferences(Project ... projectsList)
    {
        /**
         * Adauga restictiile de proiect pentru studentul curent.
         * @param projectsList Lista cu restictii
         */
        this.projects_rest = new Vector<Project>();
        for (int i = 0; i < projectsList.length; i++)
        {
            this.projects_rest.addElement(projectsList[i]);
        }
    }

    public String toString()
    {
        String msg = new String();
        msg = "Student[" + this.name + "] Restrictii: " + this.projects_rest.toString();
        return msg;
    }

    public Vector<Project> getRest()
    {
        /* TODO(mmicu): Shallow copy find a way to make a deep copy
         */
        return this.projects_rest;
    }

    public boolean equals(Object obj)
    {
        if(obj == null)
            return false;

        if(obj == this)
            return true;

        if( !(obj instanceof Student) )
        {
            return false;
        }

        Student st = (Student)obj;
        if(!(this.name.equals(st.getName())))
        {
            return false;
        }

        if(!(this.email.equals(st.getEmail())))
        {
            return false;
        }

        if(!(this.projects_rest.equals(st.getRest())))
        {
            return false;
        }
        return true;
    }
}

