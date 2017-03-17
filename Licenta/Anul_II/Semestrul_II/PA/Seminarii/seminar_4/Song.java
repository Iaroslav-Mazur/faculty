class Song extends Item
{
	static public String type = "song";
	private String name;
	private String path;

	Song(String name, String path)
	{
		this.name=name;
		this.path=path;
	}

	public void display()
	{
		System.out.println("The name of the song: " + this.name + ". \n The path leading to the song: " + path);
	}

}
