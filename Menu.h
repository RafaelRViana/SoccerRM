using namespace std;

class Menu
{
	private:
		BITMAP *buffer;
		
	public:
		Menu(BITMAP *buffer);
		void desenhar();

};

Menu::Menu(BITMAP *buffer)
{
	this -> buffer = buffer;
}

void Menu::desenhar()
{
	int linhaTexto = ALTURA_CAMPO + 5; 
	
	textout_ex(buffer, font, "1   - Start", 10, linhaTexto, makecol (255,255,255), -1);
	textout_ex(buffer, font, "2   - Pause", 10, linhaTexto+25, makecol (255,255,255), -1);
	textout_ex(buffer, font, "3   - Reset", 10, linhaTexto+50, makecol (255,255,255), -1);
	textout_ex(buffer, font, "ESC - Back to Menu", 10, linhaTexto+75, makecol (255,255,255), -1);
}
