/*
	This is where Display.h is innitialize
*/
#include"GUI.h"


/*
	constructors and distrutor zone
*/
GUI::GUI()
{
	this->InitVar();
	this->InitWindow();
	this->InitText();
}

GUI::~GUI()
{
	delete this->window;
	/*delete this->holdersentence;*/
	std::cout << "GUI ending successfully" << std::endl;
}

/*
	Accessor
*/

const bool GUI::Running() const
{
	return this->window->isOpen();
}

/*
	Updating Function
*/
void GUI::Update()
{
	this->pollEvent();
}

void GUI::UpdateText1(std::string s1)
{

	std::stringstream ss1;
	ss1 << s1;
	
	this->main_line1.setString(ss1.str());

}

void GUI::UpdateText2(std::string s2)
{

	std::stringstream ss2;
	ss2 << s2;

	this->main_line2.setString(ss2.str());

}


//void GUI::UpdateText3(std::string s3) 
//{
//
//}
//void GUI::UpdateText4(std::string s4)
//{
//
//}
//void GUI::UpdateText3(std::string s5) 
//{
//
//}



/*
	Rendering Function
*/

//void GUI::InputUpdate() {
//	this->holdersentence = new sf::String;
//
//}

void GUI::Render()
{
	this->window->clear(sf::Color::White);
	//this->window->draw(info);
	//this->window->draw(in_arrow);
	this->RenderText1(*this->window);
	this->RenderText2(*this->window);
	this->RenderText3(*this->window);
	this->RenderText4(*this->window);
	this->RenderText5(*this->window);

	this->window->display();
}

void GUI::RenderText1(sf::RenderTarget &T)
{
	T.draw(this->main_line1);
}

void GUI::RenderText2(sf::RenderTarget& H)
{
	H.draw(this->main_line2);
}
void GUI::RenderText3(sf::RenderTarget& O)
{
	O.draw(this->main_line3);
}
void GUI::RenderText4(sf::RenderTarget& O)
{
	O.draw(this->main_line4);
}
void GUI::RenderText5(sf::RenderTarget& P)
{
	P.draw(this->main_line5);
}





/*
	Poll Event
*/
void GUI::pollEvent()
{
	//Event polling.
	while (this->window->pollEvent(this->Eve))
	{
		//Checking event happening.
		switch (this->Eve.type)
		{
		//For close buttom.
		case sf::Event::Closed:
			std::cout << "Event::Eve You just pressed X" << std::endl;
			this->window->close();
			break;
		case sf::Event::Resized:
			printf("%i,%i\n", Eve.size.width, Eve.size.height);
			break;
		//For when press Escape key.
		//case sf::Event::KeyPressed:
		//	if (this->Eve.key.code == sf::Keyboard::Escape)
		//		std::cout << "Event::Eve You just pressed Escape buttom" << std::endl;
		//		this->window->close();
		//	break;

		//For entering text.
		case sf::Event::TextEntered:
				if (this->Eve.text.unicode >= 32 && Eve.text.unicode <= 126 && sentence.getSize() < 20) // รับอินพุทต์แค่ 32 - 126 ในตารางยูนิโค้ดและจำกัดมันไว้แค่ 20 ตัวอักษร
				{
					sentence += (char)Eve.text.unicode; // ใส่ตัวอักษร char ทีละตัวลงไป
				}
				else if (Eve.text.unicode == 8 /*Delete key*/ && sentence.getSize() > 0) // ลบตัวอักษร
				{
					sentence.erase(sentence.getSize() - 1, sentence.getSize()); // ลบตามขนาดลงไปทีละตัว
				}
				else if (Eve.text.unicode == 13/*Enter key*/ && sentence.getSize()) // กด ENTER 
				{
					for (unsigned int i = 0; i < sentence.getSize(); i++)
					{
						putchar(tolower(sentence[i]));
					}
					sentence.clear();
				}


		default:
			break;
		}
	}
}

/*
	Initialize stuff
*/

void GUI::InitVar()
{
	this->window = nullptr;
}

void GUI::InitWindow()
{
	this->videomode.height = 1048;
	this->videomode.width = 1048;
	this->window = new sf::RenderWindow(this->videomode, "Text Adventure", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
	this->window->setFramerateLimit(30);
}

void GUI::InitText()
{	
	//loading font
	if(this->font.loadFromFile("Resouces/Font/Simple_text.ttf"))
	{
		std::cout << "GUI::font loaded successfully"<<std::endl;
	}

	//Setting testing text	
	this->main_line1.setFont(this->font);
	this->main_line1.setCharacterSize(23);
	this->main_line1.setFillColor(sf::Color::Black);
	this->main_line1.setPosition(50, 700);

	this->main_line2.setFont(this->font);
	this->main_line2.setCharacterSize(23);
	this->main_line2.setFillColor(sf::Color::Black);
	this->main_line2.setPosition(50, 660);

	this->main_line3.setFont(this->font);
	this->main_line3.setCharacterSize(23);
	this->main_line3.setFillColor(sf::Color::Black);
	this->main_line3.setPosition(50, 600);

	this->main_line4.setFont(this->font);
	this->main_line4.setCharacterSize(23);
	this->main_line4.setFillColor(sf::Color::Black);
	this->main_line4.setPosition(50, 560);

	this->main_line5.setFont(this->font);
	this->main_line5.setCharacterSize(23);
	this->main_line5.setFillColor(sf::Color::Black);
	this->main_line5.setPosition(50, 620);


	//info.setString("Testing");
	//info.setPosition(0, 600);
	//info.setCharacterSize(23);
	//info.setFillColor(sf::Color::Black);

	//in_arrow.setString("> ");
	//in_arrow.setPosition(0, 800);
	//in_arrow.setCharacterSize(23);
	//in_arrow.setFillColor(sf::Color::Black);

}
