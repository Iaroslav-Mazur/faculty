class Book extends Item
{
	static public String type = "book";
	private String name;
	private String path;

	Book(String name, String path)
	{
		this.name=name;
		this.path=path;
	}

	public void display()
	{
		System.out.println("The name of the book: " + this.name + ". \n The path leading to the book: " + path);
	}

}
