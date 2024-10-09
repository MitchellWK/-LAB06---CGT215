#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
int main() {

	Texture backgroundTex;
	if (!backgroundTex.loadFromFile("winter.png")) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}
	Texture foregroundTex;
	if (!foregroundTex.loadFromFile("yoda.png")) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}
	Image backgroundImage = backgroundTex.copyToImage();

	Image foregroundImage = foregroundTex.copyToImage();

	Vector2u sz = backgroundImage.getSize();
	for (int y = 0; y < sz.y; y++) {
		for (int x = 0; x < sz.x; x++) {
			Color bgColor = backgroundImage.getPixel(x, y);
			Color fgColor = foregroundImage.getPixel(x, y);

			float alpha = fgColor.a / 255.f;

			Color resultColor(
				(bgColor.r + fgColor.r) / 2,
				(bgColor.g + fgColor.g) / 2,
				(bgColor.b + fgColor.b) / 2
			);

			foregroundImage.setPixel(x, y, resultColor);
		}
	}
	RenderWindow window(VideoMode(1024, 768), "Here's the output");
	Sprite sprite1;
	Texture tex1;
	tex1.loadFromImage(foregroundImage);
	sprite1.setTexture(tex1);

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(sprite1);
		window.display();
	}

	while (true);
}