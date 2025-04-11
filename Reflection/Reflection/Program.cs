var type = typeof(Array);

foreach (var field in type.GetFields())
{
	Console.WriteLine(field.Name);
}


class Array
{
	public int Length;
	public int Capacity;
}