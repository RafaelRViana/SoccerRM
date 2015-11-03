#ifndef ELEMENTO_REDONDO
#define ELEMENTO_REDONDO

class ElementoRedondo
{

	protected:
		int x, y;
		int raio;

	public:
		ElementoRedondo( int x, int y, int raio );
		int getY();
		int getX();
		int getRaio();
		
		virtual void tratarColisao( int ladoColisao ) = 0;
};

ElementoRedondo::ElementoRedondo( int x, int y, int raio )
{
	this -> x = x;
	this -> y = y;
	this -> raio = raio;
}

int ElementoRedondo::getX()
{
	return x;
}

int ElementoRedondo::getY()
{
	return y;
}

int ElementoRedondo::getRaio()
{
	return raio;
}

#endif
